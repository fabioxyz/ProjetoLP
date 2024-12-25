#include <stdio.h>
#include "head.h"

int main() {
    TCAutomovel cliente[50];
    int e;
    char nome[50];
    int total;

    total = LerClientes(cliente);
    if (total > 0) {
        printf("\n %d Clientes carregados com sucesso.\n\n", total);
    }

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

