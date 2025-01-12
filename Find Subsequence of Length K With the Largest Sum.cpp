#define PII pair<int,int>

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<PII,vector<PII>,greater<PII>>pq;
        priority_queue<PII,vector<PII>,greater<PII>>pq2;

        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
            if(pq.size()>k) pq.pop();
        }

        vector<int> ans;

        while(pq.size()){
            PII cur  = pq.top();
            pq.pop();
            pq2.push({cur.second,cur.first});
        }

         while(pq2.size()){
            PII cur  = pq2.top();
            pq2.pop();
            ans.push_back(cur.second);
        }



        return ans;
    }
};