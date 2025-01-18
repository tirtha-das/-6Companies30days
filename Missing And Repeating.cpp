 vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        long long curSum = 0 , actualSum = (((long long)n)*(n+1))/2;
        for(auto it:arr){
            curSum+=it;
        }
        
        int i=0,repeat=-1;
        while(i<arr.size()){
            while(arr[i]!=i+1){
                int j = arr[i]-1;
                if(arr[i]==arr[j]){
                    repeat = arr[i];
                    break;
                }
                else{
                   int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] =temp;
                }
            }
            if(repeat>0) break;
            i++;
        }
        
        int missing = (int)(actualSum - (curSum-repeat));
        return {repeat,missing};
    }