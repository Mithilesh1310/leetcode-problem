class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        
        for(int i = 0;i<knowledge.size();i++)
        {
            string key = knowledge[i][0];
            string value = knowledge[i][1];
            mp[key] = value;
        }

        vector<pair<int,int>>pr;

        int st = 0;

        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == '(')
                st = i;

            if(s[i] == ')')
            {
                int end = i;
                pr.push_back({st,end});
            }
        }

        int shift = 0;

        for(int i = 0;i<pr.size();i++)
        {
            int st = pr[i].first + shift;
            int end = pr[i].second + shift;

            string temp = s.substr(st + 1, end - st - 1);

            string value = "?";

            if(mp.count(temp))
                value = mp[temp];

            s.replace(st, end - st + 1, value);

            shift += value.size() - (end - st + 1);
        }

        return s;
    }
};