#include "lista.h"
#include <stdio.h>

int main() {
    Lista l;
    criar_lista(&l);

    // Verificar se a lista está vazia
    if (lista_vazia(&l)) {
        printf("A lista esta vazia.\n");
    }

    // Inserir elementos na lista
    inserir_elemento(&l, 1, 10);
    inserir_elemento(&l, 2, 20);
    inserir_elemento(&l, 3, 30);

    // Verificar se a lista está cheia após inserção
    if (lista_cheia(&l)) {
        printf("A lista esta cheia.\n");
    }

    // Imprimir a lista após inserção
    imprimir_lista(&l);  // Espera-se a saída: 10 20 30

    // Modificar o segundo elemento
    modificar_elemento(&l, 2, 25);
    imprimir_lista(&l);  // Espera-se a saída: 10 25 30

    // Remover o primeiro elemento
    remover_elemento(&l, 1);
    imprimir_lista(&l);  // Espera-se a saída: 25 30

    // Verificar novamente se a lista está cheia ou vazia
    if (lista_cheia(&l)) {
        printf("A lista esta cheia.\n");
    }
    if (lista_vazia(&l)) {
        printf("A lista esta vazia.\n");
    }

    return 0;
}

