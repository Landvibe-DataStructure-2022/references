#include <iostream>
#include <vector>

using namespace std;

enum {
    MAX = -1, MIN = 1
};

class Heap {
private:
    vector<int> v;
    int heapSize;
    int rootIndex;
    int direction;

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
        if (isEmpty()) {
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
        if (isEmpty()) {
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
        if (isEmpty()) {
            cout << "-1\n";
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
    while (t--) {
        int n, p;
        cin >> n >> p;

        Heap heap(MIN);

        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            heap.insert(k);
        }

        bool isPossible = false;
        int count = 0;
        while (true) {
            if (heap.top() >= p) {
                isPossible = true;
                break;
            }
            if(heap.size() == 1) {
                break;
            }
            int k1 = heap.pop();
            int k2 = heap.pop();
            heap.insert((k1 + k2) / 2);
            count++;
        }

        if (isPossible) {
            cout << count << "\n";
            heap.print();
        } else {
            cout << "False\n";
        }
    }
}