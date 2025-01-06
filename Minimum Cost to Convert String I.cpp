#define ll long long

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<ll>>minDist(26,vector<ll>(26,1e12));
        for(int i=0;i<26;i++){
            minDist[i][i] = 0;
        }
        for(int i=0;i<cost.size();i++){
            if(original[i]!=changed[i]){
                int row = original[i]-'a';
                int col = changed[i] - 'a';
                minDist[row][col] = min((ll)cost[i],minDist[row][col]);
            }
        }

        for(int via = 0;via<26;via++){
            for(int row = 0;row<26;row++){
                if(via!=row){
                    for(int col =0;col<26;col++){
                        if(via!=col && row!=col 
                          && minDist[row][via]!=1e12 && minDist[via][col]!=1e12){
                           minDist[row][col] = min(minDist[row][via]+minDist[via][col],
                                                   minDist[row][col]);
                        }
                    }
                }
            }
        }

        ll ans = 0;
        for(int i=0;i<source.size();i++){
            if(source[i]!=target[i]){
                int row = source[i]-'a';
                int col = target[i] - 'a';
                if(minDist[row][col]==1e12) return -1;
                else{
                    ans+=minDist[row][col];
                }
            }
        }

        return ans;
    }
};