#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estruturas.h"
#include "menus.h"
#include "funcoesGerais.h"
#include "funcoesMembros.h"
#include "funcoesVacinacao.h"
#include "funcoesConfinamento.h"
#include "funcoesFicheiros.h"
#include "funcoesTestes.h"


int main()
{
    char opcaoPrincipal, opcaoSecundaria;
    int quantMembrosComunidade = 0, quantTestesAgendados = 0, quantMembrosVacinados = 0, quantTestesRealizados = 0;
    tipoMembroCAcademica vetorMembrosCAcademica[LIMITE_MAX_MEMBROS];



    do
    {
        opcaoPrincipal = menuPrincipal(quantMembrosComunidade, quantTestesAgendados, quantMembrosVacinados, quantTestesRealizados);

        switch(opcaoPrincipal)
        {

        case 'A':
            adicionarMembro(&quantMembrosComunidade, &quantMembrosVacinados,vetorMembrosCAcademica);
            break;
        case 'L':
            listarDadosComunidade(quantMembrosComunidade, vetorMembrosCAcademica);
            break;
        case 'V':   //MENU VACINACAO
            do
            {
                opcaoSecundaria = menuVacinacao();

                switch(opcaoSecundaria)
                {
                case 'R':
                    registarEstadoVacinacao(quantMembrosComunidade, vetorMembrosCAcademica);
                    break;
                case 'A':
                    atualizarEstadoVacinacao(quantMembrosComunidade, vetorMembrosCAcademica);
                    break;
                default:
                    printf("\nERRO - OPCAO INVALIDA\n");

                }

            }
            while(opcaoSecundaria != 'S');
            break;
        case 'C':   //MENU CONFINAMENTO
            do
            {
                opcaoSecundaria = menuConfinamento();
                switch(opcaoSecundaria)
                {
                case 'R':
                    registarEstadoConfinamento(quantMembrosComunidade, vetorMembrosCAcademica);
                    break;
                case 'A':
                    atualizarEstadoConfinamento( quantMembrosComunidade,  vetorMembrosCAcademica);
                    break;
                case 'L':
                    listarCasosConfinamento(quantMembrosComunidade, vetorMembrosCAcademica);
                    break;
                default:
                    printf("\nERRO - OPCAO INVALIDA\n");

                }
            }
            while(opcaoSecundaria != 'S');
            break;
        case 'T':
            do
            {
                opcaoSecundaria = menuTestes();
                switch(opcaoSecundaria)
                {
                case 'R':
                    break;
                case 'A':
                    break;
                default:
                    printf("\nERRO - OPCAO INVALIDA\n");

                }
            }
            while(opcaoSecundaria != 'S');
            break;


        case 'F':
            do
            {
                opcaoSecundaria = menuFicheiros();
                switch(opcaoSecundaria)
                {
                case 'G':
                    gravaFicheiroBinario(vetorMembrosCAcademica, quantMembrosComunidade);
                    gravarFicheiroTexto(vetorMembrosCAcademica, quantMembrosComunidade);
                    break;
                case 'L':
                    lerFicheiroBinario(vetorMembrosCAcademica, &quantMembrosComunidade);
                    break;
                default:
                    printf("\nERRO - OPCAO INVALIDA\n");

                }
            }
            while(opcaoSecundaria != 'S');


            break;

        case 'S':
            for(int i=0; i<quantMembrosComunidade; i++)
            {
                printf("\n\nSAIDA NUMERO DE SAUDE DO UTENTE %d\nNOME %s",vetorMembrosCAcademica[i].numUtenteSaude, vetorMembrosCAcademica[i].nome );
            }
            break;

        default:
            printf("\nERRO - OPCAO INVALIDA\n");
        }

    }
    while(opcaoPrincipal != 'S');

    return 0;
}
