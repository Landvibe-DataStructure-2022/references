#include <iostream>
#include <string>

using namespace std;

class Node {
private:
    int value;
    Node *next;

public:
    Node() {
        this->value = 0;
        this->next = nullptr;
    }

    ~Node() {
        this->value = 0;
        this->next = nullptr;
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
            }
        }

        int deleteValue = deleteNode->value;
        delete deleteNode;
        this->size--;
        return deleteValue;
    }

    void insertNode(int index, int x) {
        if (index > this->size) {
            cout << "Index Error";
            return;
        }

        if (index == 0) {
            Node *insertNode = new Node;
            insertNode->value = x;
            insertNode->next = this->head;
            this->head = insertNode;
            printNode();
        } else if (index == this->size) {
            appendNode(x);
        } else {
            Node *insertNode = new Node;
            insertNode->value = x;

            Node *curNode = this->head;
            for (int i = 1; i < index; i++) {
                curNode = curNode->next;
            }
            insertNode->next = curNode->next;
            curNode->next = insertNode;
            printNode();
        }

        this->size++;
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

    LinkedList *ll = new LinkedList;

    while (m--) {
        string cmd;
        int index;
        int x;
        cin >> cmd;

        if (cmd == "Print") {
            ll->printNode();
        } else if (cmd == "Append") {
            cin >> x;
            ll->appendNode(x);
        } else if (cmd == "Delete") {
            cin >> index;
            cout << ll->deleteNode(index);
        } else if (cmd == "Insert") {
            cin >> index >> x;
            ll->insertNode(index, x);
        } else if (cmd == "Sum") {
            cout << ll->sumNode();
        }
        cout << "\n";
    }

    return 0;
}