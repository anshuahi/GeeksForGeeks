/*
GeeksForGeeks-POTD: Add two numbers represented by linked lists

POTD Link: https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

Approach
    1. reverse the list
    2. add respective nodes from two lists, and append to the new list
*/

class Solution
{
public:
    Node *reverse(Node *root)
    {
        Node *rev = NULL;
        while (root)
        {
            Node *temp = new Node(root->data);
            temp->next = rev;
            rev = temp;
            root = root->next;
        }

        return rev;
    }
    Node *insert(Node *node, int data)
    {
        Node *temp = new Node(data);
        temp->next = node;
        return temp;
    }
    // Function to add two numbers represented by linked list.
    struct Node *addTwoLists(struct Node *num1, struct Node *num2)
    {
        if (!num1)
            return num2;
        if (!num2)
            return num1;
        Node *first = reverse(num1);
        Node *second = reverse(num2);
        int carry = 0;
        Node *ans = NULL;
        while (first || second)
        {
            int sum = (first ? first->data : 0) + (second ? second->data : 0) + carry;
            carry = sum / 10;
            ans = insert(ans, sum % 10);
            if (first)
                first = first->next;
            if (second)
                second = second->next;
        }
        while (carry)
        {
            ans = insert(ans, carry % 10);
            carry = carry / 10;
        }

        while (ans && ans->next && ans->data == 0)
            ans = ans->next;

        return ans;
    }
};
