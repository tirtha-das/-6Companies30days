class Solution {
public:
    void solve(int idx,vector<int>&nums,int k,int n,vector<int>&cur,vector<vector<int>>& res){
        if(k==0){
          int sum = 0;
          for(auto it:cur){
            sum+=it;
          }
          if(sum==n){
             res.push_back(cur);
          }
          return;
        }
        if(idx==nums.size()){
            return ;
        }
       //not take case
        solve(idx+1,nums,k,n,cur,res);

        //take case
        cur.push_back(nums[idx]);
        solve(idx+1,nums,k-1,n,cur,res);
        cur.pop_back();
    }


    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
         int minSum = (k*(k+1))/2;
         int maxSum = (9*10)/2;
         maxSum -= ((9-k)*(9-k+1))/2;
         if(n<minSum || n>maxSum) return res;
         
         
        
        vector<int>nums = {1,2,3,4,5,6,7,8,9};
        vector<int>cur;
        solve(0,nums,k,n,cur,res);
        return res;
    }
};