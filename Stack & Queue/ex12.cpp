#pragma once
#include "SeqStack.h"
#include "Stack.h"
#include <iostream>
using namespace std;
int main(){
	Stack<int> *stack = new SeqStack<int>;
	int number, Base;
	cout << "������Ǹ���ʮ������: ";
	cin >> number;
	cout << "������Ҫת����B�������Ļ���B: ";
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
	cout << "ת���ɵ�B������Ϊ: ";
	while(!stack->IsEmpty()){
		stack->Pop(BNumber);
		cout << BNumber;
	}
	cout << endl;
	return 0;
}

