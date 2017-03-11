/*****************************************************************************
* @file : E:\C++Workspace\C++learning\C++learning\temp_test\Stack.cpp
* @author : Lotrea
* @date : 2017/3/10 22:09
* @description : use list to implement stack
*****************************************************************************/
#include <iostream>

template<class T> 
class Mystack
{
public:
	void push(T data);
	T pop();
	
private:
	typedef struct elementT
	{
		T data;
		elementT *next;
	}element;
	elementT* firstE = new elementT;
};
//ÈëÕ»º¯Êý
template<class T>
void Mystack<T>::push(T data)
{
	elementT *element = new elementT;
	element->data = data;
	element->next = firstE;
	firstE = element;
	return;
}

//³öÕ»º¯Êý
template<class T>
T Mystack<T>::pop()
{
	elementT* popelement = firstE;
	if (popelement==NULL)
	{
		return NULL;
	}
	T data;
	data = firstE->data;
	firstE = firstE->next;
	delete popelement;
	return data;
}

int main()
{
	Mystack<int> stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	stack.push(6);
	for (int i = 0; i < 6; i++)
	{
		std::cout << stack.pop() << std::endl;
	}
	std::cin.get();
	return 0;
}
