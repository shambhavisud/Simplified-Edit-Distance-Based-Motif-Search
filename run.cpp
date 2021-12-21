
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;

const int soize = 4;
int indel, sub, L, D;

int editDistance(string start, string target)
{
    int m = start.length();
    int n = target.length();

    // For every pair of i and j, E[i,j] stores the Edit distance
    // b/w the 1st `i` characters of `start` & the first `j` characters of target string.
    // Matrix E will hold (m+1)*(n+1) vals
    int E[m + 1][n + 1];

    // initialize `T` by all 0's
    memset(E, 0, sizeof E);

    // we can transform source prefixes into an empty string by
    // dropping all characters

    for (int i = 1; i <= m; i++)
    {
        E[i][0] = i; // (case i)
    }

    // Reaching the target prefixes from empty start prefix
    // through insertion of ev char

    for (int j = 1; j <= n; j++)
    {
        E[0][j] = j; // (case 1)
    }

    int sub_cost;

    // Bottoms up filling of Matrix E
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (start[i - 1] == target[j - 1])
            { // (case ii)
                sub_cost = 0;
            }
            else
            {
                sub_cost = sub; // (case iii(3))
            }
            E[i][j] = min(min(E[i - 1][j] + indel,     // delete (case iii(2))
                              E[i][j - 1] + indel),    // insert (case iii(1))
                          E[i - 1][j - 1] + sub_cost); // substitute (case ii and iii(3))
        }
    }

    return E[m][n];
}

int num_of_subs_possible(string str, int length, int n)
{
    int num_subs = length - n + 1;
    return num_subs;
}

string randomStringGenerator(int n)
{
    char set_acgt[soize] = {'A', 'C', 'G', 'T'};

    string gen_str = "";
    for (int i = 0; i < n; i++)
        gen_str = gen_str + set_acgt[rand() % soize];

    return gen_str;
}

int main()
{
    ofstream outfile;
    ifstream infile;
    infile.open("Data.txt");
    int inputArray[4];
    int cnt = 0;
    int read_num;
    while (cnt < inputArray[4] && infile >> read_num)
    {
        inputArray[cnt++] = read_num;
    }

    D = inputArray[0];
    L = inputArray[1];
    indel = inputArray[2];
    sub = inputArray[3];

    outfile.open("Out.txt");

    srand(time(NULL));
    int n = 600;
    string A[20];
    for (int i = 0; i < 20; i++)
    {
        A[i] = randomStringGenerator(n);
    }

    for (int i = 0; i < 20; i++) // for each string 1 to 20
    {
        string str = A[i];

        int length = str.length();
        string sub_string[num_of_subs_possible(str, length, L)]; // initialise array size with possible number of susbstrings
        for (int j = 0; j < A[i].length() - L + 1; j++)          // for each substring of A[i]
        {                                                        // initialise the array with all possible substrings

            sub_string[j] = A[i].substr(j, L);

            // int k;
            int flag = 0;

            for (int k = 0; k < 20; k++)
            {

                if (k == i)
                {
                    continue;
                }
                else
                {
                    string other_sub_string[num_of_subs_possible(A[k], A[k].length(), L)];
                    for (int y = 0; y < A[k].length() - L + 1; y++)
                    {

                        other_sub_string[y] = A[k].substr(y, L);
                        int eds = editDistance(sub_string[j], other_sub_string[y]);

                        if (eds < D || eds == D)
                        {

                            flag++;

                            break;
                        }
                    }
                }
            }

            if (flag == 19)
            {
                outfile << sub_string[j] << "\n";
            }
        }
    }

    return 0;
}
