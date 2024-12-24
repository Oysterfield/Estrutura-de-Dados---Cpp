// Copyright 2024 <Copyright Owner> André Lemos Piucco
#ifndef STRUCTURES_CIRCULAR_LIST_H
#define STRUCTURES_CIRCULAR_LIST_H

#include <cstdint>


namespace structures {

template<typename T>
class CircularList {
 public:
    CircularList();
    ~CircularList();

    void clear();  // limpar lista

    void push_back(const T& data);  // inserir no fim
    void push_front(const T& data);  // inserir no início
    void insert(const T& data, std::size_t index);  // inserir na posição
    void insert_sorted(const T& data);  // inserir em ordem

    T& at(std::size_t index);  // acessar em um indice (com checagem de limites)
    const T& at(std::size_t index) const;  // versão const do acesso ao indice

    T pop(std::size_t index);  // retirar da posição
    T pop_back();  // retirar do fim
    T pop_front();  // retirar do início
    void remove(const T& data);  // remover dado específico

    bool empty() const;  // lista vazia
    bool contains(const T& data) const;  // lista contém determinado dado?
    std::size_t find(const T& data) const;  // posição de um item na lista

    std::size_t size() const;  // tamanho da lista

 private:
    class Node {  // Elemento (implementação pronta)
     public:
        explicit Node(const T& data):
            data_{data}
        {}

        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}

        T& data() {  // getter: dado
            return data_;
        }

        const T& data() const {  // getter const: dado
            return data_;
        }

        Node* next() {  // getter: próximo
            return next_;
        }

        const Node* next() const {  // getter const: próximo
            return next_;
        }

        void next(Node* node) {  // setter: próximo
            next_ = node;
        }

     private:
        T data_;
        Node* next_{nullptr};
    };

    Node* before_index(std::size_t index) {  // nó anterior ao 'index'
        auto it = head->next();
        for (auto i = 0u; i < index-1; ++i) {
            it = it->next();
        }
        return it;
    }

    Node* head{nullptr};
    Node* tail{nullptr};
    std::size_t size_{0u};
};

}  // namespace structures

#endif

//! Construtor
template<typename T>
structures::CircularList<T>::CircularList() {
    Node *sentinela;
    sentinela = new Node(0, nullptr);
    sentinela->next(sentinela);
    head = sentinela;
    tail = sentinela;
    size_ = 0u;
}

//! Destrutor
template<typename T>
structures::CircularList<T>::~CircularList() {  // alterar destrutor?
    clear();
}

//! Esvazia
template<typename T>
void structures::CircularList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

//! Inserção no início
template<typename T>
void structures::CircularList<T>::push_front(const T& data) {
    Node *novo;
    novo = new Node(data, head->next());
    if (novo == nullptr) {
        throw std::out_of_range("memória insuficiente");
    }
    if (empty()) {
        tail = novo;
    }
    head->next(novo);
    size_++;
}

//! Inserção no fim
template<typename T>
void structures::CircularList<T>::push_back(const T& data) {
    if (empty()) {
        return push_front(data);
    }
    Node *novo = new Node(data, head);
    if (novo == nullptr) {
        throw std::out_of_range("memória insuficiente");
    }
    tail->next(novo);
    tail = novo;
    size_++;
}

//! Dado da posição 'index'
template<typename T>
T& structures::CircularList<T>::at(std::size_t index) {
    /*
        COLOQUE SEU CÓDIGO AQUI...
    */
    if (empty()) {
        throw std::out_of_range("lista vazia");
    }
    if (index >= size())
        throw std::out_of_range("índice maior que a lista");
    Node *it = head->next();
    for (auto i = 0u; i < index; ++i) {
        it = it->next();
    }
    return it->data();
}

//! Inserção na posição 'index'
template<typename T>
void structures::CircularList<T>::insert(const T& data, std::size_t index) {
    /*
    
        COLOQUE SEU CÓDIGO AQUI...
    
    */
    if (index > size())
        throw std::out_of_range("índice maior que lista");
    if (index == size())
        return push_back(data);
    if (index == 0)
        return push_front(data);
    Node *ant = before_index(index);
    Node *novo = new Node(data, ant->next());
    if (novo == nullptr)
        throw std::out_of_range("memória insuficiente");
    ant->next(novo);
    size_++;
}

//! Inserção ordenada
template<typename T>
void structures::CircularList<T>::insert_sorted(const T& data) {
    /*
    
        COLOQUE SEU CÓDIGO AQUI...
    
    */
    if (empty()) {
        return push_front(data);
    }
    Node *p = head->next();
    for (std::size_t i = 0; i < size(); ++i) {
        if (p->data() > data) {
            insert(data, i);
            return;
        }
        p = p->next();
    }
    push_back(data);
}

//! Remoção do início
template<typename T>
T structures::CircularList<T>::pop_front() {
    if (empty()) {
        throw std::out_of_range("lista vazia");
    }
    T retorno;
    Node *eliminar;
    eliminar = head->next();
    head->next(eliminar->next());
    retorno = eliminar->data();
    delete eliminar;
    if (head->next() == head) {
        tail = head;
    }
    size_--;
    return retorno;
}

//! Remoção do fim
template<typename T>
T structures::CircularList<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("lista vazia");
    }
    if (size() == 1) {
        return pop_front();
    }
    T aux;
    Node *eliminar, *ant;
    ant = head;
    eliminar = head->next();
    while (eliminar != tail) {  // 'ant' deve apontar para o penúltimo nó
        ant = eliminar;
        eliminar = eliminar->next();
    }
    ant->next(head);
    aux = eliminar->data();
    delete eliminar;
    tail = ant;
    size_--;
    return aux;
}

//! Remoção da posição 'index'
template<typename T>
T structures::CircularList<T>::pop(std::size_t index) {
    /*
    
        COLOQUE SEU CÓDIGO AQUI...
    
    */
    if (empty())
        throw std::out_of_range("lista vazia");
    if (index >= size())
        throw std::out_of_range("índice maior que lista");
    if (index == 0) {
        return pop_front();
    } else if (index == (size() - 1)) {
        return pop_back();
    }
    Node *ant = before_index(index);
    Node *eliminar = ant->next();
    T aux = eliminar->data();
    ant->next(eliminar->next());
    delete eliminar;
    size_--;
    return aux;
}

//! Remoção de um dado
template<typename T>
void structures::CircularList<T>::remove(const T& data) {
    pop(find(data));
}

//! Verificação de vazia
template<typename T>
bool structures::CircularList<T>::empty() const {
    return (size() == 0u);
}

//! Verificação se contém um dado
template<typename T>
bool structures::CircularList<T>::contains(const T& data) const {
    return find(data) != size();
}

//! Índice de um dado (se existir); ou 'size() (se não existir)
template<typename T>
std::size_t structures::CircularList<T>::find(const T& data) const {
    /*
    
        COLOQUE SEU CÓDIGO AQUI...
    
    */
    Node *p = head->next();
    for (std::size_t i = 0; i < size(); ++i) {
        if (p->data() == data)
            return i;
        p = p->next();
    }
    return size();
}

//! Quantidade atual de elementos
template<typename T>
std::size_t structures::CircularList<T>::size() const {
    return size_;
}
