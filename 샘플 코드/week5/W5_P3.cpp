#include <iostream>
#include <string>

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
    Node *head;
    Node *tail;
    int size;

public:
    Sequence() {
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    Node *begin() {
        return head->next;
    }

    Node *end() {
        return tail;
    }

    void insert(Iterator &p, int e) {
        Node *newNode = new Node();
        newNode->value = e;

        p.node->prev->next = newNode;
        newNode->prev = p.node->prev;
        newNode->next = p.node;
        p.node->prev = newNode;

        size++;
    }

    void erase(Iterator &p) {
        if (size == 0) {
            cout << "Empty\n";
        } else {
            Node *deleteNode = p.node;

            deleteNode->prev->next = deleteNode->next;
            deleteNode->next->prev = deleteNode->prev;

            delete deleteNode;
            p.node = begin();

            size--;
        }
    }

    void reversePrint() {
        if (size == 0) {
            cout << "Empty\n";
        } else {
            Node *curNode = tail->prev;
            while (curNode != head) {
                cout << curNode->value << " ";
                curNode = curNode->prev;
            }
            cout << "\n";
        }
    }

    void find(int e) {
        if (size == 0) {
            cout << "Empty\n";
        } else {
            Node *curNode = head->next;
            int index = 0;

            while (curNode != nullptr) {
                if (curNode->value == e) {
                    cout << index << "\n";
                    return;
                } else {
                    curNode = curNode->next;
                    index++;
                }
            }
            cout << "-1\n";
        }
    }
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int m;
    cin >> m;

    Sequence seq = Sequence();
    Iterator p = Iterator();
    p = seq.begin();

    while (m--) {
        string cmd;
        cin>>cmd;

        int e;
        if(cmd == "begin") {
            p = seq.begin();
        } else if(cmd == "end") {
            p = seq.end();
        } else if(cmd == "insert") {
            cin>>e;
            seq.insert(p, e);
        } else if(cmd == "erase") {
            seq.erase(p);
        } else if(cmd == "++") {
            ++p;
        } else if(cmd == "--") {
            --p;
        } else if(cmd == "reversePrint") {
            seq.reversePrint();
        } else if(cmd == "find") {
            cin>>e;
            seq.find(e);
        }
    }
}