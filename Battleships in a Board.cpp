class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X'){
                int top = i-1;
                int left = j-1;

                if((top>=0 && board[top][j]=='X') || (left>=0 && board[i][left]=='X')){
                    continue;
                }else{
                    ans++;
                }
                }
            }
        }

        return ans;
    }
};