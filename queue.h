#ifndef QUEUE_H
#define QUEUE_H

typedef struct 
{
    char clientes[20][50];
    int inicio;
    int fim;
    int tamanho;
} t_queue;

t_queue* create();
int is_empty(t_queue*);
int is_full(t_queue*);
int enqueue(t_queue*, char*);
char* dequeue(t_queue*);
void destroy(t_queue*);

#endif