class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char,int>mp;
       for(auto it:s){
        mp[it]++;
       }

       priority_queue<pair<int,char>> pq;
       for(auto it=mp.begin();it!=mp.end();it++){
        pq.push({it->second,it->first});
       }

       string ans = "";
       while(pq.size()){
        auto cur = pq.top();
        pq.pop();
        while(cur.first>0){
            ans+=cur.second;
            cur.first--;
        }
       }

       return ans;
    }
};