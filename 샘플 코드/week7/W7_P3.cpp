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

    void postOrderTraversal(Node* r) {
        for(int i=0;i<r->child.size();i++) {
            postOrderTraversal(r->child[i]);
        }

        if(r == root) {
            cout<<"0 ";
        } else {
            cout<<r->parent->value<<" ";
        }
    }
};

int main() {
    int t;
    cin>>t;

    while(t--) {
        Tree* tree = new Tree();

        int n;
        cin>>n;

        for(int i=0;i<n;i++) {
            int parentValue, childValue;
            cin>>parentValue>>childValue;
            tree->insertNode(parentValue, childValue);
        }

        tree->postOrderTraversal(tree->getRoot());
        cout<<"\n";

        delete tree;
    }
    return 0;
}