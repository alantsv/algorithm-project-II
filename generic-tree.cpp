//Programa que implementa a criação de árvores genéricas através da lista de irmãos
//Autor: Alan Veloso
//E-mail: alantsv@gmail.com
//Instituição: Universidade Federal do Pará

#include <stdio.h>
#include <stdlib.h>

// Estrutura com os ponteiros: son, para o primeiro filho,
// e brother, para um irmão de um determinado nó.
typedef struct BodyTree
{
	int dado;
	struct BodyTree *son;
	struct BodyTree *brother;
}Tree;

// Teste de árvore vazia.
int treeEmpyt(Tree *arv)
{
	return arv == NULL;
}

//Cria árvore, recebendo as sub-árvores.
Tree* makeTree(int dado, Tree *son, Tree *brother)
{
	Tree *arv = (Tree*)malloc(sizeof(Tree));
	arv->dado =  dado;
	arv->son = son;
	arv->brother = brother;
	return arv;
}

//Cria árvores vazias.
Tree* mkTreeEmpyt()
{
	return NULL;
}

// Adiciona nó irmão através de recursividade.
void addBrother (int dado, Tree* arvSibling)
{
	if (treeEmpyt(arvSibling->brother))
		arvSibling->brother = makeTree(dado, mkTreeEmpyt(), mkTreeEmpyt());
	else
		addBrother(dado, arvSibling->brother);
}

// Adiciona nó filho, diretamente, ou através do irmão do filho.
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

// Mostra árvore com parênteses balanceados.
void printTree (Tree *arv)
{
	printf("(");
	if (!treeEmpyt(arv))
	{
		printf("%i", arv->dado);
		printTree(arv->son);
		printTree(arv->brother);
	}
	printf(")");
}

//Edita a árvore existente, caminhando pelos nós.
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

//Calcula o grau de um determinado nó.
int calcularGrau(Tree *arv)
{	
	int grau = 0;
	arv = arv->son;
	while (arv !=  NULL){
		grau++;
		arv= arv->brother;
	}
	return grau;
}

//Calcula o parenstesco, se o segundo é descendente do primeiro
//ou, se o primeiro é ancestral do segundo.
int parentesco(Tree* ancestral, int descendente)
{
	Tree* herdeiro = ancestral->son;
	while (herdeiro != NULL)
	{
		if (herdeiro->dado == descendente)
			return 1;
		else
			parentesco(herdeiro, descendente);
		herdeiro = herdeiro->brother;
	}
	return 0;
}

//Determina se um nó é folha ou interior.
int folhaOuInterior(Tree* arv, int dado)
{
	Tree* filho = arv->son;	
	while (filho != NULL)
	{
		if ((filho->dado == dado) && (filho->son == NULL))
			return 1;
		else
			folhaOuInterior(filho, dado);
		filho = filho->brother;
	}
	return 0;
}

// Principal
int main ()
{
	int parente = -1;
	int grau = -1;
	int folha = -1;
	Tree *arv;

	arv = mkTreeEmpyt();
	arv = makeTree(4, mkTreeEmpyt(), mkTreeEmpyt());
	addSon(5, arv);
	addSon(6, arv);
	printTree(arv);
	printf("\n");
//	editTree(arv);
	grau = calcularGrau(arv);
	printf("\n%i\n", grau);
	parente =  parentesco(arv, 5);
	if (parente)
		printf("É descendente\n");
	else
		printf("Não é descendente\n");
	
	if (parente)
		printf("É ancestral\n");
	else
		printf("Não é ancestral\n");
	
	folha = folhaOuInterior(arv, 4);

	if (folha)
		printf("É folha\n");
	else
		printf("É interior\n");
	
}
