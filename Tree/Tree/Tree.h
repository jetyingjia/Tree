#ifndef _Tree_hpp_
#define _Tree_hpp_
#include "TreeNode.h"
#include <queue>

template<typename T>
class Tree {
private: 
	TreeNode<T>* root;
	void destoryNodes(TreeNode<T>* node);
public:
	//TreeNode<T>* root;
	Tree();
	~Tree();
	TreeNode<T>* getRoot();
	bool isEmpty();
	void createRoot(const T &val);
	void deleteSubTree(TreeNode<T>* subroot);
	TreeNode<T>* parent(TreeNode<T>* current);
	TreeNode<T>* preSibling(TreeNode<T>* current);  //返回current结点的前一个邻居结点
	void rootFirstTraverse(TreeNode<T>* root);      //先根深度优先周游树	
	void rootLastTraverse(TreeNode<T>* root);		//后根深度优先周游树
	void widthTraverse(TreeNode<T>* root);			//广度优先周游树
	void visit(T value) {							//访问结点
		std::cout<<value<<" ";
	};           
};

template<typename T>
Tree<T>::Tree(){
	root=NULL;
}

template<typename T>
Tree<T>::~Tree(){
	while(root)
		deleteSubTree(root);
}


template<typename T>
TreeNode<T>* Tree<T>::getRoot(){
	return root;
}

template<typename T>
bool Tree<T>::isEmpty() {
	if(root==NULL) {
		return true;
	}
	return false;
}


template<typename T>
void Tree<T>::createRoot(const T &val){
	if(!root)
		root=new TreeNode<T>(val);
}


template<typename T>
void Tree<T>::destoryNodes(TreeNode<T>* node){
	if(node!=NULL){
		destoryNodes(node->leftChild);
		destoryNodes(node->rSibling);
		delete node;
	}
}

template<typename T>
TreeNode<T>* Tree<T>::parent(TreeNode<T>* current) {
	TreeNode<T>* point=root;
	TreeNode<T>* upLevelPoint;
	std::queue< TreeNode<T>* > aQueue;
	if(current!=NULL&&point!=current){
		while(point) {
			if(point==current) {
				return NULL;
			}
			aQueue.push(point);
			point=point->rightSibling();
		}
		while(!aQueue.empty()) {
			point=aQueue.front();
			aQueue.pop();
			upLevelPoint=point;
			point=point->leftMostChild();
			while(point) {
				if(point==current) {
					return upLevelPoint;
				}
				else {
					aQueue.push(point);
					point=point->rightSibling();
				}
			}//end while
		}//end while
	}//end if
	return NULL;
	
}

template<typename T>
TreeNode<T>* Tree<T>::preSibling(TreeNode<T>* current) {
	TreeNode<T>* point=root;
	TreeNode<T>* pre=NULL;
	std::queue< TreeNode<T>* > aQueue;
	
	if(current==NULL||root==NULL||point==NULL) {
		return NULL;
	}
	while(point) {
		if(point==current) {
			return pre;
		}
		aQueue.push(point);
		pre=point;
		point=point->rightSibling();
	}
	while(!aQueue.empty()) {
		/*pre=NULL;*/
		point=aQueue.front();
		pre=point;
		aQueue.pop();
		point=point->leftMostChild();
		while(point) {
			if(point==current) {
				return pre;
			}
			aQueue.push(point);
			pre=point;
			point=point->rightSibling();
		}
	}
	return NULL;
}

template<typename T>
void Tree<T>::rootFirstTraverse(TreeNode<T>* root) {
	while(root!=NULL) {
		visit(root->fvalue());
		rootFirstTraverse(root->leftMostChild());
		root=root->rightSibling();

	}
}


template<typename T>
void Tree<T>::rootLastTraverse(TreeNode<T>* root) {
	while(root!=NULL) {
		rootLastTraverse(root->leftMostChild());
		visit(root->fvalue());
		root=root->rightSibling();
	}
}


template<typename T>
void Tree<T>::widthTraverse(TreeNode<T>* root) {
	std::queue< TreeNode<T>* > aQueue;
	TreeNode<T>* point=root;
	while(point!=NULL) {
		aQueue.push(point);
		point=point->rightSibling();
	}
	while(!aQueue.empty()) {
		point=aQueue.front();
		aQueue.pop();
		visit(point->fvalue());
		point=point->leftMostChild();
		while(point){
			aQueue.push(point);
			point=point->rightSibling();
		}
		
	}
}

template<typename T>
void Tree<T>::deleteSubTree(TreeNode<T>* subroot){
	if(subroot==NULL){
		return;
	}
	TreeNode<T>* point=parent(subroot);
	if(point==NULL){
		root=subroot->rSibling;
	}
	else if(point->leftChild==subroot){
		point->leftChild=subroot->rSibling;
	}
	else {
		point=point->leftMostChild();
		while(point->rightSibling()!=subroot){
			point=point->rightSibling();
		}
		point->setSibling(subroot->rightSibling());
	}
	subroot->setSibling(NULL);
	destoryNodes(subroot);

}

#endif