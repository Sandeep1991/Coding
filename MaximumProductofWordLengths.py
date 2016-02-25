"""
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0. 

Example 1:


Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
 Return 16
 The two words can be "abcw", "xtfn". 
"""
def maxProduct(words):
        """
        :type words: List[str]
        :rtype: int
        """
        n = len(words)
        elements = [0] * n
        for i, s in enumerate(words):
            for c in s:
                elements[i] |= 1 << (ord(c) - 97)

        ans = 0
        for i in xrange(n):
            for j in xrange(i + 1, n):
                if not (elements[i] & elements[j]):
                    ans = max(ans, len(words[i]) * len(words[j]))
        return ans
print maxProduct(["hello","abcd","abcde"])
