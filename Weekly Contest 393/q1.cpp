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
#include <iostream>
#include<queue>
using namespace std;
const int MOD=1e9+7;

#define pii pair<int, int>
#define pi pair<int, pair<int,int>>

class Solution {
public:
    string ans="00:00";

    void  solve(int index,string &s){
        if(index==s.size()){
            if(s<="11:59")
                ans=max(ans,s);
            return ;
        }
        if(s[index]=='?'){
            for(char k='0';k<='9';k++){
                char prev=s[index];
                s[index]=k;
                solve(index+1,s);
                s[index]=prev;
            }
        }
        else
            solve(index+1,s);
    }

    string findLatestTime(string s) {
        solve(0,s);
        return ans;
    }
};

int main(){
    Solution *pSolution=new Solution();
    string s="1?:?4";

    cout<< pSolution->findLatestTime(s)<<endl;
    return 0;
}