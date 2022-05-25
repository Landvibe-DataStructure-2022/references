#include<iostream>
#include<vector>
using namespace std;

int t, n, m, a, b;
vector<int> graph[101];
bool visited[101];

void dfs(int x) {
    cout << x << " ";
    visited[x] = true;
    for (auto i : graph[x]) {
        if (!visited[i]) dfs(i);
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
        dfs(1);
        cout << "\n";
        for (int i = 0; i <= 100; i++) {
            graph[i].clear();
            visited[i] = false;
        }
    }
}
