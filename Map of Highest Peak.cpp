class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m));

        queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    ans[i][j] = 0;
                    pq.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};

        while(pq.size()){
            auto cur = pq.front();
            pq.pop();
            int r = cur.first;
            int c = cur.second;
             for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    ans[nr][nc] = 1+ans[r][c];
                    pq.push({nr,nc});
                }
             }
        }
      return ans;
    }
};