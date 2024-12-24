#include <iostream>
#include <time.h>
#include <chrono>

// alterar o retorno
void quicksort(int conjunto[], int limite_inf, int limite_sup) {
    int i;
    if (limite_sup > limite_inf) {
        i = particao(conjunto, limite_inf, limite_sup);
        quicksort(conjunto, limite_inf, i-1);
        quicksort(conjunto, i+1, limite_sup);
    }
}

int particao(int conjunto[], int limite_inf, int limite_sup) {
    int pivo, tempo, baixo, alto;
    pivo = conjunto[limtie_inf];
    alto = limite_sup;
    baixo = limite_inf + 1;
    while (baixo < alto) {
        while ((conjunto[baixo] < pivo) && (baixo < limite_sup))
            baixo++;
        while (conjunto[alto] >= pivo)
            alto--;
        if (baixo < alto) {
            tempo = conjunto[baixo];
            conjunto[baixo] = conjunt[alto];
            conjunto[alto] = temp;
        }
    }
    conjunto[limite_inf] = conjunto[alto];
    conjunto[alto] = pivo;
    return alto;
}


// alterar o retorno
void heapsort() {
    
}

void cria_conjuntos(int conjunto[]) {
    tamanho = sizeof(conjunto);
    for (int i = 0; i < tamanho; i++) {
        int aleatorio = rand() % tamanho;  // novo numero de 0 a 999
        conjunto[i] = aleatorio;
    }
}

int main () {
    srand(time(NULL));  // nova semente
    
    // declaração dos conjuntos
    int conj1[1000];
    int conj2[5000];
    int conj3[10000];
    int conj4[50000];
    int conj5[100000];
    
    // cria cada conjunto
    cria_conjuntos(conj1);
    cria_conjuntos(conj2);
    cria_conjuntos(conj3);
    cria_conjuntos(conj4);
    cria_conjuntos(conj5);

    quicksort(conj1, 1, sizeof(conj1));
    quicksort(conj2, 1, sizeof(conj2));
    quicksort(conj3, 1, sizeof(conj3));
    quicksort(conj4, 1, sizeof(conj4));
    quicksort(conj5, 1, sizeof(conj5));
    

    auto conj1 = std::chrono::high_resolution_clock::now();

    quicksort();
    
    std::chrono::duration<double, std::milli> float_ms = end - start;
    
    auto start2 = std::chrono::high_resolution_clock::now();

    headpsort();
    
    std::chrono::duration<double, std::milli> float_ms = end - start2;

}
