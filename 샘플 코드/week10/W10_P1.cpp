#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum {
    MAX = -1, MIN = 1
};

class Heap {
private:
    vector<int> v;
    int heapSize;
    int rootIndex;
    int direction; // direction 이 1이면 minHeap, -1이면 maxHeap

public:
    Heap(int dir) {
        v.push_back(-1);
        heapSize = 0;
        rootIndex = 1;
        direction = dir;
    }

    void swap(int index1, int index2) {
        v[0] = v[index1];
        v[index1] = v[index2];
        v[index2] = v[0];
    }

    void upHeap(int index) {
        if (index == rootIndex) {
            return;
        } else {
            int parent = index / 2;
            if (v[parent] * direction > v[index] * direction) {
                swap(parent, index);
                upHeap(parent);
            }
        }
    }

    void downHeap(int index) {
        int left = index * 2;
        int right = index * 2 + 1;
        if (right <= heapSize) {
            if (v[left] * direction <= v[right] * direction) {
                if (v[left] * direction < v[index] * direction) {
                    swap(left, index);
                    downHeap(left);
                } else {
                    return;
                }
            } else {
                if (v[right] * direction < v[index] * direction) {
                    swap(right, index);
                    downHeap(right);
                } else {
                    return;
                }
            }
        } else if (left <= heapSize) {
            if (v[left] * direction < v[index] * direction) {
                swap(left, index);
                downHeap(left);
            } else {
                return;
            }
        } else {
            return;
        }
    }

    void insert(int e) {
        v.push_back(e);
        heapSize++;
        upHeap(heapSize);
    }

    int pop() {
        if(isEmpty()) {
            return -1;
        } else {
            int top = v[rootIndex];
            v[rootIndex] = v[heapSize];
            heapSize--;
            v.pop_back();
            downHeap(rootIndex);
            return top;
        }
    }

    int top() {
        if(isEmpty()) {
            return -1;
        } else {
            return v[rootIndex];
        }
    }

    int size() {
        return heapSize;
    }

    bool isEmpty() {
        return heapSize == 0;
    }

    void print() {
        if(isEmpty()) {
            cout<<"-1\n";
        } else {
            for (int i = rootIndex; i <= heapSize; i++) {
                cout << v[i] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    Heap heap(MAX);

    while (t--) {
        string cmd;
        cin >> cmd;

        if (cmd == "insert") {
            int i;
            cin >> i;
            heap.insert(i);
        } else if (cmd == "size") {
            cout << heap.size() << "\n";
        } else if (cmd == "isEmpty") {
            cout << heap.isEmpty() << "\n";
        } else if (cmd == "pop") {
            cout << heap.pop() << "\n";
        } else if (cmd == "top") {
            cout << heap.top() << "\n";
        } else if (cmd == "print") {
            heap.print();
        }
    }
    return 0;
}