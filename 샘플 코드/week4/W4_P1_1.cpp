#include <iostream>
#include <string>

using namespace std;

class Node {
private:
    Node *next;
    int value;

public:
    Node() {
        next = nullptr;
        value = 0;
    }

    friend class Queue;
};

class Queue {
private:
    Node *head;
    Node *tail;
    int queueSize;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
        queueSize = 0;
    }

    int size() {
        return queueSize;
    }

    bool isEmpty() {
        if (size() == 0) {
            return true;
        } else {
            return false;
        }
    }

    void enqueue(int value) {
        Node *newNode = new Node();
        newNode->value = value;

        if (isEmpty()) {
            head = tail = newNode;
            queueSize++;
        } else {
            tail->next = newNode;
            tail = newNode;
            queueSize++;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Empty\n";
        } else {
            Node *deleteNode = head;
            cout << deleteNode->value << "\n";

            if (queueSize == 1) {
                head = tail = nullptr;
            } else {
                head = deleteNode->next;
            }

            delete deleteNode;
            queueSize--;
        }
    }

    void front() {
        if (isEmpty()) {
            cout << "Empty\n";
        } else {
            cout << head->value << "\n";
        }
    }

    void rear() {
        if (isEmpty()) {
            cout << "Empty\n";
        } else {
            cout << tail->value << "\n";
        }
    }
};

int main() {
    int t;
    cin >> t;
    Queue q;

    while (t--) {
        string cmd;
        cin >> cmd;

        if (cmd == "enqueue") {
            int value;
            cin >> value;
            q.enqueue(value);
        } else if (cmd == "dequeue") {
            q.dequeue();
        } else if (cmd == "isEmpty") {
            if (q.isEmpty()) {
                cout << "True\n";
            } else {
                cout << "False\n";
            }
        } else if (cmd == "size") {
            cout << q.size() << "\n";
        } else if (cmd == "front") {
            q.front();
        } else if (cmd == "rear") {
            q.rear();
        }
    }

    return 0;
}