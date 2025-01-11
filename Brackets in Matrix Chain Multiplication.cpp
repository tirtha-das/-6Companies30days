#define PII pair<int,int>

class Solution {
  public:
    //recusive approch 
    static int solve(int start, int end, vector<int> &arr){
        if(start==end){
            return 0;
        }
        
        int ans = 1e13;
        for(int k=start;k<end;k++){
            int cur = solve(start,k,arr) + solve(k+1,end,arr) + (arr[start-1]*arr[k]*arr[end]);
            ans = min(ans,cur);
        }
        
        return ans;
     }

    string setBracket(string res, vector<vector<PII>>&dp,int start, int end){
        if(start==end || start==end-1){
            return res;
        }
        
        int partition = dp[start][end].second;
       // cout<<partition<<endl;
        string left = setBracket(res.substr(0,(partition-start+1)),dp,start,partition);
        string right = setBracket(res.substr(partition-start+1),dp,partition+1,end);
        if(left.size()>1) left = "("+left+")";
        if(right.size()>1) right = "("+right+")";
        string ans =  left+right;
       // cout<<ans<<endl;
        return ans;
    }
  
    string matrixChainOrder(vector<int> &arr) {
        // code here
         int size = arr.size();
        vector<vector<PII>>dp(size,vector<PII>(size));
        
        for(int i=0;i<size;i++){
            dp[i][i]={0,i};
        }
        
        for(int start = size-1;start>=1;start--){
            
            for(int end = start+1;end<size;end++){
                
                int ans = 1e9;
                int part = start;
                for(int k=start;k<end;k++){
                  int cur = dp[start][k].first + dp[k+1][end].first + (arr[start-1]*arr[k]*arr[end]);
                  //ans = min(ans,cur);
                  if(ans>cur){
                      ans = cur;
                      part = k;
                  }
                 }
                 dp[start][end] = {ans,part};
            }
            
            
        }
        
        string res = "";
        for(int i=0;i<size-1;i++){
            res += ('A'+i);
        }
       // res+=")";
       string result = setBracket(res,dp,1,size-1);
       result = "("+result+")";
       // cout<<result<<endl;
        
        return result;
        
        
    }
};