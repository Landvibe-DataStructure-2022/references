#include <iostream>
#include <string>

using namespace std;

int n;

class Node {
private:
    int value;
    Node *next;

public:
    Node() {
        this->value = 0;
        this->next = nullptr;
    }

    friend class LinkedList;

    friend class Stack;
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

    bool empty() {
        if (this->size == 0) {
            return true;
        } else {
            return false;
        }
    }

    // 링크드리스트의 맨 끝에 삽입하는 함수(스택에서 쓸거니까 맨 끝에서만 삽입하면 된다)
    void append(int x) {
        Node *appendNode = new Node;
        appendNode->value = x;

        if (empty()) {
            this->head = this->tail = appendNode;
        } else {
            this->tail->next = appendNode;
            this->tail = appendNode;
        }
        this->size++;
    }

    // 링크드리스트의 맨 끝에서 삭제하는 함수(스택에서 쓸거니까 맨 끝에서만 삭제하면 된다)
    // 추가로, empty 여부는 Stack 클래스에서 판단한다.
    int deleteNode() {
        int value = this->tail->value;

        if (this->size == 1) {
            delete this->head;
            this->head = this->tail = nullptr;
        } else {
            Node *curNode = this->head;
            while (curNode->next != this->tail) {
                curNode = curNode->next;
            }
            delete curNode->next;
            curNode->next = nullptr;
            this->tail = curNode;
        }
        this->size--;

        return value;
    }

    friend class Stack;
};

class Stack {
private:
    LinkedList ll;
    int size;

public:
    Stack() {
        ll = LinkedList();
        size = 0;
    }

    bool empty() {
        if (this->size == 0) {
            return true;
        } else {
            return false;
        }
    }

    void top() {
        if (empty()) {
            cout << "-1\n";
        } else {
            cout << ll.tail->value << "\n";
        }
    }

    void push(int x) {
        ll.append(x);
        this->size++;
    }

    void pop() {
        if (empty()) {
            cout << "-1\n";
        } else {
            cout << ll.deleteNode() << "\n";
            this->size--;
        }
    }
};

int main() {
    cin >> n;
    Stack st = Stack();

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
        int x;

        if (cmd == "empty") {
            if (st.empty()) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else if (cmd == "top") {
            st.top();
        } else if (cmd == "push") {
            cin >> x;
            st.push(x);
        } else if (cmd == "pop") {
            st.pop();
        }
    }

    return 0;
}