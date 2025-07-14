#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

int impreme_alfabeto1()
{
  Fila *f1 = iniciar();
  Fila *f2 = iniciar();

  char l1[13] = {'A', 'C', 'E', 'G', 'I', 'K', 'M', 'O', 'Q', 'S', 'U', 'W', 'Y'};
  char l2[13] = {'B', 'D', 'F', 'H', 'J', 'L', 'N', 'P', 'R', 'T', 'V', 'X', 'Z'};

  int count = 0;
  while (count < 13 )
  {
    enqueue(f1, l1[count]);
    enqueue(f2, l2[count]);
    count++;
  }
  count = 0;
  while (count < 13)
  {
    printf("%c\n", dequeue(f1));
    printf("%c\n", dequeue(f2));
    count++;
  }
  return 0;
}

int impreme_alfabeto2()
{
  Fila *f1 = iniciar();
  Fila *f2 = iniciar();

  for (char c = 'A'; c <= 'Z'; c += 2) {
    enqueue(f1, c);
  }

  for (char c = 'B'; c <= 'Z'; c += 2){
    enqueue(f2, c);
  }

  for (int i = 0; i < 13; i++) {
    printf("%c\n", dequeue(f1));
    printf("%c\n", dequeue(f2));
  }
  return 0;
}

int main() {
  impreme_alfabeto2();
}