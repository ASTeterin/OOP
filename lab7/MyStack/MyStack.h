#pragma once

template <typename T>
class CMyStack
{

	struct Node
	{
		T data;
		Node* next;
	};

private:
public:
	CMyStack() = default;

	~CMyStack()
	{
		Clear();
	}

	CMyStack(CMyStack const& other)
		: CMyStack()
	{
		try
		{
			Node* srcCurrentNode = other.m_pTop;
			Node* dstCurrentNode = this->m_pTop;
			while (srcCurrentNode)
			{
				Node* newNode = new Node;
				newNode->data = srcCurrentNode->data;
				newNode->next = nullptr;

				if (!this->m_pTop)
				{
					this->m_pTop = newNode;
				}
				else
				{
					dstCurrentNode->next = newNode;
				}
				
				dstCurrentNode = newNode;
				srcCurrentNode = srcCurrentNode->next;
			}
		}
		catch (...)
		{
			Clear();
			throw;
		}
	}

	CMyStack(CMyStack&& other)
		: CMyStack()
	{
		std::swap(this->m_pTop, other.m_pTop);
	}

	CMyStack<T> operator=(CMyStack const& other)
	{
		if (!this == &other)
		{
			if (m_pTop)
			{
				Clear();
			}
			*this = CMyStack(other);
		}
		return *this;
	}

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
			Node* tmp = m_pTop;
			try
			{
				m_pTop = m_pTop->next;
			}
			catch (...)
			{
				delete tmp;
			}
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
	}

	T GetTop() const
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