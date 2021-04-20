#include <iostream>

struct node {
    int key;
    node *left;
    node *right;
};

void show(node *&tree) {
    if (tree != nullptr) {
        std::cout << tree->key << " ";
        show(tree->left);
        show(tree->right);
    }
}

void add(int k, node *&tree) {
    if (tree == nullptr) {
        tree = new node;
        tree->key = k;
        tree->left = nullptr;
        tree->right = nullptr;
    }
    if (k < tree->key) {
        if (tree->left != nullptr) {
            add(k, tree->left);
        } else {
            tree->left = new node;
            tree->left->left = nullptr;
            tree->left->right = nullptr;
            tree->left->key = k;
        }
    }
    if (k > tree->key) {
        if (tree->right != nullptr) {
            add(k, tree->right);
        } else {
            tree->right = new node;
            tree->right->left = nullptr;
            tree->right->right = nullptr;
            tree->right->key = k;
        }
    }
}


int main() {
    node *tree = nullptr;

    add(5, tree);
    add(7, tree);
    add(1, tree);
    add(2, tree);
    add(0, tree);
    add(6, tree);
    add(10, tree);
    add(12, tree);
    add(8, tree);

    show(tree);

    return 0;
}
