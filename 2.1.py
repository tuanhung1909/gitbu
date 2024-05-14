list_mau = list()
list_mahoa = list()
list_final = list()

# Hàm đổi vị trí
def swap(m, n):
    return n, m


# Hàm sắp xếp
def quicksort(L, R):
    global list_mahoa

    if L >= R:
        return

    i = L
    j = R

    x = list_mahoa[(L + R)//2]

    while True:
        while list_mahoa[i] < x:
            i = i+1
        while list_mahoa[j] > x:
            j = j - 1

        if i <= j:
            list_mahoa[i], list_mahoa[j] = swap(list_mahoa[i], list_mahoa[j])
            i = i + 1
            j = j - 1
        else:
            break

    quicksort(L, j)
    quicksort(i, R)
def menu():
    print(
    """
    1. Thêm màu vào list
    2. Hiểm thị danh sách chưa sắp xếp
    3. Hiển thị danh sách đã sắp xếp
    4. Kết thúc chương trình
    """
    )
while True:
    menu()
    lua_chon = int(input("Nhập lựa chọn của bạn: "))
    if lua_chon == 1:
        mau = input("Nhập màu: Xanh| Đỏ | Trắng ")
        if mau == "Đỏ" or mau == "Xanh" or mau == "Trắng":
            list_mau.append(mau)
        else: continue
    elif lua_chon == 2:
        for mau in list_mau:
            print(mau, end="\t")
    elif lua_chon == 3:
        for mau in list_mau:
            if mau == 'Đỏ':
                d = 1
                list_mahoa.append(d)
            if mau == 'Xanh':
                x = 3
                list_mahoa.append(x)
            if mau == 'Trắng':
                t = 2
                list_mahoa.append(t)
        quicksort(0,len(list_mahoa)-1)
        for i in list_mahoa:
            if i == 1:
                list_final.append('Đỏ')
            elif i == 2:
                list_final.append('Trắng')
            elif i == 3:
                list_final.append('Xanh')
        print(list_final) 

        break
    elif lua_chon == 4:
        print("Kết thúc chương trình!")
        break
    else:
        print("Không hợp lệ!")
        break
"""
This is some sort of a major update that need to be sync up with the remote
"""
