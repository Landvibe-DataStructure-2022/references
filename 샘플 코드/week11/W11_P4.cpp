#include <iostream>
#include <string>

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
        if (node != nullptr) {
            node->par = this;
        }
    }

    void setRight(Node *node) {
        this->right = node;
        if (node != nullptr) {
            node->par = this;
        }
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

    void remove(int data) {
        Node *node = search(data);
        Node *parNode = node->par;

        if (node->left == nullptr && node->right == nullptr) {
            if (node == root) {
                this->root = nullptr;
            } else {
                if (node == parNode->left) {
                    parNode->setLeft(nullptr);
                } else if (node == parNode->right) {
                    parNode->setRight(nullptr);
                }
            }
        } else if (node->left == nullptr || node->right == nullptr) {
            Node *child = (node->left != nullptr) ? node->left : node->right;

            if (node == root) {
                this->root = child;
            } else {
                if (node == parNode->left) {
                    parNode->setLeft(child);
                } else if (node == parNode->right) {
                    parNode->setRight(child);
                }
            }
        } else if (node->left != nullptr && node->right != nullptr) {
            Node *succ = node->right;
            Node *succPar = node;

            while (succ->left != nullptr) {
                succPar = succ;
                succ = succ->left;
            }

            if (succ == succPar->left) {
                succPar->setLeft(succ->right);
            } else {
                succPar->setRight(succ->right);
            }

            node->data = succ->data;
            node = succ;
        }

        delete node;
    }

    void printDepth(int data) {
        Node *curNode = root;
        int depth = 0;

        while (curNode->data != data) {
            if (data < curNode->data) {
                curNode = curNode->left;
            } else if (data > curNode->data) {
                curNode = curNode->right;
            }
            depth++;
        }

        cout<<depth<<"\n";
    }
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    BST *bst = new BST();

    while (n--) {
        string cmd;
        int data;

        cin >> cmd >> data;

        if (cmd == "insert") {
            bst->insert(data);
        } else if (cmd == "delete") {
            bst->remove(data);
        } else if (cmd == "depth") {
            bst->printDepth(data);
        }
    }

    return 0;
}