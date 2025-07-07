#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int estaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void empilhar(Pilha *p, char c) {
    if (!estaCheia(p)) {
        p->itens[++(p->topo)] = c;
    }
}

char desempilhar(Pilha *p) {
    if (!estaVazia(p)) {
        return p->itens[(p->topo)--];
    }
    return '\0'; 
}

int ehPalindromo(const char *entrada) {
    Pilha pilha;
    inicializar(&pilha);

    char filtrada[MAX];
    int j = 0;

    for (int i = 0; entrada[i] != '\0'; i++) {
        if (isalnum(entrada[i])) {
            char c = tolower(entrada[i]);
            filtrada[j++] = c;
            empilhar(&pilha, c);
        }
    }
    filtrada[j] = '\0'; 

    for (int i = 0; i < j; i++) {
        if (filtrada[i] != desempilhar(&pilha)) {
            return 0;  
        }
    }

    return 1;  
}

int main() {
    char entrada[MAX];

    printf("Digite uma palavra, frase ou número: ");
    fgets(entrada, MAX, stdin);

    entrada[strcspn(entrada, "\n")] = '\0';

    if (ehPalindromo(entrada)) {
        printf("É um palíndromo!\n");
    } else {
        printf("Não é um palíndromo.\n");
    }

    return 0;
}
