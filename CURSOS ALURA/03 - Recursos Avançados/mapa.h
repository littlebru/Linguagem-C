
struct mapa {	// Estrutura do mapa
	char** matriz;
	int linhas;
	int colunas; 
};

typedef struct mapa MAPA;	// Renomeando estrutura de "struct mapa" -> "MAPA"

struct posicao {	// Estrutura de movimentação do personagem
	int x;
	int y;
};

typedef struct posicao POSICAO;	// Renomeando estrutura de "struct posicao" -> POSICAO

// Inicializando funções
void alocaMapa(MAPA* m);
void leMapa(MAPA* m);
void liberaMapa(MAPA* m);
void imprimeMapa(MAPA* m);
void encontraMapa(MAPA* m, POSICAO* p, char c);
int menorQueVetor(MAPA* m, int x, int y);
int ehPontinho(MAPA* m, int x, int y);
int andaNoMapa(MAPA* m, int Xorigem, int Yorigem, int Xdestino, int Ydestino);