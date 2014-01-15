#ifndef _AVLTree_hpp_
#define _AVLTree_hpp_

//this is avl tree class
#include "AVLNode.h"

template <class T> 
class avlTree//平衡二叉树类
{
public:
	avlTree();//构造函数
	avlTree(const avlTree<T> &source);
	~avlTree();//析构函数
	void add(T value);
	void remove(T value);
	void deleteAllValue();
	void display();
	void display(avlNode<T>* found);
	avlNode<T>* findValue(T val);
private:
	avlNode<T> *root;
};

//建立空树
template <class T>
avlTree<T>::avlTree():root(0){

}

//复制构造函数
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

//向平衡的avl树添加元素
template <class T> 
void avlTree<T>::add(T value)
{
	if(root==NULL)
		root=new avlNode<T>(value);
	else
		root->add(root,value);
}

//从avl树中删除一个元素
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

//删除avl树的全部元素
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
		std::cout<<setw(8)<<"节点值"<<setw(10)<<"平衡因子"<<" "<<setw(6)<<"层数"<<std::endl;
		root->preorderview(root);
	}
	else 
		std::cout<<"当前树空!"<<std::endl;
}

//查找val的节点值
template <class T> 
avlNode<T>* avlTree<T>::findValue(T val)
{
	avlNode<T>* found=root->findNodeValue(val);
	if (found==NULL)
		return NULL;
	else
		return found;
}

//显示指针的指向的码值
template <class T> 
void avlTree<T>::display(avlNode<T>* found)
{
	if(found==NULL) 
		std::cout<<"Sorry,没找到 :("<<std::endl;
	else
		std::cout<<"找到:"<<found->value<<std::endl;
}

#endif
