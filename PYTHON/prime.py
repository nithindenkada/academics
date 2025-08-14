def Prime(st, end):
'''  we can use this also    int(i ** 0.5)+1)   '''
    a = []
    for i in range(st, end):
        count = 0
        for j in range(2, i): 
            if i % j == 0:
                count += 1
        if count == 0:
            a.append(i)
    return a
    
start = int(input("Enter starting point"))
end = int(input("Enter ending point"))
primes = Prime(start, end)
for i in primes:
    print(i)
