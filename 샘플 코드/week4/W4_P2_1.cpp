#include <iostream>

using namespace std;

class Queue {
private:
    int queue[100]{};
    int frontIndex;
    int rearIndex;
    int queueSize;

public:
    Queue() {
        frontIndex = 0;
        rearIndex = -1;
        queueSize = 0;
    }

    void enqueue(int value) {
        rearIndex++;
        queue[rearIndex] = value;
        queueSize++;
    }

    int dequeue() {
        int returnValue = queue[frontIndex];
        frontIndex++;
        return returnValue;
        queueSize--;
    }

    int front() {
        return queue[frontIndex]++;
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
            int cardOfP1 = cardsOfP1.dequeue() + remainHpOfP1;
            int cardOfP2 = cardsOfP2.dequeue() + remainHpOfP2;

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

        if (pointOfP1 > pointOfP2) {
            cout << "1\n";
        } else if (pointOfP1 < pointOfP2) {
            cout << "2\n";
        } else {
            cout << "0\n";
        }
    }

    return 0;
}