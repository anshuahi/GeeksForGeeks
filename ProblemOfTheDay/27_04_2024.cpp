/*
GeeksForGeeks-POTD: Merge Sort on Doubly Linked List

POTD Link: https://www.geeksforgeeks.org/problems/merge-sort-on-doubly-linked-list/1

*/
/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution
{
public:
    Node *split(Node *head)
    {
        Node *fast = head, *slow = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        Node *temp = slow->next;
        slow->next = NULL;
        return temp;
    }

    Node *merge(Node *first, Node *second)
    {
        if (!first)
            return second;

        if (!second)
            return first;

        if (first->data < second->data)
        {
            first->next = merge(first->next, second);
            first->next->prev = first;
            first->prev = NULL;
            return first;
        }
        else
        {
            second->next = merge(first, second->next);
            second->next->prev = second;
            second->prev = NULL;
            return second;
        }
    }
    // Function to sort the given doubly linked list using Merge Sort.
    // struct Node
    struct Node *sortDoubly(struct Node *head)
    {
        if (!head || !head->next)
            return head;
        // split into two halves
        Node *second = split(head);

        // Recur for left and right halves
        head = sortDoubly(head);
        second = sortDoubly(second);

        // Merge the two sorted halves
        return merge(head, second);
    }
};