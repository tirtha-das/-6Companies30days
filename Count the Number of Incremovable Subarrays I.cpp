class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int len = nums.size();
        int lb=0;
        int rb = len-1;
        
        for(int i=1;i<len;i++){
            if(nums[i]>nums[i-1]) lb++;
            else break;
        }
        if(lb==len-1){
            return ((long long)(len)*(len+1))/2;
        }

        for(int i=len-2;i>=0;i--){
            if(nums[i]<nums[i+1]) rb--;
            else break;
        }

       long long sum = 0;
       for(int i=0;i<=lb+1;i++){
        int prev = (i>0)?nums[i-1]:0;
        int idx = upper_bound(nums.begin()+rb,nums.end(),prev)-nums.begin();

        sum += (len+1-idx);
       }

       return sum;
    }
};