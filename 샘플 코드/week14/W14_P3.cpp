#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int t, n, m, a, b;
vector<int> graph[101];
bool visited[101];

void bfs() {
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        if (visited[top]) continue;
        visited[top] = true;
        cout << top << " ";
        for (auto i : graph[top]) {
            if (!visited[i]) q.push(i);
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        while (m--) {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bfs();
        cout << "\n";
        for (int i = 0; i <= 100; i++) {
            graph[i].clear();
            visited[i] = false;
        }
    }
}

