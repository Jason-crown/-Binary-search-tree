#ifndef TREE_H
#define TREE_H

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

/* Create a new node */
TreeNode *create_node(int data);

/* Insert a value into the BST */
TreeNode *insert(TreeNode *root, int data);

/* Search for a value */
TreeNode *search(TreeNode *root, int data);

/* Tree traversals */
void inorder(TreeNode *root);
void preorder(TreeNode *root);
void postorder(TreeNode *root);

/* Free the entire tree */
void free_tree(TreeNode *root);

#endif
