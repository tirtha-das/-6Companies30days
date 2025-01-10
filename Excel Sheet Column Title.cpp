class Solution {
public:
    string convertToTitle(int colNum) {
        if(colNum<27){
            char c = 'A'+(colNum-1);
            string ans = "";
            ans+=c;
            return ans;
        }

        int res = colNum/26;
        int rem = colNum%26;
        if(rem==0) {
            res--;
            rem=26;
        }

        char c = 'A'+(rem-1);
        string ans = convertToTitle(res)+c;
        return ans;
    }
};