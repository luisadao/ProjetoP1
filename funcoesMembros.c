#include "funcoesMembros.h"



void adicionarMembro(int *quantMembrosComunidade, int  *quantMembrosVacinados, tipoMembroCAcademica vetorMembrosCAcademica[])
{

    char nomeTemp[LIMITE_MAX_NOME];
    int opcaoNovoMembro=NAO, posMembro;

    if((*quantMembrosComunidade) < LIMITE_MAX_MEMBROS)
    {
        do
        {
            opcaoNovoMembro = NAO;

            vetorMembrosCAcademica[(*quantMembrosComunidade)].numUtenteSaude = lerInteiro("\nIntroduza o numero de utente de saude : \n",MIN_NUM_UTENTE,MAX_NUM_UTENTE);
            posMembro = procuraNumeroSNS(vetorMembrosCAcademica, *quantMembrosComunidade, vetorMembrosCAcademica[(*quantMembrosComunidade)].numUtenteSaude);

            if(posMembro != -1)
            {

                printf("\nERROR - Ja existe um membro com esse numero de utente de saude inscrito. \n");
                opcaoNovoMembro = lerInteiro("\nDeseja inserir um numero de utente de saude novo ? (0 - NAO , 1 - SIM)\n",NAO,SIM);
                //CASO NAO ARRANJAR FORMA DE SAIR DA FUNCAO

                if(opcaoNovoMembro == 0)
                {
                    return 1;

                }

            }
            else
            {

                lerString("\nIntroduza o nome do utente : ",vetorMembrosCAcademica[(*quantMembrosComunidade)].nome, LIMITE_MAX_NOME, SIM);
                vetorMembrosCAcademica[(*quantMembrosComunidade)].tipoMembro = lerInteiro("\nIndique o seu tipo de utente : \n1 - Estudante\n2 - Docente\n3 - Técnico\n", 1,3);
                vetorMembrosCAcademica[(*quantMembrosComunidade)].anoNascimento = lerInteiro("\nIntroduza o ano de nascimento : ",MINANONASCIMENTO, MAXANONASCIMENTO);
                lerEstadoConfinamento(quantMembrosComunidade, vetorMembrosCAcademica);
                lerVacinacao(quantMembrosComunidade, vetorMembrosCAcademica);
                if(vetorMembrosCAcademica[(*quantMembrosComunidade)].estadoVacina)  // OU  vetorMembrosCAcademica[(*quantMembrosComunidade)].estadoVacina != 0
                {
                    vetorMembrosCAcademica[(*quantMembrosComunidade)].dataUltimaVacina = lerData("\nIndique a data da ultima dose da vacina administrada : ",MINANOVACINA,MAXANOVACINA);
                    (*quantMembrosVacinados)++;
                }

                (*quantMembrosComunidade)++;

            }

        }
        while(opcaoNovoMembro == SIM);
    }
    else
    {
        printf("\nERRO - A Comunidade chegou ao limite de Membros.\n\n");
    }

}


void lerEstadoConfinamento(int *quantMembrosComunidade, tipoMembroCAcademica vetorMembrosCAcademica[])
{

    vetorMembrosCAcademica[(*quantMembrosComunidade)].estadoConfinamento = lerInteiro("\nIndique o seu estado de confinamento (0 - Nao Confinado , 1 - Quarentena , 2 - Isolamento Profilatico) : ",0,2);
    if(vetorMembrosCAcademica[(*quantMembrosComunidade)].estadoConfinamento == 1 || vetorMembrosCAcademica[(*quantMembrosComunidade)].estadoConfinamento  == 2)
    {
        vetorMembrosCAcademica[(*quantMembrosComunidade)].dataConfinamento = lerData("\nIndique a data em que entrou em confinamento : ",MINANOCONFINAMENTO,MAXANOCONFINAMENTO);
    }

}

void lerVacinacao(int *quantMembrosComunidade, tipoMembroCAcademica vetorMembrosCAcademica[])
{

    vetorMembrosCAcademica[(*quantMembrosComunidade)].estadoVacina = lerInteiro("\nIndique o estado da sua vacinacao :\n0 - Nao Vacinado\n1 - Primeira Dose\n2 - Segunda Dose\n3 - Terceira Dose\n",0,3);

}

int procuraNumeroSNS(tipoMembroCAcademica vetorMembrosCAcademica[], int quantMembrosComunidade, int numSNSProcurar)
{

    int i, posicaoSNS=-1;

    for(i=0; i < quantMembrosComunidade; i++)
    {
        if(vetorMembrosCAcademica[i].numUtenteSaude == numSNSProcurar)
        {
            posicaoSNS=i;
            i=quantMembrosComunidade;
        }
    }

    return posicaoSNS;


}

void listarDadosComunidade(int quantMembrosComunidade, tipoMembroCAcademica vetorMembrosCAcademica[], tipoTeste vetorTestes[], int quantTestesAgendados)
{

    int i, quantTestesRealizadosMembro;

    if(quantMembrosComunidade == 0)
    {
        printf("\nERROR - Nao existem membros na comunidade logo nao ha dados a apresentar.\n");
    }
    else
    {

        for(i=0; i<quantMembrosComunidade; i++)
        {
            printf("\n\nNome : ");
            puts(vetorMembrosCAcademica[i].nome);
            printf("Numero Utente Saude : %d",vetorMembrosCAcademica[i].numUtenteSaude);
            printf("\nTipo de Membro : ");

            switch(vetorMembrosCAcademica[i].tipoMembro)
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

            printf("\nAno de Nascimento : %d", vetorMembrosCAcademica[i].anoNascimento);
            printf("\nEstado de Confinamento : ");

            switch(vetorMembrosCAcademica[i].estadoConfinamento)
            {
            case 0:
                printf("Nao Confinado");
                break;
            case 1:
                printf("Quarentena");
                break;
            case 2:
                printf("Isolamento Profilatico");
                break;
            }

            printf("\nEstado da Vacinacao : ");

            switch(vetorMembrosCAcademica[i].estadoVacina)
            {
            case 0:
                printf("Nao Vacinado");
                break;
            case 1:
                printf("Primeira Dose");
                break;
            case 2:
                printf("Segunda Dose");
                break;
            case 3:
                printf("Terceira Dose");
                break;
            }

            if(vetorMembrosCAcademica[i].estadoVacina)
            {
                printf("\nData Ultima Vacina : ");
                escreverData(vetorMembrosCAcademica[i].dataUltimaVacina);
            }

            printf("\nQuantidade Testes Realizados : %d", vetorMembrosCAcademica[i].quantTestesRealizados);

            if(vetorMembrosCAcademica[i].quantTestesAgendados != 0)
            {
                for(int iTestes=0; iTestes < quantTestesAgendados; iTestes++)
                {


                    if(vetorMembrosCAcademica[i].numUtenteSaude == vetorTestes[iTestes].numUtenteSaude && vetorTestes[iTestes].resultado == -1)
                    {
                        printf("\nTipo de Teste : ");

                        switch(vetorTestes[iTestes].tipoDeTeste)
                        {
                        case 1:
                            printf("Antigenio");
                            break;
                        case 2:
                            printf("PCR");
                            break;
                        }
                        printf("\nData Teste Agendado : ");
                        escreverData(vetorTestes[iTestes].dataTeste);



                    }




                }
            }
        }
    }
}

