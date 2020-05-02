/*
QUESTAO 02
Dado um número inteiro positivo n, calcular a soma dos n primeiros
números naturais.

*/


#include<stdio.h>

int main(){
  int n, soma=0, i;

  scanf("%d",&n);

  for(i=0; i<n; i++){
    soma = soma + i;
    }

  printf("Resultado da soma %d\n",soma);

  return 0;
}
