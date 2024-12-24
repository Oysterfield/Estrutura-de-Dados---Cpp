// Copyright 2024 <Copyright Owner> André Lemos Piucco
#ifndef STRUCTURES_DOUBLY_CIRCULAR_LIST_H
#define STRUCTURES_DOUBLY_CIRCULAR_LIST_H

#include <cstdint>
#include <stdexcept>  // C++ exceptions

namespace structures {

template<typename T>
class DoublyCircularList {
 public:
    DoublyCircularList();
    ~DoublyCircularList();

    void clear();

    void push_back(const T& data);  // insere no fim
    void push_front(const T& data);  // insere no início
    void insert(const T& data, std::size_t index);  // insere na posição
    void insert_sorted(const T& data);  // insere em ordem

    T pop(std::size_t index);  // retira da posição
    T pop_back();  // retira do fim
    T pop_front();  // retira do início
    void remove(const T& data);  // retira específico

    bool empty() const;  // lista vazia
    bool contains(const T& data) const;  // contém

    T& at(std::size_t index);  // acesso a um elemento (checando limites)
    const T& at(std::size_t index) const;  // getter constante a um elemento

    std::size_t find(const T& data) const;  // posição de um dado
    std::size_t size() const;  // tamanho

 private:
    class Node {
     public:
        //! metodo construtor
        explicit Node(const T& data):
            data_{data}
        {}
        //! metodo construtor
        Node(const T& data, Node* next):
            data_{data},
            next_{next}
        {}
        //! metodo construtor
        Node(const T& data, Node* prev, Node* next):
            data_{data},
            prev_{prev},
            next_{next}
        {}
        //! metodo retornar dado
        T& data() {  // getter: dado
            return data_;
        }
        //! metodo retornar dado
        const T& data() const {  // getter const: dado
            return data_;
        }
        //! metodo retornar anterior
        Node* prev() {  // getter: próximo
            return prev_;
        }
        //! metodo retornar anterior
        const Node* prev() const {  // getter const: próximo
            return prev_;
        }
        //! metodo informar anterior
        void prev(Node* node) {  // setter: próximo
            prev_ = node;
        }
        //! metodo retornar proximo
        Node* next() {  // getter: próximo
            return next_;
        }
        //! metodo retornar proximo
        const Node* next() const {  // getter const: próximo
            return next_;
        }
        //! metodo informar proximo
        void next(Node* node) {  // setter: próximo
            next_ = node;
        }

     private:
        T data_;
        Node* prev_;
        Node* next_;
    };

    //! posicionamento do ponteiro pelo caminho mais curto
    Node *posicao(std::size_t index) {
        Node *p;
        if (index < size()/2) {  // do início para o fim
            p = head->next();
            for (std::size_t i = 0; i < index; i++) {
                p = p->next();
            }
        } else {  // do fim para o início
            p = head->prev();
            for (std::size_t i = size()-1; i > index; i--) {
                p = p->prev();
            }
        }
        return p;
    }

    Node* head;
    std::size_t size_;
};

}  // namespace structures

#endif

//! Construtor
template<typename T>
structures::DoublyCircularList<T>::DoublyCircularList() {
    Node *sentinela;
    sentinela = new Node(0);
    sentinela->next(sentinela);
    sentinela->prev(sentinela);
    head = sentinela;
    size_ = 0u;
}

//! Destrutor
template<typename T>
structures::DoublyCircularList<T>::~DoublyCircularList() {
    clear();
}

//! Esvazia
template<typename T>
void structures::DoublyCircularList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

//! Inserção no início
template<typename T>
void structures::DoublyCircularList<T>::push_front(const T& data) {
    Node *novo;
    if (empty()) {
        novo = new Node(data, head, head);
        if (novo == nullptr)
            throw std::out_of_range("memória insuficiente");
        head->prev(novo);
    } else {
        novo = new Node(data, head, head->next());
        if (novo == nullptr)
            throw std::out_of_range("memória insuficiente");
        head->next()->prev(novo);
    }
    head->next(novo);
    size_++;
}

//! Inserção no fim
template<typename T>
void structures::DoublyCircularList<T>::push_back(const T& data) {
    if (empty()) {
        return push_front(data);
    }
    Node *novo = new Node(data, head->prev(), head);
    if (novo == nullptr) {
        throw std::out_of_range("memória insuficiente");
    }
    novo->prev()->next(novo);
    head->prev(novo);
    size_++;
}

//! Dado da posição 'index'
template<typename T>
T& structures::DoublyCircularList<T>::at(std::size_t index) {
    /*
        COLOQUE SEU CÓDIGO AQUI...
    */
    if (empty()) {
       throw std::out_of_range("lista vazia");
    }
    if (index >= size())
        throw std::out_of_range("índice maior que a lista");
    Node *p = posicao(index);
    return p->data();
}

//! Inserção na posição 'index'
template<typename T>
void structures::DoublyCircularList<T>::insert(const T& data,std::size_t index){
    /*
    
        COLOQUE SEU CÓDIGO AQUI...
    
    */
    if (index > size())
        throw std::out_of_range("índice maior que lista");
    if (index == size())
        return push_back(data);
    if (index == 0)
        return push_front(data);
    Node *ant = posicao(index-1);
    Node *novo = new Node(data, ant, ant->next());
    if (novo == nullptr)
        throw std::out_of_range("memória insuficiente");
    novo->next()->prev(novo);
    ant->next(novo);
    size_++;
}

//! Inserção ordenada
template<typename T>
void structures::DoublyCircularList<T>::insert_sorted(const T& data) {
    /*
    
        COLOQUE SEU CÓDIGO AQUI...
    
    */
    if (empty()) {
        return push_front(data);
    }
    Node *p = head;
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
T structures::DoublyCircularList<T>::pop_front() {
    if (empty()) {
        throw std::out_of_range("lista vazia");
    }
    T retorno;
    Node *eliminar;
    eliminar = head->next();
    head->next(eliminar->next());
    retorno = eliminar->data();
    delete eliminar;
    size_--;
    return retorno;
}

//! Remoção do fim
template<typename T>
T structures::DoublyCircularList<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("lista vazia");
    }
    if (size() == 1) {
        return pop_front();
    }
    T aux;
    Node *eliminar, *ant;
    eliminar = head->prev();
    ant = head->prev()->prev();
    aux = eliminar->data();
    ant->next(head);
    head->prev(ant);
    delete eliminar;
    size_--;
    return aux;
}

//! Remoção da posição 'index'
template<typename T>
T structures::DoublyCircularList<T>::pop(std::size_t index) {
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
    Node *ant = posicao(index-1);
    Node *eliminar = ant->next();
    T aux = eliminar->data();
    ant->next(eliminar->next());
    eliminar->next()->prev(ant);
    delete eliminar;
    size_--;
    return aux;
}

//! Remoção de um dado
template<typename T>
void structures::DoublyCircularList<T>::remove(const T& data) {
    pop(find(data));
}

//! Verificação de vazia
template<typename T>
bool structures::DoublyCircularList<T>::empty() const {
    return (size() == 0u);
}

//! Verificação se contém um dado
template<typename T>
bool structures::DoublyCircularList<T>::contains(const T& data) const {
    return find(data) != size();
}

//! Índice de um dado (se existir); ou 'size() (se não existir)
template<typename T>
std::size_t structures::DoublyCircularList<T>::find(const T& data) const {
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
std::size_t structures::DoublyCircularList<T>::size() const {
    return size_;
}
