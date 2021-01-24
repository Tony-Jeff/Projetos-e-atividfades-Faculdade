#include<stdio.h>
#include<stdlib.h>

void erroMenu(opcao)
{
	if ((opcao < 1) || (opcao > 5))
		printf("\n >_< ERRO FATAL - DIGITE UM NUMERO DO MENU!");
}
