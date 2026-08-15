class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int max_len = 0;
        vector<int> pre(n);

        pre[0] = nums[0];

        for(int i = 1; i < n; i++)
        {
            pre[i] = nums[i] ^ pre[i-1];
        }

        
        if(pre[n-1] != 0)
            return n;

       
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != 0)
            {
                max_len = n - 1;
                break;
            }
        }

        return max_len;
    }
};