// carregando as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <string.h>

//definindo um novo nome aos tipos de variaveis
typedef struct{
    char nome_ap[60];
    int apostaTimeA, apostaTimeB;
}
//variáveis são inicializadas com valor zero
Apostador;
Apostador apos[5];

//iniciando o bloco
int main(){
    setlocale(LC_ALL,"portuguese");
    
    //declarando variaveis do tipo inteiro
    int i,pontos, resultA,resultB;
    
    //iniciando o bloco de entrada de dados com nome do apostador e sua aposta
	printf("Bolao de Futebol \n");
    for(i=0; i<5; i++) {
        printf("Digite o nome do Apostador: ");
        scanf_s("%s%*c", &apos[i].nome_ap);
        printf(" Digite os gols do Time A: ");
        scanf_s("%d%*c", &apos[i].apostaTimeA);
        printf(" Digite os gols do Time B: ");
        scanf_s("%d%*c", &apos[i].apostaTimeB);
    }
    //entrando com os dados do resultado do jogo
    printf("RESULTADO DO JOGO \n");
    printf("O Time A fez: ");
    scanf_s("%d", &resultA);
    printf("O Time B fez: ");
    scanf_s("%d",&resultB);
    printf("\nO resultado do jogo foi: Time da A %d x %d Time B\n",
             resultA, resultB);
    
	//bloco que define qual apostador fez mais pontos
	for(i=0;i<5;i++){
        pontos=0;
        if(resultA > resultB){
            if(apos[i].apostaTimeA > apos[i].apostaTimeB){
                pontos += 10;
            }
            if(apos[i].apostaTimeA == resultA){
                pontos += 5;
            }
            if(apos[i].apostaTimeB == resultB){
                pontos += 5;
            }
        }
        else{
            if(resultA < resultB){
                if (apos[i].apostaTimeA < apos[i].apostaTimeB){
                   pontos += 10;
               }
                if(apos[i].apostaTimeA == resultA){
                   pontos += 5;
                }
                if(apos[i].apostaTimeB == resultB){
                    pontos += 5;
                }
            }
            else{
                if(apos[i].apostaTimeA == apos[i].apostaTimeB){
                    pontos += 10;
                }
                if(apos[i].apostaTimeA == resultA){
                    pontos += 5;
                }
                if(apos[i].apostaTimeB == resultB){
                    pontos += 5;
                }
            }
        }
        //o programa imprime na tela do usuario o total de pontos dos apostadores
        printf("\n%10s apostou: Time A %d x %d Time B e fez %d pontos",
        apos[i].nome_apostador, apos[i].apostaTimeA, apos[i].apostaTimeB, pontos);
    }
    printf("\n\n");
    system("pause");
    return 0;
}
