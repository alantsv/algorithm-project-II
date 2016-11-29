//Programa que implementa a criação de árvores genéricas através da lista de irmãos
//Autor: Alan Veloso
//E-mail: alantsv@gmail.com
//Instituição: Universidade Federal do Pará

#include <stdio.h>
#include <stdlib.h>

// Estrutura com os ponteiros: son, para o primeiro filho,
// e brother, para um irmão de um determinado nó
typedef struct BodyTree
{
	int dado;
	struct BodyTree *son;
	struct BodyTree *brother;
}Tree;

// Teste de árvore vazia
int treeEmpyt(Tree *arv)
{
	return arv == NULL;
}

//Cria árvore
Tree* makeTree(int dado, Tree *son, Tree *brother)
{
	Tree *arv = (Tree*)malloc(sizeof(Tree));
	arv->dado =  dado;
	arv->son = son;
	arv->brother = brother;
	return arv;
}

//Cria árvores vazias
Tree* mkTreeEmpyt()
{
	return NULL;
}

// Adiciona nó irmão através de recursividade
void addBrother (int dado, Tree* arvSibling)
{
	if (treeEmpyt(arvSibling->brother))
		arvSibling->brother = makeTree(dado, mkTreeEmpyt(), mkTreeEmpyt());
	else
		addBrother(dado, arvSibling->brother);
}

// Adiciona nó filho, diretamente, ou através do irmão do filho
void  addSon(int dado, Tree *arv)
{
	Tree *carv = NULL;
	carv = arv;
	if (treeEmpyt(carv->son))
	{
		carv->son = makeTree(dado, mkTreeEmpyt(), mkTreeEmpyt());
	}else
	{	
		addBrother(dado, carv->son);
	}
}

// Mostra árvore com parênteses balanceados
void printTree (Tree *tree)
{
	printf("(");
	if (!treeEmpyt(tree))
	{
		printTree(tree->son);
		printf("%i", tree->dado);
		printTree(tree->brother);
	}
	printf(")");
}

void referencia (Tree *tree)
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
void editTree (Tree* arv)
{
	int op = -1;
	printf("<%i>\n", arv->dado);
	while (op != 0){
		printf("[1] Ir para o irmão\n");
		printf("[2] Ir para o filho\n\n");
		printf("Opção: ");
		scanf("%i", &op);
		switch (op)
		{
			case 1:
				if (treeEmpyt(arv->brother))
					printf("nâo vai\n");
				else
				{
					arv = arv->brother;
					editTree(arv);
				}
			break;
			case 2:
				
				if (treeEmpyt(arv->son))
					printf("não vai\n");
				else
				{
					arv = arv->son;
					editTree(arv);
				}
			break;
			default:
				printf("Tu és burro cara?\n");
		}
	}
}

// Principal
int main ()
{
	Tree *arv;
	arv = mkTreeEmpyt();
	arv = makeTree(4, mkTreeEmpyt(), mkTreeEmpyt());
	addSon(5, arv);
	addSon(6, arv);
	printTree(arv);
	printf("\n");
	editTree(arv);
}
