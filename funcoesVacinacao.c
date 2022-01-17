//FUNCOES RELATIVAS AO MENU DA VACINACAO
#include "funcoesVacinacao.h"

void registarEstadoVacinacao(int quantMembrosComunidade, tipoMembroCAcademica vetorMembrosCAcademica[LIMITE_MAX_MEMBROS])
{

    int posicaoNUtente, tempNUtente;
//    char msg[MAXSTRING];

    if(quantMembrosComunidade == 0)
    {
        printf("\nERROR - Nao existem membros na comunidade. \n");

    }
    else
    {
        tempNUtente = lerInteiro("\nInsira o Nº de utente do Membro que pretende registar a vacinacao.",MIN_NUM_UTENTE,MAX_NUM_UTENTE);
        posicaoNUtente = procuraNumeroSNS(vetorMembrosCAcademica, quantMembrosComunidade, tempNUtente);

        if(posicaoNUtente != -1)  //encontrou logo pergunta que dose quer registar
        {
            // sprintf(msg, "\nDeseja registar a primeira dose de vacinacao neste utente %d (0 - NAO , 1 - SIM)", tempNUtente);// CRASHA O PROGRAMA stack spoof//
            vetorMembrosCAcademica[posicaoNUtente].estadoVacina = lerInteiro("\nDeseja registar a primeira dose da vacina ? (0 - NAO , 1 - SIM)",NAO,SIM);
            if(vetorMembrosCAcademica[posicaoNUtente].estadoVacina == 1)
            {
                vetorMembrosCAcademica[posicaoNUtente].dataUltimaVacina = lerData("\nIndique a data em que levou a primeira dose da vacina : ",MINANOVACINA, MAXANOVACINA);
            }

        }
        else
        {
            printf("\nERROR - Nao existe Membro registado com o numero de utente indicado.");
        }

    }

}

void atualizarEstadoVacinacao(int quantMembrosComunidade, tipoMembroCAcademica vetorMembrosCAcademica[LIMITE_MAX_MEMBROS])
{

    int posicaoNUtente, tempNUtente, confirmacao3Dose=0;
  // char msg[MAXSTRING];

    if(quantMembrosComunidade == 0)
    {
        printf("\nERROR - Nao existem membros na comunidade. \n");

    }
    else
    {
        tempNUtente = lerInteiro("\nInsira o Nº de utente do Membro que pretende atualizar a vacinacao.",MIN_NUM_UTENTE,MAX_NUM_UTENTE);
        posicaoNUtente = procuraNumeroSNS(vetorMembrosCAcademica, quantMembrosComunidade, tempNUtente);

        if(posicaoNUtente != -1)  //encontrou logo pergunta que dose quer registar
        {
            //sprintf(msg, "\nDeseja registar a primeira dose de vacinacao neste utente %d ", tempNUtente); //CRASHA O PROGRAMA

            if(vetorMembrosCAcademica[posicaoNUtente].estadoVacina == 0)
            {
                printf("\nAviso - Antes de atualizar a sua vacinacao necessita primeiro de registar a mesma.\n");
                vetorMembrosCAcademica[posicaoNUtente].estadoVacina = lerInteiro("\nDeseja registar a primeira dose agora ? (0 - NAO , 1 - SIM)",NAO,SIM);
                if(vetorMembrosCAcademica[posicaoNUtente].estadoVacina)
                {
                    vetorMembrosCAcademica[posicaoNUtente].dataUltimaVacina = lerData("\nIndique a data em que lhe foi administrada a primeira dose da vacina : ",MINANOVACINA, MAXANOVACINA);
                }

            }
            else
            {
                switch(vetorMembrosCAcademica[posicaoNUtente].estadoVacina)
                {
                case 1:
                    vetorMembrosCAcademica[posicaoNUtente].estadoVacina = lerInteiro("\nQual a ultima dose que lhe foi adminastrada ? (2 - Segunda Dose , 3 - Terceira Dose)",2,3);
                    if(vetorMembrosCAcademica[posicaoNUtente].estadoVacina == 2 || vetorMembrosCAcademica[posicaoNUtente].estadoVacina == 3)
                    {
                        printf("\nIndique a data em que lhe foi administrada a %d dose da vacina : ",vetorMembrosCAcademica[posicaoNUtente].estadoVacina );
                        vetorMembrosCAcademica[posicaoNUtente].dataUltimaVacina = lerData("",MINANOVACINA, MAXANOVACINA);
                    }
                    break;
                case 2:

                    confirmacao3Dose = lerInteiro("\nJá lhe foi administrada a terceira dose ? (0 - NAO , 1 - SIM)",0,1);
                    if(confirmacao3Dose)
                    {
                        vetorMembrosCAcademica[posicaoNUtente].estadoVacina = 3;
                        vetorMembrosCAcademica[posicaoNUtente].dataUltimaVacina = lerData("\nIndique a data em que levou a terceira dose da vacina : ",MINANOVACINA, MAXANOVACINA);
                    }

                    break;
                case 3:
                    printf("\nAviso - O membro indicado ja tem as 3 doses.\n");
                    break;


                }

            }

        }
        else
        {
            printf("\nERROR - Nao existe Membro registado com o numero de utente indicado.");
        }

    }


}

void lerVacinacao(int *quantMembrosComunidade, tipoMembroCAcademica vetorMembrosCAcademica[])
{

    vetorMembrosCAcademica[(*quantMembrosComunidade)].estadoVacina = lerInteiro("\nIndique o estado da sua vacinacao :\n0 - Nao Vacinado\n1 - Primeira Dose\n2 - Segunda Dose\n3 - Terceira Dose\n",0,3);

}
