#include <iostream>
using namespace std;

#define int long long
const int MOD=1e9+7;


class Solution1 {
public:

    int helper(vector<int>& nums, int k, int idx, int prev, int minima) {
        if (k == 0)
            return minima;

        if (idx >= nums.size())
            return 0;


        int result=helper(nums,k,idx+1,prev,minima);
        if(prev!=-1){
            minima=min(minima,nums[idx]-nums[prev]);
        }
        result=result+helper(nums,k-1,idx+1,idx,minima);

        return result;
    }



    int sumOfPowers(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int result = helper(nums,k,0,-1,1e9);
        return result % MOD;

    }
};
class Solution0 {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int bottledrunk=0;
        int  emptybottle=0;
        while(numBottles>0 ||(numExchange<=emptybottle and numExchange>0 ))  {

            if(numBottles>0){
                emptybottle+=numBottles;
                bottledrunk+=numBottles;
                numBottles=0;
                continue;
            }
            else if(numExchange<=emptybottle){
                emptybottle-=numExchange;
                numExchange+=1;
                numBottles+=1;
            }
        }
        return bottledrunk;
    }
};

signed  main(){
    Solution0 *pSolution =new Solution0();
    vector<int>nums={1,2,3,4};
    int  k = 3;
    cout<<pSolution->maxBottlesDrunk(13,6)<<endl;
    return 0;
}