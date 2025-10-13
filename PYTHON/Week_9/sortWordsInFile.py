
file = open("Files.txt", "r")
theory = file.read()
words = theory.split("\n")
print(words)

modifiedList = []
for ele in words:
    modifiedList.append(ele.lower())

modifiedList.sort(key = len)
with open("newFile", "a") as file :
    for ele in modifiedList:
        file.write(ele + "\n")

file.close()