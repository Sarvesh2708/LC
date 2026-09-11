#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    set<char> charSet;
    int left = 0;
    int result;
    for(int right=0;right<input.size();right++){
        while(charSet.find(input[right]) != charSet.end()){
            charSet.erase(input[left]);
            left++;
        }
        charSet.insert(input[right]);
        result = max(result, right - left + 1);
    }
    return result;
}