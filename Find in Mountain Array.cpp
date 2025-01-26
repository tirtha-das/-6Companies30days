/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
   int solve(int low,int high,MountainArray &arr){
      if(high<low) return -1;

      int mid = (high+low)/2;
      int cur = arr.get(mid);
      int left = arr.get(mid-1);
      int right = arr.get(mid+1);

      if(cur>left && cur>right) return mid;
     else if(cur>left) return solve(mid+1,high,arr);
      else return solve(low,mid-1,arr);
   }

   int leftSolve(int low,int high,int target, MountainArray &arr){
    if(low>high) return -1;
    int mid = (low+high)/2;
    int cur = arr.get(mid);
    if(cur==target){
        return mid;
    }else if(cur>target){
        return leftSolve(low,mid-1,target,arr);
    }else{
        return leftSolve(mid+1,high,target,arr);
    }
   }

   int rightSolve(int low,int high,int target, MountainArray &arr){
    if(low>high) return -1;
    int mid = (low+high)/2;
    int cur = arr.get(mid);
    if(cur==target){
        return mid;
    }else if(cur<target){
        return rightSolve(low,mid-1,target,arr);
    }else{
        return rightSolve(mid+1,high,target,arr);
    }
   }


    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        int topidx = solve(1,len-2,mountainArr);
        int topElement = mountainArr.get(topidx);
       if(topElement==target){
        return topidx;
       }else if(topElement<target){
        return -1;
       }
       int leftIDX = leftSolve(0,topidx-1,target,mountainArr);
       if(leftIDX!=-1) return leftIDX;
       return rightSolve(topidx+1,len-1,target,mountainArr);
    }
};