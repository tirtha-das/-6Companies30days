class Solution {
public:

   int isPointInside(int x1,int y1,int x2,int y2,int radius){
       int dx = abs(x1-x2);
       int dy = abs(y1-y2);
       long long curDist = (((long long)(dx))*dx)+ (((long long)(dy))*dy);
       long long limitDist = (((long long)(radius))*radius);
       
       if(curDist<=limitDist) return 1;
       
       return 0;
   }
  
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int arr1[] ={x1,x2};
        int arr2[] = {y1,y2};

        int count = 0;

       

       // if(count==4) return false;

        int minX = max(x1,min(x2,xCenter));
        int minY = max(y1,min(y2,yCenter));
      //cout<<minX<<" "<<minY<<endl;
        if(isPointInside(minX,minY,xCenter,yCenter,radius)) return true;

        return false;
    }
};