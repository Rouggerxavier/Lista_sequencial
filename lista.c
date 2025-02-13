#include "lista.h"
#include <stdio.h>

// Criar lista vazia
void criar_lista(Lista *l) {
    l->tamanho = 0;
}

// Verificar se a lista está vazia
int lista_vazia(Lista *l) {
    return l->tamanho == 0;
}

// Verificar se a lista está cheia
int lista_cheia(Lista *l) {
    return l->tamanho == MAX;
}

// Obter o tamanho da lista
int obter_tamanho(Lista *l) {
    return l->tamanho;
}

// Obter/modificar valor de um elemento
int obter_elemento(Lista *l, int pos, int *valor) {
    if (pos < 1 || pos > l->tamanho) return 0;
    *valor = l->dados[pos - 1];
    return 1;
}

int modificar_elemento(Lista *l, int pos, int valor) {
    if (pos < 1 || pos > l->tamanho) return 0;
    l->dados[pos - 1] = valor;
    return 1;
}

// Inserir um elemento em uma determinada posição
int inserir_elemento(Lista *l, int pos, int valor) {
    if (lista_cheia(l) || pos < 1 || pos > l->tamanho + 1) return 0;
    for (int i = l->tamanho; i >= pos; i--) {
        l->dados[i] = l->dados[i - 1];
    }
    l->dados[pos - 1] = valor;
    l->tamanho++;
    return 1;
}

// Retirar um elemento de uma determinada posição
int remover_elemento(Lista *l, int pos) {
    if (lista_vazia(l) || pos < 1 || pos > l->tamanho) return 0;
    for (int i = pos - 1; i < l->tamanho - 1; i++) {
        l->dados[i] = l->dados[i + 1];
    }
    l->tamanho--;
    return 1;
}

// Função para imprimir a lista
void imprimir_lista(Lista *l) {
    if (lista_vazia(l)) {
        printf("A lista esta vazia.\n");
        return;
    }
    for (int i = 0; i < l->tamanho; i++) {
        printf("%d ", l->dados[i]);
    }
    printf("\n");
}