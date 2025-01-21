class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<10) return {};
        vector<string> ans;
        unordered_map<string,int>freq;
        for(int i=0;i<=s.size()-10;i++){
            string temp = s.substr(i,10);
            freq[temp]++;
            if(freq[temp]==2) ans.push_back(temp);
        }

        
      return ans;
    }
};