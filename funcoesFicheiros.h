#ifndef FUNCOESFICHEIROS_H_INCLUDED
#define FUNCOESFICHEIROS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estruturas.h"
#include "funcoesGerais.h"

void gravaFicheiroBinario(tipoMembroCAcademica vetorMembrosCAcademica[], int quantMembrosComunidade);
void lerFicheiroBinario(tipoMembroCAcademica vetorMembrosCAcademica[], int *quantMembrosComunidade);
void gravarFicheiroTexto(tipoMembroCAcademica vetorMembrosCAcademica[], int quantMembrosComunidade);




#endif // FUNCOESFICHEIROS_H_INCLUDED
