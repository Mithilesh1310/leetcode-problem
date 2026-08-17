class Solution {
public:
    string multiply(string num1, string num2) {

        vector<vector<int>> ele;
        int r = 0;

        for(int i = num2.size() - 1; i >= 0; i--)
        {
            int div = 0;
            vector<int> temp;

            for(int k = 0; k < r; k++)
                temp.push_back(0);

            for(int j = num1.size() - 1; j >= 0; j--)
            {
                int mult = (num1[j] - '0') * (num2[i] - '0');

                mult += div;

                int rem = mult % 10;
                div = mult / 10;

                temp.push_back(rem);
            }

            if(div)
                temp.push_back(div);

            ele.push_back(temp);
            r++;
        }

        vector<int> ans(num1.size() + num2.size() + 1, 0);

        // Add all rows
        for(int i = 0; i < ele.size(); i++)
        {
            int carry = 0;

            for(int j = 0; j < ele[i].size(); j++)
            {
                int sum = ans[j] + ele[i][j] + carry;

                ans[j] = sum % 10;
                carry = sum / 10;
            }

            int j = ele[i].size();

            while(carry)
            {
                int sum = ans[j] + carry;

                ans[j] = sum % 10;
                carry = sum / 10;

                j++;
            }
        }

        string result = "";

        int i = ans.size() - 1;

        while(i > 0 && ans[i] == 0)
            i--;

        while(i >= 0)
        {
            result += char(ans[i] + '0');
            i--;
        }

        return result;
    }
};