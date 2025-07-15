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

  if (f->cabeca == NULL) {
    f->cabeca = e;
    f->fim = e;
  } else if (e->valor > f->fim->valor) {
    f->fim->proximo = e;
    f->fim = e;
  } else if (e->valor < f->cabeca->valor) {
    e->proximo = f->cabeca;
    f->cabeca = e;
  } else {
    Elemento *controle = f->cabeca;
    Elemento *anterior = NULL;

    while (controle != NULL && e->valor >= controle->valor) {
      anterior = controle;
      controle = controle->proximo;
    }

    anterior->proximo = e;
    e->proximo = controle;
  }

  f->tamanho++;
}

int size(Fila *f) {
  return f->tamanho;
}

int head(Fila *f) {
  return f->cabeca->valor;
}

int empty(Fila *f) {
  return f->tamanho == 0;
}

int dequeue(Fila *f) {
  Elemento *e;
  int valor;

  if (!empty(f)) {
    e = f->cabeca;
    valor = e->valor;

    f->cabeca = e->proximo;
    if (empty(f)) {
      f->fim = NULL;
    }

    f->tamanho--;
    free(e);

    return valor;
  }else {
    printf("Fila vazia!\n");
    return '\0'; 
  }
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

Fila retorna_fila_ordenada(Fila *f1, Fila *f2){
  Fila *f = iniciar();
  Elemento *controle = f1->cabeca;

  while (controle != NULL) {
    enqueue(f, controle->valor);
    controle = controle->proximo;
  }

  Elemento *controle2 = f2->cabeca;
  while (controle2 != NULL)
  {
    enqueue(f, controle2->valor);
    controle2 = controle2->proximo;
  }
  

  return *f;
}

int main() {
  Fila *f1 = iniciar();

  Fila *f2 = iniciar();

  for (int i = 0; i < 10; i = i + 2) {
    enqueue(f1, i);
  }

  for (int i = 1; i < 6; i= i + 3) {
    enqueue(f2, i + 2);
  }

  Fila f3 = retorna_fila_ordenada(f1, f2);

  impressao(f1);
  printf("\n");

  impressao(f2);
  printf("\n");
  
  impressao(&f3);
}