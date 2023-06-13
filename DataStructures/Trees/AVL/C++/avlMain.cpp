#include <iostream>

using namespace std;

class TreeNode {
public:
    int data;
    int height;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int value) {
        data = value;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

class AVLTree {
private:
    TreeNode* root;

public:
    // Constructor
    AVLTree() {
        root = nullptr;
    }

    // Get the height of a node
    int getHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    // Get the balance factor of a node
    int getBalanceFactor(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    // Update the height of a node
    void updateHeight(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    // Perform left rotation on a node
    TreeNode* leftRotate(TreeNode* node) {
        TreeNode* newRoot = node->right;
        TreeNode* subtree = newRoot->left;

        newRoot->left = node;
        node->right = subtree;

        updateHeight(node);
        updateHeight(newRoot);

        return newRoot;
    }

    // Perform right rotation on a node
    TreeNode* rightRotate(TreeNode* node) {
        TreeNode* newRoot = node->left;
        TreeNode* subtree = newRoot->right;

        newRoot->right = node;
        node->left = subtree;

        updateHeight(node);
        updateHeight(newRoot);

        return newRoot;
    }

    // Insert a node into the AVL tree
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Recursive function to insert a node
    TreeNode* insertRecursive(TreeNode* current, int value) {
        if (current == nullptr) {
            return new TreeNode(value);
        }

        if (value < current->data) {
            current->left = insertRecursive(current->left, value);
        } else {
            current->right = insertRecursive(current->right, value);
        }

        updateHeight(current);

        int balanceFactor = getBalanceFactor(current);

        // Left Left Case
        if (balanceFactor > 1 && value < current->left->data) {
            return rightRotate(current);
        }

        // Right Right Case
        if (balanceFactor < -1 && value > current->right->data) {
            return leftRotate(current);
        }

        // Left Right Case
        if (balanceFactor > 1 && value > current->left->data) {
            current->left = leftRotate(current->left);
            return rightRotate(current);
        }

        // Right Left Case
        if (balanceFactor < -1 && value < current->right->data) {
            current->right = rightRotate(current->right);
            return leftRotate(current);
        }

        return current;
    }

    // Perform in-order traversal on the AVL tree
    void inOrderTraversal() {
        inOrderRecursive(root);
    }

    // Recursive function for in-order traversal
    void inOrderRecursive(TreeNode* current) {
        if (current != nullptr) {
            inOrderRecursive(current->left);
            cout << current->data << " ";
            inOrderRecursive(current->right);
        }
    }
};

int main() {
    AVLTree tree;

    // Insert nodes into the AVL tree
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    // Perform in-order traversal on the AVL tree
    cout << "In-order traversal: ";
    tree.inOrderTraversal();
    cout << endl;

    return 0;
}
