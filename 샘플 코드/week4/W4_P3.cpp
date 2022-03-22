#include <iostream>
#include <string>

using namespace std;

int n;

class Queue {
private:
    int queue[10000]{};
    int frontIndex;
    int rearIndex;
    int queueSize;

public:
    Queue() {
        frontIndex = 0;
        rearIndex = -1;
        queueSize = 0;
    }

    void updateIndex() {
        frontIndex %= n;
        rearIndex %= n;
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
        if (queueSize >= n) {
            cout << "Full\n";
            return;
        }

        rearIndex++;
        updateIndex();
        queue[rearIndex] = value;
        queueSize++;
    }

    void dequeue() {
        if (isEmpty() == true) {
            cout << "Empty\n";
            return;
        }

        cout << queue[frontIndex] << "\n";
        frontIndex++;
        updateIndex();
        queueSize--;
    }

    void front() {
        if (isEmpty() == true) {
            cout << "Empty\n";
            return;
        }

        cout << queue[frontIndex] << "\n";
    }

    void rear() {
        if (isEmpty() == true) {
            cout << "Empty\n";
            return;
        }

        cout << queue[rearIndex] << "\n";
    }
};

int main() {
    int t;
    cin >> n >> t;

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
            if (q.isEmpty() == true) {
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