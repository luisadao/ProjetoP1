#ifndef FUNCOESCONFINAMENTO_H_INCLUDED
#define FUNCOESCONFINAMENTO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MINANOCONFINAMENTO 2020
#define MAXANOCONFINAMENTO 2022
#define MINDIASCONFINAMENTO 1
#define MAXDIASCONFINAMENTO 15

#define NAOCONFINADO 0
#define QUARENTENA 1
#define ISOLAMENTOPROFILATICO 2


#include "estruturas.h"
#include "funcoesGerais.h"
#include "funcoesMembros.h"

void registarEstadoConfinamento(int quantMembrosComunidade , tipoMembroCAcademica vetorMembrosCAcademica[LIMITE_MAX_MEMBROS]);
void atualizarEstadoConfinamento(int quantMembrosComunidade, tipoMembroCAcademica vetorMembrosCAcademica[LIMITE_MAX_MEMBROS]);
void listarCasosConfinamento(int quantMembrosComunidade, tipoMembroCAcademica vetorMembrosCAcademica[LIMITE_MAX_MEMBROS]);



#endif // FUNCOESCONFINAMENTO_H_INCLUDED
