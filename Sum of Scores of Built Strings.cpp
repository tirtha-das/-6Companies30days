class Solution {
public:
  void buildZ(string str,vector<int>&Z){
        int n = str.size();
        int l=0,r=0;
        for(int i=1;i<n;i++){
            if(i>r){
                l=i;
                r=i;
                while(r<n && str[r-l]==str[r]){
                    r++;
                }
                Z[i] = (r-l);
                r--;
            }else{
                int k = Z[i-l];
                if(i+k<=r){
                    Z[i] = Z[i-l];
                }else{
                  l=i;
                  while(r<n && str[r-l]==str[r]){
                    r++;
                  }
                  Z[i] = r-l;
                  r--;
                }
            }
        }
    }

    long long sumScores(string s) {
        string str = s+"#"+s;
        vector<int>Z(str.size(),0);
         buildZ(str,Z);
        long long ans = 0;
        for(int i=s.size()+1;i<str.size();i++){
           ans+=Z[i];
        }
        return ans;
    }
};