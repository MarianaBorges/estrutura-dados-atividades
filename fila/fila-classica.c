#include <stdlib.h>
#include <stdio.h>

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
  char caractere = e->valor;

  f->cabeca = e->proximo;
  f->tamanho--;

  if (f->cabeca == NULL) {
    f->fim = NULL;
  }

  free(e);
  return caractere;
}

char impressao(Fila *f) {
  if (empty(f)) {
    printf("Fila vazia!impressao\n");
    return '\0';
  }

  Elemento *atual = f->cabeca;
  while (atual != NULL) {
    printf("%c ", atual->valor);
    atual = atual->proximo;
  }
  printf("\n");
  
  return '\0';
}

int main()
{
  Fila *fila = iniciar();
  // 1
  dequeue(fila); 
  impressao(fila);
  // 2
  enqueue(fila, 'b');
  impressao(fila);
  // 3
  dequeue(fila);
  impressao(fila);
  // 4
  printf("4 %c \n", head(fila));
  // 5
  printf("5 %d \n", size(fila));
  // 6 
  printf("6 %d \n", empty(fila));
  // 7 
  enqueue(fila, 'c');
  impressao(fila);
  // 8
  dequeue(fila);
  impressao(fila);
  // 9
  enqueue(fila, 'd');
  impressao(fila);
  // 10
  printf("10 %c \n", head(fila));
  // 11
  dequeue(fila);
  impressao(fila);
  // 12 
  dequeue(fila);
  impressao(fila);
  // 13
  printf("13 %d \n", empty(fila));
}