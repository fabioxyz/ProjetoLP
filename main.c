#include <stdio.h>

typedef enum {
    Regular = 1,
    Esporadico,
    Ocasional
}Tipo_de_cliente;

typedef struct {
    int numero_de_cliente;
    char nome[50];
    char NIF[10];//nif tem 9 numeros e o \0 no final
    float valor_total_compras;
    Tipo_de_cliente tipo;
    char data_de_registo[50];
}TCAutomovel;

int main() {
    TCAutomovel cliente[50];
    int e;
    char nome[50];
    int total;

    total = LerClientes(cliente);
    printf("Carregados : %d", total);

    while (1) {
        e = MENU();
        switch (e)
        {
        case 0: return 0;
        case 1:
            total = InsereCliente(cliente, total);
            break;
        case 2: 
            if (total == 0) {
                printf("\nNao existem clientes guardados.\n\n");
                break;
            }
            ListarClientes(cliente, total);
            break;
        case 3:
            if (total == 0) {
                printf("\nNao existem clientes guardados.\n\n");
                break;
            }
            else {
                printf("Digite o nome do Cliente : ");
                gets(nome);
                MostrarCliente(cliente, nome, total);
            }
            break;
            // falta o case 4 procurar por tipo
        case 5:
            if (total == 0) {
                printf("\nNao existem clientes guardados.\n\n");
                break;
            }
            else {
                GravarCliente(cliente, total);
            }
            break;
        default:
            break;
        }
    }


	return 0;
}

