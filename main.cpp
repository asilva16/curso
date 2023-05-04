#include <iostream>
using namespace std;

struct No {
    int valor;
    No* esquerda;
    No* direita;
};

No* criarNo(int valor) {
    No* novoNo = new No;
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

No* inserirNo(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserirNo(raiz->esquerda, valor);
    }
    else if (valor > raiz->valor) {
        raiz->direita = inserirNo(raiz->direita, valor);
    }
    return raiz;
}

void exibirArvore(No* raiz) {
    if (raiz != NULL) {
        exibirArvore(raiz->esquerda);
        cout << raiz->valor << " ";
        exibirArvore(raiz->direita);
    }
}

int main() {
    No* raiz = NULL;
    raiz = inserirNo(raiz, 10);
    raiz = inserirNo(raiz, 5);
    raiz = inserirNo(raiz, 15);
    raiz = inserirNo(raiz, 3);
    raiz = inserirNo(raiz, 8);
    raiz = inserirNo(raiz, 12);
    raiz = inserirNo(raiz, 20);
    
    cout << "Elementos da árvore: ";
    exibirArvore(raiz);
    
    return 0;
}
