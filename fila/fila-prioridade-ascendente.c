#include <stdlib.h>

typedef struct elemento {
  char valor;
  int prioridade;
  struct elemento *proximo;
} Elemento;

typedef struct fila {
  Elemento *cabeca;
  Elemento *fim;
  int tamanho;
} Fila;

Fila* iniciar() {
  Fila *f = malloc(sizeof(Fila));
  f->cabeca = NULL;
  f->fim = NULL;
  f->tamanho = 0;

  return f;
}

void enqueue(Fila *f, char caractere, int prioridade) {
  Elemento *e = malloc(sizeof(Elemento));
  e->valor = caractere;
  e->prioridade = prioridade;
  e->proximo = NULL;

  if (f->cabeca == NULL) {
    f->cabeca = e;
    f->fim = e;
  
    f->tamanho++;
  } else {
    if(e ->prioridade > f->fim->prioridade) {
      f->fim->proximo = e;
      f->fim = e;
      f->tamanho++;
      return;
    }

    if(e->prioridade < f->cabeca->prioridade) {
      e->proximo = f->cabeca;
      f->cabeca = e;
      f->tamanho++;
      return;
    }

    Elemento *controle = f->cabeca;
    Elemento *anterior;

    while (controle->proximo != NULL){
      if (e->prioridade < controle->prioridade) {
        e->proximo = controle;
        anterior->proximo = e;

        f->tamanho++;
        return;
      } else {
        anterior = controle;
        controle = controle->proximo;
      }
    }
    free(anterior);
    free(controle);
    anterior = NULL;
    controle = NULL;
  }
}

int size(Fila *f) {
  return f->tamanho;
}

char head(Fila *f) {
  return f->cabeca->valor;
}

int empty(Fila *f) {
  return f->tamanho == 0;
}

char dequeue(Fila *f) {
  Elemento *e;
  char caractere;

  if (!empty(f)) {
    e = f->cabeca;
    caractere = e->valor;

    f->cabeca = e->proximo;
    if (empty(f)) {
      f->fim = NULL;
    }

    f->tamanho--;
    free(e);

    return caractere;
  }else {
    printf("Fila vazia!\n");
    return '\0'; 
  }
}