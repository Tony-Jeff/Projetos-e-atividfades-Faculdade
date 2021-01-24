#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 30

int menu();
void InserirInicio(char v_nome[TAMANHO], char v_artista[TAMANHO], int m, int s);
void InserirMeio(char v_nome[TAMANHO], char v_artista[TAMANHO], int m, int s);
void InserirFim(char v_nome[TAMANHO], char v_artista[TAMANHO], int m, int s);
void Listar();

struct Musicas {
	char nome[TAMANHO];
	char artista[TAMANHO];
	int min, seg, pos;
	struct Musicas *prox;
} *Head;


int  main() {
	int op, pos, c, m, s;
	char v_nome[TAMANHO];
	char v_artista[TAMANHO];
	Head = NULL;


	while (1) {
		op = menu();
		switch (op) {

		case 1:
			printf("Digite o nome da musica: ");
			gets_s(v_nome);
			while ((c = getchar()) != '\n' && c != EOF) {} //USADO PRA LIMPAR OS DADOS

			printf("Digite o nome do artista: ");
			gets_s(v_artista);
			while ((c = getchar()) != '\n' && c != EOF) {}

			printf("Digite a duracao da musica (mm ss): ");
			scanf_s("%d %d", &m, &s);
			while ((c = getchar()) != '\n' && c != EOF) {}

			InserirInicio(v_nome, v_artista, m, s);
			break;
		case 2:
			printf("Digite o nome da musica: ");
			gets_s(v_nome);
			while ((c = getchar()) != '\n' && c != EOF) {} //USADO PRA LIMPAR OS DADOS

			printf("Digite o nome do artista: ");
			gets_s(v_artista);
			while ((c = getchar()) != '\n' && c != EOF) {}

			printf("Digite a duracao da musica (mm ss): ");
			scanf_s("%d %d", &m, &s);
			while ((c = getchar()) != '\n' && c != EOF) {}

			InserirMeio(v_nome, v_artista, m, s);
			break;

		case 3:
			printf("Digite o nome da musica: ");
			gets_s(v_nome);
			while ((c = getchar()) != '\n' && c != EOF) {} //USADO PRA LIMPAR OS DADOS

			printf("Digite o nome do artista: ");
			gets_s(v_artista);
			while ((c = getchar()) != '\n' && c != EOF) {}

			printf("Digite a duracao da musica (mm ss): ");
			scanf_s("%d %d", &m, &s);
			while ((c = getchar()) != '\n' && c != EOF) {}

			InserirFim(v_nome, v_artista, m, s);
			break;

		case 5:
			Listar();
			break;
		case 6:
			return 0;
		default:
			printf("Invalido\n");
		}
	}
	return 0;
}


int menu() {
	int op, c;
	system("Cls");

	printf("*******Menu para adicionar musicas*******\n");
	printf("1 - Inserir musica no inicio da lista\n");
	printf("2 - Inserir no meio da lista encadeada simples\n");
	printf("3 - Inserir no fim da lista encadeada simples\n");
	printf("4 - Remover da lista encadeada simples\n");
	printf("5 - Listar a lista encadeada simples\n");
	printf("6 - Sair\n");
	printf("*******Digite sua escolha:************** \n");

	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {}

	system("Cls");
	return op;
}


void InserirInicio(char v_nome[TAMANHO], char v_artista[TAMANHO], int m, int s)
{
	Musicas *NovoElemento;
	NovoElemento = (struct Musicas *)malloc(sizeof(struct Musicas));
	//NovoElemento->nome[TAMANHO] = v_nome;
	strcpy_s(NovoElemento->nome, v_nome);
	//NovoElemento->artista[TAMANHO] = v_artista;
	strcpy_s(NovoElemento->artista, v_artista);
	NovoElemento->min = m;
	NovoElemento->seg = s;

	if (Head == NULL)
	{
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		NovoElemento->prox = Head;
		Head = NovoElemento;
	}
}void InserirMeio(char v_nome[TAMANHO], char v_artista[TAMANHO], int m, int s)
{
	Musicas *NovoElemento, *ElementoAuxiliar;
	NovoElemento = (struct Musicas *)malloc(sizeof(struct Musicas));
	ElementoAuxiliar = (struct Musicas *)malloc(sizeof(struct Musicas));
	//NovoElemento->nome[TAMANHO] = v_nome;
	strcpy_s(NovoElemento->nome, v_nome);
	//NovoElemento->artista[TAMANHO] = v_artista;
	strcpy_s(NovoElemento->artista, v_artista);
	strcpy_s(ElementoAuxiliar->nome, v_nome);
	strcpy_s(ElementoAuxiliar->artista, v_artista);
	NovoElemento->min = m;
	NovoElemento->seg = s;

	if (pos == 0)
	{
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		NovoElemento = Head;
		for (int i = 0; i < pos; i++) {
			NovoElemento = NovoElemento->prox;
		}
		ElementoAuxiliar = NovoElemento->prox;
		NovoElemento->prox = NovoElemento;
		NovoElemento->prox = ElementoAuxiliar;
		NovoElemento->prox = NULL;
	}
}


void InserirFim(char v_nome[TAMANHO], char v_artista[TAMANHO], int m, int s)
{
	Musicas *NovoElemento;
	NovoElemento = (struct Musicas *)malloc(sizeof(struct Musicas));
	//NovoElemento->nome[TAMANHO] = v_nome;
	strcpy_s(NovoElemento->nome, v_nome);
	//NovoElemento->artista[TAMANHO] = v_artista;
	strcpy_s(NovoElemento->artista, v_artista);
	NovoElemento->min = m;
	NovoElemento->seg = s;

	if (Head == NULL)
	{
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else
	{
		NovoElemento = Head;
		while (NovoElemento->prox != NULL) {
			NovoElemento = NovoElemento->prox;
		}
		Head = NovoElemento;
	}
}


void Listar()
{
	Musicas *ElementoVarredura;
	ElementoVarredura = (struct Musicas *)malloc(sizeof(struct Musicas));

	ElementoVarredura = Head;
	if (ElementoVarredura == NULL) {
		return;
	}
	while (ElementoVarredura != NULL) {
		//printf("Nome da música: %c\n", ElementoVarredura->nome); // AQUI TAMBÉM NÃO CONSIGO USAR O %s POIS RETORNA ERRO
		printf("Nome da musica: %s\n", ElementoVarredura->nome);
		//printf("Artista: %c\n", ElementoVarredura->artista);
		printf("Artista: %s\n", ElementoVarredura->artista);
		printf("Duracao: %.2d:%.2d\n\n", ElementoVarredura->min, ElementoVarredura->seg);
		ElementoVarredura = ElementoVarredura->prox;
	}
	printf("\n");

	system("pause");
	return;
}
