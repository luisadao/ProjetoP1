#ifndef FUNCOESTESTES_H_INCLUDED
#define FUNCOESTESTES_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTESTESPCRDIA 15
#define TESTEANTIGENIO 1
#define TESTEPCR 2
#define NEGATIVO 0
#define POSITIVO 1
#define INCONCLUSIVO 2
#define MAXMINUTOSTESTE 15


#include "estruturas.h"
#include "funcoesMembros.h"

void agendarTeste(tipoMembroCAcademica vetorMembrosCAcademica[], int quantMembrosComunidade, tipoTeste vetorTestes[],int *quantTestesAgendados);
void logTestes(tipoTeste teste, tipoMembroCAcademica membro, char operacao[]);
int procurarTeste(tipoTeste vetorTestes[], int quantTestesAgendados, int codigo);
void registarResultadoTeste(tipoMembroCAcademica vetorMembrosCAcademica[], int quantMembrosComunidade, tipoTeste vetorTestes[],int *quantTestesAgendados, int *quantTestesRealizados);


#endif // FUNCOESTESTES_H_INCLUDED
