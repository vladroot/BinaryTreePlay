#include <stdio.h>
#include "src/TreeNode.h"

void PrintTree(TreeNode *tree)
{
    RefStack stack = NULL;
    Stack_Push(&stack, tree);
    // it prints in the wrong order for every other level
    // althougth the data itself is correct
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
}

int main(int argc, char **argv)
{
    printf("Reversing binary tree!\n");
    TreeNode *base = new_TreeNode(1, NULL, NULL);
    base->left = new_TreeNode(2, new_TreeNode(4, NULL, NULL), new_TreeNode(5, NULL, NULL));
    base->right = new_TreeNode(3, new_TreeNode(6, NULL, NULL), new_TreeNode(7, NULL, NULL));

    PrintTree(base);

    base->SwapTree(base);

    PrintTree(base);

    delete_TreeNode(base);
    return 0;
}
