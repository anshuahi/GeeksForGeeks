/*
GeeksForGeeks-POTD: Remove every kth node

POTD Link: https://www.geeksforgeeks.org/problems/remove-every-kth-node/1

GitHub Solution Link- https://github.com/anshuahi/GeeksForGeeks/blob/master/ProblemOfTheDay/29_04_2024.cpp

Approach
    1. find kth element and skip it.
*/

/* Link list Node

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

/*You are required to complete this method*/

/* Function to get the middle of the linked list*/
/*K will always be in range */

class Solution
{
public:
    Node *deleteK(Node *head, int k)
    {
        if (k == 1 || !head)
            return NULL;
        Node *temp = head;
        int j = 2;
        while (temp && temp->next && j < k)
        {
            temp = temp->next;
            j++;
        }
        if (temp && temp->next)
            temp->next = deleteK(temp->next->next, k);
        return head;
    }
};