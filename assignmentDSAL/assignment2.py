'''Write a Python program to compute following operations on 
String:  
a) To display word with the longest length  
b) To determines the frequency of occurrence of particular 
character in the string  
c) To check whether given string is palindrome or not  
d) To display index of first appearance of the substring  
e) To count the occurrences of each word in a given string  
(Do not use string built-in functions) '''


class StringOperations:

    def longest_word(self, string):
        words = self.split_into_words(string)
        max_length = 0
        longest = ""
        for word in words:
            length = 0
            for _ in word:
                length += 1
            if length > max_length:
                max_length = length
                longest = word
        return longest

    def char_frequency(self, string, char):
        count = 0
        for c in string:
            if c == char:
                count += 1
        return count

    def is_palindrome(self, string):
        length = 0
        for _ in string:
            length += 1
        for i in range(length // 2):
            if string[i] != string[length - i - 1]:
                return False
        return True

    def first_substring_index(self, string, substring):
        for i in range(self.string_length(string) - self.string_length(substring) + 1):
            match = True
            for j in range(self.string_length(substring)):
                if string[i + j] != substring[j]:
                    match = False
                    break
            if match:
                return i
        return -1

    def word_count(self, string):
        words = self.split_into_words(string)
        word_frequency = {}
        for word in words:
            count = 0
            for w in words:
                if word == w:
                    count += 1
            exists = False
            for key in word_frequency:
                if word == key:
                    exists = True
                    break
            if not exists:
                word_frequency[word] = count
        return word_frequency

    def string_length(self, string):
        count = 0
        for _ in string:
            count += 1
        return count

    def split_into_words(self, string):
        words = []
        word = ""
        for char in string:
            if char == " ":
                if word:
                    words += [word]  # Using concatenation instead of append
                    word = ""
            else:
                word += char
        if word:
            words += [word]  # Using concatenation instead of append
        return words

if __name__ == "__main__":
    so = StringOperations()

    while True:
        print("\nString Operations Menu:")
        print("1. Display the word with the longest length")
        print("2. Determine the frequency of occurrence of a particular character")
        print("3. Check whether the given string is a palindrome")
        print("4. Display the index of the first appearance of a substring")
        print("5. Count the occurrences of each word in the string")
        print("6. Exit")

        choice = input("Enter your choice: ")

        if choice == '1':
            string = input("Enter a string: ")
            print("The word with the longest length is:", so.longest_word(string))

        elif choice == '2':
            string = input("Enter a string: ")
            char = input("Enter a character to find its frequency: ")
            print(f"The frequency of '{char}' is:", so.char_frequency(string, char))

        elif choice == '3':
            string = input("Enter a string: ")
            print("The string is a palindrome:", so.is_palindrome(string))

        elif choice == '4':
            string = input("Enter a string: ")
            substring = input("Enter a substring to find its first index: ")
            index = so.first_substring_index(string, substring)
            if index != -1:
                print(f"The first appearance of the substring is at index {index}")
            else:
                print("Substring not found")

        elif choice == '5':
            string = input("Enter a string: ")
            print("The occurrences of each word are:", so.word_count(string))

        elif choice == '6':
            print("Exiting...")
            break

        else:
            print("Invalid choice! Please try again.")

