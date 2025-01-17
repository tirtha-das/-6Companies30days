

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_map<string,int>mp;
        for(auto it:targetWords){
            string cur = it;
            sort(cur.begin(),cur.end());
            mp[cur]++;
        }

        int ans = 0;
        for(auto it:startWords){
            vector<int>vis(26,0);
            for(auto ch :it){
                vis[ch-'a']=1;
            }
            for(int i=0;i<26;i++){
                if(!vis[i]){
                    char ch = i+'a';
                    string cur = it;
                    cur+=ch;
                    sort(cur.begin(),cur.end());
                    if(mp.find(cur)!=mp.end()){
                        ans+=mp[cur];
                        mp.erase(cur);
                    }

                }
            }
        }

        return ans;
    }
};