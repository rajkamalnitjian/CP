#include <iostream>
using namespace std;


const int MOD=1e9+7;

  struct ListNode {
     int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* merge(ListNode *left,ListNode *right)
    {
        ListNode *dummy=new ListNode(0);
        ListNode *curr=dummy;
        while(left!=nullptr and right!=nullptr){
            if(left->val > right->val)
            {
                curr->next=right;
                right=right->next;
            }else
            {
                curr->next=left;
                left=left->next;
            }
            curr=curr->next;
        }
        curr->next=(left!=nullptr)?left:right;
        return dummy->next;
    }
    ListNode* solve(vector<ListNode*>& lists,int low,int high){
        if(low==high)
            return lists[low];

        if(low+1==high)
            return merge(lists[low],lists[high]);

        int mid=low+(high-low)/2;

        ListNode* l=solve(lists,low,mid);

        ListNode* r=solve(lists,mid+1,high);

        return merge(l,r);

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return solve(lists,0,lists.size()-1);
    }
};

int main(){
     Solution *s=new Solution();
     vector<ListNode*>arr;

//    [[1,4,5],[1,3,4],[2,6]]
 ListNode *head=new ListNode(1);
 head->next=new ListNode(4);
 head->next->next=new ListNode(5);
 arr.push_back(head);

 head=nullptr;
    head=new ListNode(1);
    head->next=new ListNode(3);
    head->next->next=new ListNode(4);
    arr.push_back(head);
    head=nullptr;
    head=new ListNode(2);
    head->next=new ListNode(6);

    arr.push_back(head);

     head= s->mergeKLists(arr);
    return 0;
}