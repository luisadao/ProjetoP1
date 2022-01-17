#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoesGerais.h"

char menuPrincipal(int quantMembrosComunidade, int quantTestesAgendados, int quantMembrosVacinados, int quantTestesRealizados);
char menuMembros(void);
char menuVacinacao(void);
char menuConfinamento(void);
char menuTestes(void);
char menuFicheiros(void);



#endif // MENUS_H_INCLUDED
