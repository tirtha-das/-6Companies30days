class KthLargest {
public:
  int limit ;
    priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int k, vector<int>& nums) {
        for(auto it:nums){
            pq.push(it);
            if(pq.size()>k) pq.pop();
        }
        limit = k;
    }
    
    int add(int val) {
        pq.push(val);
      if(limit<pq.size())  pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */