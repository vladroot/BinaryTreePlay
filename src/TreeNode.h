#ifndef TREENODE_H
#define TREENODE_H

typedef struct TreeNode
{
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
    void (*SwapTree)(struct TreeNode *);
} TreeNode;

typedef struct Stack
{
    TreeNode *node;
    struct Stack *next;
} Stack;

typedef Stack *RefStack;

static void SwapTree(TreeNode *);

void Stack_Push(RefStack *, TreeNode *);
TreeNode *Stack_Pop(RefStack *);
TreeNode *new_TreeNode(int value, TreeNode *left, TreeNode *right);
void delete_TreeNode(TreeNode *);

#endif