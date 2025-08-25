'''4.(A) Write a program to find the length of the string without using any library
functions.'''

string = input("Enter a string to find the length: ")
length = 0

for i in string:
    length += 1

print("Length of the given string is: {} characters".format(length))