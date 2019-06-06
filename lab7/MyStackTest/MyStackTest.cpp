// MyStackTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "MyStack/MyStack.h"
#include <iostream>

SCENARIO("Stack of integer")
{
	GIVEN("new stack")
	{
		CMyStack<int> stack;
		WHEN("The top of the stack points to nullptr")
		{
			CHECK(stack.IsEmpty());
		}
		WHEN("push new element")
		{
			stack.Push(10);
			THEN("")
			{
				CHECK_FALSE(stack.IsEmpty());
				CHECK(stack.GetTop() == 10);
			}
		}
	}
}