class Solution {
public:
     vector<string>solve(int idx,string digits,string arr[]){
        vector<string>ans;
        if(idx==digits.size()){
           ans.push_back("");
           return ans;
        }

        vector<string>res = solve(idx+1,digits,arr);
        int arrIdx = (digits[idx]-'0')-2;
        string cur = arr[arrIdx];
        for(auto it:cur){
            for(auto it2:res){
                string s = it+it2;
                ans.push_back(s);
            }
        }
        return ans;

     }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        string arr[] ={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        return solve(0,digits,arr);
    }
};