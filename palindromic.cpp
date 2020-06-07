// this program aims to find all palindromic substrings of a given string and sort them
 
#include <iostream>
 
using namespace std;
 
char allStrs[1000000][20]; //a 2-d array used to store all the substrings for sorting
 
// function to find the length of a string
int findLen(char str[]) {
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}
 
// function to find the palindromic substrings
int ctr = 0; // used to count how many palindromic substrings
int findPal(char str[]) 
{
    int length;
    length = findLen(str);
 
    for (int i = 0; i < length; i++)
    {
        // for odd length strings
        int j = 1;
        while ((i - j) >= 0 && (i + j) < length) {
            if (str[i - j] == str[i + j])
            {
                //testing only
                //cout << "i is " << i << endl;
                //cout << "j is " << j << endl;
 
                ctr++;
 
                for (int k = 0; k < 2 * j + 1; k++)
                {
                    allStrs[ctr][k] = str[i - j + k];
                }
                allStrs[ctr][2 * j + 1] = '\0';
                j++;
            }
            else {
                break;
            }
        }   
         
        // for even length strings
        int m = 0;
        while ((i - m) >= 0 && (i + 1 + m) < length) {
            if (str[i - m] == str[i + 1 + m])
            {
                //testing only
                //cout << "i is " << i << endl;
                //cout << "m is " << m << endl;
 
                ctr++;
 
                for (int n = 0; n < 2 * m + 2; n++)
                {
                    allStrs[ctr][n] = str[i - m + n];
                }
                allStrs[ctr][2 * m + 2] = '\0';
                m++;
            }
            else {
                break;
            }
        }
    }
    return ctr;
}
 
// modified version of string compare function in lab10
int strCom(char s1[], char s2[]) {
    int size = 0;
    int longer = 0; // setting to 0 means equal length
                    // setting to 1 means s1 is longer
 
    if (findLen(s1) > findLen(s2))
    {
        size = findLen(s2);
        longer = 1;
    }
    else if (findLen(s1) < findLen(s2)) {
        size = findLen(s1);
        longer = -1;
    }
    else {
        size = findLen(s1);
        longer = 0;
        for (int i = 0; i < size; i++)
        {
            if (s1[i] > s2[i])
            {
                return 1;
            }
            else if (s1[i] < s2[i]) {
                return -1;
            }
        }
    }
     
    return longer;
}
 
// function to swap two strings
void swap(char s1[], char s2[]) {
    char tmp[20];
    int i = 0, j = 0;
    while (s1[i] != '\0')
    {
        tmp[j] = s1[i];
        i++;
        j++;
    }
    tmp[j] = '\0';
    i = 0, j = 0;
    while (s2[i] != '\0')
    {
        s1[j] = s2[i];
        i++;
        j++;
    }
    s1[j] = '\0';
    i = 0, j = 0;
    while (tmp[i] != '\0')
    {
        s2[j] = tmp[i];
        i++;
        j++;
    }
    s2[j] = '\0';
}
 
// function to implement bubble sort and sort the list
void sort(char list[][20], int ctr) {
    for (int m = 0; m < ctr; m++)
    {
        swap(list[m], list[m + 1]);
    }
    for (int i = 0; i < ctr - 1; i++)
    {
        for (int j = 0; j < ctr - i - 1; j++)
        {
            if (strCom(list[j],list[j+1]) > 0)
            {
                swap(list[j], list[j + 1]);
            }
        }
    }
}
 
// function to print the output
void print(int ctr){
    if (ctr == 0)
    {
        cout << "There is no palindromic substring" << endl;
    }
    else
    {
        cout << "The result is:" << endl;
        for (int i = 0; i < ctr; i++)
        {
            cout << allStrs[i] << endl;
        }
    }
}
 
int main()
{
    // get user input
    char str[20];
    cout << "Please input a string:" << endl;
    cin >> str;
 
    // calling the functions
    int num = findPal(str); // store the number of p-substrings
    sort(allStrs,num);
    cout << endl;
    print(num);
 
    return 0;
}
