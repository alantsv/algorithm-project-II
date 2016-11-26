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

void addSon(int dado, Tree *arv)
{
	Tree *carv;
	carv = arv;
	if (treeEmpyt(carv->son))
	{
		carv->son = makeTree(dado, mkTreeEmpyt(), mkTreeEmpyt());
		arv = carv;

	}else
	{	
		
		addSon(dado, carv->son->brother);
		arv = carv;
	}
}

void printTree (Tree *tree)
{
	printf("(");
	if (!treeEmpyt(tree))
	{
		printTree(tree->son);
		printTree(tree->brother);
		printf("%i", tree->dado);
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
