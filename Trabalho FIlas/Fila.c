#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

void inicializa_fila(Fila *f, int size) {
	f->dados = malloc(sizeof(int) * size);
	f->ini = 0;
	f->n = 0;
	f->capacidade = size;
}

int fila_vazia(Fila f) {
	return f.n == 0;
}

int fila_cheia(Fila f) {
	return f.n == f.capacidade;
}

int inserir(Fila *f, int v) {
	if (fila_cheia(*f))
		return ERRO_FILA_CHEIA;
		
	int fim = (f->ini + f->n) % f->capacidade;
	f->dados[fim] = v;
	f->n++;
	return 1;
}

int remover(Fila *p, int *info){
	if( fila_vazia( *p ) )
		return ERRO_FILA_VAZIA;
	
	*info = p->dados[p->ini];
	p->ini = ( p->ini + 1 ) % p->capacidade;
	p->n--;
	return 1;
};

void mostra_fila(Fila f) {
	int i = f.ini, cont;
	for (cont = 0; cont < f.n; cont++) {
		printf("[%d]: %d\n", i, f.dados[i]);
		i = (i + 1) % f.capacidade;
	}
}

void desaloca_fila(Fila *f) {
	free(f->dados);
}
