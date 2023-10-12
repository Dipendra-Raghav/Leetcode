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
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n=mountainArr.length();
        int i=0;
        int j=n-1;
        int peak=-1;
        while(i<=j)
        {
            int mid=(i+j)/2;
            int t=mountainArr.get(mid);
            if(t>mountainArr.get(mid-1) && t>mountainArr.get(mid+1))
            {
                peak=mid;
                break;
            }
            else if(t<mountainArr.get(mid+1) && t>mountainArr.get(mid-1))
            {
                i=mid;
            }
            else
            {
                j=mid;
            }
        }
        
        //in first half
         i=0;
         j=peak;
        while(i<=j)
        {
            int mid=(i+j)/2;
            int t=mountainArr.get(mid);
            if(t==target)return mid;
            else if(t<target)
                i=mid+1;
            else 
                j=mid-1;
        }
         i=n-1;
         j=peak;
        while(j<=i)
        {
            int mid=(i+j)/2;
            int t=mountainArr.get(mid);
            if(t==target)return mid;
            else if(t<target)
                i=mid-1;
            else 
                j=mid+1;
        }
        return -1;
    }
};