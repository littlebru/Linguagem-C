// Diretiva de compilação com condição (em tempo de compilação)
#ifndef _UI_H_  // Caso não haja o import do headerfile
#define _UI_H_

#include "mapa.h"

void imprimeMapa(MAPA* m);
void imprimeParte(char desenho[4][7], int parte);


#endif  // Fechando definiçao do ifdef