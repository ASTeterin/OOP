#include "pch.h"
#include "TV/CTVSET.h"
//#include <optional>
#include "boost/optional.hpp"



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

TEST_CASE("Testing begin state of TV")
{
	CTVSet tv;
	CHECK(tv.IsTurnedOn() == false);
	CHECK(tv.GetChannel() == 0);
	CHECK(tv.SelectChannel(1) == false);
	CHECK(tv.SelectPreviousChannel() == false);
}


SCENARIO("TV can be turned on and off")
{
	GIVEN("A turned on TV")
	{
		CTVSet tv;
		WHEN("tv is turn on")
		{
			tv.TurnOn();
			THEN("it becomes turned on. When it turned on, 1 channel is set")
			{
				CHECK(tv.IsTurnedOn());
				CHECK(tv.GetChannel() == 1);
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

SCENARIO("Switching channels on the TV by channel number")
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







TEST_CASE("Testing channel switching")
{
	CTVSet tv;
	tv.TurnOn();

	CHECK(tv.IsTurnedOn() == true);
	CHECK(tv.GetChannel() == 1);
	
	CHECK(tv.SelectChannel(0) == false);
	CHECK(tv.SelectChannel(101) == false);
	CHECK(tv.SelectChannel(50) == true);
	CHECK(tv.GetChannel() == 50);

	tv.SelectChannel(2);
	CHECK(tv.SelectPreviousChannel() == true);
	CHECK(tv.GetChannel() == 50);
}

TEST_CASE("Testing the ability to set a name for the channel")
{
	CTVSet tv;
	CHECK(tv.GetChannelName(1) == "");
	CHECK(tv.GetChannelByName("ORT") == 0);
	CHECK(tv.SetChannelName(1, "ORT") == false);
	CHECK(tv.DeleteChannelName("ORT") == false);

	tv.TurnOn();
	
	tv.SetChannelName(1, "ORT");
	CHECK(tv.GetChannelName(1) == "ORT");
	CHECK(tv.GetChannelByName("ORT") == 1);

	tv.SelectChannel("ORT");
	CHECK(tv.GetChannel() == 1);

	tv.DeleteChannelName("ORT");
	CHECK(tv.GetChannelName(1) == "");

	tv.SetChannelName(1, "ORT");
	tv.SetChannelName(2, "ORT");
	CHECK(tv.GetChannelName(1) == "");
	CHECK(tv.GetChannelName(2) == "ORT");

	

}



