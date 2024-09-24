// Copyright [2022] <COLOQUE SEU NOME AQUI...> André Lemos Piucco
#include <string>


class Aluno {
 public:
    Aluno() {}  // construtor
    ~Aluno() {}  // destrutor
    std::string devolveNome() {
        return nome;
    }
    int devolveMatricula() {
        return matricula;
    }
    void escreveNome(std::string nome_) {
        nome = nome_;
    }
    void escreveMatricula(int matricula_) {
        matricula = matricula_;
    }
 private:
    std::string nome;
    int matricula;
};


Aluno *turma_filtra(Aluno t[], int N, int menor_matr) {
    Aluno *tf;
    int conta = 0;
    for (int i = 0; i < N; i++) {
        if (t[i].devolveMatricula() >= menor_matr) {
            conta += 1;
        }
    }
    tf = new Aluno[conta];
    conta = 0;
    for (int i = 0; i < N; i++) {
        if (t[i].devolveMatricula() >= menor_matr) {
            tf[conta] = t[i];
            conta++;
        }
    }
    return tf;
}

int *turma_conta(Aluno t[], int N) {
    int *c;
    c = new int[26];
    for (int i = 0; i < N; i++) {
        c[t[i].devolveNome()[0] - 'A'] += 1;
    }
    // i = caracter - 'A';
    return c;
}



/*
    *** Importante ***

    A função 'main()' não deve ser escrita aqui, pois é parte do código dos testes e já está implementada

*/
