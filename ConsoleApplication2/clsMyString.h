#pragma once
#include <stack>

using namespace std;

class clsMyString
{
private :
    stack<string> _undo;
    stack<string> _redo;
    string _value;

public:

    void Set(string value)
    {
        _undo.push(_value);
        _value = value;
    }

    string Get() { return _value; }

    _declspec(property(get = Get, put = Set)) string Value;
    
    void Undo()
    {
        if (!_undo.empty())
        {
            _redo.push(_value);
            _value = _undo.top();
            _undo.pop();
        }
    }

    void Redo()
    {
        if (!_redo.empty())
        {
            _undo.push(_value);
            _value = _redo.top();
            _redo.pop();
        }
    }
};

