#include <stdio.h>                               
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <Windows.h>

void troca(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void bsort(int v[], int qtd)
{
	int i = 0, j, *t = 1;
	while (t == 1)
	{
		t = 0;

		for (j = 0; j < qtd - i; j++)
		{
			if (v[j] > v[j + 1])
			{
				t = 1;
				troca(&v[j], &v[j + 1]);
			}
		}
		i++;
	}
}//FIM bubble sort_________________________________

int buscaBin(int x, int v[], int n) {
	int i = 0, f = n - 1, m, c = 0;

	while (i<=f)
	{
		m = (i + f) / 2;
		c++;
		if (x == v[m])
			return 1;
		else {
			if (x < v[m])
				f = m - 1;
			else
			{
				i = m + 1;
			}
		}
	}
	return 0;
}//FIM busca Binaria_______________________________

int buscaLin(int x, int v[], int n) {
	int i;
	for (i = 0; i <= n; i++) {
		if (x == v[i])
			return 1;
	}
	return 0;
}//FIM busca linear________________________________

int menu() {
	int r;
	printf("Escolha um opcao \n");
	printf("1. Busca Binaria. \n");
	printf("2. Busca linear. \n");
	printf("0. Sair. \n");
	scanf_s("%d", &r);
	return r;
}//FIM menu________________________________________

int main() {
	int n, i, vet[100], op, x;
	FILE *arq;
	printf("Quantidade de elementos:");
	scanf_s("%d", &n);
	arq = fopen_s("cad.txt", "r");
	for (i = 0; i < n; i++) {
		fscanf_s(arq, "%d", &vet[i]);
	}
	printf("Vetor lido. \n");
	for (i = 0; i < n; i++) {
		printf("%d", vet[i]);
	}
	bsort(vet, n - 1);
	printf("Vetor ordenado: \n");
	for (i = 0; i < n; i++) {
		printf("%d", vet[i]);
	}
	printf("\n\n");
	while (op != 0) {
		op = menu();
		switch (op)
		{
		case 1:
			printf("Entre com um valor para a busca binaria: \n");
			scanf_s("%d", &x);
			if (buscaBin(x, vet, n) == 1)
				printf("Elemento encontrado \n", x);
			else
			{
				printf("Elemento não existe \n", x);
			}
			break;

		case 2:
			printf("Entre com um valor para a busca linear: \n");
			scanf_s("%d", &x);
			if (buscaBin(x, vet, n) == 1)
				printf("Elemento encontrado \n", x);
			else
			{
				printf("Elemento não existe \n", x);
			}
			break;
		case 0: printf("Encerrando..........");
			break;
		default: printf("Opcao invalida");
		}		
	}
}

