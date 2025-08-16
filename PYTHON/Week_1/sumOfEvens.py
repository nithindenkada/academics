'''Sum of all even numbers in the range of 1 - N'''

count = 0
Start = int(input("Enter the starting point: "))
End = int(input("Enter ending point: "))
for i in range(Start, End+1):
    if i % 2 == 0:
        print(i, end = ' ')
        count += i

print("\n\nThe sum of Evens between {} to {} is {}".format(Start, End, count))