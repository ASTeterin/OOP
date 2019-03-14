#include "pch.h"
#include "HtmlEncode.h"


using namespace std;

void ProcessHtmlDocument(istream &input, ostream &output)
{
	string str;
	string encodeString;
	while (getline(input, str))
	{
		output << HtmlEncode(str) << '\n';
	}
}

int main()
{
	ProcessHtmlDocument(cin, cout);
	return 0;
}