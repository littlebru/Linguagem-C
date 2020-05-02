#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "forca.h"

char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesDados = 0;

void resultado(){

  if(acertou()){
      system("cls");
      printf("\nParabens, voce ganhou!\n\n");
      printf("Descobriu a palavra secreta: **%s**\n", palavrasecreta);

      printf("       ___________      \n");
      printf("      '._==_==_=_.'     \n");
      printf("      .-\\:      //-.    \n");
      printf("     | (|:.     |) |    \n");
      printf("      '-|:.     |-'     \n");
      printf("        \\::.    //      \n");
      printf("        '::. .'        \n");
      printf("           ) (          \n");
      printf("         _.' '._        \n");
      printf("        '-------'       \n");
      printf("\n");

  }else{
    system("cls");
    printf("\nPoxa, voce foi enforcado!\n");
    printf("A palavra era **%s** \n\n", palavrasecreta);


printf("    _______________       \n");
printf("   /               \\      \n");
printf("  /                 \\     \n");
printf("//                   \\/\\ \n");
printf("\\|  XXXX     XXXX    | /   \n");
printf(" |  XXXX     XXXX    |/    \n");
printf(" |  XXX       XXX    |     \n");
printf(" |                   |     \n");
printf(" \\_        X      __/     \n");
printf("    |\\    XXX     /|       \n");
printf("    | |           ||       \n");
printf("    | I I I I I I I|       \n");
printf("    |  I I I I I I |       \n");
printf("    \\_            _/       \n");
printf("      \\_        _/         \n");
printf("       \\_______/           \n");
printf("\n");
  }
}

void divisoria(){
  printf("\n*****************************************\n");
}

void abertura(){
  printf("******************************************\n");
  printf("*             JOGO DA FORCA              *\n");
  printf("******************************************\n");
}

void chuta(){

      char chute;

      printf("Qual letra? ");
      scanf(" %c", &chute);

      chutes[chutesDados] = chute;
      chutesDados ++;
}

int jaChutou(char letra){
  int achou = 0;

  for(int j = 0; j < chutesDados; j++){

    if(chutes[j] == letra){

    achou = 1;

    break;
    }
  }
  return achou;
}

void desenhaForca(){

    int erros = chutesErrados();

    printf(" _______        \n");
    printf(" |/     |       \n");
    printf(" |     (_)      \n");
    printf(" |     /|\\   	\n");
    printf(" |      |      	\n");
    printf(" |     / \\   	\n");
    printf(" |              \n");
    printf(" |___           \n");
    printf("\n\n");


  for(int i = 0; i < strlen(palavrasecreta); i++)
    {
      if(jaChutou(palavrasecreta[i]))
        { printf("%c ", palavrasecreta[i]); }
      else
        { printf("_ "); }
    }

    printf("\n");
}

void escolhePalavra(){
  FILE* arquivo;

  // Abrindo arquivo
  arquivo = fopen("palavras.txt", "r");

  if(arquivo == 0){
    printf("\n\nDesculpe, Banco de Dados nao disponivel :(\n\n");

    exit(1);
  }

  // Lendo a primeira linha do arquivo
  int qtdDePalavras;
  fscanf(arquivo, "%d", &qtdDePalavras);

  // Calculando um numero randomico
  srand(time(0));
  int randomico = rand() % qtdDePalavras;

  // Armazenando uma palavra
  for(int i = 0; i <= randomico; i++){
    fscanf(arquivo, "%s", palavrasecreta);
  }

  // Fechando arquivo
  fclose(arquivo);
}

int acertou(){

  for(int i = 0; i < strlen(palavrasecreta); i++){

   if(!jaChutou(palavrasecreta[i])){
      return 0;
    }
  }
  return 1;
}

int chutesErrados(){
    int erros = 0;

    for(int  i = 0; i< chutesDados; i++){
        int existe;

        existe = jaChutou(palavrasecreta[i]);

        if(!existe) erros++;
  }

  return erros;
}

int enforcou(){
  return chutesErrados() >= 6;
}

void adicionaPalavra(){
  char quer;

  divisoria();

  printf("Voce deseja adicionar uma nova palavra no jogo?  (S/N) ");
  scanf(" %c", &quer);

  if(quer == 'S'){
    char novaPalavra[TAMANHO_PALAVRA];

    printf("\n Qual a nova palavra: ");
    scanf("%s", novaPalavra);

    FILE* arquivo;

    arquivo = fopen("palavras.txt", "r+");

    if(arquivo == 0){
      printf("\n\nAcesso indisponivel :(\n\n");
      exit(1);
    }

    // Lendo a quantidade de palavras
    int qtd;
    fscanf(arquivo, "%d", &qtd);
    qtd++;

    // Sobrescrevendo a quantidade de palavras
    fseek(arquivo, 0, SEEK_SET);
    fprintf(arquivo, "%d", qtd);

    // Escrevendo nova palavra na ultima linha do arquivo
    fseek(arquivo, 0, SEEK_END);
    fprintf(arquivo, "\n%s", novaPalavra);

    printf("\n\nPALAVRA ADICIONADA COM SUCESSO !! :D\n");
    printf("Obrigada por jogar! :)\n\n");

    fclose(arquivo);
  }

  else if(quer == 'N'){

    printf("\n");
    printf("Nos vemos na proxima entao ;D\n");
    printf("Obrigada por jogar! :)\n\n");
  }
  else{
    printf("Nao entendi o que quis :(\n");
    printf("Mas vou entender como se voce nao quisesse entao ");
  }

}

int main(){

  abertura();
  escolhePalavra();

  do{

      desenhaForca();
      chuta();

  }while(!acertou() && !enforcou());

  resultado();


  adicionaPalavra();

  return 0;
}
