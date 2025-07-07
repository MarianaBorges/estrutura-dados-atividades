#include <stdlib.h>

typedef struct elemento {
  char valor;
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

void enqueue(Fila *f, char caractere) {
  Elemento *e = malloc(sizeof(Elemento));
  e->valor = caractere;
  e->proximo = NULL;

  if (f->fim != NULL) {
    f->fim->proximo = e;
  } else {
    f->cabeca = e;
  }

  f->fim = e;
  f->tamanho++;
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