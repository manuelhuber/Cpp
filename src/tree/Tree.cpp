//
// Created by Manuel on 23.07.2018.
//

#ifndef CPP_TREE_H
#define CPP_TREE_H

#include "Node.cpp"


template<class T>
class Tree {
public:
    Node<T> *find(T) const;

    bool remove(T);

    int depth() const;

    bool setRoot(T);

    Node<T> *getRoot();

private:
    Node<T> *root;

};

template<class T>
Node<T> *Tree<T>::getRoot() {
    return root;
}

template<class T>
bool Tree<T>::setRoot(T t) {
    auto oldRoot = root;
    root = new Node<T>(t);
    if (oldRoot != nullptr) {
        root->addChild(oldRoot);
    }
    return false;
}

template<class T>
Node<T> *Tree<T>::find(T t) const {
    return root->find(t);
}

template<class T>
bool Tree<T>::remove(T t) {
    if (root == nullptr) return false;
    if (root->value == t) {
        root = nullptr;
        return true;
    }
    return root->remove(root->find(t));
}

template<class T>
int Tree<T>::depth() const {
    if (root == nullptr) return 0;
    return root->depth();
}


#endif //CPP_TREE_H
