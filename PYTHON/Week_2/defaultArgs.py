def Greet(college, branch = "CSE"):
    print("This student studying in ", college, " in branch ", branch)

a = input("Enter your college name: ")
b = input("Enter branch: ")
Greet(a, b)
Greet(a)