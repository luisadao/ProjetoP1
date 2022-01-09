#ifndef FUNCOESGERAIS_H_INCLUDED
#define FUNCOESGERAIS_H_INCLUDED

#define SIM 1
#define NAO 0

#define MINANONASCIMENTO 1910
#define MAXANONASCIMENTO 2004
#define MINANO 2020
#define MAXANO 2022

#define MAXHORAS 23

#define MINMINUTOS 0
#define MAXMINUTOS 59



#define MAXSTRING 50

typedef struct
{
    int dia, mes, ano;
} tipoData;

typedef struct{

    int hora, minutos;

}tipoHora;


char lerCaracter(void);
void limpaBuffer(void);
int lerInteiro (char msg[] ,int limMin, int limMax);
void lerString(char msg[], char texto[], int tamanho, int obrigatorio);
tipoData lerData(char msg[], int minAno, int maxAno);
void escreverData(tipoData data);
int comparaData(tipoData data1, tipoData data2);
tipoHora lerHora(char msg[], int MINHORA, int MAXHORA);
void escreverHoras(tipoHora hora);


#endif // FUNCOESGERAIS_H_INCLUDED
