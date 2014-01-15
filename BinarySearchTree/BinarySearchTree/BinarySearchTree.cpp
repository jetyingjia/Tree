#include <iostream>
#include "BinarySearchTree.h"

void main()
{
	BinarySearchTree<int> aBST;
	BinarySearchTree<int>* newpoint,*node;
	std::cout<<"Please input N numbers: ";
	int N;
	std::cin>>N;
	int *p=new int[N];
	for(int i=0;i<N;i++){
		int value;
		std::cin>>value;
		p[i]=value;
	}
	for(int i=0;i<N;i++){
		newpoint=new BinarySearchTree<int>();
		newpoint->setValue(p[i]);
		if(p[i]==55){
			node=newpoint;
		}
		aBST.insertNode(aBST.Root(),newpoint);
	}

	//中序遍历结点
	std::cout<<"The midorder is: ";
	aBST.midOrder(aBST.Root());


	//删除结点
	aBST.deleteNode(node);
	std::cout<<"The delete midorder is: ";
	aBST.midOrder(aBST.Root());
	system("pause");
}