//!  Copyright [2024] <André Lemos Piucco>

#include "./array_list.h"

namespace structures {

template<typename T>
class BinaryTree {
 public:
    BinaryTree();

    ~BinaryTree();

    // Node* search(const T& data);

    void insert(const T& data);

    void remove(const T& data);

    bool contains(const T& data) const;

    bool empty() const;

    std::size_t size() const;

    ArrayList<T> pre_order() const;

    ArrayList<T> in_order() const;

    ArrayList<T> post_order() const;

 private:
    struct Node {
        explicit Node(const T& data_) {
            data = data_;
            left = nullptr;
            right = nullptr;
        }

        T data;
        Node* left;
        Node* right;

        Node* search(Node *p, const T& data) {
            if (p == nullptr) {
                return nullptr;
            } else if (p->data == data) {
                return p;
            } else if (data < p->data) {
                return search(p->left, data);
            } else {
                return search(p->right, data);
            }
        }

        void insert(Node *p, const T& data_) {
            // COLOQUE SEU CÓDIGO AQUI... SE IMPLEMENTAÇÃO RECURSIVA
            if (empty()) {
                Node novo = new Node(data_);
                p = novo;
                size_++;
                return;
            }
            if (data_ <= p->data && p->left == nullptr) {
                Node novo = new Node(data_);
                p->left = novo;
            } else if (data_ > p->data && p->right == nullptr) {
                Node novo = new Node(data_);
                p->right = novo;
            } else if (data <= p->data) {
                return insert(p->left, data_);
            } else {
                return insert(p->right, data_);
            }
        }
            /* } else {}
            } else if (data <= novo.data())
            if (data <= novo.data()) {  // inserção à esquerda
                if (novo->left == nullptr) {
                    novo = new Node(data);
                    root->left(novo);
                } else {
                    novo->left->insert(data);
                }
            } else {  // inserção à direita
                if (novo->right == nullptr) {
                    novo = new Node(data);
                    root->right(novo);
                } else {
                    novo->right->insert(data);
                }
            } */

        void remove(Node *ant, Node *tmp, const T& data_) { /*
            // COLOQUE SEU CÓDIGO AQUI... SE IMPLEMENTAÇÃO RECURSIVA
            // Não destruir o pŕoprio, mas sim os filhos
            if (ant != nullptr) {
                while (true) {
                    if (tmp->left->data == data || tmp->right->data == data) {
                        break;
                    } else if (data_ < tmp->data) {
                        tmp = tmp->left;
                    } else if (data > tmp->data) {
                        tmp = tmp->right;
                    }
                }
                if (data_ < ant->data) {
                    ant->left->remove(ant->left, data_);
                } else if (data_ > ant->data) {
                    ant->right->remove(ant->right, data_);
                } else if ((ant->left != nullptr) && (ant->right != nullptr)) {
                    // encontrei o elemento
                    // caso dois filhos
                    tmp = ant->right;
                    while (tmp != nullptr) {
                        tmp = tmp->left;
                    }
                    ant->data = tmp->data;
                    tmp->remove(tmp, tmp->data);
                } else if ((ant->left != nullptr) != (ant->right != nullptr)) {
                    // caso um filho
                    if (tmp->left->data == data) {
                        if (ant->left != nullptr) {
                            tmp->left = ant->left;
                        } else {
                            tmp->left = ant->right;
                        }
                    } else {
                        if (ant->left != nullptr) {
                            tmp->right = ant->left;
                        } else {
                            tmp->right = ant->right;
                        }
                    }
                    delete ant;
                    // size_--;
                } else {
                    // caso folha
                    if (tmp->left->data == data) {
                        tmp->left = nullptr;
                    } else {
                        tmp->right = nullptr;
                    }
                    delete ant;
                    // size_--;
                }
            }
        */}
            /* if (empty()) {
	            throw std::out_of_range("Árvore vazia");
            } else if (size_ == 1 && ant->data == data_) {
                root = nullptr;
                delete ant;
                size_--;
            } 
            if (ant->left->data == data_) {
                
            } else if (ant->data)
            if (ant->data == data_) {
                // caso nó folha
                } else if (left == nullptr && right == nullptr) {
                    ant = nullptr;
                    delete remover;
                    size_--;
                // caso filho único
                } else if ((left == nullptr) != (right == nullptr)) {
                    if (left == nullptr) {
                        ant->left = left;
                        delete remover;
                    } else {
                        ant->right = right;
                        delete remover;
                    }
                // caso 2 dois filhos
                } else {
                    Node *p = right;
                    while (p != nullptr) {
                        p = p->left;
                    }
                    data = p->data;
                    p->remove(data_);
                }
            } else if (data < data_) {
                left->remove(data_);
            } else {
                right->remove(data_);
            }
        }
*/
        bool contains(Node *p, const T& data_) const {
            /* if (data_ == data) {
                return true;
            } else if (data_ < data) {
                if (left != nullptr) {
                    return left->contains(data_);
                } else {
                    return false;
                }
            } else {  // data_ > data
                if (right != nullptr) {
                    return right->contains(data_);
                } else {
                    return false;
                }
            }
            */
            if (empty()) {
                return false;
            } else if (data == p->data) {
                return true;
            } else if (data < p->data) {
                return contains(p->left, data);
            } else {
                return contains(p->right, data);
            }
        }

