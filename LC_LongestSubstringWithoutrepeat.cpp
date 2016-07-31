/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    if(s.compare("")==0) return 0;
    int n = s.length();
    int cur_len = 1;  // lenght of current substring
    int max_len = 1;  // result
    int prev_index;  //  previous index
    int i;
    vector<int>visited(256);
    fill(visited.begin(),visited.end(),-1);
    visited[s[0]] = 0;
 
    for (i = 1; i < n; i++)
    {
        prev_index =  visited[s[i]];
        if (prev_index == -1 || i - cur_len > prev_index)
            cur_len++;
        else
        {
            if (cur_len > max_len)
                max_len = cur_len;
 
            cur_len = i - prev_index;
        }
 
        // update the index of current character
        visited[s[i]] = i;
    }
 
    // Compare the length of last NRCS with max_len and
    // update max_len if needed
    if (cur_len > max_len)
        max_len = cur_len;
 
   // free(visited); // free memory allocated for visited
    return max_len;
    }
};
