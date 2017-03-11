/*****************************************************************************
* @file : E:\C++Workspace\C++learning\C++learning\temp_test\Stack_use_array.cpp
* @author : Li weihao
* @date : 2017/3/11 14:29
* @description : Using array to implement a stack
*****************************************************************************/
#include <iostream>
using namespace std;

template <class Type>
class Stack
{
public:
	Stack();
	bool isempty();
	bool isfull();
	bool push(const Type & item);//add item to stack
	bool pop(Type & item);//pop top into item
protected:
private:
	enum { MAX=10 };
	Type items[MAX];
	int top;
};

template<class Type>
Stack<Type>::Stack()
{
	top = 0;
}

template<class Type>
bool Stack<Type>::isempty()
{
	return top == 0;
}

template<class Type>
bool Stack<Type>::isfull()
{
	return top == MAX;
}

template<class Type>
bool Stack<Type>::push(const Type & item)
{
	if (top<MAX)
	{
		items[top++] = item;
		return true;
	}
	else
	{
		return false;
	}
}

template<class Type>
bool Stack<Type>::pop(Type & item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
	{
		return false;
	}
}

int main() 
{
	Stack<int> stack;
	cout <<"stack.isempty():" << boolalpha <<stack.isempty() << endl;
	int i = 0;
	while (i < 10)
		stack.push(i++);
	cout << "stack.isfull():" << boolalpha << stack.isfull() << endl;
	int item;
	while (!stack.isempty())
	{
		stack.pop(item);
		cout << item << endl;
	}
	cin.get();
	return 0;
}