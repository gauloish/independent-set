#include <stdio.h>

#define N 10
#define M 25

int grafo[N][N];
int arestas[M][2] = {
	{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 7}, {0, 9},
	{1, 2}, {1, 3}, {1, 5}, {1, 6}, {1, 8}, {1, 9},
	{2, 3}, {2, 6}, {2, 8},
	{3, 7}, {3, 9},
	{4, 5}, {4, 9},
	{5, 7}, {5, 8}, {5, 9},
	{7, 8}, {7, 9},
};

int main() {
	int numero = 0;

	for (int i = 0; i < M; i++) {
		int u = arestas[i][0];
		int v = arestas[i][1];

		grafo[u][v] = 1;
		grafo[v][u] = 1;
	}

	for (int mascara = 1; mascara < (1 << N); mascara++) {
		int tamanho = 0;
		int conjunto[N];

		for (int i = 0; i < N; i++) {
			conjunto[i] = mascara & (1 << i);

			if (conjunto[i]) {
				tamanho++;
			}
		}

		int independente = 1;

		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (conjunto[i] && conjunto[j]) {
					if (grafo[i][j] || grafo[j][i]) {
						independente = 0;
					}
				}
			}
		}

		if (independente) {
			printf("{");

			if (numero < tamanho) {
				numero = tamanho;
			}

			for (int i = 0; i < N; i++) {
				if (conjunto[i]) {
					printf("%d", i);

					if (tamanho != 1) {
						printf(", ");
					}

					tamanho--;
				}
			}

			printf("}\n");
		}
	}

	printf("\nNumero de independencia: %d\n", numero);
}
