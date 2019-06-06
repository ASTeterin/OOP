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
	/*~CMyStack()
	{
		Clear();
	}*/

	void Push(T const& data)
	{
		try
		{
			Node* newNode = new Node;
			newNode->data = data;
			newNode->next = m_pTop;
			m_pTop = newNode;
		}
		catch (...)
		{
			throw;
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
			m_pTop = m_pTop->next;
		}
		else
		{
			throw std::logic_error("Stack is empty");
		}
	}

	void Clear()
	{
		if (!IsEmpty())
		{
			while (m_pTop)
			{
				Node* currNode = m_pTop;
				m_pTop = currNode->next;
				delete currNode;
			}
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