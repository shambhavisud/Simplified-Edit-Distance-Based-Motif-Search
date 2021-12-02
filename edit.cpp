#include <iostream>

#include <cstring>

using namespace std;
int indel, sub;

int editDistance(string s1, string s2)
{

    int m = s1.size();
    int n = s2.size();

    int **dp = new int *[s1.size() + 1];

    for (int i = 0; i < s1.size() + 1; i++)
    {
        dp[i] = new int[s2.size() + 1];
    }

    dp[0][0] = 0;

    for (int i = 1; i < m + 1; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 1; i < n + 1; i++)
    {
        dp[0][i] = i;
    }

    for (int i = 1; i < m + 1; i++)
    {

        for (int j = 1; j < n + 1; j++)
        {
            if (s1[m - i] == s2[n - j])
                dp[i][j] = dp[i - 1][j - 1];

            else
            {
                dp[i][j] = min(indel + dp[i][j - 1], min(indel + dp[i - 1][j], sub + dp[i - 1][j - 1]));
            }
        }
    }

    return dp[m][n];
}
int main()
{
    cout << "enter indel and sub\n";
    cin >> indel >> sub;

    string s1;
    string s2;
    cout << "enter strings\n";
    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2) << endl;
}