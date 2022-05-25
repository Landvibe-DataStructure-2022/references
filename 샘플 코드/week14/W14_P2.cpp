#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int t, n, m, k, a, b;
vector<int> graph[101];
bool visited[101];

int bfs(int start,int end) {
    queue<pair<int,int>> q;
    q.push({ start,0 });
    while (!q.empty()) {
        int front = q.front().first;
        int count = q.front().second;
        q.pop();
        if (front == end) return count;
        if (visited[front]) continue;
        visited[front] = true;
        for (auto i : graph[front]) {
            if (!visited[i]) q.push({ i,count + 1 });
        }
    }
    return 0;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        while (m--) {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        while (k--) {
            cin >> a >> b;
            cout << bfs(a, b) << "\n";
            for (int i = 0; i <= 100; i++) {
                visited[i] = false;
            }
        }
        for (int i = 0; i <= 100; i++) {
            graph[i].clear();
        }
    }
}
