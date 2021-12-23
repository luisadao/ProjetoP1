#include "funcoesConfinamento.h"


void registarEstadoConfinamento(int quantMembrosComunidade , tipoMembroCAcademica vetorMembrosCAcademica[LIMITE_MAX_MEMBROS]){

    int numUtenteTemp, posicaoUtente;

    if(quantMembrosComunidade == 0){
        printf("\nERROR - Nao existem membros registados.");
    }
    else{
        numUtenteTemp= lerInteiro("Indique o nr. de utente de quem pretende registar o confinamento : ", MIN_NUM_UTENTE,MAX_NUM_UTENTE);
        posicaoUtente = procuraNumeroSNS(vetorMembrosCAcademica,quantMembrosComunidade,numUtenteTemp);

        if(posicaoUtente != -1){ // encontrou o utente

            printf("\nIndique o tipo de confinamento em que se encontra o utente %s.", vetorMembrosCAcademica[posicaoUtente].nome);
            if(vetorMembrosCAcademica[posicaoUtente].estadoConfinamento == 1 || vetorMembrosCAcademica[posicaoUtente].estadoConfinamento == 2){
                    vetorMembrosCAcademica[posicaoUtente].estadoConfinamento = lerInteiro("Deseja terminar o seu estado de confinamento ", 0, 2);

            }
            vetorMembrosCAcademica[posicaoUtente].estadoConfinamento = lerInteiro("(0 - Nao Confinado , 1 - Quarentena , 2 - Isolamento Profilatico)", 0, 2);

        }else{
            printf("\nERROR - Nao existe utente com o numero %d.", numUtenteTemp);
        }

    }


}
