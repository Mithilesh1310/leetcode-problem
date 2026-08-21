class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int>sorted_a;
        int i = 0;
        int j = 0;
        while(i<m&&j<n)
        {
            if(nums1[i]<nums2[j])
            {
                sorted_a.push_back(nums1[i]);
                i++;
            }
            else
            {
            sorted_a.push_back(nums2[j]);
            j++;
            }


        }
        while(i<m)
        {
            sorted_a.push_back(nums1[i]);
            i++;
        }

         while(j<n)
        {
            sorted_a.push_back(nums2[j]);
            j++;
        }

        int o = sorted_a.size();
        double mid =0;
        if(o%2!=0)
        {
            mid = sorted_a[o/2];
            

        }
        else
        {
          mid = (sorted_a[o/2] + sorted_a[o/2 - 1]) / 2.0;

        }
        return mid;

    }
};