#include <stdlib.h>
#include <stdio.h>

typedef struct elemento {
  int valor;
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

void enqueue(Fila *f, int valor) {
  Elemento *e = malloc(sizeof(Elemento));
  e->valor = valor;
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

int empty(Fila *f) {
  return f->tamanho == 0;
}

char head(Fila *f) {
  if (empty(f)) {
    printf("fila vazia!\n");
    return '\0';
  }
  
  return f->cabeca->valor;
}


char dequeue(Fila *f) {
  if (empty(f)) {
    printf("Fila vazia!\n");
    return '\0';
  }

  Elemento *e = f->cabeca;
  char valor = e->valor;

  f->cabeca = e->proximo;
  f->tamanho--;

  if (f->cabeca == NULL) {
    f->fim = NULL;
  }

  free(e);
  return valor;
}

char impressao(Fila *f) {
  if (empty(f)) {
    printf("Fila vazia!impressao\n");
    return '\0';
  }

  Elemento *atual = f->cabeca;
  while (atual != NULL) {
    printf("%d ", atual->valor);
    atual = atual->proximo;
  }
  printf("\n");
  
  return '\0';
}

int preenche_fila(Fila *f){
  for (int i = 1; i < 16; i++) {
    enqueue(f, i);
  }
}

int main()
{
  Fila *f = iniciar();
  Fila *f_par = iniciar();
  Fila *f_impar = iniciar();

  preenche_fila(f);

  Elemento *atual = f->cabeca;

  while (atual != NULL)
  {
    if (atual->valor % 2 == 0) {
      enqueue(f_par, atual->valor);
    } else {
      enqueue(f_impar, atual->valor);
    }
    atual = atual->proximo;
  }
  
  impressao(f_par);
  impressao(f_impar);
}