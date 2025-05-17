/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int length = 0;
        while(temp)
        {
            length++;
            temp=temp->next;
        }
        if(n==length)
        {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        int finalLength = length-n;
        temp =  head;
        while(finalLength!=1)
        {
            temp = temp->next;
            finalLength--;
        }
        if( temp->next != NULL)
        {
            ListNode* nNode = temp->next;
            temp->next = temp->next->next;
            delete nNode;
        }  
        else
        {
            temp->next = NULL;
        }
        return head;
    }
};