#include <iostream>
#include <vector>

using namespace std;

int n, m, k, v;
int graph[501][501];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> k;

        vector<int> group;
        for (int j = 0; j < k; j++) {
            cin >> v;
            group.push_back(v);
        }

        int result = 0;
        for (int j = 0; j < group.size(); j++) {
            for (int l = 0; l < group.size(); l++) {
                if (j == l) continue;

                result = 0;

                if (graph[group[j]][group[l]] == 1) {
                    // 친구인 경우
                    result = 1;
                } else {
                    // 친구의 친구인 경우
                    for (int o = 1; o <= n; o++) {
                        if (graph[group[j]][o] == 1 && graph[o][group[l]] == 1) {
                            result = 1;
                            break;
                        }
                    }
                }
                if (result == 0) {
                    break;
                }
            }
            if (result == 0) {
                break;
            }
        }
        cout << result << "\n";
    }

    return 0;
}