#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fila.h"
#include "arvore_n_aria.h"

void caminho_minimo(int tam, int matriz[tam][tam], int a) {
	int *vs = calloc(tam+1, sizeof(int));
	Fila f;
	inicializa_fila(&f, tam);
	Arvore t;
	inicializa_Arvore(&t, a);
	vs[a] = 1;
	inserir(&f, a);
	int x, i;
	while( !fila_vazia(f)) {
		remover(&f, &x);
			for (i = 1; i <= tam; i++) {
				if (matriz[x-1][i-1] == 0) {
					if (vs[i] == 0) {
						vs[i] = 1;
						insere_filho(t, x, i);
						inserir(&f, i);
					}
				}
            }
    }
	gera_xml(t);
	system("PAUSE");
}

int main(int argc, char *argv[]) {
	FILE *entrada = fopen("matriz.txt", "r");
	int tam, a, lin, col, qtd_matriz;
	fscanf(entrada, "%d", &qtd_matriz);
	while(qtd_matriz--) {
		fscanf(entrada, "%d", &tam);
		int matriz[tam][tam];
		for (lin = 0; lin < tam; lin++) {
			for (col = 0; col < tam; col++) {
				fscanf(entrada, col == tam - 1 ? "%d\n" : "%d ", &matriz[lin][col]);
			}
		}
		fscanf(entrada, "%d", &a);
		caminho_minimo(tam, matriz, a);
	}
	fclose(entrada);
	return 0;
}
