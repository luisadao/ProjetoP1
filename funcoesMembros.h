#ifndef FUNCOESMEMBROS_H_INCLUDED
#define FUNCOESMEMBROS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estruturas.h"
#include "funcoesConfinamento.h"
#include "funcoesTestes.h"
#include "funcoesVacinacao.h"

#define MINANOVACINA 2019
#define MAXANOVACINA 2022

#define MIN_NUM_UTENTE 1
#define MAX_NUM_UTENTE 9

int procuraNumeroSNS(tipoMembroCAcademica vetorMembrosCAcademica[], int quantMembrosComunidade, int numSNSProcurar);


void adicionarMembro(int *quantMembrosComunidade, int  *quantMembrosVacinados, tipoMembroCAcademica vetorMembrosCAcademica[]);
void listarDadosComunidade(int quantMembrosComunidade, tipoMembroCAcademica vetorMembrosCAcademica[], tipoTeste vetorTestes[], int quantTestesAgendados);



#endif // FUNCOESMEMBROS_H_INCLUDED
