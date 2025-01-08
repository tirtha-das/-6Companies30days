class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>freq;
        queue<int>q;

        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
            q.push(i);
        }

        while(q.size()>0){
            int idx = q.front();
            if(freq[s[idx]]==1) return idx;
            q.pop();
        }

        return -1;
    }
};