#include "pch.h"
#include "TV/RemoteControl.h"
#include <catch2/catch.hpp>

SCENARIO("Remote control can turn on a TV", "[remote]")
{
	GIVEN("A remote control connected to the TV which is turned off")
	{
		CTVSet tv;
		stringstream input, output;
		CRemoteControl rc(tv, input, output);

		REQUIRE(!tv.IsTurnedOn());

		WHEN("user enters TurnOn command")
		{
			input << "TurnOn";
			CHECK(rc.HandleCommand());
			THEN("tv switches on")
			{
				CHECK(tv.IsTurnedOn());
				AND_THEN("user gets notification")
				{
					CHECK(output.str() == "TV is turned on\n");
				}
			}
		}
	}
}

SCENARIO("remote control of channel switching")
{
	CTVSet tv;
	stringstream input;
	ostringstream output;
	CRemoteControl rc(tv, input, output);
	GIVEN("TV is turned Off")
	{
		WHEN("the SelectChannel is specified")
		{
			REQUIRE(!tv.IsTurnedOn());
			input << "SelectChannel 2";
			THEN("TV status does not change")
			{
				CHECK(!rc.HandleCommand());
				CHECK(output.str() == "TV is turned off\n");
			}
		}
	}
	GIVEN("TV is Turn On")
	{
		tv.TurnOn();
		REQUIRE(tv.IsTurnedOn());
			
		WHEN("user enter SelectChannel command")
		{
			input << "SelectChannel 2";
			CHECK(rc.HandleCommand());
			THEN("TV switched to another channel")
			{
				CHECK(output.str() == "TV switched on 2 channel.\n");
			}
		}
		AND_WHEN("user enter SelectChannel by name")
		{
			REQUIRE(tv.SetChannelName(1, "ORT"));
			input << "SelectChannel ORT";
			CHECK(rc.HandleCommand());
			THEN("TV switched to another channel")
			{
				CHECK(output.str() == "TV switched on ORT channel.\n");
			}
		}
		
	}
}


SCENARIO("The remote control sets the name of the channel")
{
	CTVSet tv;
	stringstream input;
	ostringstream output;
	input << "SetChannelName 1, ORT";
	CRemoteControl rc(tv, input, output);
	GIVEN("A turned off TV")
	{
		REQUIRE(!tv.IsTurnedOn());
		WHEN("user enter Info command")
		{
			rc.HandleCommand();
			THEN("it is notified that TV is turned off")
			{
				CHECK(output.str() == "TV is turned off\n");
			}
		}
	}

	GIVEN("A turned on TV")
	{
		tv.TurnOn();
		REQUIRE(tv.IsTurnedOn());
		WHEN("user enter Info command")
		{
			CHECK(rc.HandleCommand());
			THEN("the channel name is saved for the channel")
			{
				CHECK(output.str() == "For channel 1 set up the name ORT\n");
			}
		}
	}
}

SCENARIO("The remote control deletes the channel name")
{
	CTVSet tv;
	stringstream input;
	ostringstream output;
	input << "DeleteChannelName ORT";
	CRemoteControl rc(tv, input, output);
	GIVEN("A turned off TV")
	{
		REQUIRE(!tv.IsTurnedOn());
		WHEN("user enter Info command")
		{
			rc.HandleCommand();
			THEN("it is notified that TV is turned off")
			{
				CHECK(output.str() == "TV is turned off\n");
			}
		}
	}

	GIVEN("A turned on TV")
	{
		tv.TurnOn();
		REQUIRE(tv.IsTurnedOn());
		
		WHEN("channel name exists")
		{
			REQUIRE(tv.SetChannelName(1, "ORT"));
			CHECK(tv.GetChannelByName("ORT") == 1);
			CHECK(rc.HandleCommand());
			THEN("TV reports that the channel is removed")
			{
				CHECK(output.str() == "Channel ORT was deleted\n");
			}
		}
		AND_WHEN("channel name not exists")
		{
			CHECK(!rc.HandleCommand());
			THEN("TV reports that removal is not possible")
			{
				CHECK(output.str() == "Error deleting channel\n");
			}
		}
	}
}

SCENARIO("Remote control provides information about TV", "[remote]")
{
	CTVSet tv;
	std::stringstream input;
	std::ostringstream output;
	input << "Info";
	CRemoteControl rc(tv, input, output);
	GIVEN("A turned off TV")
	{
		REQUIRE(!tv.IsTurnedOn());
		WHEN("user enter Info command")
		{
			rc.HandleCommand();
			THEN("it is notified that TV is off")
			{
				CHECK(output.str() == "TV is turned off\n");
			}
		}
	}
	GIVEN("A turned on TV")
	{
		tv.TurnOn();
		REQUIRE(tv.IsTurnedOn());
		WHEN("the user enters the command when channel names are not specified ")
		{
			tv.SelectChannel(10);
			CHECK(rc.HandleCommand());
			THEN("it is notified that TV is on the current channel")
			{
				CHECK(output.str() == "TV is turned on\nChannel is: 10\n");
			}
		}
		AND_WHEN("the user enters the command when some channel names are specified ")
		{
			REQUIRE(tv.SetChannelName(1, "ORT"));
			REQUIRE(tv.SetChannelName(2, "Russia"));
			CHECK(rc.HandleCommand());
			THEN("it is notified that TV is on the current channel")
			{
				CHECK(output.str() == "TV is turned on\nChannel is: 1\n1 - ORT\n2 - Russia\n");
			}
		}
	}
}

