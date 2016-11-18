#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore{
	char *dado;
	struct arvore *sesq;
	struct arvore *sdir;
}arv;

arv* arv_criarvazia(){
	return NULL;
}

arv* arv_criar(char *dado, arv *sesq, arv *sdir){
	arv* tree= (arv*)malloc(sizeof(arv));
	strcpy(dado, tree->dado);
	tree->sesq = sesq;
	tree->sdir = sdir;
	return tree;
}

int arv_vazia(arv *tree){
	return tree == NULL;
}

void arv_print (arv *tree){
	if (!arv_vazia(tree)){
		arv_print(tree->sesq);
		arv_print(tree->sdir);
		printf("%s", tree->dado);
	}
}

void pre_ordem(arv *tree){
	printf("(");
	printf("%s", tree->dado);
	if ( !arv_vazia(tree->sesq)){
		pre_ordem(tree->sesq);
	}
	if (!arv_vazia(tree->sdir)){
		pre_ordem(tree->sdir);
	}
	printf(")");
}

char main (){
	arv *tree;
	tree = arv_criarvazia();
	tree = arv_criar("a+",
			arv_criar("b*",
				arv_criar("c/", arv_criarvazia(), arv_criarvazia()),
				arv_criar("d", arv_criarvazia(), arv_criarvazia())
			),
			arv_criar("-e", arv_criarvazia(), arv_criarvazia())
		);
	//arv_print(tree);
	pre_ordem(tree);
}
