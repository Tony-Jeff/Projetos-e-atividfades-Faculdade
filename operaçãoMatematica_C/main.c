#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	float x, y, resultado;
	int opcao;

	do {

		printf("Digite o primeiro numero.\n");
		scanf_s("%f", &x);

		printf("Digite o Segundo numero.\n");
		scanf_s("%f", &y);
		
		printf("Escolha um opcao para o calculo. \n");
		printf(" 1 Soma. \n");
		printf(" 2 Subtracao. \n");
		printf(" 3 Multiplicacao. \n");
		printf(" 4 Divisao. \n");
		printf(" 5 Resto da divisao \n");		
		scanf_s("%d ", &opcao);
		
		
		switch (opcao >= 1 || opcao <=5) 
		{
		case 1:
			resultado = x + y;
			break;
		case 2:
			resultado = x - y;
			break;
		case 3:
			resultado = x * y;
			break;
		case 4:
			resultado = x / y;
			break;
		default:
			printf("Opcao invalida. \n");
			break;
		}
		printf("O resultado desta operacao e. %.2f", resultado);
		printf("Deseja continuar? \n 1 Sim \n 2 Nao \n");
			scanf_s("%i ", &opcao);
	} while (opcao==1);
		
	
}
