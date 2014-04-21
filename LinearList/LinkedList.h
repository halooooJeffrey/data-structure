template <class T>
struct LinkNode{
	T data;
	LinkNode<T> *link;
	LinkNode(LinkNode<T> *pt = NULL){ link = ptr; }
	LinkNode(const T &item, LinkNode<T> *ptr = NULL){
		data = item;
		link = ptr;
	}
};
template <class T>
class List: public LinearList<T> {
public:
	List(){ first = new LinkNode<T>; }
	List(const T &x){ first = new LinkNode<T>(x);}
	List(List<T> &L);
	~List(){ makeEmpty(); }
	void makeEmpty();
	int Length() const;
	LinkNode<T> * getHead() const { return first; }
	LinkNode<T> * Search(T x);
	LinkNode<T> * Locate(int i);
	bool getData(int i, T &x) const;
	void setData(int i, T &x);
	bool Insert(int i, T &x);
	bool Remove(int i, T &x);
	bool IsEmpty() const{
		return first->link == NULL ? true : false;
	}
	bool IsFull() const{
		return false;
	}
	void input();
	void output();
	List<T>& operator =(List<T> &L);
protected:
	LinkNode<T> *first;
};