#include "funcoesEstatisticas.h"

void apresentarDadosEstatisticos(tipoMembroCAcademica vetorMembrosCAcademica[], int quantMembrosComunidade,tipoTeste vetorTestes[], int quantTestesAgendados, int quantTestesRealizados)
{
    int i=0, quantTipoMembrosEstudantes=0, quantTipoMembrosDocentes=0, quantTipoMembrosTecnicos=0, quantMenorTestesRealizados=0, quantTotalTestes=0;
    int tempoMedioTestes=0, datasIguais=0;
    float percTestesInconclusivos;
    tipoTeste testeMaisRecenteRealizado;

    if(quantMembrosComunidade == 0)
    {
        printf("\nERRO : Nao existem membros registados na comunidade.\n");
    }
    else
    {
        printf("\n\n\t\t-------------- Dados Estatisticos --------------\n\n");
        quantMenorTestesRealizados = vetorMembrosCAcademica[0].quantTestesRealizados;
        quantTotalTestes = quantTestesAgendados + quantTestesRealizados;

        for(i=0; i < quantMembrosComunidade ; i++)
        {
            if(vetorMembrosCAcademica[i].quantTestesRealizados < quantMenorTestesRealizados)
            {
                quantMenorTestesRealizados = vetorMembrosCAcademica[i].quantTestesRealizados;
            }

            switch(vetorMembrosCAcademica[i].tipoMembro)
            {
            case 1:
                quantTipoMembrosEstudantes++;
                break;
            case 2:
                quantTipoMembrosDocentes++;
                break;
            case 3:
                quantTipoMembrosTecnicos++;
                break;

            }

        }
        printf("\nQuantidade de Estudantes na Comunidade Academica : %d", quantTipoMembrosEstudantes);
        printf("\nQuantidade de Docentes na Comunidade Academica : %d", quantTipoMembrosDocentes);
        printf("\nQuantidade de Tecnicos na Comunidade Academica : %d", quantTipoMembrosTecnicos);

        if(quantTestesRealizados != 0)
        {
            testeMaisRecenteRealizado= vetorTestes[0];

            for(i=0; i < quantTotalTestes ; i++)
            {
                printf("\n\n");
                escreverData(vetorTestes[i].dataTeste);
                printf("\n\n");
                if(vetorTestes[i].resultado != -1)
                {
                    tempoMedioTestes = tempoMedioTestes + vetorTestes[i].duracaoMinutos;


                    if(testeMaisRecenteRealizado.dataTeste.ano > vetorTestes[i].dataTeste.ano) // se o ano foi maior , escusa de fazer o resto das verificacoes
                    {
                         if(testeMaisRecenteRealizado.dataTeste.mes > vetorTestes[i].dataTeste.mes){

                         }
                        if(testeMaisRecenteRealizado.dataTeste.mes == vetorTestes[i].dataTeste.mes)
                        {
                            if(testeMaisRecenteRealizado.dataTeste.dia >= vetorTestes[i].dataTeste.dia){

                            }else{
                                testeMaisRecenteRealizado = vetorTestes[i];
                            }

                        }
                    }else if(testeMaisRecenteRealizado.dataTeste.ano == vetorTestes[i].dataTeste.ano)
                    {
                        if(testeMaisRecenteRealizado.dataTeste.mes >= vetorTestes[i].dataTeste.mes)
                        {

                        }else{
                            testeMaisRecenteRealizado = vetorTestes[i];

                        }

                            if(testeMaisRecenteRealizado.dataTeste.dia >= vetorTestes[i].dataTeste.dia){

                            }else{
                                testeMaisRecenteRealizado = vetorTestes[i];
                        }

                    }

                }
                if(vetorTestes[i].resultado == 2)
                {
                    percTestesInconclusivos++;
                }

            }

            tempoMedioTestes = tempoMedioTestes / quantTestesRealizados;
            percTestesInconclusivos = percTestesInconclusivos / quantTestesRealizados *100 ;
            printf("\nTempo medio de duracao de um Teste : %d minutos", tempoMedioTestes);
            printf("\nPercentagem de Testes Inconclusivos : %.2f", percTestesInconclusivos);
            printf("\nULTIMO(S) TESTE REALIZADO : \n");
            for(i=0;i<quantTotalTestes;i++){
                            datasIguais = comparaData((vetorTestes[i].dataTeste),(testeMaisRecenteRealizado.dataTeste));
                    if(vetorTestes[i].resultado != -1 && datasIguais == 1)
                {
                    printf("\nDesignacao  : %s \n data : ",vetorTestes[i].designacaoTeste);
                    escreverData(vetorTestes[i].dataTeste);
                }

            }

        }

        printf("\n\nMembros com menor quantidade de testes realizados :\n");
        for(i=0; i < quantMembrosComunidade ; i++)
        {
            if(vetorMembrosCAcademica[i].quantTestesRealizados == quantMenorTestesRealizados)
            {
                escreveDadosEstatMembro(vetorMembrosCAcademica[i]);
            }
        }
    }
}

void escreveDadosEstatMembro(tipoMembroCAcademica membro)
{

    printf("\nNome : %s", membro.nome);
    printf("\nNumero Utente : %d", membro.numUtenteSaude);
    printf("\nTipo de Membro : ");
    switch(membro.tipoMembro)
    {
    case 1:
        printf("Estudante");
        break;
    case 2:
        printf("Docente");
        break;
    case 3:
        printf("Tecnico");
        break;
    }
    printf("\nQuantidade Testes Realizados : %d",membro.quantTestesRealizados);
}

