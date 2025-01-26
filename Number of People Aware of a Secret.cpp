const int MOD = 1e9+7;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long>know(n,0);
        know[0] = 1;
        long long allowed = 0;
        for(int i=1;i<n;i++){
            if(i-forget>=0){
             allowed -= know[i-forget];
             allowed = ((allowed%MOD)+MOD)%MOD;
            }
            if(i-delay>=0){
                allowed += know[i-delay];
                allowed %= MOD;
            }

            know[i] = allowed;
        }
  
        for(int i = n-delay;i<n;i++){
            allowed += know[i];
            allowed %= MOD;
        }

        return (int)allowed;
    }
};