class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            vector<int>freq(10,0);
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int idx = board[i][j]-'0';
                //cout<<idx<<" ";
               
                     freq[idx]++;
                   if(freq[idx]==2) return false;
                
                
            }
            //cout<<endl;
        }

        for(int i=0;i<9;i++){
            vector<int>freq(10,0);
            for(int j=0;j<9;j++){
                if(board[j][i]=='.') continue;
                int idx = board[j][i]-'0';
                freq[idx]++;
                if(freq[idx]==2) return false;
            }
        }

        for(int rowlimit = 2 ;rowlimit<9;rowlimit+=3){
           for(int collimit = 2;collimit<9;collimit+=3){
            vector<int>freq(10,0);
            for(int i=rowlimit-2;i<=rowlimit;i++){
                for(int j=collimit-2;j<=collimit;j++){
                    if(board[i][j]=='.') continue;
                    int idx = board[i][j]-'0';
                freq[idx]++;
                if(freq[idx]==2) return false;
                }
            }
           }
        }

        return true;
    }
};