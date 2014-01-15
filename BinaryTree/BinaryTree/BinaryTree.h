#ifndef _BinaryTree_
#define _BinaryTree_
#include "BinaryTreeNode.h"
#include <stack>
#include <queue>

enum Tags{eLeft,eRight};             // ����ö�����ͱ�־λ// ����ö�����ͱ�־λ

template<typename T>
class stackElement {               //ջԪ�صĶ���
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
	BinaryTreeNode<T>* Parent(BinaryTreeNode<T>* current);//����current�ĸ����
	BinaryTreeNode<T>* leftSibling(BinaryTreeNode<T>* current);  //����current�������ֵ�
	BinaryTreeNode<T>* rightSibling(BinaryTreeNode<T>* current);  //����current�������ֵ�
	void createTree(const T& info, BinaryTree<T> &leftTree, BinaryTree<T> &rightTree); //����һ����infoΪ����leftTree��rightTreeΪ�����������¶�����
	void preOrder(BinaryTreeNode<T> *root); // ǰ�����ζ�������������
	void midOrder(BinaryTreeNode<T> *root);// �������ζ�������������
	void postOrder(BinaryTreeNode<T> *root);// �������ζ�������������
	//***************
	void preOrderWithoutRecursion(BinaryTreeNode<T> *root);   // ǰ�����ζ�������������
	void midOrderWithoutRecursion(BinaryTreeNode<T> *root);   // �������ζ�������������
	void postOrderWithoutRecurtion(BinaryTreeNode<T> *root);  // �������ζ�������������
	//***************
	void levelOrder(BinaryTreeNode<T> *root); // ��������ζ�������������
	void deleteBinaryTree(BinaryTreeNode<T> *root); // ɾ���������������� 
	bool isEmpty() const;
	void visit(T value) {
		std::cout<<value;
	}

};

//**********  BianryTree Implementation  ***********//
//�ж��Ƿ�Ϊ��
template<typename T>
bool BinaryTree<T>::isEmpty() const{
	return(root?false:true);
}

//����current�ĸ����
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

//����current�������ֵ�
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


//����current�������ֵ�
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

//����һ����infoΪ����leftTree��rightTreeΪ�����������¶�����
template<class T>
void BinaryTree<T>:: createTree (const T& info, BinaryTree<T> &leftTree, BinaryTree<T> &rightTree)  {
	//��������leftTree��������rightTree������Ԫ��info����һ���������������info
	//����this��leftTree��rightTree�����ǲ�ͬ��������
	root = new BinaryTreeNode<T>(info, leftTree.root, rightTree.root);	//��������
	leftTree.root = rightTree.root = NULL;  //ԭ�����������ĸ����ָ�գ��������
}

// ɾ���������������� 
template<class T>
void BinaryTree<T>:: deleteBinaryTree(BinaryTreeNode<T>* root)  { //���������εķ�ʽɾ��������
	if(root){
		deleteBinaryTree(root->Left);				//�ݹ�ɾ��������
		deleteBinaryTree(root->Right);		    //�ݹ�ɾ��������
		delete root;							//ɾ�������
	}
}


//ǰ�����ζ�������������
template<typename T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T> *root){
	if(root!=NULL){
		visit(root->value());
		preOrder(root->leftchild());
		preOrder(root->rightchild());
	}

}

//�������ζ�������������
template<typename T>
void BinaryTree<T>::midOrder(BinaryTreeNode<T> *root){
	if(root!=NULL){
		midOrder(root->leftchild());
		visit(root->value());
		midOrder(root->rightchild());
	}

}

//�������ζ�������������
template<typename T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T> *root){
	if(root!=NULL){
		postOrder(root->leftchild());
		postOrder(root->rightchild());
		visit(root->value());
	}
}

//�ǵݹ�ǰ�����ζ�������������
template<typename T>
void BinaryTree<T>::preOrderWithoutRecursion(BinaryTreeNode<T> *root){
	BinaryTreeNode<T> *point=root;
	std::stack < BinaryTreeNode<T>* > aStack;
	//aStack.push(NULL);                     // ջ�׼�����
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

//�ǵݹ��������ζ�������������
template<typename T>
void BinaryTree<T>::midOrderWithoutRecursion(BinaryTreeNode<T> *root){
	BinaryTreeNode<T> *point=root;
	std::stack<BinaryTreeNode<T> *> aStack;
	while(point||!aStack.empty()){
		if(point){
			aStack.push(point);             //��ǰָ����ջ
		    point=point->leftchild();       // ��·�½�
		
		}
		else {                                  //������������ϣ�ת�����������
			point=aStack.top();
			visit(point->value());                 
			aStack.pop();
			point=point->rightchild();
			
		}
	}
}


// �ǵݹ�������ζ�������������
// ���ڷ���ĳ�����ǰ��Ҫ֪���Ƿ��Ѿ����ʸý�����������
// �����Ҫ��ջ�е�ÿ��Ԫ�ؼ�һ����־λtag


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
		
		while(point!=NULL){               //�����ǰָ��ǿգ���ѹ��ջ�����½��������ӽڵ�
			element.point=point;
			element.tag=eLeft;              //�ñ�־λΪeleft����ʾ����������
			aStack.push(element);
			point=point->leftchild();
		}
		
		element=aStack.top();
		aStack.pop();
		point=element.point;
		
		if(element.tag==eLeft){             //�����������������������tagΪeright������������
			element.tag=eRight;
			aStack.push(element);
			point=point->rightchild();
		}
		else {
			visit(point->value());  //��������������أ�����ʵ�ǰ�ڵ�
			point=NULL;             //��pointΪNULL,������ջ
		}
	}
}

// ��������ζ�������������
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