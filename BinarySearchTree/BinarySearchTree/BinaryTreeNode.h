#ifndef _BinaryTreeNode_
#define _BinaryTreeNode_


template<typename T> class BinaryTree;       //声明
template<typename T> class BinarySearchTree;

//The Binary Tree Node(ADT)
template<typename T>
class BinaryTreeNode{
	friend class BinaryTree<T>;    //声明二叉树为结点类的友元类，便于访问私有数据成员
	friend class BinarySearchTree<T>;
private:
	T info;
	BinaryTreeNode<T>* Left;
	BinaryTreeNode<T>* Right;
public:
	BinaryTreeNode();           //缺省构造函数
	BinaryTreeNode(T &info);    //给定元素的构造函数
	BinaryTreeNode(const T &info,BinaryTreeNode<T> *l,BinaryTreeNode<T> *r);  //给定了结点值和左右子树的构造函数
	T  value() const;	// 返回当前结点的数据
	BinaryTreeNode<T>* leftchild() const;			// 返回当前结点左子树
	BinaryTreeNode<T>* rightchild() const;			// 返回当前结点右子树
	void  setLeftchild(BinaryTreeNode<T>*) ;	//设置当前结点的左子树
	void  setRightchild(BinaryTreeNode<T>*) ;	//设置当前结点的右子树
	void  setValue(const T& val); 				//设置当前结点的数据域
	bool  isLeaf() const;				//判定当前结点是否为叶结点,若是返回true
	BinaryTreeNode<T> operator = (BinaryTreeNode<T> const Node){this=Node;	};//重载赋值操作符

};
//****** BinaryTreeNode Implementation *******//

// 	//重载赋值操作符
// template<class T>
// BinaryTreeNode<T>& operator = (const BinaryTreeNode<T>& Node)  {
// 	this->info=node->info;
// 	this.left=node.left;
// 	this.right=node.right;
// }



//缺省构造函数
template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(){
	Left=Right=NULL;
}

//给定元素的构造函数
template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(T &inf){
	info=inf;
	Left=Right=NULL;
}

//给定了结点值和左右子树的构造函数
template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(const T &inf,BinaryTreeNode<T>* l,BinaryTreeNode<T>* r){
	info=inf;
	Left=l;
	Right=r;
}

template<typename T>
T BinaryTreeNode<T>::value() const{
	return info;
}

template<typename T>
BinaryTreeNode<T>* BinaryTreeNode<T>::leftchild() const{
	return Left;
}

template<typename T>
BinaryTreeNode<T>* BinaryTreeNode<T>::rightchild() const{
	return Right;
}

template<class T>
void  BinaryTreeNode<T>::setLeftchild(BinaryTreeNode<T>* subroot)  { //设置当前结点的左子树
	left = subroot;
}

template<class T>
void  BinaryTreeNode<T>::setRightchild(BinaryTreeNode<T>* subroot)  { //设置当前结点的右子树
	right = subroot;
}

template<class T>
void  BinaryTreeNode<T>::setValue(const T& val)  {	//设置当前结点的数据域
	info = val; 
} 									

template<class T>
bool  BinaryTreeNode<T>::isLeaf() const	 {	//判定当前结点是否为叶结点,若是返回true
	return (left == NULL) && (right == NULL); 
}

#endif