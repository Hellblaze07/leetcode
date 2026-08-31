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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL || head->next == NULL)
        return {-1,-1};
        int prev=head->val;
        ListNode* temp=head;
        temp=temp->next;
        vector <int> vec;
        int i=1;
        while(temp->next != NULL)
        {   i++;
            int value=temp->val;
            if(value < prev && value < temp->next->val)
            vec.push_back(i);
            else if(value > prev && value > temp->next->val)
            vec.push_back(i);
            prev=temp->val;
            temp=temp->next;
        }
        if(vec.size()<2)
        return {-1,-1};
        int mini=INT_MAX;
        for(int i=1;i<vec.size();i++)
        mini=min(mini,vec[i]-vec[i-1]);
        return {mini,vec[vec.size()-1]-vec[0]};

        
    }
};