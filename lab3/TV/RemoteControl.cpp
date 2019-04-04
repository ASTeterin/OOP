#include "pch.h"
#include "RemoteControl.h"
#include "CTVSet.h"
#include <regex>

using namespace std;
using namespace std::placeholders;

CRemoteControl::CRemoteControl(CTVSet & tv, std::istream & input, std::ostream & output)
	: m_tv(tv)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "TurnOn", [this](istream & strm) {
				return TurnOn(strm);
			} },
		{ "TurnOff", bind(&CRemoteControl::TurnOff, this, _1) },
		{ "Info", bind(&CRemoteControl::Info, this, _1) },
		{ "SelectChannel", bind(&CRemoteControl::SelectChannel, this, _1) },
		{ "SelectPreviousChannel", bind(&CRemoteControl::SelectPreviousChannel, this, _1) },
		{ "SetChannelName", bind(&CRemoteControl::SetChannelName, this, _1) },		
	})
{
}

bool CRemoteControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}
	
	return false;
}

bool CRemoteControl::TurnOn(std::istream & args)
{
	m_tv.TurnOn();
	m_output << "TV is turned on" << endl;
	return true;
}

bool CRemoteControl::TurnOff(std::istream & args)
{
	m_tv.TurnOff();
	m_output << "TV is turned off" << endl;
	return true;
}

bool CRemoteControl::Info(std::istream & args)
{
	string info = (m_tv.IsTurnedOn())
		? ("TV is turned on\nChannel is: " + to_string(m_tv.GetChannel()) + "\n")
		: "TV is turned off\n";

	m_output << info;
	return true;
}

bool CRemoteControl::SelectChannel(std::istream & args)
{
	string param;
	string notParsedChannel;
	string outputInfo;
	getline(args, param);
	notParsedChannel = regex_replace(param, std::regex("^[ ]*(.*?)[ ]*$"), "$1");
	int channel = atoi(notParsedChannel.c_str());
	
	if (channel == 0)
	{
		if (m_tv.SelectChannel(notParsedChannel))
		{
			cout << "TV switched on " << notParsedChannel	 << " channel.\n";
			return true;
		}
	}

	if (!isValidChannel(channel, FIRST_CHANNEL, END_CHANNEL))
	{
		return false;
	}

	if (m_tv.SelectChannel(channel))
	{
		cout << "TV switched on " << channel << " channel.\n";
		return true;
	}
	cout << "TV is turned off\n";
	return false;
}

bool CRemoteControl::SelectPreviousChannel(std::istream & args)
{
	if (m_tv.SelectPreviousChannel())
	{
		cout << "TV switched on " << m_tv.GetChannel() << " channel.\n";
		return true;
	}
	return false;
}

bool CRemoteControl::SetChannelName(std::istream & args)
{
	string notParsedChannelNumber;
	string notParsedChannelName;
	string channelName;
	int channel;

	getline(args, notParsedChannelNumber, ',');
	getline(args, notParsedChannelName);
	channel = atoi(notParsedChannelNumber.c_str());
	channelName = regex_replace(notParsedChannelName, std::regex("^[ ]*(.*?)[ ]*$"), "$1");

	if (channel == 0)
	{
		cout << "channel number " << notParsedChannelNumber << " is not a number. ";
		return false;
	}

	if (!isValidChannel(channel, FIRST_CHANNEL, END_CHANNEL))
	{
		return false;
	}
	if (m_tv.SetChannelName(channel, channelName))
	{
		cout << "For channel " << channel << " set up the name " << channelName << "\n";
		return true;
	}
	return false;
}


bool CRemoteControl::isValidChannel(int channel, int firstChannel, int lastChannel)
{
	if ((channel < firstChannel) || (channel > lastChannel))
	{
		cout << "Invalid channel number. ";
		return false;
	}
	return true;
}


