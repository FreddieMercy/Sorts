#ifndef DOUBLE_LINK_NODE
#define DOUBLE_LINK_NODE

#include "ListNode.h"

template <typename T>
class DoubleLinkNode : public ListNode<T>
{
protected:

	ListNode<T> *_previous;

public:
	DoubleLinkNode()
	{
		_previous = nullptr;
	}


	//DoubleLinkNode(const ListNode<T> &other)
	//{
	//	_previous = other.getPrevious();
	//}

	ListNode<T> *getPrevious()
	{
		return _previous;
	}

	void setPrevious(ListNode<T> *p_vios)
	{
		_previous = p_vios;
	}

};
#endif