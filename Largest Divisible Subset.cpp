class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<pair<int,int>>dp(nums.size());
        int end,maxCnt = 0;
        for(int i=0;i<nums.size();i++){
            int prev = i;
            int cnt = 0;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j].first>cnt){
                    cnt = dp[j].first;
                    prev = j;
                }
            }

            dp[i] = {cnt+1,prev};

            if(cnt+1>maxCnt){
                maxCnt = cnt+1;
                end = i;
            }
        }
   vector<int>ans;
        while(dp[end].second != end){
         ans.push_back(nums[end]);
         end = dp[end].second;
        }

        ans.push_back(nums[end]);

        reverse(ans.begin(),ans.end());

        return ans;
    }
};