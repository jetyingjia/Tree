#ifndef _AVLTree_hpp_
#define _AVLTree_hpp_

//this is avl tree class
#include "AVLNode.h"

template <class T> 
class avlTree//ƽ���������
{
public:
	avlTree();//���캯��
	avlTree(const avlTree<T> &source);
	~avlTree();//��������
	void add(T value);
	void remove(T value);
	void deleteAllValue();
	void display();
	void display(avlNode<T>* found);
	avlNode<T>* findValue(T val);
private:
	avlNode<T> *root;
};

//��������
template <class T>
avlTree<T>::avlTree():root(0){

}

//���ƹ��캯��
// template <class T>
// avlTree<T>::avlTree<T>(const avlTree<T> &source)
// {
// 	root=(source.root==NULL?NULL:source.root->copy());
// }

template <class T>
avlTree<T>::~avlTree()
{
	if (root!=NULL) 
		deleteAllValue();
}

//��ƽ���avl�����Ԫ��
template <class T> 
void avlTree<T>::add(T value)
{
	if(root==NULL)
		root=new avlNode<T>(value);
	else
		root->add(root,value);
}

//��avl����ɾ��һ��Ԫ��
template <class T>
void avlTree<T>::remove(T val)
{
	avlNode<T>* eNode=NULL;
	int flag=0;
	if (root)
		root=root->remove(val,eNode,flag);
	if (eNode)
		delete eNode;
	else 
		std::cout<<"The avlTree doesn't contain the value"<<std::endl;
}

//ɾ��avl����ȫ��Ԫ��
template <class T> 
void avlTree<T>::deleteAllValue()
{
	if(root!=NULL)
	{
		root->release();
		delete root;
		root=NULL;
	}
}

template <class T> 
void avlTree<T>::display()
{
	if (root) 
	{
		std::cout<<setw(8)<<"�ڵ�ֵ"<<setw(10)<<"ƽ������"<<" "<<setw(6)<<"����"<<std::endl;
		root->preorderview(root);
	}
	else 
		std::cout<<"��ǰ����!"<<std::endl;
}

//����val�Ľڵ�ֵ
template <class T> 
avlNode<T>* avlTree<T>::findValue(T val)
{
	avlNode<T>* found=root->findNodeValue(val);
	if (found==NULL)
		return NULL;
	else
		return found;
}

//��ʾָ���ָ�����ֵ
template <class T> 
void avlTree<T>::display(avlNode<T>* found)
{
	if(found==NULL) 
		std::cout<<"Sorry,û�ҵ� :("<<std::endl;
	else
		std::cout<<"�ҵ�:"<<found->value<<std::endl;
}

#endif
