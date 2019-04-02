#pragma once

using namespace std;

typedef pair <int, string> channelInfo;

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
	bool SelectPreviousChannel();
	//bool SetChannelName(int channel, string name);
	string GetChannelName(int channel)const;
private:

	
	bool m_isOn;
	int m_selectedChannel;
	int m_previousChannel;
	vector<channelInfo> m_channelInfo;
};

