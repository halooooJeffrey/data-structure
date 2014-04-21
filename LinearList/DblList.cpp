template <class T>
DblList<T>::DblList(T uniqueVal){
	first = new DblNode<T>(uniqueVal);
	if (first == NULL){
		cerr << "存储分配错误!" << endl;
		exit(1);
	}
	first->rLink = first->lLink = first;
}
template <class T>
int DblList<T>::Length() const{
	DblNode<T> *current = first->rLink;
	int count = 0;
	while (current != first){
		current = current->rLink;
		count++;
	}
	return count;
}
template <class T>
DblNode<T> * DblList<T>::Search(const T &x){
	DblNode<T> *current = first->rLink;
	while (current != first && current->data != x)
		current = current->rLink;
	if (current != first)
		return current;
	else
		return NULL;
}
template <class T>
DblNode<T> * DblList<T>::locate(int i, int d){
	if (first->rLink == first || i = 0)
		return first;
	DblNode<T> *current;
	if (d == 0)
		current = first->lLink;
	else
		current = first->rLink;
	for (int j = 1; j < i; j++){
		if (current == first) break;
		else if (d == 0)
			current = current->lLink;
		else
			current = current->rLink;
	}
	if (current != first)
		return current;
	else
		return NULL;
}
template <class T>
bool DblList<T>::Insert(int i, const T &x, int d){
	DblNode<T> *current = Locate(i, d);
	if (current == NULL)
		return false;
	DblNode<T> *newNode = new DblNode<T>(x);
	if (newNode == NULL){
		cerr << "存储分配错误!" << endl;
		exit(1);
	}
	if (d == 0){
		newNode->rLink = current;
		newNode->lLink = current->lLink;
		current->lLink->rLink = newNode;
		current->lLink = newNode;
	}
	else{
		newNode->rLink = current;
		newNode->lLink = current->rLink;
		current->rLink = newNode;
		current->rLink->lLink = newNode;
	}
	return true;
}
template <class T>
bool DblList<T>::Remove(int i, T &x, int d){
	DblNode<T> *current = locate(i, d);
	if (current == NULL)
		return false;
	current->lLink->rLink = current->rLink;
	current->rLink->lLink = current->lLink;
	x = current->data;
	delete current;
	return true;
}
