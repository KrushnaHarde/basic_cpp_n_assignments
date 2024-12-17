'''Write a Python program to compute following operations on
String:
a) To display word with the longest length
b) To determines the frequency of occurrence of particular
character in the string
c) To check whether given string is palindrome or not
d) To display index of first appearance of the substring
e) To count the occurrences of each word in a given string
(Do not use string built-in functions) '''

class String:
    def __init__(self):
        self.str = input("Enter your string: ")

    def longestWord(self):
        maxlen = 0
        wordlen = 0
        for _ in self.str:
            if _ == " ":
                maxlen = max(maxlen, wordlen)
            else:
                wordlen += 1
        return maxlen

    def freq(self):
        c = input("Enter the char who's freq you wanna know: ")
        cnt = 0
        for _ in self.str:
            if _ == c:
                cnt += 1
        return cnt

    def isPalindrome(self):
        s = self.str
        i = 0
        j = len(s)-1
        while i<j:
            if(s[i] != s[j]):
                return False
            else:
                i += 1
                j -= 1
        return True

    def firstAppearance(self):
        s = input("Enter substring to check its appearance: ")
        j = 0
        for i in range(len(self.str)):
            if s[j] == self.str[i]:
                j += 1
                if j == len(s):
                    return i - len(s) + 1
            else:
                j = 0
        return -1

    def wordOccurence(self):
        arr = []
        word = ""

        for _ in self.str:
            if _ == " ":
                if word:
                    arr += [word]
                    word = ""
            else:
                word += _
        if word:
            arr += [word]

        for word in arr:
            cnt = 0
            for w in arr:
                if w == word:
                    cnt += 1
            print(word, " : ", cnt)


if __name__ == "__main__":
    obj = String()
    print(obj.freq())
    print(obj.isPalindrome())
    print(obj.firstAppearance())
    obj.longestWord()
    obj.wordOccurence()


