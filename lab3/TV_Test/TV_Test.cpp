#include "pch.h"
#include "TV/CTVSET.h"

using namespace std;

TEST_CASE("Testing begin state of TV")
{
	CTVSet tv;
	CHECK(tv.IsTurnedOn() == false);
	CHECK(tv.GetChannel() == 0);
	CHECK(tv.SelectChannel(1) == false);
	CHECK(tv.SelectPreviousChannel() == false);
}

TEST_CASE("Testing channel switching")
{
	CTVSet tv;
	tv.TurnOn();

	CHECK(tv.IsTurnedOn() == true);
	CHECK(tv.GetChannel() == 1);
	//CHECK(tv.GetChannel() == 1);
	
	CHECK(tv.SelectChannel(0) == false);
	CHECK(tv.SelectChannel(101) == false);
	CHECK(tv.SelectChannel(50) == true);
	CHECK(tv.GetChannel() == 50);

	tv.SelectChannel(2);
	CHECK(tv.SelectPreviousChannel() == true);
	CHECK(tv.GetChannel() == 50);
}

TEST_CASE("Testing turning off the TV")
{
	CTVSet tv;
	CHECK(tv.GetChannelName(1) == "");

	tv.TurnOn();
	
	//tv.SetChannelName(1, "ORT");
	//CHECK(tv.GetChannelName(1) == "ORT");

}



