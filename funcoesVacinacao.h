#ifndef FUNCOESVACINACAO_H_INCLUDED
#define FUNCOESVACINACAO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estruturas.h"
#include "funcoesGerais.h"
#include "funcoesMembros.h"

void registarEstadoVacinacao(int quantMembrosComunidade, tipoMembroCAcademica vetorMembrosCAcademica[LIMITE_MAX_MEMBROS]);
void atualizarEstadoVacinacao(int quantMembrosComunidade, tipoMembroCAcademica vetorMembrosCAcademica[LIMITE_MAX_MEMBROS]);



#endif // FUNCOESVACINACAO_H_INCLUDED
