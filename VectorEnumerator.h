#ifndef VECTOR_ENUMERATOR_H
#define VECTOR_ENUMERATOR_H

#include "Enumerator.h"
#include "Vector.h"

template <typename T>
class VectorEnumerator : public Enumerator<T>
{
private:
	Vector<T>& _target;
	int _location_counter;
public:

	VectorEnumerator(Vector<T>& target)
	{
		_target = target;
	}

	virtual T *getNextValue()
	{
		if (_location_counter < _target.getSize())
		{
			_location_counter++;
			return _target.getElementAt(_location_counter);
		}
		return nullptr;
	}

	virtual T *getValue()
	{
		if (_location_counter < _target.getSize())
		{
			return _target.getElementAt(_location_counter);
		}
		return nullptr;
	}
};

#endif