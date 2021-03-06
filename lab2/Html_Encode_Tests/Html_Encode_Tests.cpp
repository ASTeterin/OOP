#include "pch.h"
#include "HtmlEncode/HtmlEncode.h"

using namespace std;

TEST_CASE("Program takes an empty string and return an empty string")
{
	string in;
	string out;
	CHECK(HtmlEncode(in) == out);
}

TEST_CASE("Program takes symbol \" and return &quot;")
{
	string in = "\"";
	string out = "&quot;";
	CHECK(HtmlEncode(in) == out);
}

TEST_CASE("Program takes symbol ' and return &apos;")
{
	string in = "'";
	string out = "&apos;";
	CHECK(HtmlEncode(in) == out);
}

TEST_CASE("Program takes symbol < and return &lt")
{
	string in = "<";
	string out = "&lt;";
	CHECK(HtmlEncode(in) == out);
}

TEST_CASE("Program takes symbol > and return &gt")
{
	string in = ">";
	string out = "&gt;";
	CHECK(HtmlEncode(in) == out);
}

TEST_CASE("Program takes symbol & and return &amp")
{
	string in = "&";
	string out = "&amp;";
	CHECK(HtmlEncode(in) == out);
}


TEST_CASE("Program takes string with all special and usual symbols and return encoding string")
{
	string in = "Cat <says> \"Meow\". M&M's";
	string out = "Cat &lt;says&gt; &quot;Meow&quot;. M&amp;M&apos;s";
	CHECK(HtmlEncode(in) == out);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
