#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Build tree from extended preorder traversal
TreeNode* buildTree(vector<int>& preorder, int& index) {
    if (index >= preorder.size() || preorder[index] == -1) {
        index++;
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[index++]);
    root->left = buildTree(preorder, index);
    root->right = buildTree(preorder, index);

    return root;
}

// Prune tree: remove subtrees where root value is 0
TreeNode* pruneTree(TreeNode* root) {
    if (!root) return nullptr;

    // Recursively prune left and right subtrees first
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);

    // If current node is 0 and both children are null, prune it
    if (root->val == 0 && !root->left && !root->right) {
        delete root;
        return nullptr;
    }

    return root;
}

// Output preorder traversal with -1 for null nodes
void outputPreorder(TreeNode* root) {
    if (!root) {
        cout << "-1 ";
        return;
    }

    cout << root->val << " ";
    outputPreorder(root->left);
    outputPreorder(root->right);
}

// Delete tree to prevent memory leak
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    vector<int> preorder;
    int val;

    // Read input until -2
    while (cin >> val && val != -2) {
        preorder.push_back(val);
    }

    // Build tree
    int index = 0;
    TreeNode* root = buildTree(preorder, index);

    // Prune tree
    root = pruneTree(root);

    // Output result
    outputPreorder(root);
    cout << endl;

    // Clean up memory
    deleteTree(root);

    return 0;
}
