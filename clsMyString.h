#pragma once

#include <iostream>
#include <Stack>


using namespace std;

class clsMyString
{
	string _Value ;
	stack <string>_Undo;
	stack <string>_Redo;

public:

	void SetValue(string Value)
	{
		_Undo.push(_Value);
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	void Undo()
	{
		if (!_Undo.empty())
		{
			_Redo.push(_Value);
			_Value = _Undo.top();
			_Undo.pop();
		}
	}

	void ReDo()
	{
		if (!_Redo.empty())
		{
			_Undo.push(_Value);
			_Value = _Redo.top();
			_Redo.pop();
		}
 	}

};

