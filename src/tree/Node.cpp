//
// Created by Manuel on 23.07.2018.
//

#ifndef CPP_NODE_H
#define CPP_NODE_H

#include "ArrayList.cpp"

template<class T>
class Node {
public:
    explicit Node(T);

    Node<T> *find(T);

    T value;

    void addChild(Node *);

    int depth();

    bool remove(Node *);

private:
    ArrayList<Node> *children;
};

template<class T>
Node<T>::Node(T t) {
    this->value = t;
    children = new ArrayList<Node>();
}

template<class T>
void Node<T>::addChild(Node *node) {
    this->children->add(node);
}

template<class T>
bool Node<T>::remove(Node<T> *node) {
    for (int i = 0; i < children->size(); i++) {
        Node<T> *child = this->children->get(i);
        if (child == node) {
            this->children->remove(i);
            return true;
        } else if (child->remove(node)) {
            return true;
        }
    }
    return false;
}

template<class T>
Node<T> *Node<T>::find(T t) {
    if (value == t) return this;
    for (int i = 0; i < children->size(); i++) {
        Node<T> *result = children->get(i)->find(t);
        if (result != nullptr) return result;
    }
    return nullptr;
}

template<class T>
int Node<T>::depth() {
    int max = 0;
    for (int i = 0; i < children->size(); i++) {
        Node<T> *child = children->get(i);
        if (child->depth() > 0) max = child->depth();
    }
    return max + 1;
}


#endif //CPP_NODE_H
