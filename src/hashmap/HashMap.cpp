//
// Created by Manuel on 10.07.2018.
//

#ifndef CPP_HASHMAP_H
#define CPP_HASHMAP_H

#include <iostream>
#include <string>
#include <type_traits>

template<class Key, class Value>
class HashMap {

    struct Entry {
        Key key;
        Value value;
        Entry *next;
    };

public:

    HashMap(int initialSize = 11, float lf = 0.75);

    void add(Key key, Value value);

    Value get(Key key);

    bool remove(Key key); // todo

private:

    int getIndex(Key key);

    void double_the_trouble();

    float loadFactor;
    int currentSize;
    int numberOfEntries;
    Entry **map;

};
#endif //CPP_HASHMAP_H

// The implementations for template classes have to be in the header file

template<class Key, class Value>
HashMap<Key, Value>::HashMap(int initialSize, float lf) {
    numberOfEntries = 0;
    loadFactor = lf;
    currentSize = initialSize;
    map = new Entry *[currentSize];
}

template<class Key, class Value>
bool HashMap<Key, Value>::remove(Key key) {
    return false; // todo
}

template<class Key, class Value>
void HashMap<Key, Value>::add(Key key, Value value) {
    int index = getIndex(key);

    auto newEntry = new Entry;
    newEntry->key = key,
    newEntry->value = value,
    newEntry->next = nullptr;

    Entry *entry = map[index];
    if (entry == nullptr) {
        map[index] = newEntry;
    } else {

        // Find entry
        while (entry->key != key && entry->next != nullptr) {
            entry = entry->next;
        }

        // Save entry
        if (entry->key == key) {
            // override entry
            entry->value = value;
            delete newEntry;
        } else {
            // create new entry
            entry->next = newEntry;
        }
    }

    numberOfEntries++;
    if (numberOfEntries > currentSize * loadFactor) {
        double_the_trouble();
    }
}

template<class Key, class Value>
void HashMap<Key, Value>::double_the_trouble() {
    Entry **oldMap = map;
    int oldSize = currentSize;
    currentSize *= 2;
    map = new Entry *[currentSize];
    numberOfEntries = 0;

    // Copy old values
    for (int i = 0; i < oldSize; i++) {
        Entry *entry = oldMap[i];
        while (entry != nullptr) {
            add(entry->key, entry->value);
            Entry *old = entry;
            entry = entry->next;
            delete old;
        }
    }

    delete[] oldMap;
}

template<class Key, class Value>
Value HashMap<Key, Value>::get(Key key) {
    int index = getIndex(key);
    Entry *entry = map[index];
    while (entry->key != key) {
        entry = entry->next;
    }
    return entry->value;
}

template<class Key, class Value>
int HashMap<Key, Value>::getIndex(Key key) {
    std::hash<std::string> hash_fn;
    auto index = static_cast<int>(hash_fn(key) % currentSize);
    return index;
}


