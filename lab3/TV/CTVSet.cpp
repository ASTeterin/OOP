
#include "pch.h"
#include "CTVSet.h"

CTVSet::CTVSet()
{
	m_isOn = false;
	m_selectedChannel = FIRST_CHANNEL;
	m_previousChannel = FIRST_CHANNEL;
	for (int i = FIRST_CHANNEL; i <= END_CHANNEL; i++)
	{
		m_channelInfo.push_back(make_pair(i, ""));
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
		if (currChannel.first == channel)
		{
			return currChannel.second;
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
		if (currChannel.second == name)
		{
			return currChannel.first;
		}
	}
	return 0;
}

vector<pair<int, string>> CTVSet::GetChannelList()const
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
	if (CTVSet::GetChannelByName(name) != 0)
	{
		CTVSet::DeleteChannelName(name);
	}
	for (auto currChannel= m_channelInfo.begin(); currChannel != m_channelInfo.end(); currChannel++)
	{
		if (currChannel->first == channel)
		{
			currChannel->second = name;
			return true;
		}
	}
	return false;
}


bool CTVSet::DeleteChannelName(string const& name)
{
	if ((name == "") || !m_isOn)
	{
		return false;
	}
	for (auto currChannel = m_channelInfo.begin(); currChannel != m_channelInfo.end(); currChannel++)
	{
		if (currChannel->second == name)
		{
			currChannel->second = "";
			return true;
		}
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

	for (auto currChannel = m_channelInfo.begin(); currChannel != m_channelInfo.end(); currChannel++)
	{
		if (currChannel->second == name)
		{
			m_previousChannel = m_selectedChannel;
			m_selectedChannel = currChannel->first;
			return true;
		}
	}
		
	return false;
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



