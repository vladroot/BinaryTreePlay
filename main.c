#include <stdio.h>
#include "src/TreeNode.h"

int main(int argc, char **argv)
{
    printf("Reversing binary tree!\n");
    TreeNode *base = new_TreeNode(1, NULL, NULL);
    base->left = new_TreeNode(2, new_TreeNode(4, NULL, NULL), NULL);

    base->right = new_TreeNode(3, new_TreeNode(5, NULL, NULL), new_TreeNode(6, NULL, NULL));

    base->SwapTree(base);

    RefStack stack = NULL;
    Stack_Push(&stack, base);
    while (stack != NULL)
    {
        RefStack innerStack = NULL;
        while (stack != NULL)
        {
            TreeNode *node = Stack_Pop(&stack);
            if (node->right != NULL)
                Stack_Push(&innerStack, node->right);
            if (node->left != NULL)
                Stack_Push(&innerStack, node->left);

            printf("%d", node->value);
        }
        stack = innerStack;

        printf("\n");
    }

    delete_TreeNode(base);
    return 0;
}
