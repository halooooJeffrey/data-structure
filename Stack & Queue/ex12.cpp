#pragma once
#include "SeqStack.h"
#include "Stack.h"
#include <iostream>
using namespace std;
int main(){
	Stack<int> *stack = new SeqStack<int>;
	int number, Base;
	cout << "请输入非负的十进制数: ";
	cin >> number;
	cout << "请输入要转化的B进制数的基数B: ";
	cin >> Base;
	int temp = number % Base;
	int newNumber = number;
	while (newNumber >= Base){
		stack->Push(temp);
		newNumber = newNumber / Base;
		temp = newNumber % Base;
	}
	stack->Push(temp);
	int BNumber;
	cout << "转化成的B进制数为: ";
	while(!stack->IsEmpty()){
		stack->Pop(BNumber);
		cout << BNumber;
	}
	cout << endl;
	return 0;
}

