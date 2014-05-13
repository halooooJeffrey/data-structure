#include <iostream>
#include <assert.h>
using namespace std;
template <class T>
class DblStack{
private:
	T *elements;
	int top[2];
	int maxSize;
public:
	DblStack(int sz = 10);
	~DblStack(){ delete []elements;}
	bool DblPush(T x, int tag);
	bool DblPop(T &x, int tag);
	bool IsEmpty(int tag){
		if (tag == 0)
			return top[tag] == -1;
		else
			return top[tag] == maxSize;
	}
	bool IsFull(){ return top[0] + 1 == top[1]; }
	T * DblGetTop(int tag);
	void MakeEmpty(int tag);
	void display(int tag);
};
template <class T>
 DblStack<T>::DblStack(int sz = 10){
	maxSize = sz;
	top[0] = -1;
	top[1] = maxSize;
	elements = new T[maxSize];
	assert(elements != NULL);
}
template <class T>
bool DblStack<T>::DblPush(T x, int tag){
	if (IsFull())
		return false;
	else if (tag == 0){
		top[0]++;
		elements[top[0]] = x;
		return true;
	}
	else{
		top[1]--;
		elements[top[1]] = x;
		return true;
	}
}
template <class T>
bool DblStack<T>::DblPop(T &x, int tag){
	if (IsEmpty(tag))
		return false;
	else if (tag == 0){
		x = elements[top[0]];
		top[0]--;
		return true;
	}
	else{
		x = elements[top[1]];
		top[1]++;
		return true;
	}
}

template <class T>
T * DblStack<T>::DblGetTop(int tag){
	if (IsEmpty(tag))
		return 0;
	else if (tag == 0)
		return &elements[top[0]];
	else
		return &elements[top[1]];
}

template <class T>
void DblStack<T>::MakeEmpty(int tag){
	if (tag == 0)
		top[tag] = -1;
	if (tag == 1)
		top[tag] == maxSize;
}
template <class T>
void DblStack<T>::display(int tag){
	if (IsEmpty(tag))
		return;
	if (tag == 0){
		for (int i = 0; i <= top[0]; i++)
			cout << elements[i] << " ";
	}
	if (tag == 1){
		for (int i = top[1]; i < maxSize; i++)
			cout << elements[i] << " ";
	}
	cout << endl;
}
int main(){
	DblStack<int> stack(5);
	stack.DblPush(1, 0);
	stack.DblPush(2, 0);
	stack.DblPush(3, 0);
	stack.display(0);
	int x;
	stack.DblPop(x, 0);
	cout << x << endl;
	stack.display(0);
	int *temp;
	temp = stack.DblGetTop(0);
	cout << *temp << endl;
	stack.DblPush(4, 0);
	stack.DblPush(5, 1);
	stack.DblPush(6, 1);
	stack.display(1);
	if (stack.IsFull())
		cout << "FULL!" << endl;
	stack.DblPop(x, 1);
	cout << x << endl;
	stack.display(1);
	return 0;
}


