class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        unordered_map<int, int> lost;

        vector<int> win;
        vector<int> loose;

        for (int i = 0; i < n; i++) {
            lost[matches[i][1]]++;
        }

        for (int i = 0; i < n; i++) {
            if (!lost.count(matches[i][0])) {
                win.push_back(matches[i][0]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (lost[matches[i][1]] == 1) {
                loose.push_back(matches[i][1]);
            }
        }

        sort(win.begin(), win.end());
        sort(loose.begin(), loose.end());
        win.erase(unique(win.begin(), win.end()), win.end());

        vector<vector<int>> ans;
        ans.push_back(win);
        ans.push_back(loose);

        return ans;
    }
};