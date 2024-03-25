//leetcode  Weekly cointest 390
//3091. Apply Operations to Make Sum of Array Greater Than or Equal to k

#include <iostream>
using namespace std;

class Solution {
public:
     bool check(vector<int>&freq){
         for(int i=0;i<26;i++){
             if(freq[i]>2)
                 return false;
         }
         return true;
     }
     int maximumLengthSubstring(string &s) {
        vector<int>freq(26,0);
        int maxima=0;
       for(int i=0,j=0;i<s.size();i++){
           freq[s[i]-'a']+=1;
          while(j<=i && !check(freq)){
              freq[s[j]-'a']-=1;
              j+=1;
          }
           maxima=max(maxima,i-j+1);
       }
        return maxima;
    }
};


int main(){
string s;
cin>>s;
Solution *pSolution =new Solution();
cout<<pSolution->maximumLengthSubstring(s)<<endl;
return 0;
}