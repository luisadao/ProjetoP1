#include "menus.h"

char menuPrincipal(int quantMembrosComunidade, int quantTestesAgendados, int quantMembrosVacinados, int quantTestesRealizados){

    char opcaoP;


    printf("\n\n\t\t\tPROGRAMA REGISTO SITUCAO COVID\n\n");
    printf("\n\t\t\t\tMENU PRINCIPAL\n\n");
    printf("\nMembros da Comunidade : %d\t\t\tTestes Agendados  : %d\n",quantMembrosComunidade ,quantTestesAgendados);
    printf("\nMembros Vacinados : \t%d\t\t\tTestes Realizados : %d\n", quantMembrosVacinados, quantTestesRealizados);
    printf("\n\tOPCOES : \n\n");
    printf("M - Menu Membros\n");
    printf("V - Menu Vacinacao\n");
    printf("C - Menu Confinamento\n");
    printf("T - Menu Testes\n");
    printf("F - Menu Ficheiros\n");
    printf("E - Estatisticas\n\n");
    printf("S - Sair\n\n");

    opcaoP = lerCaracter();

    return opcaoP;

}

char menuMembros(void){

    char opcaoM;

    printf("\n\t\tMENU MEMBROS\n");
    printf("A - Adicionar Novo Membro\n");
    printf("L - Listar Membros da Comunidade\n\n");
    printf("S - Regressar\n");

    opcaoM = lerCaracter();

    return opcaoM;
}

char menuVacinacao(void){

    char opcaoV;

    printf("\n\t\tMENU VACINACAO\n");
    printf("R - Registar Estado Vacina\n");
    printf("A - Atualizar Estado Vacina\n\n");
    printf("S - Regressar\n");

    opcaoV = lerCaracter();

    return opcaoV;
}

char menuConfinamento(void){

    char opcaoC;

    printf("\n\tMENU CONFINAMENTO\n");
    printf("R - Registar Confinamento\n");
    printf("A - Atualizar Confinamento\n");
    printf("L - Listar Casos de Confinamento Ocorridos\n\n");
    printf("S - Regressar\n");

    opcaoC = lerCaracter();

    return opcaoC;
}

char menuTestes(void){

    char opcaoT;

    printf("\n\tMENU TESTES\n");
    printf("A - Agendar um Teste\n");
    printf("L - Listar todos os Testes\n");
    printf("C - Alterar data de um Teste\n");
    printf("R - Registar Resultado de um Teste\n");
    printf("M - Apresentar Dados de um Teste\n\n");
    printf("S - Regressar\n");


    opcaoT = lerCaracter();

    return opcaoT;
}

char menuFicheiros(void){

    char opcaoF;

    printf("\n\tMENU FICHEIROS\n");
    printf("G - Guardar dados num Ficheiro\n");
    printf("L - Ler dados do Ficheiro\n\n");
    printf("S - Regressar\n");

    opcaoF = lerCaracter();

    return opcaoF;
}
