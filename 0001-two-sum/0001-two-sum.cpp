class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>>p;
        for(int i =0;i<n;i++)
        {
            p.push_back({nums[i],i});
        }

        sort(p.begin(),p.end());
        int i =0;
        int j = n-1;
        

        while(i < j)
        {
            int sum = p[i].first +p[j].first;

            if(sum == target)
            {
                return {p[i].second,p[j].second};
            }
            else if(sum < target)
            {
                i++;
            }
            else
            {
                j--;
            }
            
        }
        return {};
    }
};