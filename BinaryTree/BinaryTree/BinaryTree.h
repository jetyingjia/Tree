#ifndef _BinaryTree_
#define _BinaryTree_
#include "BinaryTreeNode.h"
#include <stack>
#include <queue>

enum Tags{eLeft,eRight};             // 定义枚举类型标志位// 定义枚举类型标志位

template<typename T>
class stackElement {               //栈元素的定义
public:
	BinaryTreeNode<T> *point;
	Tags tag;
};

//The BinaryTree(ADT)
template<typename T>
class BinaryTree:  public BinaryTreeNode<T>{
private:
	BinaryTreeNode<T> *root;
public:
	BinaryTree(){
		root=NULL;
	}
	~BinaryTree(){
		//deleteBinaryTree(root);
	}
	BinaryTreeNode<T> *Root(){
		return root;
	}
	BinaryTreeNode<T>* Parent(BinaryTreeNode<T>* current);//返回current的父结点
	BinaryTreeNode<T>* leftSibling(BinaryTreeNode<T>* current);  //返回current结点的左兄弟
	BinaryTreeNode<T>* rightSibling(BinaryTreeNode<T>* current);  //返回current结点的右兄弟
	void createTree(const T& info, BinaryTree<T> &leftTree, BinaryTree<T> &rightTree); //构造一棵以info为根、leftTree和rightTree为左右子树的新二叉树
	void preOrder(BinaryTreeNode<T> *root); // 前序周游二叉树或其子树
	void midOrder(BinaryTreeNode<T> *root);// 中序周游二叉树或其子树
	void postOrder(BinaryTreeNode<T> *root);// 后序周游二叉树或其子树
	//***************
	void preOrderWithoutRecursion(BinaryTreeNode<T> *root);   // 前序周游二叉树或其子树
	void midOrderWithoutRecursion(BinaryTreeNode<T> *root);   // 中序周游二叉树或其子树
	void postOrderWithoutRecurtion(BinaryTreeNode<T> *root);  // 后序周游二叉树或其子树
	//***************
	void levelOrder(BinaryTreeNode<T> *root); // 按层次周游二叉树或其子树
	void deleteBinaryTree(BinaryTreeNode<T> *root); // 删除二叉树或其子树 
	bool isEmpty() const;
	void visit(T value) {
		std::cout<<value;
	}

};

//**********  BianryTree Implementation  ***********//
//判断是否为空
template<typename T>
bool BinaryTree<T>::isEmpty() const{
	return(root?false:true);
}

//返回current的父结点
template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::Parent(BinaryTreeNode<T>* current){
	std::stack<BinaryTreeNode<T> *> aStack;
	BinaryTreeNode<T>* point=root;
	if(root!=NULL&&current!=NULL){
		while(point||!aStack.empty()){
			if(point){	
				if(current==point->leftchild()||current==point->rightchild()){
					return point;
				}
				else {
					aStack.push(point);
					point=point->leftchild();
				}
			}
			else {
				point=aStack.top();
				aStack.pop();
				point=point->rightchild();
			} //endif
		} //endwhile
	}
	else {
		return NULL;
	} //endif
}

//返回current结点的左兄弟
template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::leftSibling(BinaryTreeNode<T>* current){
	if(current){
		BinaryTreeNode<T>* temp=Parent(current);
		if(temp==NULL||current==temp.leftchild()){
			return  NULL;
		}
		else {
			return temp->leftchild();
		}
	}
	return NULL;
}


//返回current结点的右兄弟
template<typename T>
BinaryTreeNode<T>* BinaryTree<T>::rightSibling(BinaryTreeNode<T>* current){
	if(current){
		BinaryTreeNode<T>* temp=Parent(current);
		if(temp==NULL||current==temp->rightchild()){
			return NULL;
		}
		else {
			return temp->rightchild();
		}
	}
	else {
		return NULL;
	}
}

//构造一棵以info为根、leftTree和rightTree为左右子树的新二叉树
template<class T>
void BinaryTree<T>:: createTree (const T& info, BinaryTree<T> &leftTree, BinaryTree<T> &rightTree)  {
	//由左子树leftTree、右子树rightTree和数据元素info创建一棵新树，根结点是info
	//其中this、leftTree、rightTree必须是不同的三棵树
	root = new BinaryTreeNode<T>(info, leftTree.root, rightTree.root);	//创建新树
	leftTree.root = rightTree.root = NULL;  //原来两棵子树的根结点指空，避免访问
}

