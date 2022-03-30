#include <iostream>

using namespace std;

class Node {
private:
    Node *next;
    Node *prev;
    int value;

public:
    Node() {
        next = prev = nullptr;
        value = 0;
    }

    Node(int v) {
        next = prev = nullptr;
        value = v;
    }

    friend class Iterator;

    friend class Sequence;
};

class Iterator {
private:
    Node *node;

public:
    Iterator() {
        node = nullptr;
    }

    Iterator(Node *n) {
        node = n;
    }

    Iterator *operator++() {
        node = node->next;
        return this;
    }

    Iterator *operator--() {
        node = node->prev;
        return this;
    }

    friend class Sequence;
};

class Sequence {
private:
    Node *header;
    Node *trailer;
    int size;

public:
    Sequence() {
        header = new Node;
        trailer = new Node;
        header->next = trailer;
        trailer->prev = header;
        size = 0;
    }

    Node *begin() {
        return header->next;
    }

    void insert(Iterator &p, int v) {
        Node *newNode = new Node(v);

        p.node->prev->next = newNode;
        newNode->prev = p.node->prev;
        newNode->next = p.node;
        p.node->prev = newNode;

        size++;
    }

    void findConvolution(Iterator &p) {
        int num1 = p.node->prev->value;
        int num2 = p.node->value;
        int num3 = p.node->next->value;

        cout<<num1*1 + num2*3 + num3*1<<" ";
    }
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t, n;
    cin >> t;

    while (t--) {
        Sequence seq = Sequence();
        Iterator p = Iterator(seq.begin());

        cin >> n;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;

            seq.insert(p, num);
        }

        p = seq.begin();

        for(int i=0;i<n;i++) {
            seq.findConvolution(p);
            ++p;
        }
        cout<<"\n";
    }

    return 0;
}