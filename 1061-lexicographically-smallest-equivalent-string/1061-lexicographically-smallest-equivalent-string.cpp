class Solution {
public:
    int findmin(unordered_map<int,vector<int>>&mp, int curr, vector<int>&vis)
    {
        int minstring = curr;
        vis[curr] = 1;

        for(auto &val : mp[curr])
        {
            if(!vis[val])
            {
                minstring = min(minstring, findmin(mp, val, vis));
            }
        }

        return minstring;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();

        unordered_map<int,vector<int>>mp;

        for(int i = 0; i < n; i++)
        {
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        for(int i = 0; i < baseStr.size(); i++)
        {
            vector<int> vis(26, 0);

            int x = findmin(mp, baseStr[i] - 'a', vis);

            baseStr[i] = x + 'a';
        }

        return baseStr;
    }
};