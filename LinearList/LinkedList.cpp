#include "LinkedList.h"
template <class T>
List<T>::List(List<T> &L){
	T value;
	LinkNode<T> *srcptr = L.getHead();
	LinkNode<T> *destptr = first = new LinkNode<T>;
	while (srcptr->link != NULL){
		value = srcptr->link->data;
		destptr->link = new LinkNode<T>(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
	destptr->link = NULL;
}
template <class T>
void Link<T>::makeEmpty(){
	LinkNode<T> *q;
	while (first->link != NULL){
		q = first->link;
		first->link = q->link;
		delete q;
	}
}
template <class T>
int Link<T>::length() const{
	int count = 0;
	LinkNode<T> *p = first->link;
	while (p != NULL){
		count++;
		p = p->link;
	}
	return count;
}
template <class T>
LinkNode<T> * List<T>::Search(T x){
	LinkNode<T> *q = first->link;
	while (q != NULL){
		if (q->data == x)
			break;
		else
			q = q->link;
	}
	return q;
}
template <class T>
LinkNode<T> * List<T>::Locate(int i){
	if (i < 0) return NULL;
	LinkNode<T> *q = first;
	int k = 0;
	while (q != NULL && k < i){
		q = q->link;
		k++;
	}
	return q;
}
template <class T>
bool List<T>::getData(int i, T &x) const{
	if (i <= 0)
		reurn false;
	LinkNode<T> *q = locate(i);
	if (q == NULL)
		return false;
	else{
		x = q->data;
		return true;
	}
}
template <class T>
void List<T>::setData(int i, T &x){
	if (i <= 0)
		return;
	LinkNode<T> *q = locate(i);
	if (q == NULL)
		return;
	else
		q->data = x;
}
template <class T>
bool List<T>::Insert(int i, T &x){
	LinkNode<T> *q = new LinkNode<T>(x);
	if (q = NULL){
		cerr << "存储分配错误!" << endl;
		exit(1);
	}
	LinkNode<T> *current = locate(i);
	if (current == NULL)
		return false;
	q->link = current->link;
	current->link = q;
	return true;
}
template <class T>
bool List<T>::Remove(int i, T &x){
	LinkNode<T> *current = locate(i - 1)
	if (current == NULL || current->link == NULL)
		return false;
	LinkNode<T> *del = current->link;
	current->link = del->link;
	x = del->data;
	delete del;
	return true;
}
template <class T>
//two methods to replement input function
void List<T>::inputFront(T endTag){
	LinkNode<T> *newNode;
	T val;
	makeEmpty();
	cin >> val;
	while (val != endTag){
		newNode = new LinkNode<T>(val);
		if (newNode == NULL){
			cerr << "存储分配错误!" << endl;
			exit(1);
		}
		newNode->link = first->link;
		first->link = newNode;
		cin >> val;
	}
}
template <class T>
void List<T>::inputRear(T endTag){
	LinkNode<T> *newNode, *last;
	T val;
	makeEmpty();
	cin >> val;
	last = first;
	while (val != endTag){
		newNode = new LinkNode<T>(val);
		if (newNode == NULL){
			cerr << "存储分配错误!" << endl;
			exit(1);
		}
		last->link = newNode;
		last = newNode;
		cin >> val;
	}
	last->link = NULL;
}
template <class T>
void List<T>::output(){
	LinkNode<T> *current = first->link;
	if (current == NULL){
		cout << "链表为空!" << endl;
		return;
	}
	else{
		while (current != NULL){
			cout << current->data << "  ";
			current = current->link;
		}
	}
}
template <class T>
List<T>& List<T>::operator =(List<T> &L){
	LinkNode<T> *srcptr = L.getHead();
	LinkNode<T> *destptr = first = new LinkNode<T>;
	T value;
	while (srcptr->link != NULL){
		value = srcptr->link->data;
		destptr->link = new LinkNode<T>(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
	destptr->link = NULL;
	return *this;
}