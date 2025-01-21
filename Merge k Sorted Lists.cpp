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
#define PIL pair<int,ListNode*>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<PIL,vector<PIL>,greater<PIL>> pq;
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;

        for(auto it:lists){
            if(it!=NULL){
            pq.push({it->val,it});
            }
        }

        while(pq.size()>0){
          auto cur = pq.top();
           pq.pop();
           //int val = cur.first;
           ListNode* node = cur.second;
           if(node->next!=NULL){
            pq.push({node->next->val,node->next});
           }
           node->next = NULL;
           temp->next = node;
           temp = temp->next;
        }

        return head->next;
    }
};