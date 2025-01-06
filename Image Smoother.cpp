class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(),m = img[0].size();

        vector<vector<int>>smoother(n,vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int totalSum = 0;
                int cnt = 0;
                for(int dr=-1;dr<=1;dr++){
                    for(int dl = -1;dl<=1;dl++){
                        int nr = i+dr;
                        int nl = j+dl;
                        if(nr>=0 && nr<n && nl>=0 && nl<m){
                          totalSum+=img[nr][nl];
                          cnt++;
                        }
                    }
                }
               
                smoother[i][j] = (totalSum)/cnt;
            }
        }
        return smoother;
    }
};