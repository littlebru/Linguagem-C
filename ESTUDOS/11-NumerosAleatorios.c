#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Fun��o principal do programa
void main(){

   //Respons�vel por alimentar o rand de forma diferente
   srand((unsigned)time(NULL));

   // Armazenando o resto da divis�o do n�mero aleatorio por 3
   int aleatorio = rand() % 3;

   // Armazenando o resto da divis�o do n�mero aleatorio por 5
   int aleatorioSegundo = (rand() % 5) + 1;

   //Imprime o valor
   printf("%d", aleatorioSegundo);

   //Pausa o programa ap�s executar (Apenas no Windows)
   system("pause");

}

