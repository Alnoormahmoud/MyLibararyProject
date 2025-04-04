#pragma once

#include <iostream>

using namespace std;

template <class T>
class clsDynamicArray
{
	int _Size = 0;
	T * _TempArray;

public:
	 
	T* OriginalArray;

	clsDynamicArray()
	{ 
		OriginalArray = new T[_Size];
	}

	~clsDynamicArray()
	{
		delete[] OriginalArray;
	}

	bool SetItem(int Index, T Value)
	{
		if (Index >= _Size || _Size < 0)
		{
			return false;
		}

		OriginalArray[Index] = Value;
		return true;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0 ? true : false);
	}

	void ReSize(int NewSize)
	{
		if (NewSize < 0)
			NewSize = 0;
		
		_TempArray = new T[NewSize];

		if (_Size > NewSize)
			_Size = NewSize;
 
		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}
		_Size = NewSize;

		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	T GetItem(int Index)
	{
		return OriginalArray[Index];
	}

	void Reverse()
	{
		T* TempArray = new T[_Size];

		int Counter = 0;
		for (int i = _Size - 1; i >= 0; i--)
		{
			TempArray[Counter] = OriginalArray[i];

			Counter++;
		}

		delete[] OriginalArray;
		OriginalArray = TempArray;
	}

	void Clear()
	{
		_Size = 0;
		_TempArray = new T[0];
		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	bool DeleteItemAt(int index)
	{

		if (index >= _Size || index < 0)
		{
			return false;
		}

		_Size--;

		_TempArray = new T[_Size];

		//copy all before index
		for (int i = 0; i < index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		//copy all after index
		for (int i = index + 1; i < _Size + 1; i++)
		{
			_TempArray[i - 1] = OriginalArray[i];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;

	}

	bool DeleteFirstItem()
	{
		if (DeleteItemAt(0))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool DeleteLastItem()
	{
		if (DeleteItemAt(_Size-1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int Find(T Value)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == Value)
			{
				return i;
			}
		}
		return -1;
	}

	bool DeleteItem(T Value)
	{
		int Index = Find(Value);

		if (Index == -1)
		{
			return false;
		}

		DeleteItemAt(Index);
		return true;
	}
	
	bool InsertAt(int Index, T Value)
	{
		if (Index > _Size || Index < 0)
		{
			return false;
		}

		_Size++;

		_TempArray = new T[_Size];

		//copy all before index
		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}
		 
		_TempArray[Index] = Value;

		//copy all after index
		for (int i = Index ; i < _Size -1; i++)
		{
			_TempArray[i+1] = OriginalArray[i];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	void InsertAtBeginning(T Value)
	{
		InsertAt(0, Value);
	}	

	bool InsertBefore(int Index, T Value)
	{
		if (Index < 1)
			return InsertAt(0, Value);
		else
			return InsertAt(Index - 1, Value);
	}

	bool InsertAfter(int Index, T Value)
	{
		if (Index >= _Size)
			return InsertAt(_Size - 1, Value); 
		else
			return InsertAt(Index + 1, Value); 
	}

	void InsertAtEnd(T Value)
	{
		InsertAt(_Size , Value);
	}

	void PrintList()
	{
		for (int i = 0; i <= _Size - 1; i++)
		{
			cout << OriginalArray[i] << " ";
		}
		cout << endl;
	}

};

