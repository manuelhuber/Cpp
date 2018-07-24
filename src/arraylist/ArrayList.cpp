//
// Created by Manuel on 23.07.2018.
//

#ifndef CPP_ARRAYLIST_H
#define CPP_ARRAYLIST_H

template<class T>
class ArrayList {
public:
    ArrayList();

    void add(T *);

    bool remove(int);

    int size();

    T *get(int);

private:
    void grow();

    int nextIndex;
    int max;
    T **data;
};

template<class T>
ArrayList<T>::ArrayList() {
    nextIndex = 0;
    max = 10;
    data = new T *[max];
}

template<class T>
void ArrayList<T>::add(T *t) {
    if (max - nextIndex < 1) grow();
    data[nextIndex++] = t;
}

template<class T>
bool ArrayList<T>::remove(int i) {
    if (i >= nextIndex) return false;
    i++;
    for (; i < nextIndex; i++) {
        data[i - 1] = data[i];
    }
    data[nextIndex - 1] = nullptr;
    nextIndex--;
    return true;
}

template<class T>
T *ArrayList<T>::get(int index) {
    return data[index];
}

template<class T>
void ArrayList<T>::grow() {
    T **oldData = data;
    int oldSize = max;
    max *= 2;
    data = new T *[max];

    // Copy old values
    for (int i = 0; i < nextIndex; i++) {
        data[i] = oldData[i];
    }

    delete[] oldData;
}

template<class T>
int ArrayList<T>::size() {
    return nextIndex;
}


#endif //CPP_ARRAYLIST_H
