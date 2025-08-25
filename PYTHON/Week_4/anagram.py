'''4.(B)Write a program to check if two strings are anagrams or not.'''

str1 = input("Enter the first string: ")
str2 = input("Enter the second string: ")

if(sorted(str1) == sorted(str2)):
    print("These are anagrams!")
else:
    print("These are not anagrams!")