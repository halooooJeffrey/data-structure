#include "SeqList.h"
#include <iostream>
using namespace std;
template <class T>
SeqList<T>::SeqList(int sz){
	if (sz > 0){
		maxSize = sz;
		last = -1;
		data = new T[mazSize];
		if (data == NULL){
			cerr << "存储分配错误!" << endl;
			exit(-1);
		}
	}
}
SeqList<T>::SeqList(SeqList<T> &L){
	maxSize = L.Size();
	last = L.Length() - 1;
	T value;
	data = new T[maxSize];
	if (data == NULL){
		cerr << "存储分配错误!" << endl;
		exit(-1);
	}
	for (int i = 1; i <= last + 1; i++){
		L.getData(i, value);
		data[i - 1] = value;
	}
}
void SeqList<T>::reSize(int newSize){
	if (newSize <= 0){
		cerr << "无效的数据大小!" << endl;
		return;
	}
	if (newSize != maxSize){
		T *newarray = new T[newSize];
		if (newarray == NULL){
			cerr << "存储分配错误!" << endl;
			exit(-1);
		}
		int n = last + 1;
		T *srcptr = data;
		T *destptr = newarray;
		while (n--)
			*destptr++ = *srcptr++;
		delete []data;
		data = newarray;
		maxSize = newSize;
	}
}
int SeqList<T>::search(T &x) const{
	for (int i = 0; i <= last; i++){
		if (data[i] == x)
			return i + 1;
	}
	return 0;
}
int SeqList<T>::Locate(int i) const{
	if (i >= 1 && i <= last + 1)
		return i;
	else
		return 0;
}
bool SeqList<T>::Insert(int i, T &x){
	if (last == maxSize - 1)
		return false;
	if (i < 0 || i > last + 1)
		return false;
	for (int j = last; j >= i; j--)
		data[j + 1] = data[j];
	data[i] = x;
	last++;
	return true;
}
bool SeqList<T>::Remove(int i, T &x){
	if (last == -1)
		return false;
	if (i < 1 || i > last + 1)
		return false;
	x = data[i - 1];
	for (int j = i; j <= last; j++)
		data[j - 1] = data[j];
	last--;
	return true;
}
void SeqList<T>::input(){
	cout << "开始建立顺序表，请输入表中元素个数: ";
	while(1){
		cin >> last;
		if (last <= maxSize - 1)
			break;
		cout << "表中元素个数输入有误，范围不能超过" << maxSize - 1; << ":";
	}
	for (int i = 0; i <= last; i++){
		cin >> data[i];
		cout << i + 1 << endl;
	}
}
void SeqList<T>::output(){
	cout << "顺序表当前元素最后位置为: " << last << endl;
	for (int i = 0; i <= last; i++)
		cout << "#" << i + 1 << ":" << data[i] << endl;
}
SeqList<T> SeqList<T>::opertaor =(SeqList<T> &L){
	SeqList<T> temp;
	maxSize = L.Size();
	last = L.Length() - 1;
	T value;
	temp.data = new T[maxSize];
	if (data == NULL){
		cerr << "存储分配错误!" << endl;
		exit(-1);
	}
	for (int i = 1; i <= last + 1; i++){
		L.getData(i, value);
		temp.data[i - 1] = value;
	}
	return temp;
}