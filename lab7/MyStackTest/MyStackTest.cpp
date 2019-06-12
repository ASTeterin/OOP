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
		WHEN("usinging the copy constructor")
		{
			stack.Push(10);
			stack.Push(11);
			stack.Push(12);
			CMyStack<int> other(stack);
			THEN("the elements of the stacks are equal")
			{
				while (!(stack.IsEmpty()) and !(other.IsEmpty()))
				{
					CHECK(stack.GetTop() == other.GetTop());
					stack.Pop();
					other.Pop();
				}
			}
		}
		WHEN("using operator =")
		{
			stack.Push(10);
			stack.Push(11);
			stack.Push(12);
			CMyStack<int> other = stack;
			THEN("the elements of the stacks are equal")
			{
				while (!(stack.IsEmpty()) and !(other.IsEmpty()))
				{
					CHECK(stack.GetTop() == other.GetTop());
					stack.Pop();
					other.Pop();
				}
			}
			
		}

		WHEN("push new element")
		{
			stack.Push(10);
			THEN("Stack is not empty, at the top of the stack is an element")
			{
				CHECK_FALSE(stack.IsEmpty());
				CHECK(stack.GetTop() == 10);
			}
		}
		WHEN("pop element")
		{
			THEN("stack is empty")
			{
				CHECK_THROWS_WITH(stack.Pop(), "Stack is empty");
			}
			AND_THEN("stack is not empty")
			{
				stack.Push(10);
				stack.Push(11);
				stack.Pop();
				THEN("the top of the stack will point to the previous element")
				{
					CHECK(stack.GetTop() == 10);
				}
			}
		}
		WHEN("Clear stack")
		{
			THEN("stack is empty")
			{
				CHECK_THROWS_WITH(stack.Pop(), "Stack is empty");
			}
			AND_THEN("stack is not empty")
			{
				stack.Push(10);
				stack.Push(11);
				stack.Clear();
				THEN("Stack will be empty")
				{
					CHECK(stack.IsEmpty());
				}
			}
		}
	}
}