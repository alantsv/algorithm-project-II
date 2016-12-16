#include <stdio.h>
#include <stdlib.h>

typedef struct BodyTree
{
	int key;
	int dado;
	struct BodyTree* sTreeRight;
	struct BodyTree* sTreeLeft;
}Tree;

Tree* makeLeaf (int key)
{
	Tree *newLeaf;
	newLeaf = (Tree *)malloc(sizeof(Tree));
	newLeaf->key = key;
	newLeaf->sTreeLeft = newLeaf->sTreeRight = NULL;
	return newLeaf;
}

Tree* insertLeaf (Tree* root, Tree* newleaf)
{
	if (root == NULL) return newleaf;
	if (root->key > newleaf->key)
		root->sTreeLeft = insertLeaf (root->sTreeLeft, newleaf);
	else
		root->sTreeRight = insertLeaf (root->sTreeRight, newleaf);
	return root;
}
