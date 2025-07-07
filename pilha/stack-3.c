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

int corresponde(char abre, char fecha){
  return (abre == '(' && fecha == ')') || (abre == '{' && fecha == '}') || (abre == '[' && fecha == ']');        
}

// A função estaBalanceada():
// - Lê cada caractere da expressão.
// - Quando vê um símbolo de abertura ((, [, {), empilha.
// - Quando vê um símbolo de fechamento (), ], }):
// - Verifica se há um correspondente no topo da pilha.
// - Se sim, desempilha (removendo o par correspondente).
// - Se não, a expressão não está balanceada.
// No final:
// Se a pilha estiver vazia, está tudo fechado corretamente → balanceada.
// Se sobrar algo na pilha, está faltando fechar algo → não balanceada.

int estaBalanceada(const char *entrada) {
  Pilha *pilha = iniciar();
    
  for (int i = 0; entrada[i] != '\0'; i++) {
    char c = entrada[i];
        
    if (c == '(' || c == '{' || c == '[') {
      push(pilha, c);
    } else if (c == ')' || c == '}' || c == ']') {
      if (empty(pilha) || !corresponde(pop(pilha), c)) {
        free(pilha);
  
        return 0; 
      }
    }
  }  
  
  int resultado = empty(pilha);
  free(pilha);

  return resultado;
}

int main() {
  char entrada[1000];

  printf("Digite uma expressão: ");
  fgets(entrada, sizeof(entrada), stdin);

  entrada[strcspn(entrada, "\n")] = '\0'; 
  if(estaBalanceada(entrada)) {
    printf("A expressão está balanceada!\n");
  } else {
    printf("A expressão não está balanceada.\n");
  }
  return 0;
}