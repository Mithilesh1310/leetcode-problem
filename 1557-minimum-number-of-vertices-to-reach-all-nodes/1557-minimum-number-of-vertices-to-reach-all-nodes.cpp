class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool>ind(n,false);
        for(auto &i : edges)
        {
            int u = i[0];
            int v = i[1];

            ind[v] = true;
        }

        vector<int>result;

        for(int i =0;i<n;i++)
        {
            if(ind[i] == false)
            result.push_back(i);
        }

        return result;
    }
};