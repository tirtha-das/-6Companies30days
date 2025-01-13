class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        int res = 0;
        
        for(int i=0;i<nums.size();i++){
            if(i>0){
                sum+=nums[i];
            }
            res += (nums[i]*i);
        }

       int ans = res;
       int j=1;
       int sz = nums.size();
       while(j<sz){
          res -= sum;
          int idx = j+(sz-1);
         res +=  nums[idx%sz]*(sz-1);
          ans = max(res,ans);
          sum-=nums[j];
          sum+=nums[idx%sz];
          j++;
       } 
       return ans;
    }
};