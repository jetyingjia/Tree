#ifndef _BinarySearchTree_hpp_
#define _BinarySearchTree_hpp_
//#include "BinaryTreeNode.h"
#include "BinaryTree.h"

template<typename T>
class BinarySearchTree: public BinaryTree<T>{
public:
	BinarySearchTree(){
		root=NULL;
	};
	~BinarySearchTree(){};
	void initialize(BinaryTreeNode<T>* newpoint);
	void insertNode(BinaryTreeNode<T>* root,BinaryTreeNode<T>* newpointer);
	void deleteNode(BinaryTreeNode<T>* point);
	void deleteNodeEx(BinaryTreeNode<T>* point);

};

//****** BinarySearchTree Implementation *******//

//初始化
template <typename T>
void BinarySearchTree<T>::initialize(BinaryTreeNode<T>* point){
	root=point;
}

//向二叉搜索树插入新结点
template <typename T>
void BinarySearchTree<T>::insertNode(BinaryTreeNode<T>* root,BinaryTreeNode<T>* newpointer){
	BinaryTreeNode<T>* point;
	if(root==NULL){										//如果是空树，初始化
		initialize(newpointer);							//用指针newpointer初始化二叉搜索树树根，赋值实现
		return;
	}
	else {
		point=root;
	}
	while(point!=NULL){
		if(point->value()==newpointer->value()){
			return;										//相等则不用插入
		}
		else if(newpointer->value()<point->value()) {
			
			if(point->leftchild()==NULL){
				point->Left=newpointer;					//作为左子树
				return;
			}
			else {
				point=point->leftchild();
			}
		}

		else {
			if(point->rightchild()==NULL){
				point->Right=newpointer;				//作为右子树
				return;
			}
			else {
				point=point->rightchild();
			}

		}
	}
}

//删除某元素
//改进的二叉搜索树结点删除算法的思想为
//若结点pointer没有左子树，则用pointer右子树的根代替被删除的结点pointer
//若结点pointer有左子树，则在左子树里找到按中序周游的最后一个结点temppointer（即左子树中的最大结点）并将其从二叉搜索树里删除
//由于temppointer没有右子树，删除该结点只需用temppointer的左子树代替temppointer，然后用temppointer结点代替待删除的结点pointer

template<typename T>
void BinarySearchTree<T>::deleteNode(BinaryTreeNode<T>* point){
	if(point==NULL){
		return;
	}
	BinaryTreeNode<T>* temppoint;					// 用于保存替换结点
	BinaryTreeNode<T>* tempparent=NULL;				// 用于保存替换结点的父结点
	BinaryTreeNode<T>* parent=Parent(point);		// 保存删除结点的父结点
	if(point->leftchild()==NULL){					// 如果待删除结点的左子树为空，就将它的右子树代替它
		temppoint=point->rightchild();
	}
	else {
		// 当待删除结点左子树不为空，就在左子树中寻找最大结点替换待删除结点
		temppoint=point->leftchild();
		while(temppoint->rightchild()!=NULL){
			tempparent=temppoint;
			temppoint=temppoint->rightchild();
		}
		// 删除替换结点
		if(tempparent==NULL){
			point->Left=temppoint->leftchild();
		}
		else {
			tempparent->Right=temppoint->leftchild();
		}
		temppoint->Left=point->leftchild();			// 继承pointer的左子树
		temppoint->Right=point->rightchild();		// 继承pointer的右子树
	}
	// 用替换结点去替代真正的删除结点
	if(parent==NULL){
		root=temppoint;
	}
	else if(parent->Left==point){
		parent->Left=temppoint;
	}
	else {
		parent->Right=temppoint;
	}
	delete point;									// 删除该结点
	point=NULL;
	return;
}


//删除某元素
//若结点pointer没有左子树，则用pointer右子树的根代替被删除的结点pointer
//若结点pointer有左子树，则在左子树里找到按中序周游的最后一个结点temppointer,
//把temppointer的右指针置成指向pointer的右子树的根，然后用结点pointer左子树的根代替被删除的结点pointer。 

template<typename T>
void BinarySearchTree<T>::deleteNodeEx(BinaryTreeNode<T>* pointer)  {      //教材中写出这个算法
	//二叉搜索树中结点的删除
	BinaryTreeNode<T>* temppointer = NULL;
	if(!pointer)                            //如果删除的是空结点，则返回
		return;
	BinaryTreeNode<T>* parent = parent(pointer);
	if (pointer->leftchild() == NULL)  {
		//被删结点无左子树，则将其右子树的根代替该删除结点
		if (parent == NULL)                 //被删除结点是根结点
			root = pointer->rightchild();
		else if (parent->leftchild() == pointer)
			parent->left = pointer->rightchild();
		else
			parent->right = pointer->rightchild();
		delete pointer;                     //删除该结点
		pointer = NULL;
		return;
	}
	else                                 //左子树不为空时
		temppointer = pointer->leftchild();
	while (temppointer->rightchild() != NULL)  //在左子树中找对称序的最后一个结点
		temppointer = temppointer->rightchild();
	//被删除结点的右子树作为temppointer的右子树
	temppointer->right = pointer->rightchild();
	//被删除结点的左子树根代替被删除结点
	if(NULL == parent)
		root = pointer->leftchild();
	else if (parent->leftchild() == pointer)
		parent->left = pointer->leftchild();
	else 
		parent->right = pointer->leftchild();
	delete pointer;                          //删除该结点
	pointer = NULL;
	return;
}

#endif