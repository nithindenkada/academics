
with open ("frequent.txt" , "r") as file:
    content = file.read()
    content = content.replace(",", "").replace(".", "")
    words = content.split(" ")
    for i in range(len(words)):
        words[i] = words[i].lower()

freDIct = {}
for ele in words:
    if ele in freDIct.keys():
        freDIct[ele] += 1
    else:
        freDIct[ele] = 1

maxKey = max(freDIct, key = freDIct.get)
maxValue = freDIct[maxKey]
print("{} => {}".format(maxKey, maxValue))