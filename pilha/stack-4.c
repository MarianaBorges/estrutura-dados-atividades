#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento {
  int valor;
  struct elemento *proximo;
} Elemento;

typedef struct pilha {
  Elemento *topo;
  int tamanho;
} Pilha;

Pilha* iniciar() {
  Pilha *p = malloc(sizeof(Pilha));
  p->topo = NULL;
  p->tamanho = 0;
    
  return p;
}

void push(Pilha *p, char caractere) {
  Elemento *e = malloc(sizeof(Elemento));
  e->valor = caractere;
  e->proximo = p->topo;
  p->topo = e;
    
  p->tamanho = p->tamanho + 1;
}

int size(Pilha *p) {
  return p->tamanho;
}

int empty(Pilha *p) {
  return p->topo == NULL;
}

char top(Pilha *p) {
  if(empty(p)) {
    return '\0';
  }
    
  return p->topo->valor;
}

char pop(Pilha *p) {
  Elemento *e;
  char c;
    
  if (!empty(p)) { 
    e = p->topo; 
    c = e->valor; 
    p->topo = p->topo->proximo;
    p->tamanho = p->tamanho - 1;
    free(e);
    e = NULL;
    return c;

  } else {
    return '\0';
  }
}

Pilha* ordenar(Pilha *p) {
  Pilha *aux = iniciar();

  while (!empty(p)) {
    int valor = pop(p);
    while (!empty(aux) && top(aux) > valor) {
      push(p, pop(aux));
    }
    push(aux, valor);
  }

  return aux;
}


Pilha* removePrimeiro(Pilha *p) {
  if (empty(p)) {
    return p;
  }
  
  Elemento *e = p->topo;
  p->topo = e->proximo;
  free(e);
  p->tamanho--;
  
  return p;
}

Pilha* removeUltimo(Pilha *p) {
  if (empty(p)) {
    return p;
  }
  
  Elemento *atual = p->topo;
  Elemento *anterior = NULL;
  
  while (atual->proximo != NULL) {
    anterior = atual;
    atual = atual->proximo;
  }
  
  if (anterior != NULL) {
    anterior->proximo = NULL;
  } else {
    p->topo = NULL;
  }
  
  free(atual);
  p->tamanho--;
  
  return p;
}

void imprimirPilha(Pilha *p) {
  Elemento *atual = p->topo;

  printf("Pilha (topo -> base): ");
  while (atual != NULL) {
      printf("%d ", atual->valor);
      atual = atual->proximo;
  }
  printf("\n");
}

int main() {
  Pilha *primeiraPilha = iniciar();

  push(primeiraPilha, 30);
  push(primeiraPilha, 10);
  push(primeiraPilha, 20);
  push(primeiraPilha, 50);
  push(primeiraPilha, 40);

  Pilha *p = ordenar(primeiraPilha);

  removePrimeiro(p);
  removeUltimo(p);

  imprimirPilha(p);
}