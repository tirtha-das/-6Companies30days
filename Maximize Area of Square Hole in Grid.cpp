class Solution {
public:
     void getInterval(vector<int>& vect,vector<int>&temp){
      int i = 0;
      while(i<vect.size()){
        int lb = vect[i]-1;
        while(i+1<vect.size()&& vect[i]+1==vect[i+1]){
            i++;
        }
        int rb = vect[i]+1;
        int dif = rb-lb;
        temp.push_back(dif);
        i++;
      }
     }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        vector<int>rows;
        vector<int>cols;
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        getInterval(hBars,rows);
        getInterval(vBars,cols);

        int ans = 1;
        for(auto it:rows){
            for(auto it2:cols){
                int cur = min(it,it2);
                ans = max(ans,cur*cur);
            }
        }

        return ans;
        
    }
};