        void pre_order(ArrayList<T>& v) const {
            // COLOQUE SEU CÓDIGO AQUI...
            v.push_back(data);
            if (left)
                left->pre_order(v);
            if (right)
                right->pre_order(v);
        }

        void in_order(ArrayList<T>& v) const {
            // COLOQUE SEU CÓDIGO AQUI...
            if (left)
                left->in_order(v);
            v.push_back(data);
            if (right)
                right->in_order(v);
        }

        void post_order(ArrayList<T>& v) const {
            // COLOQUE SEU CÓDIGO AQUI...
            v.push_back(data);
            if (left)
                left->post_order(v);
            if (right)
                right->post_order(v);
        }
    };

    Node* root;
    std::size_t size_;
};

}  // namespace structures

//-------------------------------------

template<typename T>
structures::BinaryTree<T>::BinaryTree() {
    root = nullptr;
    size_ = 0;
}

template<typename T>
structures::BinaryTree<T>::~BinaryTree() {
    // COLOQUE SEU CÓDIGO AQUI...
    ArrayList<T> L = in_order();
    int i = 0;
    while (!empty()) {
        remove(L[i]);
        i++;
    }
}
/*
template<typename T>
Node* structures::BinaryTree<T>::search(const T& data) {
    if (empty()) {
        return nullptr;
    }
    Node *p = root;
    while (p != nullptr) {
        if (p->data == data) {
            return true;
        } else if (data < p->data) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    return p;
}

*/
template<typename T>
void structures::BinaryTree<T>::insert(const T& data) {
    // COLOQUE SEU CÓDIGO AQUI...
    Node *novo = new Node(data);
    if (empty()) {
        root = novo;
        size_++;
        return;
    }
    Node *p = root;
    while (true) {
        if (data <= p->data) {
            if (p->left == nullptr) {
                p->left = novo;
                break;
            }
            p = p->left;
        } else {
            if (p->right == nullptr) {
                p->right = novo;
                break;
            }
            p = p->right;
        }
    }
    size_++;
}

template<typename T>
void structures::BinaryTree<T>::remove(const T& data) {
    // COLOQUE SEU CÓDIGO AQUI...
    root->remove(root, root, data);
    size_--;
}

template<typename T>
bool structures::BinaryTree<T>::contains(const T& data) const {
    if (empty()) {
        return false;
    }
    Node *p = root;
    while (p != nullptr) {
        if (p->data == data) {
            return true;
        } else if (data < p->data) {
            p = p->left;
        } else {
            p = p->right;
        }
    }
    return false;
}

template<typename T>
bool structures::BinaryTree<T>::empty() const {
    return size() == 0;
}

template<typename T>
std::size_t structures::BinaryTree<T>::size() const {
    return size_;
}

template<typename T>
structures::ArrayList<T> structures::BinaryTree<T>::pre_order() const {
    structures::ArrayList<T> L;
	if (root != nullptr) {
		root->pre_order(L);
	}
	return L;
}

template<typename T>
structures::ArrayList<T> structures::BinaryTree<T>::in_order() const {
    // COLOQUE SEU CÓDIGO AQUI...
    structures::ArrayList<T> L;
	if (root != nullptr) {
		root->in_order(L);
	}
	return L;
}

template<typename T>
structures::ArrayList<T> structures::BinaryTree<T>::post_order() const {
    // COLOQUE SEU CÓDIGO AQUI...
    structures::ArrayList<T> L;
	if (root != nullptr) {
		root->post_order(L);
	}
	return L;
}
