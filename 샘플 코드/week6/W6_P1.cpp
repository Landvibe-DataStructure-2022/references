#include <iostream>
#include <vector>
#include <string>

using namespace std;

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

    Node(Node* p, int v) {
        parent = p;
        value = v;
    }

    friend class Tree;
};

class Tree {
private:
    Node *root;
    vector<Node *> nodeList;

public:
    Tree() {
        root = new Node(1);
        nodeList.push_back(root);
    }

    Node *findNode(int v) {
        for (int i = 0; i < nodeList.size(); i++) {
            if (nodeList[i]->value == v) {
                return nodeList[i];
            }
        }
        return nullptr;
    }

    void insertNode(int x, int y) {
        Node *parentNode = findNode(x);

        if (parentNode == nullptr) {
            cout << "-1\n";
        } else {
            Node *newNode = new Node(parentNode, y);
            parentNode->child.push_back(newNode);
            nodeList.push_back(newNode);
        }
    }

    void deleteNode(int x) {
        Node *deleteNode = findNode(x);

        if (deleteNode == root || deleteNode == nullptr) {
            cout << "-1\n";
        } else {
            for (int i = 0; i < deleteNode->child.size(); i++) {
                deleteNode->parent->child.push_back(deleteNode->child[i]);
                deleteNode->child[i]->parent = deleteNode->parent;
            }

            for (int i = 0; i < deleteNode->parent->child.size(); i++) {
                if (deleteNode == deleteNode->parent->child[i]) {
                    deleteNode->parent->child.erase(deleteNode->parent->child.begin() + i);
                    break;
                }
            }

            for(int i=0;i<nodeList.size();i++) {
                if(deleteNode == nodeList[i]) {
                    nodeList.erase(nodeList.begin() + i);
                    break;
                }
            }

            delete deleteNode;
        }
    }

    void printNode(int x) {
        Node* curNode = findNode(x);

        if(curNode == nullptr || curNode->child.empty()) {
            cout<<"-1\n";
        } else {
            for(int i=0;i<curNode->child.size();i++) {
                cout<<curNode->child[i]->value<<" ";
            }
            cout<<"\n";
        }
    }
};

int main() {
    int n;
    cin>>n;

    Tree* tree = new Tree();

    while(n--) {
        string cmd;
        cin>>cmd;

        if(cmd == "insert") {
            int x, y;
            cin>>x>>y;
            tree->insertNode(x, y);
        } else if(cmd == "delete") {
            int x;
            cin>>x;
            tree->deleteNode(x);
        } else if(cmd == "print") {
            int x;
            cin>>x;
            tree->printNode(x);
        }
    }
    delete tree;
    return 0;
}