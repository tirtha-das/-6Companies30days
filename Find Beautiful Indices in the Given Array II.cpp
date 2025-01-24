class Solution {
public:
   vector<int>KMP(string pat, string text){
      string temp = pat+"#"+text;
      int size = temp.size();
      vector<int>lps(size,0);
      int cur = 1;
      while(cur<size){
        int prev = lps[cur-1];
        while(prev>0 && temp[cur]!=temp[prev]){
            prev=lps[prev-1];
        }
        if(temp[cur]==temp[prev]) lps[cur] = prev+1;

        cur++;
      }

      vector<int>res;
      for(int i=0;i<size;i++){
        if(lps[i]==pat.size()){
            
            res.push_back(i-(2*pat.size()));
        }
      }

      return res;

   }
     
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>ans;
        if(s.size()<a.size() || s.size()<b.size()) return ans;

        vector<int>first = KMP(a,s);
        vector<int>second = KMP(b,s);


        for(int i=0;i<first.size();i++){
            int idx = lower_bound(second.begin(),second.end(),first[i]-k)-second.begin();
            if(idx<second.size() && second[idx]<=first[i]+k){
                ans.push_back(first[i]);
            }
        }

        return ans;


    }
};