from collections import namedtuple

cap = namedtuple("cap",['x','y'])
def phanTichSoNguyen(n):
    i = 2
    listngto = list()
    # phân tích
    while (n > 1):
        if n % i == 0:
            n = n // i
            listngto.append(i)
        else:
            i = i + 1
    # nếu n là số nguyên tố
    if (len(listngto) == 0):
        listngto.append(n)
    return listngto
def ktmang_Blum(n):
    listngto = phanTichSoNguyen(n)
    if len(listngto)==2:
        for i in range(0,len(listngto)):
            if listngto.count(listngto[i])==1:
                return False
    else:
        return True

n = int(input("Nhập số nguyên dương n = "));
# phân tích số nguyên dương n
mang_Blum=[]
k=0
cap_so=[]
for i in range(0,n):
    if ktmang_Blum(i)==False:
        mang_Blum.append(i)
print(mang_Blum)
#Tìm bộ đôi có tổng nhỏ hơn n
for i in range(0,len(mang_Blum)):
    for j in range(1, len(mang_Blum)):
        if i+j < len(mang_Blum):
            k=mang_Blum[i]+mang_Blum[i+j]
        if i+j >n:
            k=0
        if k<n:
            cap=[mang_Blum[i],mang_Blum[i+j]]
            cap_so.append(cap)
print(cap_so)

M = int(input("Nhập số cần kiểm tra: "))
d=0
for i in range(0,len(mang_Blum)):
    if mang_Blum[i] == M:
        print(M," tồn tại trong mảng Blum")
        d+=1
if d==0:
    print(M, " không tồn tại trong mảng Blum")
