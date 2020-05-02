#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

// Structs do tipo MAPA e POSICAO
MAPA m;
POSICAO heroi;

void moveFantasma(){
	MAPA copia;

	copiaMapa(&copia, &m);

	for(int c_x = 0; c_x < m.linhas; c_x++){
		for(int c_y = 0; c_y < m.colunas; c_y++){

			if(copia.matriz[c_x][c_y] == FANTASMA){
				if(ehValida(&m, c_x, c_y + 1) && ehVazia(&m, c_x, c_y+1)){
					andaNoMapa(&m, c_x, c_y, c_x, c_y + 1);
				}
			}
		}
	}

	liberaMapa(&copia);
}

// Função acabou: finaliza o jogo
int acabou() {
	return 0;
}

int ehDirecao(char direcao){
	// Pior caso: Entrada do usuário é inválida
	return direcao == 'a' ||
	 direcao == 'w' ||
	 direcao == 's' ||
	 direcao == 'd';
}

// Função Move: lê entrada do usuario e move o personagem
void move(char direcao) {
	
	if(!ehDirecao(direcao))
		return;

	// Armazenando posição atual do personagem
	int proximoX = heroi.x;
	int proximoY = heroi.y;

	switch(direcao) {

		case ESQUERDA:
			proximoY--;
			break;
		
		case CIMA:
			proximoX--;
			break;

		case BAIXO:
			proximoX++;
			break;

		case DIREITA:
			proximoY++;
			break;
	}

	// Pior caso: Proxima casa ultrapassa o tamanho do array de linhas e colunas
	if(!ehValida(&m, proximoX, proximoY))
		return;
	
	// Pior caso: Proxima casa é vazia ou uma parede
	if(ehVazia(&m, proximoX, proximoY))
		return;
	
	// Movimentando personagem no mapa
	andaNoMapa(&m, heroi.x, heroi.y, proximoX, proximoY);

	// Atualizando posição atual do personagem
	heroi.x = proximoX;
	heroi.y = proximoY;
}

// Limpa a tela do programa
void limparTela(){
	system("clear || cls");
}

// Função principal do jogo
int main() {
	
	leMapa(&m);
	encontraMapa(&m, &heroi, HEROI);

	do {
		imprimeMapa(&m);
		// Lendo a entrada do usuário
		char comando;
		scanf(" %c", &comando);

		move(comando);
		moveFantasma();

		limparTela();

	} while (!acabou());

	liberaMapa(&m);
}