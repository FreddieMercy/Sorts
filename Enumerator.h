#ifndef ENUMERATOR_H
#define ENUMERATOR_H

template <typename T>
class Enumerator
{
public:
	virtual void next() = 0;
	virtual T* getValue() = 0;
	virtual bool isFinished() const = 0;
};

#endif