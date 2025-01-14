class Solution {
public:
    int solve(int idx1,int idx2,int flag,vector<int>& nums1,vector<int>& nums2,vector<vector<vector<int>>>&dp,int n, int m){
        if(idx1==n || idx2==m){
            return 0;
        } 
       if(dp[idx1][idx2][flag]!=-1) return dp[idx1][idx2][flag];

        if(flag == 1){
            if(nums1[idx1]==nums2[idx2]) return dp[idx1][idx2][flag] = 1+solve(idx1+1,idx2+1,flag,nums1,nums2,dp,n,m);
            else return dp[idx1][idx2][flag]= 0;
        }else{
            int notTake1 = solve(idx1+1,idx2,flag,nums1,nums2,dp,n,m);
            int notTake2 = solve(idx1,idx2+1,flag,nums1,nums2,dp,n,m);

            int ans = max(notTake1,notTake2);
            if(nums1[idx1]==nums2[idx2]){
                ans = max(ans, 1+solve(idx1+1,idx2+1,1,nums1,nums2,dp,n,m));
            }

            return dp[idx1][idx2][flag] = ans;
        }
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m = nums2.size();
        vector<int>next(m+1,0);
        int ans = 0;

        for(int idx1=n-1;idx1>=0;idx1--){
             vector<int>cur(m+1,0);
            for(int idx2=m-1;idx2>=0;idx2--){
               if(nums1[idx1]==nums2[idx2]){
                cur[idx2] = 1+next[idx2+1];
                 ans = max(ans,cur[idx2]);
               }
            }
            next = cur;
        }

        return ans;
    }
};