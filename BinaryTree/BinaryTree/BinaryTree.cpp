#include <iostream>
#include "BinaryTree.h"
void main()
{
	BinaryTree<char> a,b,c,d,e,f,g,h,i,nulltree;
	d.createTree('D',nulltree,nulltree);
	g.createTree('G', nulltree, nulltree);
	h.createTree('H', nulltree, nulltree);
	i.createTree('I', nulltree, nulltree);
	f.createTree('F', h, i);
	e.createTree('E', g, nulltree);
	b.createTree('B', d, e);
	c.createTree('C', nulltree, f);
	a.createTree('A', b, c);

	//ǰ�����ζ�����
	std::cout<<"Preorder sequence is: "<<std::endl;
	a.preOrder(a.Root());				//�ݹ�
	std::cout<< std::endl<<"Preorder sequence Without Recursion is: " <<std::endl;
	a.preOrderWithoutRecursion(a.Root());//�ǵݹ�

	//�������ζ�����
	std::cout <<std::endl<< "Inorder sequence is: "<<std::endl;
	a.midOrder(a.Root());			//�ݹ�
	std::cout<<std::endl<< "Inorder sequence Without Recursion is: " <<std::endl;
	a.midOrderWithoutRecursion(a.Root());//�ǵݹ�

	//�������ζ�����
	std::cout <<std::endl<< "Postorder sequence is: "<<std::endl;
	a.postOrder(a.Root());			//�ݹ�
	std::cout<< std::endl<<"Postorder sequence Without Recursion is: " <<std::endl;
	a.postOrderWithoutRecurtion(a.Root());//�ǵݹ�

	//root
	std::cout<<"The root is: "<<a.Root()->value();

	//level order
	a.levelOrder(a.Root());

	//delete tree
	a.deleteBinaryTree(a.Root());
	std::cout<<"The tree is deleted";

	system("pause");
	
	
}
