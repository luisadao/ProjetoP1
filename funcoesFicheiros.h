#ifndef FUNCOESFICHEIROS_H_INCLUDED
#define FUNCOESFICHEIROS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "funcoesGerais.h"

void gravaFicheiroBinarioComunidade(tipoMembroCAcademica vetorMembrosCAcademica[], int quantMembrosComunidade, int quantMembrosVacinados);
void lerFicheiroBinarioComunidade(tipoMembroCAcademica vetorMembrosCAcademica[], int *quantMembrosComunidade, int *quantMembrosVacinados);
void gravarFicheiroTextoComunidade(tipoMembroCAcademica vetorMembrosCAcademica[], int quantMembrosComunidade, int quantMembrosVacinados);
void gravaFicheiroBinarioTestes(tipoTeste vetorTestes[], int quantTestesAgendados, int quantTestesRealizados);
tipoTeste* lerFicheiroBinarioTestes(tipoTeste vetorTestes[], int *quantTestesAgendados, int *quantTestesRealizados);





#endif // FUNCOESFICHEIROS_H_INCLUDED
