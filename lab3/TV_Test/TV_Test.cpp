#pragma once
#include "pch.h"
#include "TV/CTVSet.h"
//#include <optional>
//#include "boost/optional.hpp"



using namespace std;

void ExpectOperationSuccess(CTVSet& tv, function<bool(CTVSet&tv)> const& op, boost::optional<int> const& expectedChannel)
{
	
	CHECK(op(tv)); // убедились, что операция завершится успешно
	// сравниваем включенность и канал с ожидаемыми значениями
	CHECK(tv.IsTurnedOn() == expectedChannel.has_value());
	CHECK(tv.GetChannel() == expectedChannel.value_or(0));
}

void ExpectOperationFailure(const CTVSet& tv, const function<bool(CTVSet&tv)>& op)
{
	CTVSet tvCopy(tv); // копия телевизора, над которой будет выполняться операция
	CHECK(!op(tvCopy)); // убедились, что операция (над копией) завершится неуспешно
	// сравниваем включенность и канал с прежними значениями
	CHECK(tvCopy.IsTurnedOn() == tv.IsTurnedOn());
	CHECK(tvCopy.GetChannel() == tv.GetChannel());
}

TEST_CASE("TV can select channels from 1 to 99 only when it is on")
{
	CTVSet tv;
	tv.TurnOn();

	ExpectOperationSuccess(tv, [](CTVSet& tv) { return tv.SelectChannel(99); }, 99);
	ExpectOperationFailure(tv, [](CTVSet& tv) { return tv.SelectChannel(100); });
	
}


SCENARIO("TV can be turned on and off")
{
	GIVEN("A turned off TV")
	{
		CTVSet tv;
		WHEN("tv is turn on first time")
		{
			tv.TurnOn();
			THEN("it becomes turned on. When it turned on, 1 channel is set")
			{
				CHECK(tv.IsTurnedOn());
				CHECK(tv.GetChannel() == 1);
			}
		}
		AND_WHEN("TV is turn on. ")
		{
			tv.TurnOn();
			tv.SelectChannel(1);
			tv.SelectChannel(5);
			tv.TurnOff();
			tv.TurnOn();
			THEN("it becomes turned on. Stay of current and previous channels was save")
			{
				CHECK(tv.IsTurnedOn());
				CHECK(tv.GetChannel() == 5);
				ExpectOperationSuccess(tv, [](CTVSet& tv) { return tv.SelectPreviousChannel(); }, 1);
			}
		}
		AND_WHEN("tv is turned off")
		{
			tv.TurnOff();
			THEN("it becomes turned off and current channel number is 0.")
			{
				CHECK(!tv.IsTurnedOn());
				CHECK(tv.GetChannel() == 0);
			}
		}
	}
}

SCENARIO("Switching channels on the TV")
{
	GIVEN("A turned on TV")
	{
		CTVSet tv;
		WHEN("TV is turned on")
		{
			tv.TurnOn();
			THEN("it is possible to switch channels in the range from 1 to 99")
			{
				ExpectOperationSuccess(tv, [](CTVSet& tv) { return tv.SelectChannel(99); }, 99);
				ExpectOperationSuccess(tv, [](CTVSet& tv) { return tv.SelectChannel(1); }, 1);
				ExpectOperationSuccess(tv, [](CTVSet& tv) { return tv.SelectChannel(50); }, 50);
				ExpectOperationFailure(tv, [](CTVSet& tv) { return tv.SelectChannel(100); });
				ExpectOperationFailure(tv, [](CTVSet& tv) { return tv.SelectChannel(0); });
			}
			AND_THEN("it is possible to switch channels by name if the name was set")
			{
				tv.SetChannelName(1, "ORT");
				ExpectOperationSuccess(tv, [](CTVSet& tv) { return tv.SelectChannel("ORT"); }, 1);
				ExpectOperationFailure(tv, [](CTVSet& tv) { return tv.SelectChannel("NTV"); });
			}
		}
		AND_WHEN("TV is turned off")
		{
			tv.TurnOff();
			THEN("TV state does not change")
			{
				ExpectOperationFailure(tv, [](CTVSet& tv) { return tv.SelectChannel(50); });
			}
		}
	}
}

SCENARIO("Naming a channel")
{
	GIVEN("A turned of TV")
	{
		CTVSet tv;
		WHEN("TV is turned on")
		{
			tv.TurnOn();
			THEN("it is possible to give the channel in the range from 1 to 99 a name")
			{
				ExpectOperationSuccess(tv, [](CTVSet& tv) { return tv.SetChannelName(1, "ORT"); }, 1);
				CHECK(tv.GetChannelName(1) == "ORT");
				CHECK(tv.GetChannelByName("ORT") == 1);
			}
			AND_THEN("for a channel outside the range, this does not change the state of TV")
			{
				ExpectOperationFailure(tv, [](CTVSet& tv) {return tv.SetChannelName(0, "ORT"); });
				ExpectOperationFailure(tv, [](CTVSet& tv) {return tv.SetChannelName(100, "ORT"); });
			}
			AND_THEN("if you re-assign a name to another channel, the existing name is overwritten")
			{
				ExpectOperationSuccess(tv, [](CTVSet& tv) { return tv.SetChannelName(1, "ORT"); }, 1);
				CHECK(tv.GetChannelName(1) == "ORT");
				ExpectOperationSuccess(tv, [](CTVSet& tv) { return tv.SetChannelName(5, "ORT"); }, 1);
				CHECK(tv.GetChannelName(1) == "");
				CHECK(tv.GetChannelName(5) == "ORT");
			}
		}
		AND_WHEN("TV is turned off")
		{
			tv.TurnOff();
			THEN("TV state does not change")
			{
				ExpectOperationFailure(tv, [](CTVSet& tv) {return tv.SetChannelName(1, "ORT"); });
			}
		}
	}
}

SCENARIO("switch to previous channel")
{
	GIVEN("A turned of TV")
	{
		CTVSet tv;
		WHEN("TV is turned on")
		{
			tv.TurnOn();
			THEN("it is possible to switch to the previous channel")
			{
				ExpectOperationSuccess(tv, [](CTVSet& tv) { return tv.SelectChannel(10); }, 10);
				ExpectOperationSuccess(tv, [](CTVSet& tv) { return tv.SelectChannel(20); }, 20);
				ExpectOperationSuccess(tv, [](CTVSet& tv) { return tv.SelectPreviousChannel(); }, 10);
			}
		}
		AND_WHEN("TV is turned off")
		{
			tv.TurnOff();
			THEN("TV state does not change")
			{
				ExpectOperationFailure(tv, [](CTVSet& tv) {return tv.SelectPreviousChannel(); });
			}
		}
	}
}

SCENARIO("deleting channel")
{
	GIVEN("A turned of TV")
	{
		CTVSet tv;
		WHEN("TV is turned on")
		{
			tv.TurnOn();
			THEN("if the channel is named, you can delete the name")
			{
				tv.SetChannelName(1, "ORT");
				CHECK(tv.GetChannel() == 1);
				tv.DeleteChannelName("ORT");
				CHECK(tv.GetChannelName(1) == "");
			}
			AND_THEN("if the channel name is not assigned the status will not change")
			{
				ExpectOperationFailure(tv, [](CTVSet& tv) {return tv.DeleteChannelName("TNT"); });
			}
		}
		AND_WHEN("TV is turned off")
		{
			tv.TurnOff();
			THEN("TV state does not change")
			{
				ExpectOperationFailure(tv, [](CTVSet& tv) {return tv.DeleteChannelName("TNT"); });
			}
		}
	}
}



