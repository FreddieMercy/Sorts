#ifndef BUBBLE_SORTER_H
#define BUBBLE_SORTER_H

#include "IndexedSorter.h"

template <typename T>
class BubbleSorter : public IndexedSorter<T>
{
	virtual Indexed<T>& sort(Indexed<T>& data)
	{
		int data_size = data.getSize();
		bool swapped = false;
		while (false == swapped)
		{
			swapped = true;

			for (int i = 0; i < data_size - 1; i++)
			{

				//is the current item greater than the
				//next adjacent item
				if (data.getElementAt(i) > 
					data.getElementAt(i + 1))
				{
					//..if so, swap the values
					T first = data.getElementAt(i);
					T second = data.getElementAt(i + 1);
					data.setElementAt(first, i + 1);
					data.setElementAt(second, i);
					swapped = false;
				}
			}
			data_size--;
		}
		return data;
	}
};

#endif