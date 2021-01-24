#include <stdio.h>
#include <stdlib.h>

int main()
{
	int opcao;

	do {
		menu();
		scanf_s("%d ", &opcao);
		erroMenu(opcao);
	} while ((opcao < 1) || (opcao > 5));



	opcao = opcao;

	switch (opcao)
	{
	case 1:	atendente();
		break;

	case 2:	cliente();
		break;

	case 3:	incluirExcluir(opcao);
		break;

	case 4: incluirExpluir(opcao);
		break;

	case 5: bonsEstudos();
		break;
	}

	system("pause");
	return 0;
}
