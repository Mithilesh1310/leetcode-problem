class Solution {
public:
    int sumdigit(int x)
    {
        int sum = 0;

        while(x != 0)
        {
            int rem = x%10;
            sum += rem;
            x /= 10;
        }

        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        int ans = 10000;

        for(int i = 0;i<n;i++)
        {
            if(i == sumdigit(nums[i]))
            ans = min(ans,i);
        }
        if(ans == 10000)
        return -1;

        return ans;

    }
};