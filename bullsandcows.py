""" 
You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

For example:

Secret number:  "1807"
Friend's guess: "7810"
Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B".

Please note that both secret number and friend's guess may contain duplicate digits, for example:

Secret number:  "1123"
Friend's guess: "0111"
In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
"""
def getHint(secret, guess):
    """
    :type secret: str
    :type guess: str
    :rtype: str
    """
    bc = 0
    cc = 0
    secret = list(secret)
    guess = list(guess)
    n = len(secret)
    s = [] + secret
    for i in range(0,n):
        if guess[i] == secret[i]:
            bc = bc + 1
            s.remove(guess[i])
        else:
           # print s
            for j in s:
                #if guess[i] == s[j]:
                    #cc = cc + 1
                    #secret.pop(j)
                if guess[i] == j:
                    cc = cc + 1
    return str(bc) +"a" + str(cc) + "b"

print getHint("0102","0120")
#For this above answer I got output limit exceeded. This is true for a very big input string as I am converting them to 
#list and then performing the comparisons. Here's the second method below:
def getHint(secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        #if not secret or not guess: return '0A0B'
        bulls, cows, digits = 0, 0, [0 ] * 10
        for i in xrange(len(secret)):
            if secret[i] == guess[i]:
                bulls += 1
            else:
                digits[int(secret[i])] += 1

        for i in xrange(len(secret)):
            if secret[i] != guess[i] and digits[int(guess[i])] != 0:
                cows += 1
                digits[int(guess[i])] -= 1
        return str(bulls) + 'A' + str(cows) + 'B'

print getHint()
