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

    int rotate(int key, int offset, bool isClock, int divisor) {
        int returnValue = 0;
        if(isClock) {
            if(offset - (key % divisor) < 0) {
                returnValue = divisor + (offset - (key % divisor));
            } else {
                returnValue = offset - (key % divisor);
            }
        } else {
            returnValue = (offset + (key % divisor)) % divisor;
        }
        return returnValue;
    }

    int hash_func_a(int key, int offset, bool isClock) {
        return rotate(key, offset, isClock, x);
    }

    int hash_func_b(int key, int offset, bool isClock) {
        return rotate(key, offset, isClock, y);
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
        indexA = hash_func_a(key, idxA, false);
        indexB = hash_func_b(key, idxB, true);
        int probing = 1;

        if (hash_table[indexA].valid == ISITEM && probing <= x) {
            indexA = hash_func_a(indexB + 1, indexA, true);
            indexB = hash_func_b(indexB + 1, indexB, false);
            probing++;
        }

        while (hash_table[indexA].valid == ISITEM && probing <= x) {
            indexA = hash_func_a(1, indexA, false);
            indexB = hash_func_b(1, indexB, true);
            probing++;
        }

        if (probing > x) {
            return;
        }

        hash_table[indexA] = Entry(key, true);
        cout << indexA + 1 << " ";
    }

    int getIndexA() {
        return indexA;
    }

    int getIndexB() {
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