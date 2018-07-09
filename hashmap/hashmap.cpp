#include <iostream>
#include <string>
#include <iostream>
#include <type_traits>

template<class Key, class Value>
class HashMap {

    struct Entry {
        Key key;
        Value value;
        Entry *next;
    };

public:

    HashMap() {
        HashMap(11, 0.75);
    }

    HashMap(int initialSize, float lf);

    void add(Key key, Value value);

    Value get(Key key);

    bool remove(Key key); // todo

private:

    int getIndex(Key key);

    void double_the_trouble();

    float loadFactor{};
    int currentSize{};
    int numberOfEntries{};
    Entry **map;

};

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
HashMap<Key, Value>::HashMap(int initialSize, float lf) {
    numberOfEntries = 0;
    loadFactor = lf;
    currentSize = initialSize;
    map = new Entry *[currentSize];
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


int main() {
    auto mappo = new HashMap<std::string, int>();
    mappo->add("1", 10);
    mappo->add("2", 20);
    mappo->add("3", 30);
    mappo->add("4", 40);
    mappo->add("4", 44);
    mappo->add("5", 50);
    mappo->add("6", 60);
    mappo->add("7", 70);
    mappo->add("8", 80);
    mappo->add("9", 90);
    mappo->add("10", 100);
    mappo->add("11", 110);
    mappo->add("12", 120);
    std::cout << mappo->get("4") << std::endl;
    std::cout << mappo->get("12") << std::endl;
    return 0;
}