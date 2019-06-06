#pragma once

template <typename T>
class CMyStack
{

	struct Node
	{
		T data;
		Node* next;
	};

public:
	CMyStack() = default;

	void Push(T const& data)
	{
		try 
		{
			Node* newNode = new Node;
			newNode.data = data;
			newNode.next = nullptr;
			m_pTop.next = newNode;
			m_pTop = newNode;
		}
		catch (std::bad_alloc const& e)
		{
			throw std::bad_alloc("Out of memory");
		}	
	}

	bool IsEmpty() const
	{
		return !m_pTop;
	}

	void Pop()
	{
		if (!IsEmpty())
		{
			m_pTop = m_pTop.next;	
		}
		else
		{
			throw std::logic_error("Stack is empty");
		}	
	}

	T GetTop()
	{
		if (!IsEmpty())
		{
			return m_pTop.data;
		}
		else
		{
			throw std::logic_error("Stack is empty");
		}		
	}

	

private:
	T* m_pTop = nullptr;
};