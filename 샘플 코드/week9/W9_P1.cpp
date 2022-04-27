#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
private:
    vector<int> v;

public:
    bool empty() {
        return v.size() == 0;
    }

    void push(int e) {
        if (empty()) {
            v.push_back(e);
        } else {
            vector<int>::iterator iter;
            for (iter = v.begin(); iter != v.end(); iter++) {
                if (e < *iter) {
                    v.insert(iter, e);
                    return;
                }
            }
            v.insert(v.end(), e);
        }
    }

    int pop() {
        if (!empty()) {
            int value = v.front();
            v.erase(v.begin());
            return value;
        } else {
            return 0;
        }
    }
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> v;
        PriorityQueue pq;

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            v.push_back(num);
        }

        for (int i = 0; i < n; i++) {
            pq.push(v.front());
            v.erase(v.begin());
        }

        for (int i = 0; i < n; i++) {
            v.push_back(pq.pop());
        }

        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}