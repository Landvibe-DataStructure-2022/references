#include <iostream>
#include <queue>

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
    Node *frontNode;
    Node *rearNode;
    int queueSize;

public:
    Queue() {
        frontNode = nullptr;
        rearNode = nullptr;
        queueSize = 0;
    }

    bool empty() {
        if (queueSize == 0) {
            return true;
        } else {
            return false;
        }
    }

    void enqueue(int value) {
        Node *enqueueNode = new Node;
        enqueueNode->value = value;

        if (empty()) {
            frontNode = rearNode = enqueueNode;
        } else {
            rearNode->next = enqueueNode;
            rearNode = enqueueNode;
        }
        queueSize++;
    }

    int dequeue() {
        if (empty()) {
//            cout<<"비어있을 때는 별도의 예외처리 필요\n";
            return -1;
        } else {
            Node *dequeueNode = frontNode;
            int returnValue = dequeueNode->value;

            frontNode = frontNode->next;
            delete dequeueNode;
            queueSize--;

            return returnValue;
        }
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        Queue cardsOfP1;
        Queue cardsOfP2;
        int remainHpOfP1 = 0;
        int remainHpOfP2 = 0;
        int pointOfP1 = 0;
        int pointOfP2 = 0;

        for (int i = 0; i < n; i++) {
            int card;
            cin >> card;
            cardsOfP1.enqueue(card);
        }
        for (int i = 0; i < n; i++) {
            int card;
            cin >> card;
            cardsOfP2.enqueue(card);
        }

        for (int i = 0; i < n; i++) {
            int cardOfP1 = cardsOfP1.dequeue() + remainHpOfP2;
            int cardOfP2 = cardsOfP2.dequeue() + remainHpOfP1;

            if (cardOfP1 > cardOfP2) {
                remainHpOfP1 = cardOfP1 - cardOfP2;
                remainHpOfP2 = 0;
                pointOfP1++;
            } else if (cardOfP1 < cardOfP2) {
                remainHpOfP1 = 0;
                remainHpOfP2 = cardOfP2 - cardOfP1;
                pointOfP2++;

            } else {
                remainHpOfP1 = remainHpOfP2 = 0;
            }
        }

        if (pointOfP1 >= pointOfP2) {
            cout << pointOfP1 << "\n";
        } else if (pointOfP1 < pointOfP2) {
            cout << pointOfP2 << "\n";
        }
    }

    return 0;
}