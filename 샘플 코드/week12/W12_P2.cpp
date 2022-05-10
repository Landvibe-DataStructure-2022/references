#include <iostream>

#define NOITEM 0
#define ISITEM 1

using namespace std;

struct Entry {
    int key;
    bool value;
    int valid;

    Entry() {
        key = 0;
        value = false;
        valid = NOITEM;
    }

    Entry(int _key, bool _value) {
        key = _key;
        value = _value;
        valid = ISITEM;
    }
};

class HashTable {
private:
    Entry *hash_table;
    int x;
    int y;
    int indexA;
    int indexB;

    int hash_fun_a1(int key, int offset) {
        return (offset + key % x) % x;
    }

    int hash_fun_b1(int key, int offset) {
        if (offset - (key % y) < 0) {
            return y + (offset - (key % y));
        } else {
            return offset - (key % y);
        }
    }

    int hash_fun_a2(int key, int offset) {
        return offset - key < 0 ? x + (offset - key) : offset - key;
    }

    int hash_fun_b2(int key, int offset) {
        return (offset + 1) % y;
    }

public:
    HashTable(int _x, int _y) {
        x = _x;
        y = _y;
        hash_table = new Entry[x];
        indexA = 0;
        indexB = 0;
    }

    void put(int key, int idxA, int idxB) {
        indexA = hash_fun_a1(key, idxA);
        indexB = hash_fun_b1(key, idxB);
//        cout << "1차: ";
//        cout << "indexA = " << indexA << ", indexB = " << indexB << "\n";
        int probing = 1;

        if (hash_table[indexA].valid == ISITEM && probing <= x) {
            indexA = hash_fun_a1(indexB + 1, indexA);
            indexB = hash_fun_b1(indexB + 1, indexB);
//            cout << "2차: ";
//            cout << "indexA = " << indexA << ", indexB = " << indexB << "\n";
            probing++;
        }

        while (hash_table[indexA].valid == ISITEM && probing <= x) {
            indexA = hash_fun_a2(1, indexA);
            indexB = hash_fun_b2(1, indexB);
//            cout << "3차: ";
//            cout << "indexA = " << indexA << ", indexB = " << indexB << "\n";
            probing++;
        }

        if (probing > x) {
            return;
        }

        hash_table[indexA] = Entry(key, true);
        cout << indexA + 1 << " ";
    }

    int getIndexA() {
//        cout << "getIndexA() = " << indexA << "\n";
        return indexA;
    }

    int getIndexB() {
//        cout << "getIndexB() = " << indexB << "\n";
        return indexB;
    }
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int x, y, n;
        cin >> x >> y >> n;
        HashTable *hashTable = new HashTable(x, y);

        while (n--) {
            int k;
            cin >> k;

            int idxA = hashTable->getIndexA();
            int idxB = hashTable->getIndexB();

            hashTable->put(k, idxA, idxB);
        }
        cout << "\n";
    }

    return 0;
}