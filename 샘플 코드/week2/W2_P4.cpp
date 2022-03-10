#include <iostream>
#include <string>

using namespace std;

class Node {
private:
    int value;
    Node *next;
    Node *prev;

public:
    Node() {
        this->value = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }

    ~Node() {
        this->value = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }

    friend class LinkedList;
};

class LinkedList {
private:
    Node *head;
    Node *tail;
    int size;

public:
    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    ~LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    bool empty() {
        if (this->size == 0) {
            return true;
        } else {
            return false;
        }
    }

    void printNode() {
        if (empty()) {
            cout << "empty";
            return;
        }

        Node *curNode = this->head;
        while (curNode != nullptr) {
            cout << curNode->value << " ";
            curNode = curNode->next;
        }
    }

    void appendNode(int x) {
        Node *appendNode = new Node;
        appendNode->value = x;

        if (empty()) {
            this->head = appendNode;
            this->tail = appendNode;
        } else {
            this->tail->next = appendNode;
            appendNode->prev = this->tail;
            this->tail = appendNode;
        }

        this->size++;
        printNode();
    }

    int deleteNode(int index) {
        if (index >= this->size) {
            return -1;
        }

        Node *deleteNode = this->head;

        if (index == 0) {
            if (this->size == 1) {
                this->head = nullptr;
                this->tail = nullptr;
            } else {
                this->head = deleteNode->next;
                deleteNode->next->prev = nullptr;
            }
        } else {
            Node *prevNode = this->head;
            for (int i = 0; i < index; i++) {
                prevNode = deleteNode;
                deleteNode = deleteNode->next;
            }
            prevNode->next = deleteNode->next;
            if (deleteNode == this->tail) {
                this->tail = prevNode;
            } else {
                deleteNode->next->prev = prevNode;
            }
        }

        int deleteValue = deleteNode->value;
        delete deleteNode;
        this->size--;
        return deleteValue;
    }

    void printReverseNode() {
        if (empty()) {
            cout << "empty";
            return;
        }

        Node *curNode = this->tail;
        while (curNode != nullptr) {
            cout << curNode->value << " ";
            curNode = curNode->prev;
        }
    }

    int sumNode() {
        int sumValue = 0;
        Node *curNode = this->head;

        while (curNode != nullptr) {
            sumValue += curNode->value;
            curNode = curNode->next;
        }

        return sumValue;
    }
};

int main() {
    int m;
    cin >> m;

    LinkedList *dll = new LinkedList;

    while (m--) {
        string cmd;
        int index;
        int x;
        cin >> cmd;

        if (cmd == "Print") {
            dll->printNode();
        } else if (cmd == "Append") {
            cin >> x;
            dll->appendNode(x);
        } else if (cmd == "Delete") {
            cin >> index;
            cout << dll->deleteNode(index);
        } else if (cmd == "Print_reverse") {
            dll->printReverseNode();
        } else if (cmd == "Sum") {
            cout << dll->sumNode();
        }
        cout << "\n";
    }

    return 0;
}