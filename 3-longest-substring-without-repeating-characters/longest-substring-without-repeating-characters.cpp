class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
        int maxLength = 0;
        int start = 0; 
        for (int end = 0; end < s.length(); ++end) {
            char currentChar = s[end];
            if (charIndex.count(currentChar) && charIndex[currentChar] >= start) {
                start = charIndex[currentChar] + 1; 
            }
            charIndex[currentChar] = end; 
            maxLength = max(maxLength, end - start + 1);
        }
        return maxLength;
        
    }
};