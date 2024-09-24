// Copyright [2022] <COLOQUE SEU NOME AQUI...> André Lemos Piucco
#include "./array_stack.h"

bool verificaChaves(std::string trecho_programa) {
    bool resposta = true;
    int  tamanho  = trecho_programa.length();
    structures::ArrayStack<char> pilha(500);
    for (int i = 0; i < tamanho; i++) {
        // condições de parada dor 'for' podem ser adicionadas...

        /*
        
            COLOCAR SEU CÓDIGO AQUI...
        */
        if (trecho_programa[i] == '{' || trecho_programa[i] == '}')
            pilha.push(trecho_programa[i]);
        std::size_t size_1 = static_cast<std::size_t>(1);
        if (!pilha.empty() && pilha.top() == '}' && pilha.size() == size_1) {
            std::cout << "Há problema" << std::endl;
            resposta = false;
            break;
        } else if (trecho_programa[i] == '}') {
            pilha.pop();
            pilha.pop();
        }
    }
    return resposta;
}
