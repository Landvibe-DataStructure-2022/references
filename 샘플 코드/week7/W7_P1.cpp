#include <iostream>
#include <vector>
using namespace std;

class Node {
private:
    Node* parent;
    vector<Node*> child;
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

    Node(Node* p, int v) {
        parent = p;
        value = v;
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
        root->parent = new Node();
        nodeList.push_back(root);
    }

    Node* getRoot() {
        return root;
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
        Node* newNode = new Node(parentNode, childValue);

        parentNode->child.push_back(newNode);
        nodeList.push_back(newNode);
    }

    void preOrderTraversal(Node* r) {
        if(r == root) {
            cout<<"0 ";
        } else {
            cout<<r->parent->value<<" ";
        }

        for(int i=0;i<r->child.size();i++) {
            preOrderTraversal(r->child[i]);
        }
    }
};

int main() {
    int t, n;
    cin>>t;

    while(t--) {
        Tree* tree = new Tree();

        cin>>n;
        while(n--) {
            int parentValue, childValue;
            cin>>parentValue>>childValue;
            tree->insertNode(parentValue, childValue);
        }

        tree->preOrderTraversal(tree->getRoot());
        cout<<"\n";

        delete tree;
    }
    return 0;
}