/*
GeeksForGeeks-POTD: Delete Middle of Linked List

POTD Link: https://www.geeksforgeeks.org/problems/delete-middle-of-linked-list/1

Approach
    1. find middle using slow and fast pointers, and delete it.
*/
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

* /

    // Deletes middle of linked list and returns head of the modified list
    class Solution
{
public:
    Node *deleteMid(Node *head)
    {
        if (!head || !head->next)
            return NULL;
        Node *slow = head;
        Node *fast = head;
        Node *prev = NULL;
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev && prev->next)
        {
            prev->next = prev->next->next;
        }
        return head;
    }
};
