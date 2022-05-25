#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int t, n, m, k, a, b;
vector<int> graph[101];
bool visited[101];

int bfs(int start) {
	queue<int> q;
	q.push(start);
	int connected = 0;
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		if (visited[front]) continue;
		visited[front] = true;
		++connected;
		for (auto i : graph[front]) {
			if (!visited[i]) q.push(i);
		}
	}
	return connected;
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
			cin >> a;
			cout<<bfs(a)<<"\n";
			for (int i = 0; i <= 100; i++) {
				visited[i] = false;
			}
		}
		for (int i = 0; i <= 100; i++) {
			graph[i].clear();
		}
	}
}
