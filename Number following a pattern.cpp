class Solution{   
public:
    string printMinNumberForPattern(string s){
        int n = s.size();
        int cur = 1;
        int i = 0;
        string ans = "";
        while(i<n){
            if(s[i]=='D'){
                int j = i;
                while(j<n && s[j]=='D'){
                    j++;
                }
                cur += (j-i);
                int cnt = cur;
                while(i<=j){
                    ans += (cnt+'0');
                    i++;
                    cnt--;
                }
                cur++;
            }else{
                ans += (cur+'0');
                i++;
                cur++;
            }
        }
        
        if(ans.size()<n+1) ans+= (cur+'0');
        return ans;
    }
};