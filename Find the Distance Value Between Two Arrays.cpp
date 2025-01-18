class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        for(auto it:arr1){
          ans++;
          for(auto it2:arr2){
            if(abs(it-it2)<=d){
                ans--;
                break;
            }
          }
        }
        return ans;
    }
};