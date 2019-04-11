#include "pch.h"
#include "RemoteControl.h"
#include "CTVSet.h"
#include <sstream>
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
		{ "DeleteChannelName", bind(&CRemoteControl::DeleteChannelName, this, _1) },
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
	
	for (auto channelInfo : m_tv.GetChannelList())
	{
		if (channelInfo.channelName != "")
		{
			m_output << channelInfo.channel << " - " << channelInfo.channelName << "\n";
		}
	}
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
	bool isParsAllString = (notParsedChannel.length() == to_string(channel).length());
	
	if ((channel == 0) || (!isParsAllString))
	{
		if (m_tv.SelectChannel(notParsedChannel))
		{
			m_output << "TV switched on " << notParsedChannel	 << " channel.\n";
			return true;
		}
	}

	if (!isValidChannel(channel, FIRST_CHANNEL, END_CHANNEL))
	{
		m_output << "Invalid channel specified.\n";
		return false;
	}

	if (m_tv.SelectChannel(channel))
	{
		m_output << "TV switched on " << channel << " channel.\n";
		return true;
	}
	m_output << "TV is turned off\n";
	return false;
}

bool CRemoteControl::SelectPreviousChannel(std::istream & args)
{
	if (m_tv.SelectPreviousChannel())
	{
		m_output << "TV switched on " << m_tv.GetChannel() << " channel.\n";
		return true;
	}
	m_output << "TV is turned off\n";
	return false;
}

bool CRemoteControl::DeleteChannelName(std::istream & args)
{
	string channelName;
	string notParsedChannelName;
	getline(args, notParsedChannelName);
	channelName = regex_replace(notParsedChannelName, std::regex("^[ ]*(.*?)[ ]*$"), "$1");
	if (!m_tv.IsTurnedOn())
	{
		m_output << "TV is turned off\n";
		return false;
	}

	if (m_tv.DeleteChannelName(channelName))
	{
		m_output << "Channel " << channelName << " was deleted\n";
		return true;
	}

	m_output << "Error deleting channel\n";
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
		m_output << "channel number " << notParsedChannelNumber << " is not a number. ";
		return false;
	}

	if (!isValidChannel(channel, FIRST_CHANNEL, END_CHANNEL))
	{
		m_output << "Invalid channel specified.\n";
		return false;
	}
	if (m_tv.SetChannelName(channel, channelName))
	{
		m_output << "For channel " << channel << " set up the name " << channelName << "\n";
		return true;
	}
	m_output << "TV is turned off\n";
	return false;
}


bool CRemoteControl::isValidChannel(int channel, int firstChannel, int lastChannel)
{
	if ((channel < firstChannel) || (channel > lastChannel))
	{
		m_output << "Invalid channel number. ";
		return false;
	}
	return true;
}


