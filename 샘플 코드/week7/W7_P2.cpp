#include <iostream>
#include <vector>

using namespace std;

vector<int> nodeValue;
vector<int> nodeDepth;

class Node {
private:
    Node *parent;
    vector<Node *> child;
    int value;

public:
    Node() {
        parent = nullptr;
        value = 0;
    }

    Node(int v) {
        parent = nullptr;
        value = v;
    }

    Node(Node *p, int v) {
        parent = p;
        value = v;
    }

    friend class Tree;
};

class Tree {
private:
    Node *root;

public:
    Tree() {
        root = nullptr;
    }

    Node *getRoot() {
        return root;
    }

    void makeTree() {
        int depth = -1;
        Node *curNode = root;
        for (int i = 0; i < nodeDepth.size(); i++) {
            if (nodeDepth[i] == 0) {
                root = new Node(nodeValue[i]);
                depth = nodeDepth[i];
                curNode = root;
            } else {
                if (depth < nodeDepth[i]) {
                    // 직전 노드의 depth 보다 현재 노드의 depth 가 더 클 때
                    // 갑자기 depth 2 이상 내려갈 수 없다는 점을 파악 해야함
                    // 현재 노드가 직전 노드의 자식 이라는 것을  의미
                    Node *newNode = new Node(curNode, nodeValue[i]);
                    curNode->child.push_back(newNode);
                    curNode = newNode;
                } else if (depth == nodeDepth[i]) {
                    // 직전 노드의 depth 와 현재 노드의 depth 가 같을 때
                    // 직전 노드와 현재 노드는 형제 관계
                    Node *newNode = new Node(curNode->parent, nodeValue[i]);
                    curNode->parent->child.push_back(newNode);
                    curNode = newNode;
                } else if (depth > nodeDepth[i]) {
                    // 직전 노드의 depth 보다 현재 노드의 depth 가 더 작을 때
                    // 직전 노드의 조상 중 현재 노드와 같은 depth 를 가진 조상을 찾아 그 조상의 형제로 연결 해줘야 한다
                    while (depth != nodeDepth[i]) {
                        curNode = curNode->parent;
                        depth--;
                    }
                    Node *newNode = new Node(curNode->parent, nodeValue[i]);
                    curNode->parent->child.push_back(newNode);
                    curNode = newNode;
                }
                depth = nodeDepth[i];
            }
        }
    }

    void postOrderTraversal(Node *r) {
        for (int i = 0; i < r->child.size(); i++) {
            postOrderTraversal(r->child[i]);
        }

        cout << r->value << " ";
    }
};

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        Tree *tree = new Tree();
        cin >> n;

        nodeValue.clear();
        nodeDepth.clear();

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            nodeValue.push_back(value);
        }

        for (int i = 0; i < n; i++) {
            int depth;
            cin >> depth;
            nodeDepth.push_back(depth);
        }

        tree->makeTree();
        tree->postOrderTraversal(tree->getRoot());
        cout << "\n";

        delete tree;
    }
    return 0;
}