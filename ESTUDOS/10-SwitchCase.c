#include <stdio.h>
#include <stdlib.h>

//Fun��o principal do programa
void main(){

    //Definindo Vari�veis
    int a = 2;
    char b = 'y';

    // Condicionais tipo IF e ELSE
    if(a == 1){
        printf("\n Opcao escolhida: 1");
    }else if(a == 2){
        printf("\n Opcao escolhida: 2");
    }else if(a == 3){
        printf("\n Opcao escolhida: 3");
    }else{
        printf("\n Opcao invalida");
    }

    // Condicionais tipo SWITCH CASE
    switch(a){
        case 1:
            printf("\n Opcao escolhida: 1");
            break;
        case 2:
            printf("\n Opcao escolhida: 2");
            break;
        case 3:
            printf("\n Opcao escolhida: 2");
            break;
        default:
            printf("\n Opcao invalida");
            break;
    }

    //Switch com Char
    switch(b){
        case 'x':
            printf("\n A letra eh x");
            break;
        default:
            printf("\n Opcao invalida");
            break;
    }

    //Pausa o programa ap�s executar
    system("pause");

}

