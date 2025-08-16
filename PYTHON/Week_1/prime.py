def Prime(st, end):
    a = []
    for i in range(st, end+1):
        count = 0
        for j in range(2, i+1): 
            if i % j == 0:
                count += 1
        if count < 2:
            a.append(i)
    return a
    
start = int(input("Enter starting point"))
end = int(input("Enter ending point"))
primes = Prime(start, end)
for i in primes:
    print(i)
