#define TAMANHO 8

int fila[TAMANHO];

int quantidade, cabeca, fim;

void iniciar() {
  quantidade = 0;
  cabeca = 0;
  fim = 0;
}

void enqueue(char caractere) {
  if(!full()) {
    fila[fim] = caractere;
    fim++;
    quantidade++;
   
    if(fim == TAMANHO) {
      fim = 0;
    }
  } else {
    printf("Fila cheia!");
  }
}

int size() {
  return quantidade;
}

char head() {
  return fila[cabeca];
}

int empty() {
  return quantidade == 0;
}

char dequeue() {
  char caractere;

  if(!empty()) {
    caractere = fila[cabeca];
    cabeca++;
    quantidade--;

    if(cabeca == TAMANHO) {
      cabeca = 0;
    }

    return caractere;
  } else {
    printf("Fila vazia!");
  }
}

int full() {
  return quantidade == TAMANHO;
}