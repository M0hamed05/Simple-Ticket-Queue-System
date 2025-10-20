#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDynamicArray
{
private:
	int _Size = 0;
	T* _TempArry;

public:
	T* OriginalArray;

	clsDynamicArray(int size = 0)
	{
		if (size < 0) size = 0;
		_Size = size;

		OriginalArray = new T[_Size];
	}

	~clsDynamicArray()
	{
		delete[] OriginalArray;
	}

	bool SetItem(int index, T value)
	{
		if (index >= _Size || _Size < 0) return false;

		OriginalArray[index] = value; return true;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0) ? true : false;
	}

	void PrintList()
	{
		for (int i = 0; i <= _Size - 1; i++)
		{
			cout << OriginalArray[i] << " ";
		}
	}

	void Resize(int newsize)
	{
		if (newsize == _Size) return;

		if (newsize < 0) newsize = 0;

		_TempArry = new T[newsize];

		if (newsize < _Size) _Size = newsize;

		for (int i = 0;i < _Size;i++)
		{
			_TempArry[i] = OriginalArray[i];
		}

		_Size = newsize;

		delete[]OriginalArray;
		OriginalArray = _TempArry;
	}

	void Reverse()
	{
		_TempArry = new T[_Size];

		for (int i = 0;i < _Size;i++)
		{
			_TempArry[i] = OriginalArray[_Size - i - 1];
		}
		delete[]OriginalArray;
		OriginalArray = _TempArry;
	}

	void Clear()
	{
		_Size = 0;
		_TempArry = new T[0];
		delete[]OriginalArray;
		OriginalArray = _TempArry;
	}

	T GetItem(int index)
	{
		return OriginalArray[index];
	}

	bool DeleteItemAt(int index)
	{
		if (index < 0 || index >= _Size) return false; 

		T* _TempArry = new T[_Size - 1];
		int j = 0;

		for (int i = 0; i < _Size; i++)
		{
			if (i == index) continue;
			_TempArry[j++] = OriginalArray[i];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArry;
		_Size--;

		return true;
	}
	
	void DeleteFirstItem()
	{
		DeleteItemAt(0);
	}

	void DeleteLastItem()
	{
		DeleteItemAt(_Size - 1);
	}

	int Find(T value)
	{
		for (int i = 0;i < _Size;i++)
		{
			if (OriginalArray[i] == value) return i;
		}

		return -1;
	}

	bool DeleteItem(T value)
	{
		if (DeleteItemAt(Find(value))) return true;
		return false;
	}

	bool InsertAt(int index, T value)
	{
		if (index < 0 || index > _Size) return false;

		_Size++;
		T* _TempArry = new T[_Size];
	
		for (int i = 0; i < _Size; i++)
		{
			if (i == index)
			{
				_TempArry[i] = value;
				i++;
				for (i; i < _Size; i++)
				{
					_TempArry[i] = OriginalArray[i-1];
				}
				break;
			}
			_TempArry[i] = OriginalArray[i];
		}

		delete[] OriginalArray;
		OriginalArray = _TempArry;

		return true;
	}

	bool InsertAtBeginning(T value)
	{
		return InsertAt(0, value);
	}

	bool InsertAtEnd(T value)
	{
		return InsertAt(_Size, value);
	}

	bool InsertBefore(int index, T value)
	{
		if (index < 1) 
			return InsertAt(0, value);
		else
			return InsertAt(index - 1, value);
	}

	bool InsertAfter(int index, T value)
	{
		if (index >= _Size)
			return InsertAt(_Size, value);
		else
			return InsertAt(index + 1, value);
	}

};

