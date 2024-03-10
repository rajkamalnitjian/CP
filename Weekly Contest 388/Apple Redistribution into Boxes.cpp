class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=0;
        for(auto &it:apple) sum+=it;
        sort(capacity.rbegin(),capacity.rend());
        int cnt=0;
        for(int i=0;i<capacity.size();i++)
        {
            cnt+=capacity[i];
            if(cnt>=sum)
                return i+1;
        }
        return  capacity.size();
    }
};