#include "funcoesFicheiros.h"

void gravaFicheiroBinarioComunidade(tipoMembroCAcademica vetorMembrosCAcademica[], int quantMembrosComunidade, int quantMembrosVacinados)
{

    FILE  *ficheiro;
    int controlo;

    if(quantMembrosComunidade == 0)
    {
        printf("ERRO - nao existem dados a guardar\n");
    }
    else
    {

        ficheiro = fopen("dadosComunidade.bin", "wb");

        if (ficheiro == NULL)
        {

            printf("\nERRO : falha na abertura do ficheiro!\n");
        }
        else
        {
            controlo = fwrite(&quantMembrosComunidade, sizeof(int), 1, ficheiro);

            if(controlo != 1)
            {
                printf("\nERRO (1): Falha na escrita dos dados\n");
            }
            else
            {
                controlo = fwrite(&quantMembrosVacinados, sizeof(int), 1, ficheiro);
                if(controlo != 1)
                {
                    printf("\nERRO (2): Falha na escrita dos dados\n");

                }
                else
                {

                    controlo = fwrite(vetorMembrosCAcademica, sizeof(tipoMembroCAcademica), quantMembrosComunidade, ficheiro);

                    if(controlo != quantMembrosComunidade)
                    {
                        printf("\nERRO (3): Falha na escrita dos dados\n");
                    }
                    else
                    {
                        printf("\nGravacao dos dados efetuada com SUCESSO!\n");
                    }
                }
            }

            fclose(ficheiro);
        }

    }

}


void lerFicheiroBinarioComunidade(tipoMembroCAcademica vetorMembrosCAcademica[], int *quantMembrosComunidade, int *quantMembrosVacinados)
{

    FILE  *ficheiro;
    int controlo;

    ficheiro = fopen("dadosComunidade.bin", "rb");

    if (ficheiro == NULL)
    {
        printf("\nERRO : falha na abertura do ficheiro!\n");
    }
    else
    {
        //controlo = fread(&*quantMembrosComunidade
        controlo = fread(quantMembrosComunidade, sizeof(int), 1, ficheiro);

        if(controlo != 1)
        {
            printf("\nERRO (1): Falha na leitura dos dados\n");
        }
        else
        {
            controlo = fread(quantMembrosVacinados, sizeof(int), 1, ficheiro);

            if(controlo != 1)
            {
                printf("\nERRO (2): Falha na leitura dos dados\n");

            }
            else
            {


                controlo = fread(vetorMembrosCAcademica, sizeof(tipoMembroCAcademica), *quantMembrosComunidade, ficheiro);

                if(controlo != *quantMembrosComunidade)
                {
                    printf("\nERRO (3): Falha na leitura dos dados\n");
                    *quantMembrosComunidade = 0;
                }
                else
                {
                    printf("\nLeitura dos dados efetuada com SUCESSO!\n");
                }
            }
        }

        fclose(ficheiro);
    }

}


void gravarFicheiroTextoComunidade(tipoMembroCAcademica vetorMembrosCAcademica[], int quantMembrosComunidade, int quantMembrosVacinados)
{
    int i;

    FILE *ficheiro;

    ficheiro = fopen("dadosComunidade.txt", "w");

    if(ficheiro == NULL)
    {
        printf("\nErro - falha na abertura do ficheiro\n");
    }
    else
    {

        for (i=0; i < quantMembrosComunidade; i++)
        {
            fprintf(ficheiro,"\n\nMembro (%d)\n", i+1);
            fprintf(ficheiro,"Nr.Utente: %d - Nome: %s\n", vetorMembrosCAcademica[i].numUtenteSaude, vetorMembrosCAcademica[i].nome);
            if (vetorMembrosCAcademica[i].estadoVacina == 0)
            {
                fprintf(ficheiro,"Membro Nao Vacinado");
            }
            else
            {
                fprintf(ficheiro,"Estado Vacina : %d Dose\t\t", vetorMembrosCAcademica[i].estadoVacina);
                fprintf(ficheiro,"Data Avaliacao: %d - %d - %d", vetorMembrosCAcademica[i].dataUltimaVacina.dia,vetorMembrosCAcademica[i].dataUltimaVacina.mes,vetorMembrosCAcademica[i].dataUltimaVacina.ano);

            }
            fprintf(ficheiro,"\n_________________________________________________\n");
        }

        fprintf(ficheiro, "\nTotal de Membros Vacinados : %d",quantMembrosVacinados);

        fclose(ficheiro);
    }
}


