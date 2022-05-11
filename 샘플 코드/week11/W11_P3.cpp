#include <iostream>

using namespace std;

class Node {
private:
    int data;
    Node *par;
    Node *left;
    Node *right;

public:
    Node(int d) {
        data = d;
        par = nullptr;
        left = nullptr;
        right = nullptr;
    }

    void setLeft(Node *node) {
        this->left = node;
        node->par = this;
    }

    void setRight(Node *node) {
        this->right = node;
        node->par = this;
    }

    friend class BST;
};

class BST {
public:
    Node *root;

    BST() {
        root = nullptr;
    }

    Node *search(int data) {
        Node *curNode = root;
        while (curNode != nullptr) {
            if (data == curNode->data) {
                return curNode;
            } else if (data < curNode->data) {
                curNode = curNode->left;
            } else if (data > curNode->data) {
                curNode = curNode->right;
            }
        }
        return nullptr;
    }

    void insert(int data) {
        Node *node = new Node(data);

        if (root == nullptr) {
            root = node;
            return;
        }

        Node *parNode = root->par;
        Node *curNode = root;
        while (curNode != nullptr) {
            if (data < curNode->data) {
                parNode = curNode;
                curNode = curNode->left;
            } else if (data > curNode->data) {
                parNode = curNode;
                curNode = curNode->right;
            }
        }
        if (data < parNode->data) {
            parNode->setLeft(node);
        } else if (data > parNode->data) {
            parNode->setRight(node);
        }
    }

    void print(Node *node) {
        if (node == nullptr) {
            return;
        }

        print(node->left);
        cout << node->data << " ";
        print(node->right);
    }
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        BST *bst = new BST();

        for (int i = 0; i < n; i++) {
            int data;
            cin >> data;

            bst->insert(data);
        }

        bst->print(bst->root);
        cout<<"\n";
    }

    return 0;
}