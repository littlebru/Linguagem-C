#include <stdio.h>
#include <stdlib.h>

//Fun��o principal do programa
void main(){

    //Definindo Vari�veis
    int a = 1, b = 10;

    //Contando at� 10
    while(a <= 10){

        //Imprimindo 'a' na tela
        printf("\n%d", a);

        // Somando 1
        a++;     //a = a + 1;

    }

    //Contagem Regressiva
    while(b >= 1){

        //Imprimindo 'b' na tela
        printf("\n%d", b);

        // Subtraindo 1
        b--;

    }

    //Pausa o programa ap�s executar
    system("pause");

}

