#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"


MAPA m;
POSICAO heroi;


// Função: finaliza o programa
int acabou() {
	return 0;
}

int ehDirecao(char direcao){
	return direcao == 'a' ||
		direcao == 'w' ||
		direcao == 's' ||
		direcao == 'd';
}

// Função: lê entrada do usuario e move o personagem
void move(char direcao) {

	if(!ehDirecao(direcao))
		return;

	// Armazenando posição atual do personagem
	int proximoX = heroi.x;
	int proximoY = heroi.y;

	// Movimentação do personagem com o comando das teclas WASD
	switch(direcao) {
		
		case 'a':	// esquerda
			proximoY--;
			break;

		case 'w':	// cima
			proximoX--;
			break;

		case 's':	// baixo
			proximoX++;
			break;

		case 'd':	// direita
			proximoY++;
			break;
	}

	if(!menorQueVetor(&m, proximoX, proximoY))
		return;

	if(!ehPontinho(&m, proximoX, proximoY))
		return;

	andaNoMapa(&m, heroi.x, heroi.y, proximoX, proximoY);
	
	// Atualizando posição atual do heroi
	heroi.x = proximoX;
	heroi.y = proximoY;
}

/* ---------------------------------------- */

// Função principal do jogo
int main() {	
	leMapa(&m);
	encontraMapa(&m, &heroi, '@');

	do {
		imprimeMapa(&m);
		
		char comando;
		scanf(" %c", &comando);	// Lendo a entrada do usuário

		move(comando);

	} while (!acabou());
	liberaMapa(&m);
}