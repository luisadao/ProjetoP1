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
    int quantMembrosComunidade = 0, quantTestesAgendados = 0, quantMembrosVacinados = 0, quantTestesRealizados = 0, quantTotalTestes=0;
    tipoMembroCAcademica vetorMembrosCAcademica[LIMITE_MAX_MEMBROS];
    tipoTeste vetorTestes[20];



    do
    {
        opcaoPrincipal = menuPrincipal(quantMembrosComunidade, quantTestesAgendados, quantMembrosVacinados, quantTestesRealizados);

        switch(opcaoPrincipal)
        {

        case 'A':
            adicionarMembro(&quantMembrosComunidade, &quantMembrosVacinados,vetorMembrosCAcademica);
            break;
        case 'L':
            listarDadosComunidade(quantMembrosComunidade, vetorMembrosCAcademica,vetorTestes,quantTestesAgendados);
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
            do  //MENU TESTES
            {
                quantTotalTestes = quantTestesAgendados + quantTestesRealizados;

                opcaoSecundaria = menuTestes();

                switch(opcaoSecundaria)
                {
                case 'L':
                    listarTestes(vetorTestes, quantTotalTestes);
                    break;
                case 'A':
                    agendarTeste(vetorMembrosCAcademica,  quantMembrosComunidade, vetorTestes, &quantTestesAgendados);
                    break;
                case 'C':
                    alterarDataTeste(vetorTestes,  quantTestesAgendados);
                    break;
                case 'R':
                    registarResultadoTeste(vetorMembrosCAcademica, quantMembrosComunidade, vetorTestes, &quantTestesAgendados, &quantTestesRealizados);
                    break;
                case 'M':
                    apresentarDadosTeste( vetorTestes,  quantTotalTestes,  vetorMembrosCAcademica,  quantMembrosComunidade);
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
                    gravaFicheiroBinarioComunidade(vetorMembrosCAcademica, quantMembrosComunidade,quantMembrosVacinados);
                    gravarFicheiroTextoComunidade(vetorMembrosCAcademica, quantMembrosComunidade,quantMembrosVacinados);
                    gravaFicheiroBinarioTestes(vetorTestes,quantTestesAgendados,quantTestesRealizados);

                    break;
                case 'L':
                    lerFicheiroBinarioComunidade(vetorMembrosCAcademica, &quantMembrosComunidade,&quantMembrosVacinados);
                    lerFicheiroBinarioTestes(vetorTestes, &quantTestesAgendados, &quantTestesRealizados);

                    break;
                default:
                    printf("\nERRO - OPCAO INVALIDA\n");

                }
            }
            while(opcaoSecundaria != 'S');


            break;

        case 'S':

            break;

        default:
            printf("\nERRO - OPCAO INVALIDA\n");
        }

    }
    while(opcaoPrincipal != 'S');

    return 0;
}
