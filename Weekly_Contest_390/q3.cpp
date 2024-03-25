//3092. Most Frequent IDs

#include <iostream>
#include<queue>
#define pi pair<ll,ll>
#define ll long long
using namespace std;

class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
       priority_queue<pi> pq;
       unordered_map<ll,ll>mp;
       vector<ll>res;
       for(int i=0;i<nums.size();i++){
           mp[nums[i]]+=freq[i];
           pq.push({mp[nums[i]],nums[i]});
            while(!pq.empty() and mp[pq.top().second]!=pq.top().first){
                pq.pop();
            }
             if(!pq.empty()){
                 res.push_back(pq.top().first);
             }
             else
             res.push_back(0ll);
       }
       return res;
    }
};

int main(){
    vector<int>nums={5,5,3};
    vector<int> freq = {2,-2,1};
    Solution *pSolution =new Solution();
    vector<long long>res= pSolution->mostFrequentIDs(nums,freq);

     for(auto &it:res){
         cout<<it<<" ";
     }
     cout<<endl;
    return 0;
}