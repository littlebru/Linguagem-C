#include<stdio.h>

int main(){

    //imprime cabeçalho do nosso jogo
    printf("********************************************\n");
    printf("   Seja bem-vindo ao jogo de adivinhacao!   \n");
    printf("********************************************\n");

    int numSecreto = 42;

    int chute;
    int tentativas = 1;

    float pontos = 1000;
    float pontosperdidos = 0;

    //Criando um loop infinito
    while(1){

        printf("\n");
        printf("TENTATIVA %d\n", tentativas);

        printf("Qual seu chute: ");
        scanf("%d", &chute);

        if(chute < 0){
            printf("Voce nao pode chutar numeros negativos\n");

            continue;
        }

        int acertou = (chute == numSecreto);

        int maior = chute > numSecreto;

        if(acertou){
                printf("\n");
                printf("Parabens! voce descobriu o numero secreto\n");
                printf("Jogue denovo, voce e' um bom jogador\n");

                break;
            }
        else if(maior){
                printf("\n");
                printf("resultado:  Seu chute foi maior que o numero secreto\n");
            }
        else{
                printf("\n");
                printf("resultado:  Seu chute foi menor que o numero secreto\n");
            }
            tentativas ++;
            pontosperdidos = (chute - numSecreto) / 2.0;
            pontos -= pontosperdidos;
    }

    printf("\n********************************************\n");
    printf("FIM DE JOGO!\n");
    printf("Voce acertou com %d tentativa(s)\n", tentativas);
    printf("Total de pontos: %.1f\n", pontos);

    return 0;

}
