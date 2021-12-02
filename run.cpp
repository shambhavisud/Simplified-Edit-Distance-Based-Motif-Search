// CPP Program to generate random alphabets
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 4;
int indel, sub, L, D;

int possible_substring(string str, int length, int n)
{
    int count = length - n + 1;
    return count;
}

// Returns a string of random alphabets of
// length n.
string printRandomString(int n)
{
    char alphabet[MAX] = {'A', 'C', 'G', 'T'};

    string res = "";
    for (int i = 0; i < n; i++)
        res = res + alphabet[rand() % MAX];

    return res;
}

int editDistance(string s1, string s2)
{

    int m = s1.size();
    int n = s2.size();

    int **E = new int *[s1.size() + 1];

    for (int i = 0; i < s1.size() + 1; i++)
    {
        E[i] = new int[s2.size() + 1];
    }

    E[0][0] = 0;

    for (int i = 1; i < m + 1; i++)
    {
        E[i][0] = i;
    }
    for (int i = 1; i < n + 1; i++)
    {
        E[0][i] = i;
    }

    for (int i = 1; i < m + 1; i++)
    {

        for (int j = 1; j < n + 1; j++)
        {
            if (s1[m - i] == s2[n - j])
                E[i][j] = E[i - 1][j - 1];

            else
            {
                E[i][j] = min(indel + E[i][j - 1], min(indel + E[i - 1][j], sub + E[i - 1][j - 1]));
            }
        }
    }

    return E[m][n];
}

void print_neighbour(string A[], string s)
{
    // ofstream outfile;
    // outfile.open("output.txt");
    int flag = 0;

    for (int i = 0; i < 20; i++)
    {
        if (editDistance(s, A[i]) < D || editDistance(s, A[i]) == D)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }
    }
    if (flag == 0)
    {
        //outfile << s << " is a neighbour to all others!\n";
    }
}

// Driver code
int main()
{
    ofstream outfile;
    ifstream infile;
    infile.open("input.txt");
    int inputArray[4];
    int cnt = 0;
    int read_num;
    while (cnt < inputArray[4] && infile >> read_num)
    {
        inputArray[cnt++] = read_num;
    }

    // cout << "The integers are:"
    //      << "\n";
    // for (int i = 0; i < cnt; i++)
    // {
    //     cout << inputArray[i] << ' ';
    // }

    D = inputArray[0];
    L = inputArray[1];
    indel = inputArray[2];
    sub = inputArray[3];

    outfile.open("output.txt");

    srand(time(NULL));
    int n = 600;
    string A[20];
    for (int i = 0; i < 20; i++)
    {
        A[i] = printRandomString(n);
    }

    // cout << "enter values of D L indel and sub\n";
    // cin >> D >> L >> indel >> sub;

    // for (int i = 0; i < 20; i++)
    // {
    //     outfile << A[i] << "\n";
    // }

    //outfile << "Count of substrings of length n possible from the given string are: " << possible_substring(str, length, L);

    for (int i = 0; i < 20; i++) //for each string 1 to 20
    {
        string str = A[i];

        int length = str.length();
        string sub_string[possible_substring(str, length, L)]; //initialise array size with possible number of susbstrings
        for (int j = 0; j < A[i].length() - L + 1; j++)        //initialise the array with all possible substrings
        {

            sub_string[j] = A[i].substr(j, L);
            int flag = 0;

            //print_neighbour(A, sub_string[j]);
            int k;
            for (k = 0; k < 20; k++)
            {

                if (editDistance(sub_string[j], A[k]) < D || editDistance(sub_string[j], A[k]) == D)
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
            {
                outfile << sub_string[j] << "ed is " << editDistance(sub_string[j], A[k]) << "\n";
            }
        }
    }

    return 0;
}
