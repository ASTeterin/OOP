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
			//this->Push(other.GetTop());
			Node* srcCurrentNode = other.m_pTop;
			Node* dstCurrentNode = this->m_pTop;
		
			while (srcCurrentNode)
			{
				Node* tmp = new Node;
				tmp->data = srcCurrentNode->data;
				srcCurrentNode = srcCurrentNode->next;
				dstCurrentNode = tmp;
		
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
		swap(this->m_pTop, other.m_pTop);
	}

	/*CMyStack<T> &CMyStack<T>::operator=(const CMyStack other)
	{


		this->Clear();
		try
		{
			CMyStack tempStack;
			Node* currentNode = other.m_pTop;
			while (currentNode->next)
			{
				tempStack.Push(currentNode->data);
				currentNode = currentNode->next;
			}
			while (!tempStack.IsEmpty())
			{
				Push(tempStack.GetTop());
				tempStack.Pop();
			}
		}
		catch (...)
		{
			Clear();
			throw;
		}


	}
	*/
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