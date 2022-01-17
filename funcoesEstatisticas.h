#ifndef FUNCOESESTATISTICAS_H_INCLUDED
#define FUNCOESESTATISTICAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estruturas.h"
#include "funcoesGerais.h"
#include "funcoesMembros.h"


void apresentarDadosEstatisticos(tipoMembroCAcademica vetorMembrosCAcademica[], int quantMembrosComunidade,tipoTeste vetorTestes[], int quantTestesAgendados, int quantTestesRealizados);
void escreveDadosEstatMembro(tipoMembroCAcademica membro);



#endif // FUNCOESESTATISTICAS_H_INCLUDED
