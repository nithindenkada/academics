A = int(input("Enter first number:"))
B = int(input("Enter second number:"))
C = int(input("Enter third number:"))

if A > B and A > C :
    print("{} is the largest number!".format(A))
elif B > A and B > C:
    print("{} is largest number!".format(B))
else:
    print("{} is the largest number!".format(C))