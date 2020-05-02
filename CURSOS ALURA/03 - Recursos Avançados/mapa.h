// Definindo Contantes
#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

// Estrutura do mapa
struct mapa {
	char** matriz;
	int linhas;
	int colunas; 
};

// Renomeando estrutura de "struct mapa" -> "MAPA"
typedef struct mapa MAPA;

// Estrutura de movimentação do personagem
struct posicao {
	int x;
	int y;
};

// Renomeando estrutura de "struct posicao" -> POSICAO
typedef struct posicao POSICAO;

// Inicializando funções
void alocaMapa(MAPA* m);
void copiaMapa(MAPA* destino, MAPA* origem);
void leMapa(MAPA* m);
void liberaMapa(MAPA* m);
void imprimeMapa(MAPA* m);
void encontraMapa(MAPA* m, POSICAO* p, char c);
int ehValida(MAPA* m, int x, int y);
int ehVazia(MAPA* m, int x, int y);
void andaNoMapa(MAPA* m, int origemX, int origemY, int destinoX, int destinoY);
