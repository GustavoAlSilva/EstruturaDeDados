#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fila.h"
#include "Pilha.h"

void bfs(int size, int m[size][size], int a, int b, int count) {

	int *vs = calloc(size+1, sizeof(int));
	int *va = calloc(size+1, sizeof(int));

	Fila f;

	inicializa_fila(&f, size);

	vs[a] = 1;

	inserir(&f, a);

	int achou = 0, x, i;

	while( !fila_vazia(f) && !achou ) {

		remover(&f, &x);

		if (x == b) {

			achou = 1;
		} else {

			for (i = 1; i <= size; i++) {

				if (m[x-1][i-1]) {

					if (!vs[i]) {

						vs[i] = 1;
						va[i] = x;

						inserir(&f, i);
					}
				}
			}
		}
	}

	printf("%dª Matriz: ", count);

	if (achou) {

		Pilha p;

		inicializa_pilha(&p, size);

		while(x != 0) {

			empilha(&p, x);

			x = va[x];
		}

		while( !pilha_vazia(p) ) {

			desempilha(&p, &x);

			printf("%d ", x);
		}

		printf("\n\n");
	} else {

		printf("%d nao eh alcancavel a partir de %d\n\n", b, a);
	}
}

int main() {

	FILE *file = fopen("matriz.txt", "r");

	int size, a, b, i, j, qtd, count = 1;

	fscanf(file, "%d", &qtd);

	while(qtd--) {

		fscanf(file, "%d", &size);

		int m[size][size];

		for (i = 0; i < size; i++) {

			for (j = 0; j < size; j++) {

				fscanf(file, j == size - 1 ? "%d\n" : "%d ", &m[i][j]);
			}
		}

		fscanf(file, "%d %d", &a, &b);

		bfs(size, m, a, b, count);

		count++;
	}

	fclose(file);

	return 0;
}
