class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        long long rightSum = 0,leftSum = 0;
        for(auto it:nums){
            rightSum += it;
        }
         int i=0,j = 0;
         long long ans = INT_MAX;
        while(i<nums.size()){
          while(j<nums.size() && nums[i]==nums[j]){
            
            rightSum-= nums[i];
            j++;
          }
          long long leftShort = (i*(long long)(nums[i]) - leftSum);
          long long rightReduce = rightSum - ((long long)(nums.size()-j)*nums[i]);

          ans = min(ans,leftShort+rightReduce);

           leftSum += (j-i)*nums[i];
            i = j;
           


        }

        return (int)ans;
        
    }
};