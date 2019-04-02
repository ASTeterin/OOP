#pragma once
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
private:
	bool m_isOn;
	int m_selectedChannel;
	int m_previousChannel;
};

