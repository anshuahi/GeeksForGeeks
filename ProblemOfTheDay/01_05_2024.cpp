/*
GeeksForGeeks-POTD: Arrange Consonants and Vowels

POTD Link: https://www.geeksforgeeks.org/problems/arrange-consonants-and-vowels/1

Approach
    1. filter out vowels and consonants
    2. create a new linked-list

*/

class Solution
{
public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    Node *insert(string v)
    {
        Node *root = NULL;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            Node *temp = new Node(v[i]);
            temp->next = root;
            root = temp;
        }
        return root;
    }

    bool isVowel(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    struct Node *arrangeCV(Node *head)
    {
        if (!head || !head->next)
            return head;
        string vowels, cons;
        while (head)
        {
            if (isVowel(head->data))
            {
                vowels += head->data;
            }
            else
            {
                cons += head->data;
            }
            head = head->next;
        }
        Node *ans = insert(vowels + cons);
        return ans;
    }
};
