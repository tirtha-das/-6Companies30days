class Solution {
  public:
    string encode(string s) {
      char ch = s[0];
      int cnt = 1;
      string ans ="";
      for(int i=1;i<s.size();i++){
         if(s[i]==ch){
             cnt++;
         }else{
            ans += ch;
            ans += to_string(cnt);
            ch = s[i];
            cnt = 1;
         }
      }
      
      ans += ch;
      ans += to_string(cnt);
      return ans;
    }
};