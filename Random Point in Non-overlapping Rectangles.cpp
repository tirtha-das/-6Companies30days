class Solution {
    
public:

vector<int>prefArea;
vector<vector<int>>store;
    
    Solution(vector<vector<int>>& rects) {
        int prev = 0;
        for(auto it:rects){
            if(it.size()>0 && it[0]!=it[2] && it[1]!=it[3]){
             int curArea = (it[2]-it[0]+1)*(it[3]-it[1]+1);
             prefArea.push_back(curArea+prev);
             prev = curArea+prev;
             store.push_back(it);
             
            }
        }
    }
    
    vector<int> pick() {
        int size = store.size();
        int item = ((rand())%prefArea[size-1]);
        int curIdx = upper_bound(prefArea.begin(),prefArea.end(),item)-prefArea.begin();
        vector<int>selected = store[curIdx];
       // return {selected[0]+1,temp[1]};
        int x = rand() % (selected[2] - selected[0] + 1) + selected[0];
        int y = rand() % (selected[3] - selected[1] + 1) + selected[1];
        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
