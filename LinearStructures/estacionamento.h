// Copyright [2024] <COLOQUE SEU NOME AQUI...> André Lemos Piucco

/*
    *** Importante ***

    O código de fila em vetor está disponível internamente (não precisa de implementação aqui)

*/



void retira_veiculo(structures::ArrayQueue<int> *f, int k) {
    for (int i = 0; i < k; i++) {
        if (i != k-1) {
            f->enqueue(f->dequeue());
        } else {
            f->dequeue();
        }
    }
}


void mantenha_veiculo(structures::ArrayQueue<int> *f, int k) {
    int tam = static_cast<int>(f->size());
    for (int i = 0; i < tam; i++) {
        if (i != k-1) {
            f->dequeue();
        } else {
            f->enqueue(f->dequeue());
        }
    }
}



/*
    *** Importante ***

    A função 'main()' não deve ser escrita aqui, pois é parte do código dos testes e já está implementada

*/
