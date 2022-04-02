#include <iostream>
#include <vector>
using namespace std;

class Node {
private:
    Node* parent;
    vector<Node*> child;
    int value;
    int level;

public:
    Node() {
        parent = nullptr;
        value = 0;
        level = 1;
    }

    Node(int v) {
        parent = nullptr;
        value = v;
        level = 1;
    }

    Node(Node* p, int v, int l) {
        parent = p;
        value = v;
        level = l;
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

    void insertNode(int parentValue, int childValue) {
        Node* parentNode = findNode(parentValue);
        Node* childNode = new Node(parentNode, childValue, parentNode->level + 1);

        parentNode->child.push_back(childNode);
        nodeList.push_back(childNode);
    }

    void printLevel(int v) {
        Node* curNode = findNode(v);

        if(curNode == nullptr) {
            cout<<"-1\n";
        } else {
            cout<<curNode->level<<"\n";
        }
    }
};

int main() {
    int n, m;
    Tree* tree = new Tree();

    cin>>n>>m;

    while(n--) {
        int x, y;
        cin>>x>>y;

        tree->insertNode(x, y);
    }

    while(m--) {
        int x;
        cin>>x;

        tree->printLevel(x);
    }

    return 0;
}