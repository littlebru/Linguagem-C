/*
QUESTAO 03
Dado um número inteiro positivo n, imprimir os n primeiros naturais ímpares.
 Exemplo: Para n=4 a saída deverá ser 1,3,5,7.
*/

#include<stdio.h>

int main(){
  int impares[20], impar, num, i;

  for(i=0; i<20; i++)impares[i]=0;                    //Limpando os indices do vetor

  scanf("%d",&num);

  for(i=0; i<=num; i++){
    impares[i] = i+(i-1);                             //pegando apenas numeros impares
  }

  printf("Impares: ");
  for(i=0; i<20; i++){
    if(impares[i] == 0 || impares[i] <0)continue;     //pular quando for menor ou igual a zero

    if((num - i) == 0){
      printf("%d.",impares[i]);
    }
    else{
      printf("%d,",impares[i]);
    }
  }

  return 0;
}
