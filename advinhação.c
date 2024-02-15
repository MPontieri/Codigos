#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("========================================\n");
    printf("************* BEM-VINDO AO *************\n");
    printf("********* JOGO DA ADIVINHAÇÃO **********\n");
    printf("========================================\n");

    int chute,max,dificuldade,numerosecreto;
    int acertou = 0;
    int tentativa = 1;
    double pontos = 1000;
    
    printf("Informe o número de tentativas desejadas: ");
    scanf("%d",&max);
    printf("escolha a dificuldade:\n");
    printf("1 - número aleatório de 1 a 10\n");
    printf("2 - número aleatório de 1 a 100\n");
    printf("3 - número aleatório de 1 a 1000\n");
    scanf("%d",&dificuldade);

    srand(time(NULL));

    switch(dificuldade){
        case 1:
            numerosecreto = rand() % 10;
            break;
        case 2:
            numerosecreto = rand() % 100;
            break;
        default:
            numerosecreto = rand() % 1000;
            break;
    }

    while(1) {

        printf("Tentativa %d\n",tentativa);
        printf("Qual é o seu chute? \n");
        scanf("%d", &chute);

        if(chute < 0) {
            printf("Tente com um número positivo\n");
            continue;
        }

        printf("\n\nSua tentativa %d foi: %d\n", tentativa, chute);

        acertou = chute == numerosecreto;
        int maior = chute > numerosecreto;

        if(acertou) {
            printf("Parabéns! Você acertou!\n");
            break;
        } else if(maior) {
            printf("Seu chute foi maior do que o número secreto!\n");
        } else {
            printf("Seu chute foi menor do que o número secreto!\n");
        }

        if(tentativa >= max){
            printf("Não foi desta vez...\n");
            printf("O número secreto era: %d",numerosecreto);
            return 0;
        }
        tentativa++;

        double pontosperdidos = abs(chute - numerosecreto) / 2;
        pontos = pontos - pontosperdidos;
    }
    printf("O número secreto era: %d\n",numerosecreto);
    printf("Você fez %.1f pontos\n", pontos);
    printf("Você conseguiu! Parabéns!\n");
}