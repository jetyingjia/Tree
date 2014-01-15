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

//��ʼ��
template <typename T>
void BinarySearchTree<T>::initialize(BinaryTreeNode<T>* point){
	root=point;
}

//����������������½��
template <typename T>
void BinarySearchTree<T>::insertNode(BinaryTreeNode<T>* root,BinaryTreeNode<T>* newpointer){
	BinaryTreeNode<T>* point;
	if(root==NULL){										//����ǿ�������ʼ��
		initialize(newpointer);							//��ָ��newpointer��ʼ��������������������ֵʵ��
		return;
	}
	else {
		point=root;
	}
	while(point!=NULL){
		if(point->value()==newpointer->value()){
			return;										//������ò���
		}
		else if(newpointer->value()<point->value()) {
			
			if(point->leftchild()==NULL){
				point->Left=newpointer;					//��Ϊ������
				return;
			}
			else {
				point=point->leftchild();
			}
		}

		else {
			if(point->rightchild()==NULL){
				point->Right=newpointer;				//��Ϊ������
				return;
			}
			else {
				point=point->rightchild();
			}

		}
	}
}

//ɾ��ĳԪ��
//�Ľ��Ķ������������ɾ���㷨��˼��Ϊ
//�����pointerû��������������pointer�������ĸ����汻ɾ���Ľ��pointer
//�����pointer�����������������������ҵ����������ε����һ�����temppointer�����������е�����㣩������Ӷ�����������ɾ��
//����temppointerû����������ɾ���ý��ֻ����temppointer������������temppointer��Ȼ����temppointer�������ɾ���Ľ��pointer

template<typename T>
void BinarySearchTree<T>::deleteNode(BinaryTreeNode<T>* point){
	if(point==NULL){
		return;
	}
	BinaryTreeNode<T>* temppoint;					// ���ڱ����滻���
	BinaryTreeNode<T>* tempparent=NULL;				// ���ڱ����滻���ĸ����
	BinaryTreeNode<T>* parent=Parent(point);		// ����ɾ�����ĸ����
	if(point->leftchild()==NULL){					// �����ɾ������������Ϊ�գ��ͽ�����������������
		temppoint=point->rightchild();
	}
	else {
		// ����ɾ�������������Ϊ�գ�������������Ѱ��������滻��ɾ�����
		temppoint=point->leftchild();
		while(temppoint->rightchild()!=NULL){
			tempparent=temppoint;
			temppoint=temppoint->rightchild();
		}
		// ɾ���滻���
		if(tempparent==NULL){
			point->Left=temppoint->leftchild();
		}
		else {
			tempparent->Right=temppoint->leftchild();
		}
		temppoint->Left=point->leftchild();			// �̳�pointer��������
		temppoint->Right=point->rightchild();		// �̳�pointer��������
	}
	// ���滻���ȥ���������ɾ�����
	if(parent==NULL){
		root=temppoint;
	}
	else if(parent->Left==point){
		parent->Left=temppoint;
	}
	else {
		parent->Right=temppoint;
	}
	delete point;									// ɾ���ý��
	point=NULL;
	return;
}


//ɾ��ĳԪ��
//�����pointerû��������������pointer�������ĸ����汻ɾ���Ľ��pointer
//�����pointer�����������������������ҵ����������ε����һ�����temppointer,
//��temppointer����ָ���ó�ָ��pointer���������ĸ���Ȼ���ý��pointer�������ĸ����汻ɾ���Ľ��pointer�� 

template<typename T>
void BinarySearchTree<T>::deleteNodeEx(BinaryTreeNode<T>* pointer)  {      //�̲���д������㷨
	//�����������н���ɾ��
	BinaryTreeNode<T>* temppointer = NULL;
	if(!pointer)                            //���ɾ�����ǿս�㣬�򷵻�
		return;
	BinaryTreeNode<T>* parent = parent(pointer);
	if (pointer->leftchild() == NULL)  {
		//��ɾ������������������������ĸ������ɾ�����
		if (parent == NULL)                 //��ɾ������Ǹ����
			root = pointer->rightchild();
		else if (parent->leftchild() == pointer)
			parent->left = pointer->rightchild();
		else
			parent->right = pointer->rightchild();
		delete pointer;                     //ɾ���ý��
		pointer = NULL;
		return;
	}
	else                                 //��������Ϊ��ʱ
		temppointer = pointer->leftchild();
	while (temppointer->rightchild() != NULL)  //�����������ҶԳ�������һ�����
		temppointer = temppointer->rightchild();
	//��ɾ��������������Ϊtemppointer��������
	temppointer->right = pointer->rightchild();
	//��ɾ�����������������汻ɾ�����
	if(NULL == parent)
		root = pointer->leftchild();
	else if (parent->leftchild() == pointer)
		parent->left = pointer->leftchild();
	else 
		parent->right = pointer->leftchild();
	delete pointer;                          //ɾ���ý��
	pointer = NULL;
	return;
}

#endif