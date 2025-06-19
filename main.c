#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"

int main(){
    t_queue* fila_prioridade = create();
    t_queue* fila_geral = create();

    if(!fila_prioridade || !fila_geral) {
        printf("Erro ao criar fila.\n");
        return 1;
    }

    char comando;
    char nome[50];
    int prioridade_cont = 0;
    char atendimentos[50][50];
    int atend_cont = 0;

    while(comando != 'f'){
        scanf("%c", &comando);
        if(comando == 'p' || comando == 'g') {
            scanf("%s", &nome);

            if(comando == 'p') {
                if(!enqueue(fila_prioridade, nome)){
                    printf("Não foi possível adicionar: fila prioritária cheia.");
                }
            } else {
                if(!enqueue(fila_geral, nome)){
                    printf("Não foi possível adicionar: fila geral cheia.");
                }
            }
        } else {
            if(comando == 's') {
                if(!is_empty(fila_prioridade) && prioridade_cont < 3) {
                    strcpy(atendimentos[atend_cont], dequeue(fila_prioridade));
                    prioridade_cont++;
                } else if(!is_empty(fila_geral)) {
                    strcpy(atendimentos[atend_cont], dequeue(fila_geral));
                    prioridade_cont = 0;
                } else if(!is_empty(fila_prioridade)){
                    strcpy(atendimentos[atend_cont], dequeue(fila_prioridade));
                    prioridade_cont++;
                }
                atend_cont++;
            }
        }
    }

    printf("Ordem de atendimento\n\n");

    for (int i = 0; i < atend_cont; i++) {
        printf("%s \n", atendimentos[i]);
    }

    destroy(fila_prioridade);
    destroy(fila_geral);
    

    return 0;
}