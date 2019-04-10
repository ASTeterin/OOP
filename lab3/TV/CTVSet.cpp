
#include "pch.h"
#include "CTVSet.h"

CTVSet::CTVSet()
{
	m_isOn = false;
	m_selectedChannel = FIRST_CHANNEL;
	m_previousChannel = FIRST_CHANNEL;
	channelInfo currentChannel;
	for (int i = FIRST_CHANNEL; i <= END_CHANNEL; i++)
	{
		
		currentChannel.channel = i;
		currentChannel.channelName = "";
		m_channelInfo.push_back(currentChannel);
	}
}


CTVSet::~CTVSet()
{
}


bool CTVSet::IsTurnedOn()const
{
	return m_isOn;
}

void CTVSet::TurnOn()
{
	m_isOn = true;
}

void CTVSet::TurnOff()
{
	m_isOn = false;
}

int CTVSet::GetChannel()const
{
	return m_isOn ? m_selectedChannel : 0;
}

string CTVSet::GetChannelName(int channel)const
{
	if (!m_isOn)
	{
		return "";
	}
	for (channelInfo currChannel : m_channelInfo)
	{
		if (currChannel.channel == channel)
		{
			return currChannel.channelName;
		}
	}
	return "";
}

int CTVSet::GetChannelByName(string const& name)const
{
	if (!m_isOn)
	{
		return 0;
	}
	for (channelInfo currChannel : m_channelInfo)
	{
		if (currChannel.channelName == name)
		{
			return currChannel.channel;
		}
	}
	return 0;
}

vector <channelInfo> CTVSet::GetChannelList()const
{
	return m_channelInfo;
}


bool CTVSet::SetChannelName(int channel, string const& name)
{
	bool isAvailableChannel = (channel >= 1) && (channel <= 99);
	if (!isAvailableChannel || !m_isOn)
	{
		return false;
	}
	if (GetChannelByName(name) != 0)
	{
		DeleteChannelName(name);
	}

	m_channelInfo[channel - 1].channelName = name;
	return true;
}


bool CTVSet::DeleteChannelName(string const& name)
{
	if ((name == "") || !m_isOn)
	{
		return false;
	}
	/*for (auto currChannel = m_channelInfo.begin(); currChannel != m_channelInfo.end(); currChannel++)
	{
		if (currChannel->channelName == name)
		{
			currChannel->channelName = "";
			return true;
		}
	}*/

	if (int channel = RequiredChannel(name, m_channelInfo) != 0)
	{
		SetChannelName(channel, "");
		return true;
	}
	return false;

}

bool CTVSet::SelectChannel(int channel)
{
	bool isAvailableChannel = (channel >= FIRST_CHANNEL) && (channel <= END_CHANNEL);
	if (isAvailableChannel && m_isOn)
	{
		m_previousChannel = m_selectedChannel;
		m_selectedChannel = channel;
		return true;
	}
	return false;
}

bool CTVSet::SelectChannel(string const& name)
{
	if ((!m_isOn) || (name == ""))
	{
		return false;
	}

	if (int currChannel = RequiredChannel(name, m_channelInfo) != 0)
	{
		m_previousChannel = m_selectedChannel;
		m_selectedChannel = currChannel;
		return true;
	}		
	return false;
}

int CTVSet::RequiredChannel(string const& name, vector<channelInfo> const& channelInfo)
{
	for (auto currChannel = channelInfo.begin(); currChannel != channelInfo.end(); currChannel++)
	{
		if (currChannel->channelName == name)
		{
			return currChannel->channel;
		}
	}
	return 0;
}

bool CTVSet::SelectPreviousChannel()
{
	if (m_isOn)
	{
		std::swap(m_selectedChannel, m_previousChannel);
		return true;
	}
	return false;
}



