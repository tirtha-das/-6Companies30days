class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int left=0,right=0;
        bool isAllowed = true;
        int best= 0;
        while(right<nums.size()){
          mp[nums[right]]++;
          if(mp[nums[right]]>k){
            isAllowed = false;
          }

          while(left<right && !isAllowed){
            mp[nums[left]]--;
           if(mp[nums[left]]==k) isAllowed = true;
            left++;
          }

          best = max(best,(right+1-left));
          right++;
        }

        return best;
    }
};