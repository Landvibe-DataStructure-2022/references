#include <iostream>

using namespace std;

class Node {
private:
    int data;
    Node *par;
    Node *left;
    Node *right;

    bool visit;

public:
    Node(int d) {
        data = d;
        par = nullptr;
        left = nullptr;
        right = nullptr;

        visit = false;
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
private:
    Node *root;

public:
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

    void findNodeByIndex(int index) {
        Node *curNode = root;
        int curIndex = 0;

        while (curIndex != index) {
            if (curNode->left != nullptr) {
                if (!curNode->left->visit) {
                    curNode = curNode->left;
                    continue;
                }
            }

            if (!curNode->visit) {
                curIndex++;
                curNode->visit = true;
                if (curIndex == index) {
                    cout << curNode->data << "\n";
                }
            }

            if (curNode->right != nullptr) {
                if (!curNode->right->visit) {
                    curNode = curNode->right;
                    continue;
                }
            }

            if (curNode == root) {
                return;
            } else {
                curNode = curNode->par;
            }
        }
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

        int index;
        cin >> index;

        bst->findNodeByIndex(index);
    }

    return 0;
}