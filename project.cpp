#include <iostream>
using namespace std;

// Definition of a node in the binary search tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class
class BST {
private:
    TreeNode *root;

    // Helper function to insert a value into the BST
    TreeNode* insert(TreeNode *node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }
        if (val < node->val) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }
        return node;
    }

    // Helper function to delete a value from the BST
    TreeNode* deleteNode(TreeNode *node, int val) {
        if (node == nullptr) return node;

        if (val < node->val) {
            node->left = deleteNode(node->left, val);
        } else if (val > node->val) {
            node->right = deleteNode(node->right, val);
        } else {
            // Node to be deleted found

            // Case 1: Node has no children or only one child
            if (node->left == nullptr) {
                TreeNode *temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode *temp = node->left;
                delete node;
                return temp;
            }

            // Case 2: Node has two children
            TreeNode *temp = minValueNode(node->right);
            node->val = temp->val;
            node->right = deleteNode(node->right, temp->val);
        }
        return node;
    }

    // Helper function to find the node with the minimum value in a subtree
    TreeNode* minValueNode(TreeNode *node) {
        TreeNode *current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Helper function to perform inorder traversal recursively
    void inorderTraversal(TreeNode *node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            cout << node->val << " ";
            inorderTraversal(node->right);
        }
    }

    // Helper function to perform preorder traversal recursively
    void preorderTraversal(TreeNode *node) {
        if (node != nullptr) {
            cout << node->val << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    // Helper function to perform postorder traversal recursively
    void postorderTraversal(TreeNode *node) {
        if (node != nullptr) {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->val << " ";
        }
    }

public:
    // Constructor
    BST() : root(nullptr) {}

    // Method to insert a value into the BST
    void insert(int val) {
        root = insert(root, val);
    }

    // Method to delete a value from the BST
    void deleteNode(int val) {
        root = deleteNode(root, val);
    }

    // Method to perform inorder traversal of the BST
    void inorder() {
        inorderTraversal(root);
        cout << endl;
    }

    // Method to perform preorder traversal of the BST
    void preorder() {
        preorderTraversal(root);
        cout << endl;
    }

    // Method to perform postorder traversal of the BST
    void postorder() {
        postorderTraversal(root);
        cout << endl;
    }
};

// Main function to demonstrate the BST operations
int main() {
    BST bst;

    // Inserting elements into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Printing inorder traversal
    cout << "Inorder traversal:" << endl;
    bst.inorder();

    // Deleting an element (example: delete 30)
    bst.deleteNode(30);

    // Printing inorder traversal after deletion
    cout << "Inorder traversal after deleting 30:" << endl;
    bst.inorder();

    // Printing preorder traversal
    cout << "Preorder traversal:" << endl;
    bst.preorder();

    // Printing postorder traversal
    cout << "Postorder traversal:" << endl;
    bst.postorder();

    return 0;
}