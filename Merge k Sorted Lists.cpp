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
struct cmp{
    bool operator()(ListNode* node1,ListNode* node2){
        return node1->val>node2->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp>pq;
        for(int i=0;i<lists.size();i++){
           ListNode* node=lists[i];
           while(node!=nullptr){
            pq.push(node);
            node=node->next;
           }
           
        }
         if (pq.empty()) return nullptr; 
        ListNode* temp=NULL;
        temp=pq.top();
        ListNode* head=temp;
        pq.pop();
        while(!pq.empty()){
            temp->next=pq.top();
            pq.pop();
            temp=temp->next;
        }
        temp->next = nullptr;
        return head;
    }
};