class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> charSet;
    int left = 0;
    int result = 0;  
    for(int right=0;right<s.size();right++){
        while(charSet.find(s[right]) != charSet.end()){
            charSet.erase(s[left]);
            left++;
        }
        charSet.insert(s[right]);
        result = max(result, right - left + 1);
    }
    return result;
}
};