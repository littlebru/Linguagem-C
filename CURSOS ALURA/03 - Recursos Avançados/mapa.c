#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

// Função: Move o personagem no mapa
int andaNoMapa(MAPA* m, int Xorigem, int Yorigem, int Xdestino, int Ydestino){
	
	char personagem = m->matriz[Xorigem][Yorigem];

	m->matriz[Xdestino][Ydestino] = personagem;	// Movendo personagem
	m->matriz[Xorigem][Yorigem] = '.';		// Rastro do personagem
}

// Função: valida se posicão não ultrapassa o vetor
int menorQueVetor(MAPA* m, int x, int y){
		if(x >= m->linhas)	// Pior caso: Proxima casa ultrapassa o tamanho do array de linhas
		return 0;

	if(y >= m->colunas)	// Pior caso: Proxima casa ultrapassa o tamanho do array de colunas
		return 0;

	return 1;
}

// Função: Proxima posição é uma parede ou vazia
int ehPontinho(MAPA* m, int x, int y){
	m->matriz[x][y] != '.';
}

// Função: Lê o arquivo onde está estruturado o mapa
void leMapa(MAPA* m) {
	FILE* f;
	f = fopen("mapa.txt", "r");	// Abrindo arquivo do mapa
	
	// Pior caso: Arquivo inexistente ou indisponivel
	if(f == 0) {
		printf("Erro na leitura do mapa");
		exit(1);
	}

	fscanf(f, "%d %d", &(m->linhas), &(m->colunas));	// Lendo quantidade de Linhas e Colunas do mapa
	alocaMapa(m);

	for(int i = 0; i < m->linhas; i++) {
		fscanf(f, "%s", m->matriz[i]);	// Lendo desenho do mapa
	}

	fclose(f);
}

// Função: Reserva espaço de memória para o mapa do jogo
void alocaMapa(MAPA* m) {
	m->matriz = malloc(sizeof(char*) * m->linhas);	// Alocando dinamicamente o espaço para as linhas do mapa

	for(int i = 0; i < m->linhas; i++) {
		m->matriz[i] = malloc(sizeof(char) * m->colunas + 1);	// Alocando dinamicamente o espaço para as colunas do mapa
	}
}

// Função: Libera o espaço de memória reservado para o mapa do jogo
void liberaMapa(MAPA* m) {
	for(int i = 0; i < m->linhas; i++) {
		free(m->matriz[i]);	// Removendo espaço da memória reservados para as colunas
	}

	free(m->matriz);	// Removendo espaço da memória reservados para as linhas
}

// Função: Imprime o mapa do jogo
void imprimeMapa(MAPA* m) {
	for(int i = 0; i < m->linhas; i++) {
		printf("%s\n", m->matriz[i]);	// Imprimindo o mapa
	}
}

// Função: Procura o herói no mapa
void encontraMapa(MAPA* m, POSICAO* p, char c) {
	for(int i = 0; i < m->linhas; i++) {
		for(int j = 0; j < m->colunas; j++) {
			if(m->matriz[i][j] == c) {
				p->x = i;
				p->y = j;
				return;
			}
		}
	}

}