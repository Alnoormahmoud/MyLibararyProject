#pragma once

#include <iostream>
#include "clsDynamicArray.h"

using namespace std;

template <class T>

class clsMyQueueArr
{

protected:

	clsDynamicArray <T> _DynamicArray;

public:

	void Push(T Item)
	{
		_DynamicArray.InsertAtEnd(Item);
	}

	void Pop()
	{
		_DynamicArray.DeleteFirstItem();
	}

	void Print()
	{
		_DynamicArray.PrintList();
	}

	int Size()
	{
		return _DynamicArray.Size();
	}

	int IsEmpty()
	{
		return _DynamicArray.IsEmpty();
	}

	T Front()
	{
		return _DynamicArray.GetItem(0);
	}

	T Back()
	{
		return _DynamicArray.GetItem(Size() - 1);
	}

	T GetItem(int Index)
	{
		return _DynamicArray.GetItem(Index);
	}

	void Reverse()
	{
		_DynamicArray.Reverse();
	}

	void UpdateItem(int Index, T Num)
	{
		_DynamicArray.SetItem(Index, Num);
	}

	void InsertBefore(T Num)
	{
		_DynamicArray.InsertAtBeginning(Num);
	}

	void InsertAfter(int Index, T Num)
	{
		_DynamicArray.InsertAfter(Index, Num);
	}

	void InsertAtFront(T Value)
	{
		_DynamicArray.InsertAtBeginning(Value);
	}

	void InsertAtEnd(T Value)
	{
		_DynamicArray.InsertAtEnd(Value);
	}

	void Clear()
	{
		_DynamicArray.Clear();
	}

};

