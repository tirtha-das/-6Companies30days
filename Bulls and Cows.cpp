class Solution {
public:
    int updateFreq(unordered_map<char,int>&present,int key,unordered_map<char,int>&change){
       if(present.find(key)!=present.end()){
                present[key]--;
                if(present[key] == 0){
                    present.erase(key);
                }
                return 1;
              }else{
                change[key]++;
              }
              return 0;
    }

    string getHint(string secret, string guess) {
       
        unordered_map<char,int>first,second;
        int freqBull=0,freqCow = 0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                freqBull++;
            }else{
                int key1 = secret[i];
                int key2 = guess[i];
              freqCow +=(updateFreq(second,key1,first));
              freqCow +=(updateFreq(first,key2,second));
            }
        }


        return to_string(freqBull)+"A"+to_string(freqCow)+"B";
    }
};