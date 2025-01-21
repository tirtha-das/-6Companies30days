const int MOD = 1e9+7;

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(auto it:nums){
            pq.push(it);
        }
        while(k){
            long long cur = pq.top();
            pq.pop();
            cur++;
            pq.push(cur);
            k--;

        }

        long long ans = 1;
        while(pq.size()){
            ans*=pq.top();
            pq.pop();
            ans%=MOD;
        }

        return (int)ans;
    }
};