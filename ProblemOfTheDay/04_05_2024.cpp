/*
GeeksForGeeks-POTD: Construct Binary Tree from Inorder and Postorder

POTD Link: https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1
*/

/* Tree node structure


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
public:
    // Function to return a tree created from postorder and inoreder traversals.
    int search(int arr[], int strt, int end, int value)
    {
        for (int i = strt; i <= end; i++)
        {
            if (arr[i] == value)
                return i;
        }
    }

    Node *build(int in[], int post[], int inStrt, int inEnd, int &pIndex)
    {
        if (inStrt > inEnd)
            return NULL;

        Node *node = new Node(post[pIndex]);
        pIndex--;

        if (inStrt == inEnd)
            return node;

        int iIndex = search(in, inStrt, inEnd, node->data);
        node->right = build(in, post, iIndex + 1, inEnd, pIndex);
        node->left = build(in, post, inStrt, iIndex - 1, pIndex);

        return node;
    }

    Node *buildTree(int in[], int post[], int n)
    {
        int p = n - 1;
        return build(in, post, 0, n - 1, p);
    }
};
