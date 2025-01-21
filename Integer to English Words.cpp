class Solution {
public:

   string solve(int idx,vector<int>& v, string unitPlace[],string tenPlace[],string oneCase[]){
        string ans = unitPlace[v[idx]];
        if(ans.size()) ans+=" Hundred";
        if(v[idx-1]==1){
            if(ans.size()) ans+= " ";
            ans+=oneCase[v[idx-2]];
            return ans;
        }
        else{
           
            if(v[idx-1]!=0){
                 if(ans.size()) ans +=" ";
                ans += tenPlace[v[idx-1]];
            }if(v[idx-2]!=0){
                 if(ans.size()) ans +=" ";
                ans += unitPlace[v[idx-2]];
                
            }
            return ans;
        }
   }

    string numberToWords(int num) {
        if(num==0) return "Zero";
        
        string unitPlace[]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
        string tenPlace[] = {"","Nothing","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        string oneCase[] ={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};

        vector<int>v(10,0);
        int i=0;
        while(num){
            v[i] = num%10;
            num /= 10;
            i++;
        }

        string ans ="";
        if(v[9]>0){
            ans+=unitPlace[v[9]]+" Billion";
        }

        string millionPart = solve(8,v,unitPlace,tenPlace,oneCase);
        if(millionPart.size()){
            if(ans.size()) ans += " ";
            ans+=millionPart;
            ans+=" Million";
        }

        string thousandPart = solve(5,v,unitPlace,tenPlace,oneCase);
         if(thousandPart.size()){
            if(ans.size()) ans += " ";
            ans+=thousandPart;
            ans+=" Thousand";
        }

         string normalPart = solve(2,v,unitPlace,tenPlace,oneCase);
         if(normalPart.size()){
            if(ans.size()) ans += " ";
            ans+=normalPart;
        }

        return ans;
    }
};