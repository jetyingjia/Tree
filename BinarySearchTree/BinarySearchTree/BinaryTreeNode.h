#ifndef _BinaryTreeNode_
#define _BinaryTreeNode_


template<typename T> class BinaryTree;       //����
template<typename T> class BinarySearchTree;

//The Binary Tree Node(ADT)
template<typename T>
class BinaryTreeNode{
	friend class BinaryTree<T>;    //����������Ϊ��������Ԫ�࣬���ڷ���˽�����ݳ�Ա
	friend class BinarySearchTree<T>;
private:
	T info;
	BinaryTreeNode<T>* Left;
	BinaryTreeNode<T>* Right;
public:
	BinaryTreeNode();           //ȱʡ���캯��
	BinaryTreeNode(T &info);    //����Ԫ�صĹ��캯��
	BinaryTreeNode(const T &info,BinaryTreeNode<T> *l,BinaryTreeNode<T> *r);  //�����˽��ֵ�����������Ĺ��캯��
	T  value() const;	// ���ص�ǰ��������
	BinaryTreeNode<T>* leftchild() const;			// ���ص�ǰ���������
	BinaryTreeNode<T>* rightchild() const;			// ���ص�ǰ���������
	void  setLeftchild(BinaryTreeNode<T>*) ;	//���õ�ǰ����������
	void  setRightchild(BinaryTreeNode<T>*) ;	//���õ�ǰ����������
	void  setValue(const T& val); 				//���õ�ǰ����������
	bool  isLeaf() const;				//�ж���ǰ����Ƿ�ΪҶ���,���Ƿ���true
	BinaryTreeNode<T> operator = (BinaryTreeNode<T> const Node){this=Node;	};//���ظ�ֵ������

};
//****** BinaryTreeNode Implementation *******//

// 	//���ظ�ֵ������
// template<class T>
// BinaryTreeNode<T>& operator = (const BinaryTreeNode<T>& Node)  {
// 	this->info=node->info;
// 	this.left=node.left;
// 	this.right=node.right;
// }



//ȱʡ���캯��
template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(){
	Left=Right=NULL;
}

//����Ԫ�صĹ��캯��
template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(T &inf){
	info=inf;
	Left=Right=NULL;
}

//�����˽��ֵ�����������Ĺ��캯��
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
void  BinaryTreeNode<T>::setLeftchild(BinaryTreeNode<T>* subroot)  { //���õ�ǰ����������
	left = subroot;
}

template<class T>
void  BinaryTreeNode<T>::setRightchild(BinaryTreeNode<T>* subroot)  { //���õ�ǰ����������
	right = subroot;
}

template<class T>
void  BinaryTreeNode<T>::setValue(const T& val)  {	//���õ�ǰ����������
	info = val; 
} 									

template<class T>
bool  BinaryTreeNode<T>::isLeaf() const	 {	//�ж���ǰ����Ƿ�ΪҶ���,���Ƿ���true
	return (left == NULL) && (right == NULL); 
}

#endif