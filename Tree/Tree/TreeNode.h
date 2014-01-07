#ifndef _TreeNode_hpp_
#define _TreeNode_hpp_


template<typename T> class Tree;

template<typename T>
class TreeNode {
	friend class Tree<T>;
private:
	T value;
	TreeNode<T>* leftChild;
	TreeNode<T>* rSibling;

	
public:
	TreeNode(const T &val);
	virtual ~TreeNode(){};
	bool isLeaf();
	T fvalue();
	TreeNode<T>* leftMostChild();
	TreeNode<T>* rightSibling();
	void setValue( T &val);
	void setChild(TreeNode<T>* point);
	void setSibling(TreeNode<T>* point);
	void insertFirst(TreeNode<T>* node);
	void insertrSibling(TreeNode<T>* node);

};


template<typename T>
TreeNode<T>::TreeNode(const T &val){
	value=val;
	leftChild=rSibling=NULL;
}

template<typename T>
bool TreeNode<T>::isLeaf(){
	if(leftChild==NULL){
		return true;
	}
	return false;
}

template<typename T>
T TreeNode<T>::fvalue(){
	return value;
}

template<typename T>
TreeNode<T>* TreeNode<T>::leftMostChild(){
	return leftChild;
}

template<typename T>
TreeNode<T>* TreeNode<T>::rightSibling(){
	return rSibling;
}

template<typename T>
void TreeNode<T>::setValue(T &val){
	return value;
}

template<typename T>
void TreeNode<T>::setChild(TreeNode<T>* point){
	leftChild=point;
}

template<typename T>
void TreeNode<T>::setSibling(TreeNode<T>* point){
	rSibling=point;
}

template<typename T>
void TreeNode<T>::insertFirst(TreeNode<T>* node){
	if(leftChild){
		node->rSibling=leftChild;
	}
	leftChild=node;

}

template<typename T>
void TreeNode<T>::insertrSibling(TreeNode<T>* node){
	if(rSibling){
		node->rSibling=rSibling;
	}
	rSibling=node;
}


#endif