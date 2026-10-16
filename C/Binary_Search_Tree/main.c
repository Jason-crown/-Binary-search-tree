#include <stdio.h>
#include "tree.h"

int main(void)
{
    TreeNode *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    if (search(root, 40) != NULL) {
        printf("40 found\n");
    } else {
        printf("40 not found\n");
    }

    if (search(root, 100) != NULL) {
        printf("100 found\n");
    } else {
        printf("100 not found\n");
    }

    free_tree(root);

    return 0;
}
