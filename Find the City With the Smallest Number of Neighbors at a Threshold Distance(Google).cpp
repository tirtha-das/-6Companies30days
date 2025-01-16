class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adjMat(n,vector<int>(n,INT_MAX));

        for(int i=0;i<n;i++){
            adjMat[i][i] = 0;
        }

        for(auto edge:edges){
            adjMat[edge[0]][edge[1]] = min(adjMat[edge[0]][edge[1]],edge[2]);
            adjMat[edge[1]][edge[0]] = min(adjMat[edge[1]][edge[0]],edge[2]);

        }

        for(int via=0;via<n;via++){
            for(int src=0;src<n;src++){
                if(src!=via){
                    for(int dest = 0;dest<n;dest++){
                        if(adjMat[src][via]!=INT_MAX && adjMat[via][dest]!=INT_MAX){
                            adjMat[src][dest] = min(adjMat[src][dest],
                                                     adjMat[src][via]+adjMat[via][dest]);
                        }
                    }
                }
            }
        }

        int ans = 0;
        int minNeighbor = INT_MAX;

        for(int node=0;node<n;node++){
            int curNeighbor = 0;
            for(auto it:adjMat[node]){
                if(it<=distanceThreshold){
                    curNeighbor++;
                }
            }
            if(curNeighbor<=minNeighbor){
                ans = node;
                minNeighbor = curNeighbor;
            }
        }

        return ans;
    }
};