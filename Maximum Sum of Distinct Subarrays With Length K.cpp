class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        unordered_map<int,int>freq;
        int cnt=0;
        int left = 0;
        long long sum = 0;
        for(int i=0;i<nums.size();i++){
           freq[nums[i]]++;
           if(freq[nums[i]]==2) cnt++;
           sum+=nums[i];
           if(i>=k-1){
            if(cnt==0){
              ans = max(ans,sum);
            }

            sum-=nums[left];
            if(freq[nums[left]]==2) cnt--;
             freq[nums[left]]--;
             left++;
           }


        }

        return ans;
    }
};