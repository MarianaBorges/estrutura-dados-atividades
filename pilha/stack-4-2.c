#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = -1;
}

int vazia(Pilha* p) {
    return p->topo == -1;
}

int cheia(Pilha* p) {
    return p->topo == MAX - 1;
}

void push(Pilha* p, int valor) {
    if (cheia(p)) {
        printf("Pilha cheia!\n");
        return;
    }
    p->itens[++(p->topo)] = valor;
}

int pop(Pilha* p) {
    if (vazia(p)) {
        printf("Pilha vazia!\n");
        return -1;
    }
    return p->itens[(p->topo)--];
}

void imprimir(Pilha* p) {
    printf("Pilha: ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

void removerMaiorEMenor(Pilha* p) {
    if (vazia(p)) return;

    Pilha temp;
    inicializar(&temp);

    int maior = INT_MIN;
    int menor = INT_MAX;

    // Encontra o maior e o menor
    while (!vazia(p)) {
        int val = pop(p);
        if (val > maior) maior = val;
        if (val < menor) menor = val;
        push(&temp, val);
    }

    // Reinsere, pulando maior e menor
    while (!vazia(&temp)) {
        int val = pop(&temp);
        if (val != maior && val != menor) {
            push(p, val);
        }
    }
}

int main() {
    Pilha pilha;
    inicializar(&pilha);

    // Push conforme a sequência
    push(&pilha, 30);
    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 50);
    push(&pilha, 40);

    printf("Antes de remover:\n");
    imprimir(&pilha);

    removerMaiorEMenor(&pilha);

    printf("Depois de remover maior e menor:\n");
    imprimir(&pilha);

    return 0;
}