void gravaFicheiroBinarioTestes(tipoTeste vetorTestes[], int quantTestesAgendados, int quantTestesRealizados)
{

    int quantTotalTestes=0;

    FILE  *ficheiro;
    int controlo;

    if(quantTestesAgendados == 0 && quantTestesRealizados == 0)
    {
        printf("ERRO - nao existem dados dos testes a guardar\n");
    }
    else
    {

        ficheiro = fopen("dadosTestes.bin", "wb");

        if (ficheiro == NULL)
        {

            printf("\nERRO : falha na abertura do ficheiro!\n");
        }
        else
        {
            controlo = fwrite(&quantTestesAgendados, sizeof(int), 1, ficheiro);

            if(controlo != 1)
            {
                printf("\nERRO (1): Falha na escrita dos dados\n");
            }
            else
            {
                controlo = fwrite(&quantTestesRealizados, sizeof(int), 1, ficheiro);
                if(controlo != 1)
                {
                    printf("\nERRO (2): Falha na escrita dos dados\n");

                }
                else
                {

                    quantTotalTestes = quantTestesRealizados+quantTestesAgendados;

                    controlo = fwrite(vetorTestes, sizeof(tipoTeste), quantTotalTestes, ficheiro);

                    if(controlo != quantTotalTestes)
                    {
                        printf("\nERRO (3): Falha na escrita dos dados\n");
                    }
                    else
                    {
                        printf("\nGravacao dos dados efetuada com SUCESSO!\n");
                    }


                }

            }

            fclose(ficheiro);
        }

    }

}

tipoTeste* lerFicheiroBinarioTestes(tipoTeste vetorTestes[], int *quantTestesAgendados, int *quantTestesRealizados)
{

    int quantTotalTestes = 0;

    FILE  *ficheiro;
    int controlo;

    ficheiro = fopen("dadosTestes.bin", "rb");

    if (ficheiro == NULL)
    {
        printf("\nERRO : falha na abertura do ficheiro!\n");
    }
    else
    {
        controlo = fread(quantTestesAgendados, sizeof(int), 1, ficheiro);

        if(controlo != 1)
        {
            printf("\nERRO (1): Falha na leitura dos dados\n");
        }
        else
        {

            controlo = fread(quantTestesRealizados, sizeof(int), 1, ficheiro);

            if(controlo != 1)
            {
                printf("\nERRO (2): Falha na leitura dos dados\n");
            }
            else
            {
                quantTotalTestes = *quantTestesRealizados+*quantTestesAgendados;

                vetorTestes = realloc(vetorTestes, (quantTotalTestes)*sizeof(tipoTeste));
                if(vetorTestes == NULL && quantTotalTestes != 0)
                {
                    printf("\nERRO : Ocorreu um erro durante a alocacao de memoria.\n");
                    *quantTestesRealizados=0;
                    *quantTestesAgendados=0;
                }
                else
                {

                    controlo = fread(vetorTestes, sizeof(tipoTeste), quantTotalTestes, ficheiro); // controlo = fread(vetorTestes, sizeof(tipoTeste), (quantTestesRealizados+quantTestesAgendados), ficheiro);

                   if(controlo != quantTotalTestes)
                    {
                        printf("\nERRO (3): Falha na leitura dos dados\n");
                    }
                    else
                    {
                        printf("\nLeitura dos dados efetuada com SUCESSO!\n");
                   }
                }
            }
        }

        fclose(ficheiro);
    }
    return vetorTestes;
}


