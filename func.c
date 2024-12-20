#include "head.h"
#include <stdio.h> 
#include <ctype.h>  // Para isdigit()
#define TMAX 50 // maximo tamanho nome

typedef enum {
    Regular = 1,
    Esporadico,
    Ocasional
}Tipo_de_cliente;

typedef struct {
    int dia_registo;
    int mes_registo;
    int ano_registo;
}Data_Registro;

typedef struct {
    int numero_de_cliente;
    char nome[50];
    char NIF[10];
    float valor_total_compras;
    Tipo_de_cliente tipo;
    Data_Registro data;
}TCAutomovel;

int validar_data(int dia, int mes, int ano) {

    int ano_atual = 2024;
    if (ano != ano_atual) {
        return 0;
    }

    if (mes < 1 || mes > 12) {
        return 0;
    }

    int dias_por_mes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        dias_por_mes[1] = 29;
    }

    if (dia < 1 || dia > dias_por_mes[mes - 1]) {
        return 0; 
    }

    return 1;
}

int validar_nome(char *nome) {
    char* pi; int tem = 1;

    for (pi = nome; *pi != '\0'; pi++) {
        if ((*pi >= 'a' && *pi <= 'z') || (*pi >= 'A' && *pi <= 'Z')) {
        }
        else if (*pi == ' ') {
        }
        else {
            tem = 0;
            break;
        }
    }
    return tem;
}

int validar_nif(char* nif) {
    int i;

    if (strlen(nif) != 9) {
        return 0;
    }

    for (i = 0; i < 9; i++) { // nif tem 9 digitos
        if (!isdigit(nif[i]) && !(nif[i] < 0)) {
            return 0;  
        }
    }

    return 1; 
}

char* imprimir_tipo(Tipo_de_cliente tipo) {
    switch (tipo) {
    case Regular:
        return "Regular";
    case Esporadico:
        return "Esporadico";
    case Ocasional:
        return "Ocasional";
    default:
        return "Desconhecido";
    }
}

int MENU() {

    int opcao;

    do {
        printf("\t\tMENU\n");
        printf("[1] Inserir Informacao dos Clientes\n");
        printf("[2] Listar todos os Registos de Clientes inseridos\n");
        printf("[3] Procurar Cliente por Nome\n");
        printf("[4] Procurar Cliente por tipo de Cliente\n");
        printf("[5] Gravar Registos de Clientes no Ficheiro\n");
        printf("[0] Sair\n\n");
        printf(" -> ");
        scanf("%d", &opcao);

        if (opcao == 0) {
            printf("\nA sair..\n");
            break;
        }
        else if (opcao > 5 || opcao < 0) {
            printf("\nEscolha apenas opcoes validas!\n\n");
        }
        getchar();
        
    } while (opcao > 5 || opcao < 0);

    return opcao;
}

int InsereCliente(TCAutomovel Cliente[],int total) {
    int i = total; int certo;

    Cliente[i].numero_de_cliente = i + 1;
    printf("\nNumero de Cliente : %03d\n", Cliente[i].numero_de_cliente);

    do {
        certo = 1;
        printf("Nome : ");
        gets(Cliente[i].nome);
        certo = validar_nome(Cliente[i].nome);

        if (certo == 0) printf("Insira um nome valido (apenas letras e espacos).\n");
    } while (certo != 1);

    //nif
    do {
        printf("NIF : ");
        gets(Cliente[i].NIF);
        certo = validar_nif(Cliente[i].NIF);
        if (certo == 0) printf("Insira um nif valido (9 digitos) e apenas algarismos.\n");
    } while (certo != 1);

    //compras
    do {
        printf("Valor total de compras : ");
        if (scanf("%f", &Cliente[i].valor_total_compras) != 1) {
            printf("Insira uma opcao valida.\n");
        }
        } while (Cliente[i].valor_total_compras < 0);

        // tipo
        do {
            printf("Tipo de Cliente:  1) Regular | 2)Esporadico | 3)Ocasional\n - ");
            if (scanf("%d", &Cliente[i].tipo) != 1) {
                printf("Insira uma opcao valida.\n");
            }
            getchar();
        } while (Cliente[i].tipo < 1 || Cliente[i].tipo > 3);

        // data
        do {
            printf("Data de Registro : ");
            scanf("%d:%d:%d", &Cliente[i].data.dia_registo,
                &Cliente[i].data.mes_registo,
                &Cliente[i].data.ano_registo);
            certo = validar_data(Cliente[i].data.dia_registo,
                Cliente[i].data.mes_registo,
                Cliente[i].data.ano_registo);

            if (certo == 0) printf("Insira uma data valida.\n");
        } while (certo != 1);

        i++;
        printf("\nCliente adicionado com sucesso.\n\n");
        return i;
    }


int ListarClientes(TCAutomovel Cliente[], int total) {
    int i;

    for (i = 0; i < total; i++) {
        printf("\nNumero de Cliente : %03d\n", Cliente[i].numero_de_cliente);
        printf("Nome do Cliente : %s\n", Cliente[i].nome);
        printf("NIF : %s\n", Cliente[i].NIF);
        printf("Valor Total De Compras : %.2f euros\n", Cliente[i].valor_total_compras);
        printf("Tipo De Cliente: %s\n", imprimir_tipo(Cliente[i].tipo));
        printf("Data De Registo: %02d:%02d:%04d\n\n", Cliente[i].data.dia_registo,
            Cliente[i].data.mes_registo,
            Cliente[i].data.ano_registo);
    }
}

int MostrarCliente(TCAutomovel Cliente[], char nome[], int total) {
    int i, encontrou = 0;

    for (i = 0; i < total; i++) {
        if (strstr(Cliente[i].nome, nome) != NULL) { 
            encontrou = 1;
            printf("\n\t----DADOS DO CLIENTE----\n");
            printf("Numero De Cliente: %03d\n", Cliente[i].numero_de_cliente);
            printf("Nome: %s\n", Cliente[i].nome);
            printf("NIF: %s\n", Cliente[i].NIF);
            printf("Valor Total Compras: %.6f\n", Cliente[i].valor_total_compras);
            printf("Tipo De Cliente: %s\n", imprimir_tipo(Cliente[i].tipo));
            printf("Data De Registo: %02d:%02d:%04d", Cliente[i].data.dia_registo,
                Cliente[i].data.mes_registo,
                Cliente[i].data.ano_registo);
            break; 
        }
    }
    if (!encontrou) { 
        printf("\nEsse cliente nao existe\n");
    }
    return 0;
}


int GravarCliente() {
    FILE* fp;


    if ((fp = fopen("clientes.bin", "rb")) == NULL) {
        fp = fopen("clientes.bin", "wb");
        return 2;
    }
    else {
        fclose(fp);
        fp = fopen("clientes.bin", "ab");
        return 3;
    }



    fclose(fp);
    return 0;
}