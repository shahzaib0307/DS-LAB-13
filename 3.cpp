#include <iostream>
#include <list>
using namespace std;

class Hash {
    int capacity;
    list<int>* table;

    int hashFunction(int key) {
        return key % capacity;
    }

public:
    Hash(int size) {
        capacity = size;
        table = new list<int>[capacity];
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (int val : table[index]) {
            if (val == key)
                return true;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << i << ": ";
            for (int val : table[i]) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Hash h(7);

    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(7);
    h.insert(32);

    h.display();

    h.remove(20);
    cout << "After deletion:" << endl;
    h.display();

    cout << "Search 15: " << (h.search(15) ? "Found" : "Not Found") << endl;
    cout << "Search 20: " << (h.search(20) ? "Found" : "Not Found") << endl;

    return 0;
}
