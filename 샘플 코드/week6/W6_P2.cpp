#include <iostream>
#include <vector>
using namespace std;

class Node {
private:
    Node* parent;
    vector<Node*> child;
    int value;
    int depth;

public:
    Node() {
        parent = nullptr;
        value = 0;
        depth = 0;
    }

    Node(int v) {
        parent = nullptr;
        value = v;
        depth = 0;
    }

    Node(Node* p, int v, int d) {
        parent = p;
        value = v;
        depth = d;
    }

    friend class Tree;
};

class Tree {
private:
    Node* root;
    vector<Node*> nodeList;

public:
    Tree() {
        root = new Node(1);
        nodeList.push_back(root);
    }

    Node* findNode(int v) {
        for(int i=0;i<nodeList.size();i++) {
            if(nodeList[i]->value == v) {
                return nodeList[i];
            }
        }
        return nullptr;
    }

    void insertNode(int p, int v) {
        Node* parentNode = findNode(p);
        Node* newNode = new Node(parentNode, v, parentNode->depth + 1);

        parentNode->child.push_back(newNode);
        nodeList.push_back(newNode);
    }

    void printDepth(int v) {
        Node* targetNode = findNode(v);
        if(targetNode == nullptr) {
            cout<<"-1\n";
        } else {
            cout << targetNode->depth << "\n";
        }
    }
};

int main() {
    int n, m;
    cin>>n>>m;

    Tree* tree = new Tree();

    while(n--) {
        int parentValue, childValue;
        cin>>parentValue>>childValue;

        tree->insertNode(parentValue, childValue);
    }

    while(m--) {
        int targetValue;
        cin>>targetValue;

        tree->printDepth(targetValue);
    }

    return 0;
}