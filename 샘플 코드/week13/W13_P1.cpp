#include <iostream>
#include <string>

using namespace std;

// input
int t, n, vertex, s, d;
string cmd;
// variables
bool graph[2000][2000];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t >> n;

    for (int i = 0; i < n; i++) {
        cin >> vertex;
    }

    for (int i = 0; i < t; i++) {
        cin >> cmd >> s >> d;

        if(cmd == "insertEdge") {
            if(graph[s][d]) {
                cout<<"Exist\n";
            } else {
                graph[s][d] = true;
                graph[d][s] = true;
            }
        } else if(cmd == "eraseEdge") {
            if(!graph[s][d]) {
                cout<<"None\n";
            } else {
                graph[s][d] = false;
                graph[d][s] = false;
            }
        } else if(cmd == "isAdjacentTo") {
            if(graph[s][d]) {
                cout<<"True\n";
            } else {
                cout<<"False\n";
            }
        }
    }

    return 0;
}