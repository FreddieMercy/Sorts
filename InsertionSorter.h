#ifndef INSERTION_SORTER_H
#define INSERTION_SORTER_H

#include "IndexedSorter.h"

template <typename T>
class InsertionSorter : public IndexedSorter<T>
{
	//Insertion Sort taken from Wikipedia: http://en.wikipedia.org/wiki/Insertion_sort
	//See site for a nice visualization of the process
	virtual Indexed<T>& sort(Indexed<T>& data)
	{
		for (int i = 0; i < data.getSize(); i++)
		{
			int j = i;
			while (j > 0
				&& data.getElementAt(j - 1) > data.getElementAt(j)
				)
			{
				T current = data.getElementAt(j);
				T prev = data.getElementAt(j - 1);
				data.setElementAt(prev, j);
				data.setElementAt(current, j - 1);
				j--;
			}
		}
		return data;
	}
};

#endif