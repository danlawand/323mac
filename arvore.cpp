#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) ((a) > (b)? (a): (b))

using namespace std;

typedef struct celula Celula;
struct celula{
	int conteudo;  /* tipo devia ser Item */
	Celula *pai;	/*É bom para caso voltar*/
	Celula *esq;
	Celula *dir;
};
typedef Celula No;
typedef No *Arvore;

/*************************************************
Recebe a raiz r de uma árvore binária não vazia e
imprime a Árvore na ordem e-r-d
**************************************************/
void inOrdem( Arvore r) {
	if (r != NULL) {
		inOrdem(r->esq);
		printf("%d\n", r->conteudo);
		inOrdem(r->dir);
	}
}

/*************************************************
Recebe a raiz r de uma árvore binária não vazia e
retorna o primeiro nó na ordem e-r-d
**************************************************/
No *primeiro (Arvore r) {
	while (r->esq != NULL) {
		r = r->esq;
	}
	return r;
}


/***********************************************
A altura de uma arvore é o caminho mais longo
que leva até uma folha.
***********************************************/
int altura (Arvore r) {
	if (r == NULL) return -1;
	else {
		int he = altura(r->esq);
		int hd = altura(r->dir);
		return MAX(he,hd) + 1;
	}
}

/**************************************************
Recebe o endereço p de um nó de uma árvore binária
não vazia e retorna o seu sucessor na ordem e-r-d.
**************************************************/
No *sucessor (No *p) {
	if (p->dir != NULL) {
		No *q = p->dir;
		while (q->esq != NULL) q = q->esq;
		return q;
	}
	while (p->pai != NULL && p->pai->dir == p) {
		p = p->pai;
	}
	return p->pai;
}


int main() {
	Arvore r = new Arvore;
	r->conteudo = 1;
	r->pai = NULL;
	Arvore p = new Arvore;
	
}