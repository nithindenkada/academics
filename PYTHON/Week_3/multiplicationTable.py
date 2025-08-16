def mulTable(num, len):
    for i in range(1, len+1):
        print(num, " * ", i, " = ", num*i)
    
num = int(input("Enter the multipilcation number: "))
length = int(input("Enter the number you want to multiply upto that: "))
mulTable(num, length)