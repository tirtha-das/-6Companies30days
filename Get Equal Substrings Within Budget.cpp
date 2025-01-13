class Solution {
public:

    int calCost(char ch1, char ch2){
        return abs((ch1-'a')-(ch2-'a'));
    }
   
    int equalSubstring(string s, string t, int maxCost) {
       int len=0,left = 0,right= 0;
       int curCost = 0;
       while(right<s.size()){
         curCost += calCost(s[right],t[right]);
         right++;
         while(left<right && curCost>maxCost){
           curCost -= calCost(s[left],t[left]);
           left++;
         }

         if(curCost<=maxCost){
            len = max((right-left),len);
         }
         
       }
      return len;
    }
};