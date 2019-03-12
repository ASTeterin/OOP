// HtmlEncode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include "HtmlEncode.h"

using namespace std;

const vector<pair<char, string>> HTML_ESSENCE = {
	{'"', "&quot;"}, 
	{'\'', "&apos;"},
	{ '<', "&lt;" },
	{ '>', "&gt;" },
	{ '&', "&amp;" }

};

string GetHtmlCode(char ch)
{
	for (pair<char, string> element : HTML_ESSENCE)
	{
		if (element.first == ch)
		{
			return element.second;
		}
	}
	return "";
}



string HtmlEncode(string const& encodingString)
{
	
	char ch;
	string processedLine;

	if (encodingString.empty())
	{
		return "";
	}

	istringstream sourceString(encodingString);
	while (sourceString.get(ch))
	{
		string htmlCode = GetHtmlCode(ch);
		if (htmlCode.empty())
		{
			processedLine += ch;	
		}
		else
		{
			processedLine.append(htmlCode);
		}
	}
	return processedLine;
}

/*int main()
{
	cout << "1";
}*/

