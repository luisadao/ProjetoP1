#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

#define LIMITE_MAX_MEMBROS 200
#define LIMITE_MAX_NOME 50
#include "funcoesGerais.h"

typedef struct{

    int codigo;
    int tipoDeTeste; // 1 - Antigenio 2 - PCR
    tipoData dataTeste;
    int numUtenteSaude;
    int resultado; // -1 nao realizado , 1 negativo , 2 positivo
    tipoHora horaColheita;
    int duracaoMinutos;

}tipoTeste; //FIM Estrutura Tipo Teste

typedef struct {

    int numUtenteSaude;
    char nome[LIMITE_MAX_NOME];
    int tipoMembro; // 1 - Estudante 2 - Docente 3 - Técnico
    int anoNascimento;
    int estadoConfinamento;  //(0 - não confinado , 1 - quarentena , 2 - isolamento profilatico)
    int estadoVacina; //0 - Nao Vacinado\n1 - Primeira Dose\n2 - Segunda Dose 3 - Terceira Dose
    tipoData dataUltimaVacina;
    int quantTestesAgendados;
    int quantTestesRealizados;
    tipoTeste testesAgendados[10]; //10 enquanto nao dermos memoria dinamica
    tipoData dataConfinamento;
    int duracaoConfinamentoDias;

}tipoMembroCAcademica; // FIM Estrutura Membro Comunidade Academica




#endif // ESTRUTURAS_H_INCLUDED
