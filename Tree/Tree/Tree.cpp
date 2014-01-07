#include <iostream>
#include "Tree.h"

void main()
{
	Tree<char> aTree;
	aTree.createRoot('A');
	TreeNode<char> *f = new TreeNode<char>('F');
	TreeNode<char> *e = new TreeNode<char>('E');
	TreeNode<char> *d = new TreeNode<char>('D');
	TreeNode<char> *c = new TreeNode<char>('C');
	TreeNode<char> *b = new TreeNode<char>('B');
	b->setSibling(c);
	c->setSibling(d);
	c->setChild(e);
	e->setSibling(f);
	aTree.getRoot()->setChild(b);


	TreeNode<char> *x=new TreeNode<char>('X');
	TreeNode<char> *y=new TreeNode<char>('Y');
	TreeNode<char> *z=new TreeNode<char>('Z');
	aTree.getRoot()->setSibling(x);
	x->setChild(y);
	y->setSibling(z);

	//显示树的结构
	std::cout << "      A            X        \n";
    std::cout << "   /  |  \\      /   \\     \n";
    std::cout << "  B   C    D    Y     Z     \n";
    std::cout << "    /   \\                  \n";
    std::cout << "   E     F                  \n";
    std::cout << "\n";

	std::cout<<"rootfirstTraverse: ";
	aTree.rootFirstTraverse(aTree.getRoot());
	std::cout<<std::endl<<"rootLastTraverse: ";
	aTree.rootLastTraverse(aTree.getRoot());
	std::cout<<std::endl<<"widthTraverse: ";
	aTree.widthTraverse(aTree.getRoot());
	
	//e结点以第一个兄弟的身份插入H
	std::cout<<std::endl<<"insertSIbling of e with h: ";
	TreeNode<char>* h=new TreeNode<char> ('H');
	e->insertrSibling(h);
	std::cout<<"rootfirstTraverse: ";
	aTree.rootFirstTraverse(aTree.getRoot());

	//求父结点
	std::cout<<std::endl<<"the parent of e: ";
	aTree.visit(aTree.parent(e)->fvalue());
	
	//获得b的上一个兄弟结点
	std::cout<<std::endl<<"The preSibling of b: ";
	aTree.visit(aTree.preSibling(b)->fvalue());

	////删除根为E的子树
	std::cout<<std::endl<<"delete the subtree e: ";
	aTree.deleteSubTree(c);
	aTree.rootFirstTraverse(aTree.getRoot());

	system("pause");

}