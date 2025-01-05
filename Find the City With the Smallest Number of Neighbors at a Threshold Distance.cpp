class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adjMatrix(n,vector<int>(n,INT_MAX));

        for(int i=0;i<n;i++){
          adjMatrix[i][i]=0;
        }

        for(auto it:edges){
            adjMatrix[it[0]][it[1]] = it[2];
            adjMatrix[it[1]][it[0]] = it[2];
        }

        for(int via = 0;via<n;via++){
            for(int i=0;i<n;i++){
                if(via!=i){
                    for(int j=0;j<n;j++){
                        if(j==via || adjMatrix[i][via]==INT_MAX 
                            || adjMatrix[via][j]==INT_MAX) continue;
                            else{
                                adjMatrix[i][j] = min(adjMatrix[i][via]+adjMatrix[via][j],
                                                      adjMatrix[i][j]);
                            }
                    }
                }
            }
        }

        int ans = 0, cnt = n;
        for(int i=0;i<n;i++){
            int curCnt = 0;
            for(auto it:adjMatrix[i]){
                if(it<=distanceThreshold){
                    curCnt++;
                }
            }
            if(curCnt<=cnt){
                cnt = curCnt;
                ans = i;
            }
        }

        return ans;
    }
};