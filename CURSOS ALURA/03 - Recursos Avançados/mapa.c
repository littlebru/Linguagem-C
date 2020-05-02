#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"

void copiaMapa(MAPA* destino, MAPA* origem){
	destino->linhas = origem->linhas;
	destino->colunas = origem->colunas;

	alocaMapa(destino);

	for(int i=0; i< origem->linhas; i++){

		// Copiando o mapa com strcpy()
		strcpy(destino->matriz[i], origem->matriz[i]);
	}
}


// Função: Move personagem no mapa
void andaNoMapa(MAPA* m, int origemX, int origemY,
	int destinoX, int destinoY){

	char personagem = m->matriz[origemX][origemY];

	m->matriz[destinoX][destinoY] = personagem;
	m->matriz[origemX][origemY] = VAZIO;
}

// Função: Verifica se a proxima casa ultrapassa o tamanho do array de linhas e colunas
int ehValida(MAPA* m, int x, int y){
	if(x >= m->linhas)
		return 0;
	if(y >= m->colunas)
		return 0;

	return 1;
}

// Função: Verifica se a proxima casa é vazia ou uma parede
int ehVazia(MAPA* m, int x, int y){
	return m->matriz[x][y] != VAZIO;	
}


// Função: Lê o arquivo onde está estruturado o mapa
void leMapa(MAPA* m) {
	FILE* f;

	// Abrindo arquivo mapa.txt
	f = fopen("mapa.txt", "r");
	
	// Pior caso: Arquivo inexistente ou indisponivel
	if(f == 0) {
		printf("Erro na leitura do mapa");
		exit(1);
	}

	// Lendo quantidade de Linhas e Colunas do mapa
	fscanf(f, "%d %d", &(m->linhas), &(m->colunas));

	// Chamando função alocamapa()
	alocaMapa(m);
	
	// Lendo desenho do mapa
	for(int i = 0; i < m->linhas; i++) {

		fscanf(f, "%s", m->matriz[i]);
	}

	fclose(f);
}

// Função: Reserva espaço de memória para o mapa do jogo
void alocaMapa(MAPA* m) {
	// Alocando dinamicamente o espaço para as linhas do mapa
	m->matriz = malloc(sizeof(char*) * m->linhas);

	for(int i = 0; i < m->linhas; i++) {

		// Alocando dinamicamente o espaço para as colunas do mapa
		m->matriz[i] = malloc(sizeof(char) * m->colunas + 1);
	}
}

// Função: Libera o espaço de memória reservado para o mapa do jogo
void liberaMapa(MAPA* m) {
	// 
	for(int i = 0; i < m->linhas; i++) {
		// Removendo conteudo e espaço da memória reservados para as colunas do mapa
		free(m->matriz[i]);
	}
	// Removendo conteudo e espaço da memória reservados para as linhas do mapa
	free(m->matriz);
}

// Função: Imprime o mapa do jogo
void imprimeMapa(MAPA* m) {
	
	for(int i = 0; i < m->linhas; i++) {
		// Imprimindo o mapa
		printf("%s\n", m->matriz[i]);
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