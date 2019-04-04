#pragma once

using namespace std;

typedef pair <int, string> channelInfo;

const int FIRST_CHANNEL = 1;
const int END_CHANNEL = 99;

class CTVSet
{
public:
	CTVSet();
	~CTVSet();
	bool IsTurnedOn()const;
	void TurnOn();
	void TurnOff();
	int GetChannel()const;
	bool SelectChannel(int channel);
	bool SelectChannel(string const& name);
	bool SelectPreviousChannel();
	bool SetChannelName(int channel, string const& name);
	string GetChannelName(int channel)const;
	int GetChannelByName(string const& name)const;
	bool DeleteChannelName(string const& name);
	vector<pair<int, string>> GetChannelList()const;

private:
	bool m_isOn;
	int m_selectedChannel;
	int m_previousChannel;
	vector<channelInfo> m_channelInfo;
};

