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

int editdistance(string s1, string s2, int **output)
{
    int m = s1.size(), n = s2.size();
    //base case
    if (s1.size() == 0 || s2.size() == 0)
        return max(s1.size(), s2.size());

    //checking if distance already exists
    if (output[m][n] != -1)
        return output[m][n]; //output[i][j] signifies edit distance of string 1 with length i and 2 with j.
    int ans;
    //recursive calls
    if (s1[0] == s2[0])
        ans = editdistance(s1.substr(1), s2.substr(1), output);

    //small calculation
    else
    {
        int insert = indel + editdistance(s1.substr(1), s2, output);
        int replace = sub + editdistance(s1.substr(1), s2.substr(1), output);
        int del = indel + editdistance(s1, s2.substr(1), output);
        ans = min(insert, min(replace, del));
    }
    //saving the unique call output
    output[m][n] = ans;

    return ans;
}
int editdistancemain(string s1, string s2) //function so that the user doesn't have to pass output array
{
    int m = s1.size(), n = s2.size();
    int **output = new int *[m + 1]; //output dimensions[m+1][n+1] as string length can be from 0 to m or n.
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
        for (int j = 0; j <= n; j++)
            output[i][j] = -1; //initialisation
    }
    return editdistance(s1, s2, output);
}

void print_neighbour(string A[], string s)
{
    // ofstream outfile;
    // outfile.open("output.txt");
    int flag = 0;

    for (int i = 0; i < 20; i++)
    {
        if (editdistancemain(s, A[i]) < D || editdistancemain(s, A[i]) == D)
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

    for (int i = 0; i < 20; i++)
    {
        outfile << A[i] << "\n";
    }

    //outfile << "Count of substrings of length n possible from the given string are: " << possible_substring(str, length, L);

    // for (int i = 0; i < 20; i++) //for each string 1 to 20
    // {
    //     string str = A[i];

    //     int length = str.length();
    //     string sub_string[possible_substring(str, length, L)]; //initialise array size with possible number of susbstrings
    //     for (int j = 0; j < A[i].length() - L + 1; j++)        //initialise the array with all possible substrings
    //     {

    //         sub_string[j] = A[i].substr(j, L);
    //         int flag = 0;

    //         //print_neighbour(A, sub_string[j]);
    //         // int k;
    //         for (int k = 0; k < 20; k++)
    //         {

    //             if (editdistancemain(sub_string[j], A[k]) < D || editdistancemain(sub_string[j], A[k]) == D)
    //             {
    //                 flag = 1;
    //             }
    //             else
    //             {
    //                 flag = 0;
    //                 break;
    //             }
    //         }
    //         if (flag == 1)
    //         {
    //             outfile << sub_string[j] << "\n";
    //         }
    //     }
    // }

    return 0;
}
