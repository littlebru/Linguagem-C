#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "fogefoge.h"
#include "mapa.h"
#include "ui.h"

MAPA m;
POSICAO heroi;
int temPilula = 0;


int acabou() {
	POSICAO p;

	int encontrouHeroi = encontraMapa(&m, &p, HEROI);

	return !encontrouHeroi;
}

int ehDirecao(char direcao) {
	return
		direcao == ESQUERDA || 
		direcao == CIMA ||
		direcao == BAIXO ||
		direcao == DIREITA;
}

void move(char direcao) {

	if(!ehDirecao(direcao))	
		return;

	int proximox = heroi.x;
	int proximoy = heroi.y;

	switch(direcao) {
		
		case ESQUERDA:
			proximoy--;
			break;

		case CIMA:
			proximox--;
			break;

		case BAIXO:
			proximox++;
			break;

		case DIREITA:
			proximoy++;
			break;
	}

	if(!podeAndar(&m, HEROI, proximox, proximoy))
		return;

	if(ehPersonagem(&m, PILULA, proximox, proximoy)){
		temPilula = 1;
	}

	andaNoMapa(&m, heroi.x, heroi.y, proximox, proximoy);
	heroi.x = proximox;
	heroi.y = proximoy;
}

int praOndeFantasmaVai(int xatual, int yatual, 
	int* xdestino, int* ydestino) {

	int opcoes[4][2] = { 
		{ xatual   , yatual+1 }, 
		{ xatual+1 , yatual   },  
		{ xatual   , yatual-1 }, 
		{ xatual-1 , yatual   }
	};

	srand(time(0));

	for(int i = 0; i < 10; i++) {
		int posicao = rand() % 4;

		if(podeAndar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])) {
			*xdestino = opcoes[posicao][0];
			*ydestino = opcoes[posicao][1];
			return 1;
		}
	}

	return 0;
}

void moveFantasma() {
	MAPA copia;

	copiaMapa(&copia, &m);

	for(int i = 0; i < copia.linhas; i++) {
		for(int j = 0; j < copia.colunas; j++) {
			if(copia.matriz[i][j] == FANTASMA) {

				int xdestino;
				int ydestino;

				int encontrou = praOndeFantasmaVai(i, j, &xdestino, &ydestino);

				if(encontrou) {
					andaNoMapa(&m, i, j, xdestino, ydestino);
				}
			}
		}
	}

	liberaMapa(&copia);
}

void explodePilula(){

	if(!temPilula)return;

	explodir(heroi.x, heroi.y, 0, 1, 3);	// Explodindo lado esquerdo
	explodir(heroi.x, heroi.y, 0, -1, 3);	// Explodindo lado direito
	explodir(heroi.x, heroi.y, 1, 0, 3);	// Explodindo parte de baixo
	explodir(heroi.x, heroi.y, -1, 0, 3);	// Explodindo parte de cima

	temPilula--;
}

void explodir(int x, int y, int somaX, int somaY, int qtd_vezes){

	if(qtd_vezes == 0) return;

	int novoX = x + somaX;
	int novoY = y + somaY; 

	if(!ehValida(&m, novoX, novoY)) return;
	if(ehParede(&m, novoX, novoY)) return;
	
	m.matriz[novoX][novoY] = VAZIO;
	explodir(novoX, novoY, somaX, somaY, qtd_vezes - 1);
}

void limpaTela(){
	system("cls || clear");
}

int main() {
	
	leMapa(&m);
	encontraMapa(&m, &heroi, HEROI);

	do {
		printf("Tem pilula: %s\n", (temPilula ? "SIM" : "NAO"));
		imprimeMapa(&m);

		char comando;
		scanf(" %c", &comando);

		move(comando);

		if(comando == BOMBA) explodePilula();

		moveFantasma();

		limpaTela();
	} while (!acabou());

	liberaMapa(&m);
}