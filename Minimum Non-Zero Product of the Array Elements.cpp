const int MOD = 1e9+7;
class Solution {
public:
    
    long long getPower(int n){
        if(n==0){
            return 1;
        }
        long long ans = 1;
        long long half = getPower(n/2);
        if(n%2==1) ans*=2;
        ans*=half;
        ans*=half;
        return ans;
    }

    long long solve(long long num,long long p){
        //cout<<num<<" "<<p<<endl;
        if(p==0){
            return 1;
        }
        long long ans = 1;
        long long half = solve(num,p/2);
        if(p%2==1){
            ans*=num;
            ans%=MOD;
        }
       ans=((ans%MOD)*(half%MOD))%MOD;
        ans=((ans%MOD)*(half%MOD))%MOD;
        
        return ans;
    }


    int minNonZeroProduct(int p) {
        // if(p==1)
        // {
        //     return 1;
        // }
        long long power = getPower(p);
       
        long long lastDigit = power-1;
        long long secondLastDigit = lastDigit-1;
        long long ans = solve(secondLastDigit,secondLastDigit/2);
        //cout<<ans<<endl;
        //cout<<lastDigit<<" "<<secondLastDigit<<endl;
        ans=((ans%MOD)*(lastDigit%MOD))%MOD;
        
        return (int)ans;
    }
};