// 删除二叉树或其子树 
template<class T>
void BinaryTree<T>:: deleteBinaryTree(BinaryTreeNode<T>* root)  { //依后序周游的方式删除二叉树
	if(root){
		deleteBinaryTree(root->Left);				//递归删除左子树
		deleteBinaryTree(root->Right);		    //递归删除右子树
		delete root;							//删除根结点
	}
}


//前序周游二叉树或其子树
template<typename T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T> *root){
	if(root!=NULL){
		visit(root->value());
		preOrder(root->leftchild());
		preOrder(root->rightchild());
	}

}

//中序周游二叉树或其子树
template<typename T>
void BinaryTree<T>::midOrder(BinaryTreeNode<T> *root){
	if(root!=NULL){
		midOrder(root->leftchild());
		visit(root->value());
		midOrder(root->rightchild());
	}

}

//后序周游二叉树或其子树
template<typename T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T> *root){
	if(root!=NULL){
		postOrder(root->leftchild());
		postOrder(root->rightchild());
		visit(root->value());
	}
}

//非递归前序周游二叉树或其子树
template<typename T>
void BinaryTree<T>::preOrderWithoutRecursion(BinaryTreeNode<T> *root){
	BinaryTreeNode<T> *point=root;
	std::stack < BinaryTreeNode<T>* > aStack;
	//aStack.push(NULL);                     // 栈底监视哨
	while( point||!aStack.empty() ){
// 		visit(point->value());
// 		if(point->rightchild()!=NULL){
// 			aStack.push(point->rightchild());
// 		}
// 		if(point->leftchild()!=NULL){
// 			point=point->leftchild();
// 		}
// 		else {
// 			point=aStack.top();
// 			aStack.pop();
// 		}
		if(point){
			visit(point->value());
			aStack.push(point);
			point=point->leftchild();
		}
		else {
			point=aStack.top();
			aStack.pop();
			point=point->rightchild();
		}
	}
}

//非递归中序周游二叉树或其子树
template<typename T>
void BinaryTree<T>::midOrderWithoutRecursion(BinaryTreeNode<T> *root){
	BinaryTreeNode<T> *point=root;
	std::stack<BinaryTreeNode<T> *> aStack;
	while(point||!aStack.empty()){
		if(point){
			aStack.push(point);             //当前指针入栈
		    point=point->leftchild();       // 左路下降
		
		}
		else {                                  //左子树访问完毕，转向访问右子树
			point=aStack.top();
			visit(point->value());                 
			aStack.pop();
			point=point->rightchild();
			
		}
	}
}


// 非递归后序周游二叉树或其子树
// 由于访问某个结点前需要知道是否已经访问该结点的右子树，
// 因此需要给栈中的每个元素加一个标志位tag


template<typename T>
void BinaryTree<T>::postOrderWithoutRecurtion(BinaryTreeNode<T> *root){
	stackElement<T> element;
	std::stack< stackElement<T> > aStack;
	BinaryTreeNode<T> * point;
	if(root==NULL)
		return ;
	else {
		point=root;
	}
	while(!aStack.empty()||point){
		
		while(point!=NULL){               //如果当前指针非空，则压入栈，并下降到最左子节点
			element.point=point;
			element.tag=eLeft;              //置标志位为eleft，表示进入左子树
			aStack.push(element);
			point=point->leftchild();
		}
		
		element=aStack.top();
		aStack.pop();
		point=element.point;
		
		if(element.tag==eLeft){             //如果从左子树返回来，则置tag为eright，进入右子树
			element.tag=eRight;
			aStack.push(element);
			point=point->rightchild();
		}
		else {
			visit(point->value());  //如果从右子树返回，则访问当前节点
			point=NULL;             //置point为NULL,继续弹栈
		}
	}
}

// 按层次周游二叉树或其子树
template<typename T>
void BinaryTree<T>::levelOrder(BinaryTreeNode<T> *root){
	BinaryTreeNode<T>* point=root;
	std::queue< BinaryTreeNode<T>* > aQueue;
	if(point){
		aQueue.push(point);
	}
	while(!aQueue.empty()){
		point=aQueue.front();
		aQueue.pop();
		visit(point->value());
		if(point->leftchild()){
			aQueue.push(point->leftchild());
		}
		if(point->rightchild()){
			aQueue.push(point->rightchild());
		}
	}
}

#endif