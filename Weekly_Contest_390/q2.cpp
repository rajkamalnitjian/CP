//leetcode  Weekly cointest 390
//3091. Apply Operations to Make Sum of Array Greater Than or Equal to k

#include <iostream>
using namespace std;

class Solution {
public:
    bool check(int mid, int p) {
        int ans=1e9;
         for(int k=1;k<=mid;k++){
              int total=(k+1);
              total+=(total)*(mid-k);
             if(total>=p)
                   return true;
         }
         return false;
    }

    int minOperations(int k) {
        if(k==1) {
            cout << "0" << endl;
            return 0;
        }
        int low=0,high=1e5;
        int ans=0;
         while(low<=high){
             int  mid=(low+high)/2;
              if(check(mid,k)){
                   ans=mid;
                   high=mid-1;
              }
              else
                  low=mid+1;
         }
         return ans;
    }
};

int main(){
    int k;
     cin>>k;
    Solution *pSolution =new Solution();
     cout<<pSolution->minOperations(k);

    return 0;
}