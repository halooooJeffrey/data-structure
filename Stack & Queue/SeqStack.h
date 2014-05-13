#pragma once
#include <assert.h>
#include <iostream>
#include "Stack.h"
const int INCREMENT = 10;
template <class T>
class SeqStack: public Stack<T>{
public:
	SeqStack(int sz = 0);
	~SeqStack(){ delete []elements; }
	bool Push(T x);
	bool Pop(T &x);
	bool getTop(T &x);
	int getSize() const{ return top + 1;}
	bool IsEmpty() const{ return top == -1; }
	bool IsFull() const{ return top == maxSize - 1; }
	void display();
private:
	T *elements;
	int top;
	int maxSize;
};
template <class T>
SeqStack<T>::SeqStack(int sz = 0): maxSize(sz), top(-1){
	elements = new T[maxSize];
	assert(elements != NULL);
}
template <class T>
bool SeqStack<T>::Push(T x){
	if (IsEmpty()){
		T *temp;
		int newMaxSize = maxSize + INCREMENT;
		temp = new T[newMaxSize];
		assert(temp != NULL);
		for (int i = 0; i < maxSize; i++)
			temp[i] = elements[i];
		delete []elements;
		elements = temp;
		maxSize = newMaxSize;
	}
	top++;
	elements[top] = x;
	return true;
}
template <class T>
bool SeqStack<T>::Pop(T &x){
	if (IsFull())
		return false;
	else{
		x = elements[top];
		top--;
		return true;
	}
}
template <class T>
bool SeqStack<T>::getTop(T &x){
	if (IsFull())
		return false;
	else{
		x = elements[top];
		return true;
	}
}
template <class T>
void SeqStack<T>::display(){
	if (IsEmpty())
		return;
	for (int i = 0; i <= top; i++){
		std::cout << elements[i] << " ";
	}
	cout << endl;
}