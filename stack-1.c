#include <stdio.h>
#include <stdlib.h>

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
    printf("%i \n", p->tamanho);
    return p->tamanho;
}
int empty(Pilha *p) {
    return p->topo == NULL;
}

char top(Pilha *p) {
    if(empty(p)) {
        printf("Pilha vazia!\n\n");
        return '\0';
    }
    printf("%c \n", p->topo->valor);
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
         printf("%c \n", c);
        
        
        return c;
    } else {
        printf("Pilha vazia.\n\n");
        
        return '\0';
    }
}

int main()
{
    Pilha *minhaPilha = iniciar();
    
    pop(minhaPilha);
    push(minhaPilha, 'a');
    push(minhaPilha, 'c');
    top(minhaPilha);
    size(minhaPilha);
    push(minhaPilha, 'g');
    pop(minhaPilha);
    push(minhaPilha, 'm');
    pop(minhaPilha);
    top(minhaPilha); 
    pop(minhaPilha);
    pop(minhaPilha);
    empty(minhaPilha);
    
    printf("Hello World");

    return 0;
}