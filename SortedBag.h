#ifndef SORTED_BAG_H
#define SORTED_BAG_H

#include <exception>
#include "Bag.h"
#include "Indexed.h"

using namespace std;
template <typename T>
class SortedBag : public Bag<T>
{
private:
	Indexed<T> *_container;

private:

	int binarySearch(T& value)
	{
		int low = 0;
		int mid = 0;
		int high = _container->getSize();
		while (low < high)
		{
			mid = (low + high) / 2;
			if (_container->getElementAt(mid) < value)
			{
				low = mid + 1;
			}
			else
			{
				high = mid;
			}
		}
		return low;
	}

public:
	SortedBag(Indexed<T> *container)
	{
		_container = container;
	}

	~SortedBag()
	{
		delete _container;
	}

#pragma region Collection overrides
	virtual bool isEmpty() const
	{
		return _container->isEmpty();
	}
	virtual int getSize() const
	{
		return _container->getSize();
	}
#pragma endregion

#pragma region Bag overrides
	
	//For Vector, we'll make this work just like push()
	virtual void addElement(T item)
	{
		int insertLocation = binarySearch(item);
		_container->addElementAt(item, insertLocation);
	}

#pragma endregion


	virtual T &getElementAt(int index)
	{
		return _container->getElementAt(index);
	}

};

#endif