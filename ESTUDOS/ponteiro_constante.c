/* ponteirocons.c */
/* Mostra ponteiros constantes */

#include<stdio.h>
#include<stdlib.h>

int main(){
  int i, j, k;

  printf("Imprimindo o endereco das variaveis na memoria\n");
  printf("Endereco de i: %p\n", &i);          /* O c�digo especial %p � utilizado para imprimir ponteiros, endere�o de uma vari�vel*/
  printf("Endereco de j: %p\n", &j);
  printf("Endereco de k: %p\n", &k);

  return 0;
}
