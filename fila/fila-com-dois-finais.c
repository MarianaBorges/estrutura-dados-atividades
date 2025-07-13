#include <stdio.h>
#define TAMANHO 8

int fila[TAMANHO];

int quantidade, cabeca, fim;

void iniciar() {
  quantidade = 0;
  cabeca = -1;
  fim = -1;
}

int empty() {
  return quantidade == 0;
}


int full() {
  return quantidade == TAMANHO;
}

void enqueue(char caractere) {
  if(!full()) {
    if (empty()) {
      cabeca = 0;
      fim = 0;
    } else {
      fim = (fim + 1) % TAMANHO; 
    }

    fila[fim] = caractere;
    quantidade++;

  } else {
    printf("Fila cheia!");
  }
}

void enqueue_head(char caractere) {
  if (full()){
    printf("Fila cheia!");
    return;
  } else {
    if (empty()){
      cabeca = 0;
      fim = 0;
    } else {
      if (cabeca == 0){
        cabeca = TAMANHO -1;
      } else {
        cabeca--;
      }
    }

    quantidade++;
    fila[cabeca] = caractere;
  }
}

int size() {
  return quantidade;
}

char head() {
  return fila[cabeca];
}

char dequeue() {
  char caractere;

  if(!empty()) {
    caractere = fila[cabeca];
    cabeca++;
    quantidade--;

    if (cabeca == fim){
      cabeca = -1;
      fim = -1; 
    }else {
      cabeca = (cabeca + 1) % TAMANHO;
    }
    
    return caractere;
  } else {
    printf("Fila vazia!");
  }
}

char dequeue_fim() {
  char caractere;
  
  if(empty()) {
    printf("Fila vazia!");
    return '\0';
  } else {
    caractere = fila[fim];
    fila[fim] = '\0'; 

    if (cabeca == fim){ // se fila vazia
      cabeca = -1;
      fim = -1;

    } else {
      if (fim == 0) {
        fim = TAMANHO - 1;
      } else {
        fim = fim - 1;
      }
    }

    quantidade = quantidade - 1;
    return caractere;
  }
}

void imprime() {
  if (empty()) {
    printf("Fila vazia!\n");
    return;
  }

  int i = cabeca;
  printf("Fila: ");
  while (1) {
    printf("%c ", fila[i]);
    if (i == fim) break;
    i = (i + 1) % TAMANHO;
  }
  printf("\n");
}


int main()
{
  iniciar();
  enqueue('A');
  enqueue('B');
  imprime();

  dequeue_fim();

  imprime();
}