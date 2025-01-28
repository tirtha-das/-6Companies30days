class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        // code here
        map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[nuts[i]]++;
            mp[bolts[i]]++;
        }
        int j = 0;
        for(auto it= mp.begin();it!=mp.end();it++){
            char key = it->first;
            char value = it->second;
            if(value>0){
            nuts[j] = key;
            bolts[j] = key;
            j++;
            }
        }
    }
};