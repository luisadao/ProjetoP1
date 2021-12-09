#ifndef FUNCOESMEMBROS_H_INCLUDED
#define FUNCOESMEMBROS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estruturas.h"

#define MINANOVACINA 2019
#define MAXANOVACINA 2021

#define MIN_NUM_UTENTE 1
#define MAX_NUM_UTENTE 5


int procuraNumeroSNS(tipoMembroCAcademica vetorMembrosCAcademica[LIMITE_MAX_MEMBROS], int quantMembrosComunidade, int numSNSProcurar);
void lerEstadoConfinamento(int *quantMembrosComunidade, tipoMembroCAcademica vetorMembrosCAcademica[LIMITE_MAX_MEMBROS]);
void lerVacinacao(int *quantMembrosComunidade, tipoMembroCAcademica vetorMembrosCAcademica[LIMITE_MAX_MEMBROS]);
void adicionarMembro(int *quantMembrosComunidade, int  *quantMembrosVacinados, tipoMembroCAcademica vetorMembrosCAcademica[LIMITE_MAX_MEMBROS]);
void listarDadosComunidade(int quantMembrosComunidade, tipoMembroCAcademica vetorMembrosCAcademica[LIMITE_MAX_MEMBROS]);



#endif // FUNCOESMEMBROS_H_INCLUDED
