#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
	int dado;
	struct arvore *sesq;
	struct arvore *sdir;
}arv;

arv* arv_criarvazia(){
	return NULL;
}

arv* arv_criar(int dado, arv *sdir, arv *sesq){
	arv* tree= (arv*)malloc(sizeof(arv));
	tree->dado =  dado;
	tree->sesq = sesq;
	tree->sdir = sdir;
	return tree;
}

int arv_vazia(arv *tree){
	return tree == NULL;
}

void arv_print (arv *tree){
	printf("(");
	if (!arv_vazia(tree)){
		arv_print(tree->sesq);
		arv_print(tree->sdir);
		printf("%i", tree->dado);
	}
	printf(")");
}

int main (){
	arv *tree;
	tree = arv_criarvazia();
	tree = arv_criar(1,
			arv_criar(2,
				arv_criarvazia(),
				arv_criar(3, arv_criarvazia(), arv_criarvazia())
			),
			arv_criar(4,
				arv_criar(5, arv_criarvazia(), arv_criarvazia()),
				arv_criar(6, arv_criarvazia(), arv_criarvazia())
			)
		);
	arv_print(tree);
}
