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
		AND_WHEN("test constructor and operator =")
		{
			stack.Push(10);
			stack.Push(11);
			stack.Push(12);
			WHEN("usinging the copy constructor")
			{
				CMyStack<int> other(stack);
				THEN("the elements of the stacks are equal")
				{
					while (!(stack.IsEmpty()))
					{
						CHECK(stack.GetTop() == other.GetTop());
						stack.Pop();
						other.Pop();
					}
				}

			}
		
		
			WHEN("using operator =")
			{
				CMyStack<int> other;
				
				other = stack;
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
			WHEN("usinging the moving constructor")
			{
				CMyStack<int> copyStack = stack;
				CMyStack<int> other(std::move(stack));
				THEN("the elements of the stacks are equal and ")
				{
					while (!(copyStack.IsEmpty()) and !(other.IsEmpty()))
					{
						CHECK(copyStack.GetTop() == other.GetTop());
						copyStack.Pop();
						other.Pop();
					}
					CHECK(stack.IsEmpty());
				}
			}
			WHEN("usinging the moving operator =")
			{
				CMyStack<int> copyStack;
				copyStack = stack;
				CMyStack<int> other = std::move(stack);
				while (!(copyStack.IsEmpty()) and !(other.IsEmpty()))
				{
					CHECK(copyStack.GetTop() == other.GetTop());
					copyStack.Pop();
					other.Pop();
				}
				CHECK(stack.IsEmpty());

			}

		}
		AND_WHEN("push new element")
		{
			stack.Push(10);
			THEN("Stack is not empty, at the top of the stack is an element")
			{
				CHECK_FALSE(stack.IsEmpty());
				CHECK(stack.GetTop() == 10);
			}
		}
		AND_WHEN("pop element")
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
		AND_WHEN("Clear stack")
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


SCENARIO("Stack of string")
{
	GIVEN("new stack")
	{
		CMyStack<std::string> stack;
		WHEN("The top of the stack points to nullptr")
		{
			CHECK(stack.IsEmpty());
		}
		WHEN("test constructor and operator =")
		{
			stack.Push("qwery");
			stack.Push("asdf");
			stack.Push("zxcv");
			WHEN("usinging the copy constructor")
			{
				CMyStack<std::string> other(stack);
				THEN("the elements of the stacks are equal")
				{
					while (!(stack.IsEmpty()))
					{
						CHECK(stack.GetTop() == other.GetTop());
						stack.Pop();
						other.Pop();
					}
				}
			}

			WHEN("using operator =")
			{
				CMyStack<std::string> other = stack;
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
			WHEN("usinging the moving constructor")
			{
				CMyStack<std::string> copyStack = stack;
				CMyStack<std::string> other(std::move(stack));
				THEN("the elements of the stacks are equal and ")
				{
					while (!(copyStack.IsEmpty()) and !(other.IsEmpty()))
					{
						CHECK(copyStack.GetTop() == other.GetTop());
						copyStack.Pop();
						other.Pop();
					}
					CHECK(stack.IsEmpty());
				}
			}
			WHEN("usinging the moving operator =")
			{
				CMyStack<std::string> copyStack = stack;
				CMyStack<std::string> other = std::move(stack);
				while (!(copyStack.IsEmpty()) and !(other.IsEmpty()))
				{
					CHECK(copyStack.GetTop() == other.GetTop());
					copyStack.Pop();
					other.Pop();
				}
				CHECK(stack.IsEmpty());
			}
		}
		WHEN("push new element")
		{
			stack.Push("Qwerty");
			THEN("Stack is not empty, at the top of the stack is an element")
			{
				CHECK_FALSE(stack.IsEmpty());
				CHECK(stack.GetTop() == "Qwerty");
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
				stack.Push("10");
				stack.Push("11");
				stack.Pop();
				THEN("the top of the stack will point to the previous element")
				{
					CHECK(stack.GetTop() == "10");
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
				stack.Push("10");
				stack.Push("11");
				stack.Clear();
				THEN("Stack will be empty")
				{
					CHECK(stack.IsEmpty());
				}
			}
		}
	}
}