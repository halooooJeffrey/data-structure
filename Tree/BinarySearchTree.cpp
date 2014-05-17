template <typename Comparable>
class BinarySearchTree{
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& rhs);
	~BinarySearchTree();
	const Comparable& findMin() const;
	const Comparable& findMax() const;
	bool contains(const Comparable& x) const;
	bool isEmpty() const;
	void printTree() const;
	void makeEmpty();
	void insert(const Comparable& x);
	void remove(const Comparable& x);
	const BinarySearchTree& operator =(const BinarySearchTree& rhs);
private:
	struct BinaryNode{
		Comparable element;
		BinaryNode *left;
		BinaryNode *right;
		BinaryNode(const Comparable& theElement, BinaryNode *lt, BinaryNode *rt)
		:element(theElement), left(lt), right(rt){}
	};
	BinaryNode *root;
	void insert(const Comparable& x, BinaryNode * &t) const;
	void remove(const Comparable& x, BinaryNode * &t) const;
	BinaryNode* findMin(BinaryNode *t) const;
	BinaryNode* findMax(BinaryNode *t) const;
	bool contains(const Comparable& x, BinaryNode *t) const;
	void makeEmpty(BinaryNode * &t);
	void printTree(BinaryNode *t) const;
	BinaryNode* clone(BinaryNode *t) const;
};

/**
* Return true if x is found in the tree.
*/
bool contains(const Comparable &x) const{
	return contains(x, root);
}
/**
* Insert x into the tree; duplicates are ignored.
*/
void insert(const Comparable &x){
	insert(x, root);
}
/**
* Remove x from the tree. Nothing is done if x is not found.
*/
void remove(const Comparable &x){
	romove(x, root);
}
/**
* Internal method to test if an item is in a subtree.
* x is item to search for.
* t is the node that roots the subtree.
*/
bool contains(const Comparable &x, BinaryNode *t) const{
	if (t == NULL)
		return false;
	else if (x < t->element)
		return contains(x, t->left);
	else if (x > t->element)
		return contains(x, t->right);
	else
		return true;
}

// using function object
template <typename Object, typename Comparator = less<Object> >
class BinarySearchTree{
public:

	// Same methods, with Object replacing Comparable

private:
	BinaryNode *root;
	Comparator isLessThan;

	// Same methods, with Object replacing Comparable

	/**
	* Internal method to test if an item is in a subtree.
	* x is item to search for.
	* t is the node that roots the subtree.
	*/

	bool contains(const Object &x, BinaryNode *t) const{
		if (t == NULL)
			return false;
		else if (isLessThan(x, t->element))
			return contains(x, t->left);
		else if (isLessThan(t->element, x))
			return contains(x, t->right);
		else
			return true;	//Match
	}
};

/**
* Internal method to find the smallest item in a subtree t.
* Return node containing the smallest item.
*/
BinaryNode* findMin(BinaryNode *t) const{
	if (t == NULL)
		return NULL;
	if (t->left == NULL)
		retur t;
	return findMin(t->left);
}
/**
* Internal method to find the largest item in a subtree t.
* Return node containing the largets item.
*/
BinaryNode* findMax(BinaryNode *t) const{
	if (t != NULL){
		while (t->right != NULL)
			t = t->right;
	}
	return t;
}
/**
* Internal method to insert into a subtree.
* x is the item to insert.
* t is the node that roots the subtree.
* Set the new root of the subtree.
*/
void insert(const Comparable &x, BinaryNode * &t){
	if (t == NULL)
		t = new BinaryNode(x, NULL, NULL);
	else if (x < t->element)
		insert(x, t->left);
	else if (t->element < x)
		insert(x, t->right);
	else
		;	//Duplicate; do nothing
}
/**
* Internal method to remove from a subtree.
* x is the item to remove.
* t is the node that roots the subtree.
* Set the new root of the subtree.
*/
void remove(conat Comparable &x, BinaryNode *&t){
	if (t == NULL)
		return;
	if (x < t->element)
		remove(x, t->left);
	else if (t->element < x)
		remove(x, t->right);
	else if (t->left != NULL && t->right != NULL){ //two children
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else{
		BinaryNode* oldNode = t;
		t = (t->left != NULL) ? t->left : t->right;
		delete oldMode;
	}
}
/**
* Destructor for the tree
*/
~BinarySearchTree(){
	makeEmpty();
}
/**
* Internal method to make subtree empty.
*/
void makeEmpty(BinaryNode * &t){
	if (t != NULL){
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = NULL;
}
/**
* Deep copy
*/
const BinarySearchTree& operator =(const BinarySearchTree& rhs){
	if (*this != rhs){
		makeEmpty();
		root = clone(rhs.root);
	}
	return *this;
}
/**
* Internal method to clone subtree.
*/
BinaryNode* clone(BinaryNode *t) const{
	if (t == NULL)
		return NULL;
	return new BinaryNode(t->left, clone(t->left), clone(t->right));
}