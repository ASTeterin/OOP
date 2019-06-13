#pragma once

template <typename T>
class CMyStack
{

	struct Node
	{
		Node(T data, Node* next)
			: data(std::move(data))
			, next(next)
		{
		}
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
				Node* newNode = new Node(srcCurrentNode->data, nullptr);
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

	CMyStack<T>& operator=(CMyStack const& other)
	{
		if (this != &other)
		{
			CMyStack tmp = CMyStack(other);
			std::swap(tmp.m_pTop, m_pTop);
		}
		return *this;
	}

	CMyStack<T>& operator=(CMyStack&& other)
	{
		if (this != &other)
		{
			Clear();
			this = &other;
		}
		return *this;
	}

	void Push(T const& data)
	{
		Node* newNode = new Node(data, m_pTop);
		m_pTop = newNode;	
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
			m_pTop = m_pTop->next;
			delete tmp;
		}
		else
		{
			throw std::logic_error("Stack is empty");
		}
	}

	void Clear()
	{
		while (m_pTop)
		{
			Node* currNode = m_pTop;
			m_pTop = currNode->next;
			delete currNode;
		}
	}

	const T& GetTop() const
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