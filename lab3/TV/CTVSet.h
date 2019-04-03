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
	bool SelectChannel(string name);
	bool SelectPreviousChannel();
	bool SetChannelName(int channel, string name);
	string GetChannelName(int channel)const;
	int GetChannelByName(string name)const;
	bool DeleteChannelName(string name);
	bool IsValidChannel(int channel);

private:

	
	bool m_isOn;
	int m_selectedChannel;
	int m_previousChannel;
	vector<channelInfo> m_channelInfo;
};

