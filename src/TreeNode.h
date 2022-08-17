#ifndef TREENODE_H
#define TREENODE_H

typedef struct TreeNode TreeNode;
struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
    void (*SwapTree)(TreeNode *);
};

typedef struct Stack Stack;
struct Stack
{
    TreeNode *node;
    Stack *next;
};

typedef Stack *RefStack;

static void SwapTree(TreeNode *);

void Stack_Push(RefStack *, TreeNode *);
TreeNode *Stack_Pop(RefStack *);
TreeNode *new_TreeNode(int value, TreeNode *left, TreeNode *right);
void delete_TreeNode(TreeNode *);

#endif