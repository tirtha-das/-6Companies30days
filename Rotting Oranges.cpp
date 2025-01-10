class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>pn;
        
        int freshOrange  = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                  pn.push({i,j});
                  vis[i][j] = 1;
                }else if(grid[i][j]==1){
                    freshOrange++;
                }
            }
        }
    if(!freshOrange) return 0;
      int dr[] = {-1,0,1,0};
      int dc[] = {0,-1,0,1};

      int time = 0;
      while(pn.size()>0){
        if(!freshOrange) return time;
        int sz = pn.size();
        for(int i=0;i<sz;i++){
            auto cur = pn.front();
            pn.pop();
            for(int j=0;j<4;j++){
                int nr = cur.first+dr[j];
                int nc = cur.second+dc[j];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && !vis[nr][nc]){
                    pn.push({nr,nc});
                    vis[nr][nc] = 1;
                    freshOrange--;
                }
            }

        }
        time++;
        
      }




        return -1;
    }
};