#ifndef _FOGEFOGE_H_	// Caso não haja o import do headerfile
#define _FOGEFOGE_H_

// Definindo Contantes
#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

// Inicializando funções
int acabou();
void move(char direcao);
int ehDirecao(char direcao);
void moveFantasma();
int praOndeFantasmaVai(int xatual, int yatual, int* xdestino, int* ydestino);
void explodir(int x, int y, int somaX, int somaY, int qtd_vezes);
void explodePilula();
void limpaTela(); 

#endif