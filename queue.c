#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"

t_queue* create(){
    t_queue* fila = (t_queue *)malloc(sizeof(t_queue));
    if(fila == NULL){
        return NULL;
    }
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
    return fila;
}

int is_empty(t_queue* fila){
    return fila->tamanho <= 0;
}

int is_full(t_queue* fila){
    return fila->tamanho >= 20;
}

int enqueue(t_queue* fila, char* nome_cliente){
    if(is_full(fila)) {
        return 0;
    }
    strcpy(fila->clientes[fila->fim], nome_cliente);
    fila->fim = (fila->fim + 1) % 20;
    fila->tamanho++;
    return 1;
}

char* dequeue(t_queue* fila){
    if(is_empty(fila)) {
        return NULL;
    }
    char* cliente = fila->clientes[fila->inicio];
    fila->inicio = (fila->inicio + 1) % 20;
    fila->tamanho--;
    return cliente;
}

void destroy(t_queue* fila){
    if(fila != NULL){
        free(fila);
    }
}