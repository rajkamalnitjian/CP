class Solution {
public:
#define ll long long

    ll solve(int i,vector<int>&nums, int k,int choice,vector<vector<vector<ll>>>&dp){

        if  (k < 0) return -1e18;
        if (i == nums.size()) {
            if (k == 0) return 0;
            else return -1e18;
        }

        if(dp[i][k][choice]!=-1)
            return dp[i][k][choice];

        ll res1=-1e18,res2=-1e18;
        if(choice==1){
            res1=max(res1,solve(i+1,nums,k,choice,dp));
        }

        if(k%2==0){
            res2=max(res2,solve(i+1,nums,k-1,1,dp)-(ll)nums[i]*(ll)k);
            res2=max(res2,solve(i+1,nums,k,0,dp)-(ll)nums[i]*k);
        }
        else{
            res2=max(res2,solve(i+1,nums,k-1,1,dp)+(ll)nums[i]*k);
            res2=max(res2,solve(i+1,nums,k,0,dp)+(ll)nums[i]*k);
        }
        return dp[i][k][choice]=max(res1,res2);
    }
    long long maximumStrength(vector<int>& nums, int k) {
        ll n=nums.size();
        vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(k + 1, vector<ll>(3, -1)));

        return solve(0,nums,k,1,dp);
    }
};