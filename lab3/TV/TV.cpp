// TV.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "CTVSet.h"
#include "RemoteControl.h"


using namespace std;




string GetCommand(istream &input)
{
	string command;
	input >> command;
	return command;
}



int main()
{
	CTVSet tv;
	CRemoteControl remoteControl(tv, cin, cout);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!remoteControl.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}
	return 0;
}


