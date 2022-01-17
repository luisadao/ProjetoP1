#ifndef FUNCOESVACINACAO_H_INCLUDED
#define FUNCOESVACINACAO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estruturas.h"

#include "funcoesMembros.h"

void registarEstadoVacinacao(int quantMembrosComunidade, tipoMembroCAcademica vetorMembrosCAcademica[LIMITE_MAX_MEMBROS]);
void atualizarEstadoVacinacao(int quantMembrosComunidade, tipoMembroCAcademica vetorMembrosCAcademica[LIMITE_MAX_MEMBROS]);
void lerVacinacao(int *quantMembrosComunidade, tipoMembroCAcademica vetorMembrosCAcademica[]);



#endif // FUNCOESVACINACAO_H_INCLUDED
