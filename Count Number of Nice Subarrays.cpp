class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int>evenFreq;
        int cnt = 0;
        for(auto it:nums){
            if(it%2==1){
                evenFreq.push_back(cnt);
                cnt=0;
            }else{
                cnt++;
            }
        }
        evenFreq.push_back(cnt);
        int left = 0,right = k;
        int ans = 0;

        while(right<evenFreq.size()){
          ans+= ((evenFreq[left]+1)*(evenFreq[right]+1));
          left++;
          right++;
        }
        
        return ans;
    }
};