#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


void cliente() {

	char nome[50];
	char telefone[11];
	char email[30];


	printf("\n ****************** Cadastro de clientes ******************\n\n\n ");

	printf("Digite o nome do cliente: ");
	scanf_s("%s ", &nome);

	printf("Digite o telefone do cliente: ");
	scanf_s("%s ", &telefone);

	printf("Digite o E-mail do cliente: ");
	scanf_s("%s ", &email);

	printf("\n ****************** Lendo os dados do CADASTRO ****************** \n\n\n ");

	printf("****************** Nome.....: %s\n\n", nome);
	printf("****************** Telefone......:%s\n\n", telefone);
	printf("****************** E-mail......:%s\n\n", email);

	printf("\n\n");
	system("pause");
}
