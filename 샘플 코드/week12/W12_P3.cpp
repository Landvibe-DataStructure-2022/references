#include <iostream>
#include <string>

#define NOITEM 0
#define ISITEM 1
#define AVAILABLE 2

using namespace std;

struct Entry {
    int key;
    string value;
    int valid;

    Entry() {
        key = 0;
        value = "";
        valid = NOITEM;
    }

    Entry(int _key, string _value) {
        key = _key;
        value = _value;
        valid = ISITEM;
    }

    void erase() {
        valid = AVAILABLE;
    }
};

class HashTable {
private:
    Entry *hash_table;
    int capacity;
    int divisor;

    int hash_func(int key) {
        return key % capacity;
    }

    int hash_func2(int key) {
        return divisor - (key % divisor);
    }

public:
    HashTable(int _capacity, int _divisior) {
        capacity = _capacity;
        divisor = _divisior;
        hash_table = new Entry[capacity];
    }

    void put(int key, string value) {
        int index = hash_func(key);
        int probing = 1;

        while (hash_table[index].valid == ISITEM && probing <= capacity) {
            index = hash_func(index + hash_func2(key));
            probing++;
        }

        cout << probing << "\n";

        if (probing > capacity) {
            return;
        }

        hash_table[index] = Entry(key, value);
    }

    void erase(int key) {
        int index = hash_func(key);
        int probing = 1;

        while (hash_table[index].valid != NOITEM && probing <= capacity) {
            if (hash_table[index].valid == ISITEM && hash_table[index].key == key) {
                hash_table[index].erase();
                return;
            }

            index = hash_func(index + hash_func2(key));
            probing++;
        }

        cout << "None\n";
    }

    string find(int key) {
        int index = hash_func(key);
        int probing = 1;

        while (hash_table[index].valid != NOITEM && probing <= capacity) {
            if (hash_table[index].valid == ISITEM && hash_table[index].key == key) {
                cout << hash_table[index].value << "\n";
                return hash_table[index].value;
            }

            index = hash_func(index + hash_func2(key));
            probing++;
        }

        cout << "None\n";
        return "";
    }
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t, n, m;
    cin >> t >> n >> m;

    HashTable *hashTable = new HashTable(n, m);
    while (t--) {
        string cmd;
        cin >> cmd;

        if (cmd == "put") {
            int key;
            string value;
            cin >> key >> value;

            hashTable->put(key, value);
        } else if (cmd == "erase") {
            int key;
            cin >> key;

            hashTable->erase(key);
        } else if (cmd == "find") {
            int key;
            cin >> key;

            hashTable->find(key);
        }
    }

    return 0;
};