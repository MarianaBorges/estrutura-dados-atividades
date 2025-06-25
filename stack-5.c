#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento {
  char valor;
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

void imprimirPilha(Pilha *p) {
  Elemento *atual = p->topo;

  printf("Pilha (topo -> base): ");
  while (atual != NULL) {
      printf("%c ", atual->valor);
      atual = atual->proximo;
  }
  printf("\n");
}

void removeValoresRepitidos(Pilha *p) {
  if (empty(p)) {
    return;
  }

  Pilha *aux = iniciar();

  while (!empty(p)) {
    int val = pop(p);
    
    int rep = 0;

    Elemento *atual = p->topo;

    while (atual != NULL) {
      if (atual->valor == val) {
        printf("%d \n", rep);
        rep++;
      }
      atual = atual->proximo;
    }

    if(rep == 0) {
      push(aux, val);
    }
  }

  while (!empty(aux)) {
    int val = pop(aux);

    push(p, val);
  }

}

int main(){
  Pilha *p = iniciar();
  
  push(p, '@');
  push(p, '&');
  push(p, '@');
  push(p, '#');
  push(p, '%');
  push(p, '&');
  push(p, '$');

  imprimirPilha(p);

  removeValoresRepitidos(p);
  
  imprimirPilha(p);
}