class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp(nums);
        int j = nums.size()-1;

        for(int i=1;i<nums.size();i+=2){
            nums[i] = temp[j];
            j--;
            
        }
        for(int i=0;i<nums.size();i+=2){
            nums[i] = temp[j];
            j--;
            
        }

    }
};