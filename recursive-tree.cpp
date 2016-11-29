#include <stdio.h>
#include <stdlib.h>

typedef struct BodyTree
{
	int dado;
	struct BodyTree *son;
	struct BodyTree *brother;
}Tree;

int treeEmpyt(Tree *arv)
{
	return arv == NULL;
}

Tree* makeTree(int dado, Tree *son, Tree *brother)
{
	Tree *arv = (Tree*)malloc(sizeof(Tree));
	arv->dado =  dado;
	arv->son = son;
	arv->brother = brother;
	return arv;
}

Tree* mkTreeEmpyt()
{
	return NULL;
}

void addBrother (int dado, Tree* arvSibling)
{
	arvSibling->brother = (Tree*)malloc(sizeof(Tree));
	arvSibling->brother->dado = dado;
	arvSibling->brother->brother = mkTreeEmpyt();
	arvSibling->brother->son = mkTreeEmpyt();
}

void  addSon(int dado, Tree *arv)
{
	Tree *carv = NULL;
	carv = arv;
	if (treeEmpyt(carv->son))
	{
		carv->son = makeTree(dado, mkTreeEmpyt(), mkTreeEmpyt());
	}else
	{	
		while (carv->brother != NULL)
			carv = carv->brother;
		addBrother(dado, carv);
	}
}

void printTree (Tree *tree)
{
	printf("(");
	if (!treeEmpyt(tree))
	{
		printf("%i", tree->dado);
		printTree(tree->son);
		printTree(tree->brother);
	}
	printf(")");
}

int main ()
{
	Tree *arv;
	arv = mkTreeEmpyt();
	arv = makeTree(4, mkTreeEmpyt(), mkTreeEmpyt());
	addSon(5, arv);
	addSon(6, arv);
	printTree(arv);
}
