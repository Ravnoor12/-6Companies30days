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
    int binarysearch(int low,int high,int val,MountainArray &mountainArr){
        int i = low,j = high;
        int mid;
        bool rev = mountainArr.get(i) > mountainArr.get(j);
        while(j>=i){
            mid = i + (j-i)/2;
            int a = mountainArr.get(mid);
            if(a==val){
                return mid;
            }
            else if(a>val) {
                if(rev) i = mid+1;
                else 
                j=mid-1;
            }
            else{
                if(rev) j = mid-1;
                else 
                i = mid+1;
            }
        }
        return -1;
    }
    int findpeak(MountainArray &mountainArr,int n){
        int i=0,j = n-1;
        int mid;
        while(j!=i){
            mid = i + (j-i)/2;
            int a = mountainArr.get(mid);
            if(a<mountainArr.get(mid+1)) i = mid+1;
            else 
                j = mid;
          }
        return j;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int mid = findpeak(mountainArr,n);
       int ans = binarysearch(0,mid,target,mountainArr);
        if(ans==-1) {
            ans = binarysearch(mid+1,n-1,target,mountainArr);
        }
        return ans;
    }
};