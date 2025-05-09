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
    ListNode* GetKthNode(ListNode* temp,int k)
    {
        k = k-1;
        while(temp!=NULL && k>0)
        {
            temp = temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* Next;
        while(curr!=NULL)
        {
            Next=curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;           
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* nextNode= NULL;
        while(temp!=NULL){
            ListNode* kthNode = GetKthNode(temp,k);
            if(kthNode==NULL){
                if(prev)
                {
                    prev->next = temp;
                }
                break;
            }
            nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseList(temp);
            if(temp == head)
            {
                head = kthNode;
            }
            else
            {
                prev->next = kthNode;
            }
                prev = temp;
                temp = nextNode;
        }
        return head;
    }
};