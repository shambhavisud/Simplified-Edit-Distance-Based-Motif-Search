// int MinEditDistance(string target, string source)
// {
//     int n = target.length();
//     int m = source.length();
//     int E[n + 1][m + 1];

//     E[0][0] = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         E[i][0] = E[i - 1][0] + indel;
//     }

//     for (int j = 1; j <= m; j++)
//     {
//         E[0][j] = E[0][j - 1] + indel;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= m; j++)
//         {
//             E[i][j] = std::min({E[i - 1][j] + indel, E[i - 1][j - 1] + sub, E[i][j - 1] + indel});
//         }
//     }

//     return E[n][m];
// }

// int main()
// {

//     // for (int j = 0, k = 4; j < test.length(), k < test.length() - 5; j++, k++)
//     // {
//     //     cout << test.substr(j, k) << "___";
//     // }

//     cout << "enter\n";
//     cin >> indel >> sub;
//     cout << MinEditDistance("radhikana", "shambhavi");
// }

// int main()
// {
//     string s1, s2;
//     cout << "enter indel and sub\n";
//     cin >> indel >> sub;

//     cout << "\nENTER STRINGS:\t";
//     cin >> s1 >> s2;
//     cout << "THE DISTANCE/NUMBER OF OPERATIONS ARE " << editdistancemain(s1, s2);

//     return 0;
// }

//exclusive stufffffffffff
/*outfile << A[1] << " is the actual string\n";

    int length = A[1].length();
    string sub_string[possible_substring(A[1], length, L)];
    for (int j = 0; j < A[1].length() - 15; j++)
    {
        sub_string[j] = A[1].substr(j, 15);
        outfile << sub_string[j] << endl;
    }

    outfile << "ed b/w " << A[1] << "and " << sub_string[1] << " is " << editdistancemain(A[1], sub_string[1]) << "\n";*/

// int editdistance(string s1, string s2, int **output)
// {
//     int m = s1.size(), n = s2.size();
//     //base case
//     if (s1.size() == 0 || s2.size() == 0)
//         return max(s1.size(), s2.size());

//     //checking if distance already exists
//     if (output[m][n] != -1)
//         return output[m][n]; //output[i][j] signifies edit distance of string 1 with length i and 2 with j.
//     int ans;
//     //recursive calls
//     if (s1[0] == s2[0])
//         ans = editdistance(s1.substr(1), s2.substr(1), output);

//     //small calculation
//     else
//     {
//         int insert = indel + editdistance(s1.substr(1), s2, output);
//         int replace = sub + editdistance(s1.substr(1), s2.substr(1), output);
//         int del = indel + editdistance(s1, s2.substr(1), output);
//         ans = min(insert, min(replace, del));
//     }
//     //saving the unique call output
//     output[m][n] = ans;

//     return ans;
// }
// int editdistancemain(string s1, string s2) //function so that the user doesn't have to pass output array
// {
//     int m = s1.size(), n = s2.size();
//     int **output = new int *[m + 1]; //output dimensions[m+1][n+1] as string length can be from 0 to m or n.
//     for (int i = 0; i <= m; i++)
//     {
//         output[i] = new int[n + 1];
//         for (int j = 0; j <= n; j++)
//             output[i][j] = -1; //initialisation
//     }
//     return editdistance(s1, s2, output);
// }
