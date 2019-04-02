
#include "pch.h"
#include "CTVSet.h"

CTVSet::CTVSet()
{
	m_isOn = false;
	m_selectedChannel = 1;
	m_previousChannel = 1;
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


bool CTVSet::SelectChannel(int channel)
{
	bool isAvailableChannel = (channel >= 1) && (channel <= 99);
	if (isAvailableChannel && m_isOn)
	{
		m_previousChannel = m_selectedChannel;
		m_selectedChannel = channel;
		return true;
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

