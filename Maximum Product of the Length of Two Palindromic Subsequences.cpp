class Solution {
public:

  bool isPalindrome(string& str){
    int i = 0 ,j = str.size()-1;
    while(i<j){
        if(str[i]!=str[j]) return false;
        i++;
        j--;
    }
    return true;
  }
      

     int solve(string &s, int idx, string& first,string& second){
        if(idx==s.size()){
          if(isPalindrome(first) && isPalindrome(second)){
                return first.size()*second.size();
            }
            return 0;
        }
         first += s[idx];
        int take1 = solve(s,idx+1,first,second);
        first.pop_back();
        second += s[idx];
        int take2 = solve(s,idx+1,first,second);
        second.pop_back();
        int notTake = solve(s,idx+1,first,second);

        return max(take1,max(take2,notTake));
     }

    int maxProduct(string s) {
        string first = "",second="";
        return solve(s,0,first,second);
    }
};