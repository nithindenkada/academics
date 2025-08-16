def Rec(len, bre):
    # area = 0 
    # peri = 0
    area = len* bre
    peri = 2 *(len + bre)
    return area, peri

Area, Perimeter = Rec(2, 4)
print("Area : ", Area, "perimeter: ", Perimeter)