/*
QUESTAO 04
Dados um inteiro x e um inteiro não-negativo n, calcular x^(n).

*/

#include<stdio.h>
#include<math.h>//biblioteca que contem o "pow"

int main(){
  int i, x, n, expo = 0;

  scanf("%d",&x);

  do
  {printf("Elevado a: ");
    scanf("%d",&n);} while(n<0);//nao pega numeros negativos

  expo = pow(x,n); //realizando a exponenciacao com pow

  printf("da: %d\n",expo);

  return 0;
}
