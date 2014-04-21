template <class T>
struct DblNode{
	T data;
	DblNode<T> *lLink, *rLink;
	DblNode(DblNode<T> *left = NULL, DblNode<T> *right = NULL): lLink(left), rLink(right){}
	DblNode(T value, DblNode<T> *left = NULL, DblNode<T> *rLink = NULL), lLink(left), rLink(right), data(value){}
};

template <class T>
class DblList: public LinearList<T>{
public:
	DblList(T uniqueVal);
	~DblList();
	int Length() const;
	bool IsEmpty() { return first->rlink == first; }
	DblNode<T> *getHead() const { return first; }
	void setHead(DblNode<T> *ptr) { first = ptr; }
	DblNode<T> *Search(const T &x);
	DblNode<T> *Locate(int i, int d); //d=0按前驱方向，d!=0按后驱方向
	bool Insert(int i, const T &x, int d);
	bool Remove(int i, T &x, int d);
private:
	DblNode<T> *first;
}