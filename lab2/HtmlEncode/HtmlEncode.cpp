// HtmlEncode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include "HtmlEncode.h"

using namespace std;

const vector<pair<char, string>> HTML_ENTITIES = {
	{'"', "&quot;"}, 
	{'\'', "&apos;"},
	{ '<', "&lt;" },
	{ '>', "&gt;" },
	{ '&', "&amp;" }

};

string HtmlEncodeChar(const char ch)
{
	for (pair<char, string> element : HTML_ENTITIES)
	{
		if (element.first == ch)
		{
			return element.second;
		}
	}
	string str;
	return (str + ch);
}



string HtmlEncode(string const& encodingString)
{
	string processedLine;
	for (auto ch : encodingString)
	{
		string htmlCode = HtmlEncodeChar(ch);
		processedLine.append(htmlCode);
	}
	return processedLine;
}



