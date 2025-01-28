class Solution {
public:

 long long gcd(long long a, long long b)
    {
        if (a == 0)
            return b; 
        return gcd(b % a, a); 
    }
    
    // method to return LCM of two numbers
     long long lcm(long long a, long long b)
    {
        return (a / gcd(a, b)) * b;
    }


     long long solve(long long left, long long right,int d1,int d2,int u1,int u2){
        if(left>right){
            return 1e16;
        }

        long long mid = (left+right)/2;
        long long a = mid - (mid/d1);
        long long b = mid - (mid/d2);
        long long c = mid - ((mid)/d1) -((mid)/d2) + (mid/lcm(d1,d2));
        if(a>=u1 && b>=u2 && (a+b-c)>=(u1+u2)){
            return min(mid,solve(left,mid-1,d1,d2,u1,u2));
        }
        return solve(mid+1,right,d1,d2,u1,u2);
     }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        return (int)solve(0,1e12,divisor1,divisor2,uniqueCnt1,uniqueCnt2);
    }
};