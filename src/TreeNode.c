#include "TreeNode.h"
#include <stdlib.h>

static void SwapTree(TreeNode *tree)
{
    RefStack stack = NULL;

    Stack_Push(&stack, tree);

    while (stack != NULL)
    {
        TreeNode *node = Stack_Pop(&stack);
        int isRightNode = node->right != NULL;
        int isLeftNode = node->left != NULL;

        if (!isRightNode && !isLeftNode)
            continue;

        if (isRightNode)
            Stack_Push(&stack, node->right);
        if (isLeftNode)
            Stack_Push(&stack, node->left);

        TreeNode *tmp = node->left;
        node->left = node->right;
        node->right = tmp;
    }
}

void Stack_Push(RefStack *stack, TreeNode *node)
{
    Stack *nextNode = malloc(sizeof(*nextNode));
    nextNode->node = node;
    nextNode->next = *stack;
    *stack = nextNode;
}

TreeNode *Stack_Pop(RefStack *stack)
{
    TreeNode *result = (*stack)->node;
    RefStack next = (*stack)->next;
    free((*stack));
    *stack = next;

    return result;
}

TreeNode *new_TreeNode(int value, TreeNode *left, TreeNode *right)
{
    TreeNode *result = (TreeNode *)malloc(sizeof(*result));
    result->value = value;
    result->left = left;
    result->right = right;
    result->SwapTree = &SwapTree;
    return result;
}

void delete_TreeNode(TreeNode *tree)
{
    Stack *stack = NULL;

    Stack_Push(&stack, tree);
    while (stack != NULL)
    {
        TreeNode *node = Stack_Pop(&stack);

        if (node->left != NULL)
            Stack_Push(&stack, node->left);
        if (node->right != NULL)
            Stack_Push(&stack, node->right);

        free(node);
    }
}