#ifndef FUNCOESTESTES_H_INCLUDED
#define FUNCOESTESTES_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTESTESPCRDIA 2
#define TESTEANTIGENIO 1
#define TESTEPCR 2
#define NEGATIVO 0
#define POSITIVO 1
#define INCONCLUSIVO 2
#define MAXMINUTOSTESTE 15


#include "estruturas.h"
#include "funcoesGerais.h"
#include "funcoesMembros.h"

tipoTeste* agendarTeste(tipoMembroCAcademica vetorMembrosCAcademica[], int quantMembrosComunidade, tipoTeste vetorTestes[],int *quantTestesAgendados, int quantTestesRealizados);
void logTestes(tipoTeste teste, tipoMembroCAcademica membro, char operacao[]);
int procurarTeste(tipoTeste vetorTestes[], int quantTestesAgendados, char designacaoTeste[]);
void registarResultadoTeste(tipoMembroCAcademica vetorMembrosCAcademica[], int quantMembrosComunidade, tipoTeste vetorTestes[],int *quantTestesAgendados, int *quantTestesRealizados);
void listarTestes(tipoTeste vetorTestes[],int quantTestesAgendados, int quantTestesRealizados);
void apresentarDadosTeste(tipoTeste vetorTeste[], int quantTotalTestes, tipoMembroCAcademica vetorMembrosCAcademica[], int quantMembrosCAcademica);
void alterarDataTeste(tipoTeste vetorTeste[], int quantTestesAgendados);


#endif // FUNCOESTESTES_H_INCLUDED
