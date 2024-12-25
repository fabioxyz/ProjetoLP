#pragma once
#define TMAX 50

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
    char nome[TMAX];
    char NIF[10];
    float valor_total_compras;
    Tipo_de_cliente tipo;
    char dataCriacao[20]; // Armazena a data e hora no formato "dd-mm-yyyy hh:mm"
}TCAutomovel;

void obterDataAtual(char* buffer, size_t tamanho);
int validar_data(int dia, int mes, int ano);
int validar_nome(char* nome);
int verificar_nome_existente(TCAutomovel Cliente[], int totalClientes, char* nome);
int validar_nif(char* nif);
char* imprimir_tipo(Tipo_de_cliente tipo);
int MENU();
int InsereCliente(TCAutomovel Cliente[], int total);
int ListarClientes(TCAutomovel Cliente[], int total);
int MostrarCliente(TCAutomovel Cliente[], char nome[], int total);
int GravarCliente(TCAutomovel Cliente[], int total);
int LerClientes(TCAutomovel Cliente[]);
