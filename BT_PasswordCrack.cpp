#include <bits/stdc++.h>
using namespace std;

// Define the real password and a function to check if a given password matches it
string realpasscode = "pasd";

bool passchecker(string passcode)
{
    return (passcode == realpasscode);
}

//Recursive function for Backtracking
string crack(int length, string pass = "")
{
    // If the current password matches the real password, return it
    if (passchecker(pass))
        return pass;
    // If the password length is 0, return an empty string (empty string means invalid password or not found)
    else if (length == 0)
        return "";

    // Iterate over all lowercase alphabetical characters and recursively call the crack function
    // with the password string concatenated with the current character
    for (char ch = 'a'; ch <= 'z'; ch++) //26 characters O(26^n) or (2^n) exponential
    {
        string res = crack(length - 1, pass + ch);
        if (!res.empty())
            return res;
    }
    // If the password is not found, return empty string
    return "";
}

int main()
{
    cout << crack(6) << "\n";
}

/* brief explanation

If the current password combination is not valid, the algorithm backtracks and
tries the next possible character until the password is found or all possible combinations have been exhausted.
This process continues until the password is found or all possible combinations of characters have been tried.

Therefore, the recursive function crack() is an example of backtracking because it builds up a solution
incrementally (by trying different characters in the password string) and undoes previous
choices (by backtracking to try other characters when a dead end is reached).
*/