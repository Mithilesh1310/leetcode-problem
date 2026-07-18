class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>p;
        for(int i = 0;i<nums.size();i++)
        {
            p.push_back(make_pair(nums[i],i));
        }
        sort(p.begin(),p.end());
        // vector<int>ans(2,0);
        int sum;
        int start = 0;
        int end = nums.size()-1;
        while(start<end)
        {
            sum = p[start].first +p[end].first;
            if(sum == target)
            {
                // ans[0] = p[start].second;
                // ans[1] = p[end].second;
                // break;
                return {p[start].second,p[end].second};
            }
            else if(sum>target)
            {
                end--;
            }
            else
            {
                start++;
            }
        }

        // map<int,int> d;
        // vector<int>ans;
        // for(int i = 0;i<nums.size();i++)
        // {
        //     int t = target - nums[i];
        //     if(d.find(t) != d.end()){
        //         ans.push_back(d[t]);
        //         ans.push_back(i);
        //         break;

        //     }
        //     d[nums[i]] = i;


        // }
        return {};

    }
};
