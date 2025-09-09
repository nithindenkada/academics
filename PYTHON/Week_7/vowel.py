vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
print(vowel)
str1 = input("Enter the strings to check the no.of vowels:")

count = sum(map( lambda ch: ch in vowel, str1))
print((count))