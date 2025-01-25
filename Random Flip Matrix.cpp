class Solution {
public:
    
    unordered_set<int>myset;
    int n;
    int m;

    Solution(int m, int n) {
       this->m = m;
       this->n = n;
    }
    
    vector<int> flip() {
        int r = rand()%m;
        int c = rand()%n;
        int cur  = (r*n)+c;
        if(myset.find(cur)==myset.end()){
            myset.insert(cur);
            return {r,c};
        }
        else{
            return flip();
        }
    }
    
    void reset() {
        
        myset.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */