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

		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		newNode->next = m_pTop;
		m_pTop = newNode;
		//throw std::bad_alloc("Out of memory");
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
			return m_pTop->data;
		}
		else
		{
			throw std::logic_error("Stack is empty");
		}		
	}

	

private:
	Node* m_pTop = nullptr;
};