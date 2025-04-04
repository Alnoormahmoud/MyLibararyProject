#pragma once

#include <iostream>
#include "clsMyQueueArr.h"
using namespace std; 

template <class T>

class claMyStackArr :public clsMyQueueArr<T>
{

public:

	void Push(T Item)
	{
		clsMyQueueArr <T>::InsertAtFront(Item);
	}

	T Top()
	{
		return clsMyQueueArr <T>::Front();

	}

	T Bottom()
	{
		return clsMyQueueArr <T>::Back();

	}
};

