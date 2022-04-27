#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
private:
    vector<int> v;

public:
    void push(int e) {
        v.push_back(e);
    }

    int pop() {
        vector<int>::iterator p = v.begin();
        for(vector<int>::iterator iter = v.begin(); iter != v.end(); iter++) {
            if(*p < *iter) {
                p = iter;
            }
        }
        int maxValue = *p;
        v.erase(p);
        return maxValue;
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