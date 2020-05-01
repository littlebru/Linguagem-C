#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Função principal do programa
void main(){

   //Responsável por alimentar o rand de forma diferente
   srand((unsigned)time(NULL));

   // Armazenando o resto da divisão do número aleatorio por 3
   int aleatorio = rand() % 3;

   // Armazenando o resto da divisão do número aleatorio por 5
   int aleatorioSegundo = (rand() % 5) + 1;

   //Imprime o valor
   printf("%d", aleatorioSegundo);

   //Pausa o programa após executar (Apenas no Windows)
   system("pause");

}

