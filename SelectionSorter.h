#ifndef SELECTION_SORTER_H
#define SELECTION_SORTER_H

#include "IndexedSorter.h"

template <typename T>
class SelectionSorter : public IndexedSorter<T>
{
	//see http://en.wikipedia.org/wiki/Selection_sort for a 
	//Selection Sort implementation
	virtual Indexed<T>& sort(Indexed<T>& data)
	{
		int min_index = 0;
		int data_size = data.getSize();

		//we do data_size - 1 because we're assigning i = j + 1
		for (int j = 0; j < data_size - 1; j++)
		{
			min_index = j;
			for (int i = j + 1; i < data_size; i++)
			{
				//did we find something smaller?
				if (data.getElementAt(i) < data.getElementAt(min_index))
				{
					min_index = i;
				}
			}

			//Do we need to make the swap?
			//is the IF statement worth it? (Answer: yes!)
			if (min_index != j) 
			{
				T at_j = data.getElementAt(j);
				T at_min = data.getElementAt(min_index);
				data.setElementAt(at_j, min_index);
				data.setElementAt(at_min, j);
			}
		}
		return data;
	}
};

#endif