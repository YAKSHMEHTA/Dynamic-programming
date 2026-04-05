#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool solve(string s1, string s2)
    {
        int n = s1.size();
        if (s1.size() <= 1 || s2.size() <= 1)
        {
            return false;
        }
        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            if (solve(s1.substr(0, i), s2.substr(0, i)) && solve(s1.substr(i, s1.size() - i), s2.substr(i, s2.size() - i)))
            {
                ans = true;
            }

            if (solve(s1.substr(0, i), s2.substr(s2.size() - i)) &&
                solve(s1.substr(i), s2.substr(0, s2.size() - i)))
            {
                ans = true;
            }
        }
        return ans;
    }

    bool isScramble(string s1, string s2)
    {
        int n = s1.size();
        int m = s2.size();

        return solve(s1, s2);
    }
};

int main()
{
    Solution s;
    string s1= "";
    string s2= "";
    cout << "ANS => " << s.solve(s1,s2) << "<- ans" << endl;

    return 0;
}