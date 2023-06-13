#include <iostream>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    TreeNode* root;

public:
    // Constructor
    BinaryTree() {
        root = nullptr;
    }

    // Check if the tree is empty
    bool isEmpty() {
        return root == nullptr;
    }

    // Insert a node into the binary tree
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

        return current;
    }

    // Search for a value in the binary tree
    bool search(int value) {
        return searchRecursive(root, value);
    }

    // Recursive function to search for a value
    bool searchRecursive(TreeNode* current, int value) {
        if (current == nullptr) {
            return false;
        }

        if (value == current->data) {
            return true;
        } else if (value < current->data) {
            return searchRecursive(current->left, value);
        } else {
            return searchRecursive(current->right, value);
        }
    }

    // Traverse the binary tree in pre-order (root -> left -> right)
    void preOrderTraversal() {
        preOrderRecursive(root);
    }

    // Recursive function for pre-order traversal
    void preOrderRecursive(TreeNode* current) {
        if (current != nullptr) {
            cout << current->data << " ";
            preOrderRecursive(current->left);
            preOrderRecursive(current->right);
        }
    }

    // Traverse the binary tree in in-order (left -> root -> right)
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

    // Traverse the binary tree in post-order (left -> right -> root)
    void postOrderTraversal() {
        postOrderRecursive(root);
    }

    // Recursive function for post-order traversal
    void postOrderRecursive(TreeNode* current) {
        if (current != nullptr) {
            postOrderRecursive(current->left);
            postOrderRecursive(current->right);
            cout << current->data << " ";
        }
    }
};

int main() {
    BinaryTree tree;

    // Insert nodes into the binary tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    // Check if the tree is empty
    if (tree.isEmpty()) {
        cout << "Tree is empty" << endl;
    } else {
        cout << "Tree is not empty" << endl;
    }

    // Search for a value in the binary tree
    int value = 40;
    if (tree.search(value)) {
        cout << "Value " << value << " found in the tree" << endl;
    } else {
        cout << "Value " << value << " not found in the tree" << endl;
    }

    // Perform different traversals on the binary tree
    cout << "Pre-order traversal: ";
    tree.preOrderTraversal();
    cout << endl;

    cout << "In-order traversal: ";
    tree.inOrderTraversal();
    cout << endl;

    cout << "Post-order traversal: ";
    tree.postOrderTraversal();
    cout << endl;

    return 0;
}
