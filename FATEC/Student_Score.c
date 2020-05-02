/*
QUESTAO 05
Dados o número n de alunos de uma turma e suas notas da primeira prova,
determinar a maior e a menor nota obtidas por essa turma (Nota máxima = 10
e nota mínima = 0), não permitindo que sejam digitadas notas inválidas.
*/
#include<stdio.h>

int main(){
  int n, nota, N_maxima=0, N_minima=10, i;

  printf("Quantidade de alunos:\n");
  scanf("%d", &n);

  for(i=0; i<n; i++){

      do{
          printf("Nota obtida:\n");
          scanf("%d",&nota);

        }while(nota>10 || nota<0);

        if(nota > N_maxima)
          N_maxima = nota;
        if(nota < N_minima)
          N_minima = nota;
  }

  printf("Maior nota da turma: %d\n", N_maxima);
  printf("Menor nota da turma: %d\n", N_minima);

  return 0;

}
