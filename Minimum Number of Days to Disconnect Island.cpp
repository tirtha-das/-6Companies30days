class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis){
         int m = grid.size();
        int n = grid[0].size();

        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};

        queue<pair<int,int>>pn;
        pn.push({row,col});
        vis[row][col] = 1;

        while(pn.size()){
            auto cur = pn.front();
            pn.pop();
            for(int i=0;i<4;i++){
                int nr = cur.first+dr[i];
                int nc = cur.second+dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && !vis[nr][nc]){
                    pn.push({nr,nc});
                    vis[nr][nc] = 1;
                }
            }
        }

    }
   
    bool alreadyDisconnected(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j] && !vis[i][j]){
                 bfs(i,j,grid,vis);
                 cnt++;
                 }
               }
            }
       if(cnt==1){
        return false;
       }
       return true;
    }

    int minDays(vector<vector<int>>& grid) {
        if(alreadyDisconnected(grid)) return 0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    grid[i][j] = 0;
                    if(alreadyDisconnected(grid)){
                        return 1;
                    }
                    grid[i][j]=1;
                }
            }
        }

        return 2;
    }
};