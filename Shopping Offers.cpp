class Solution {
public:

    bool checkPossible(vector<int>&limit ,vector<int>&offer){
        for(int i=0;i<offer.size()-1;i++){
            if(limit[i]>=offer[i]){
                limit[i] -= offer[i];
            }else{
                return false;
            }
        }

        return true;
    }

    void numConverter(int num , int size, vector<int>&arr){
        int op = 15;
        for(int i=0;i<size;i++){
            int temp = (num) & (15);
            arr.push_back(temp);
            if(num>0) num = num>>4;

        }
    }

    int calRemains(vector<int>& arr){
         int num = 0;
        for(int i=0;i<arr.size();i++){
            int temp = (arr[i])<<(i*4);
            num |= temp;
        }

        return num;
    }
     

    int solve(int idx, vector<vector<int>>& special,int remains,vector<int>& price
               ,vector<unordered_map<int,int>>&dp){
        if(remains == 0) return 0;
         vector<int> converted ;
          numConverter(remains,price.size(),converted);

         if(idx == special.size()){
         
          int totSum = 0;
          for(int i=0;i<price.size();i++){
            totSum += converted[i]*price[i];
          }
          return totSum;
        }
        else if(dp[idx].find(remains)!=dp[idx].end()) return dp[idx][remains];

        int notTake = solve(idx+1,special,remains,price,dp);
        
        int take = INT_MAX;

        

        int isPossible = checkPossible(converted,special[idx]);

        if(isPossible){
            int newRemains = calRemains(converted);
            take = special[idx][price.size()] + solve(idx,special,newRemains,price,dp);
        }

        return dp[idx][remains] = min(take,notTake);
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        vector<unordered_map<int,int>>dp(special.size());
        int remains = calRemains(needs);
        return solve(0,special,remains,price,dp);
    }
};