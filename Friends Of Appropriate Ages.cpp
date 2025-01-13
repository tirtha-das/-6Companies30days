class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end());
        int ans = 0;
        for(int i=0;i<ages.size();i++){
          int low = (ages[i]/2)+7;
           if(low<ages[i]){
             int left = upper_bound(ages.begin(),ages.end(),low)-ages.begin();
             int right = upper_bound(ages.begin(),ages.end(),ages[i])-ages.begin();
             ans += (right-left-1);
           } 
        }
        return ans;
    }
};