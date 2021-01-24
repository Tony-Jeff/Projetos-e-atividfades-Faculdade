#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct aluno {
	int ru;
	char nome[50];
	char email[60];
	struct aluno * proximo;
} t_cad;
t_cad *ini_cad = NULL;

int op;
void cadastro();
void pesquisa();
int main(int argc, char *argv[]) {

	do {
		system("cls");
		printf("Escolha uma opcao\n");
		printf("1 - Cadastrar Alunos\n");
		printf("2 - Pesquisar Alunos\n");
		printf("3 - Sair\n");
		scanf("%d", &op);
		switch (op) {
		case 1:
			cadastro();

			break;

		case 2:
			pesquisa();

			break;

		case 3:

			system("exit");
			break;
		default:
			printf("Opcao Invalida...");
			break;
		}

	} while (op != 3);


void liberarmem();

	return 0;
}
void cadastro() {

	int cont;
	t_cad* prox_cad;

	if (ini_cad == NULL)
	{
		ini_cad = (t_cad*)malloc(sizeof(t_cad));
		ini_cad ->proximo = NULL;
		if (ini_cad == NULL) exit(1);
	}
	prox_cad = ini_cad;

	while (1) {
		printf("Digite o RU:\n");
		scanf("%d", &prox_cad->ru);
		printf("Digite o Nome:\n");
		scanf("%s", &prox_cad->nome);
		printf("Digite o email:\n");
		scanf("%s", &prox_cad->email);
		printf("Deseja continuar? (1)SIM e (0)NAO\n");
		scanf("\n %d", &cont);
		if (cont == 0) break;
	    prox_cad->proximo = (t_cad *)malloc(sizeof(t_cad));
		prox_cad = prox_cad->proximo;
		prox_cad->proximo = NULL;
	}
	printf("\n");
}

void pesquisa() {
	int ru_aux;
	char nome_aux[60];
	t_cad* prox_cad;

	do {
		printf("\n Escolha uma opcao para a pesquisa: \n1 RU \n2 Nome :\n0 para sair\n");
		scanf("%d", &op);
		if (op == 0) break;
		prox_cad = ini_cad;
		switch (op) {
		case 1:
			printf("\n Digite o RU do Aluno:");
			scanf("%d", &ru_aux);
			while (prox_cad != NULL) {
		     if (prox_cad-> ru == ru_aux)
		     {
			    printf("ru: %d\n nome:%s\n email:%s", prox_cad->ru, prox_cad->nome, prox_cad->email);
			    break;
			  }
			  prox_cad = prox_cad->proximo;
			}
            break;
		case 2:
			printf("\n Digite o nome do Aluno:");
			scanf("%s", nome_aux);//não precisa de & para string
			while (prox_cad != NULL) {
		     if (strcmp(prox_cad->nome, nome_aux) == 0)
		     {
			    printf("ru: %d\n nome:%s\n email:%s", prox_cad->ru, prox_cad->nome, prox_cad->email);
			    break;
		      }
		      prox_cad = prox_cad->proximo;
			}
		    break;

		default:
			printf("\n****opcao invalida*****");
			break;
		}
	} while (1);
}


void liberarmem()
{
    t_cad *prox_cad;
    while (ini_cad != NULL) {
             prox_cad = ini_cad;
             ini_cad  = prox_cad->proximo;
             free(prox_cad);
		  	}
}
