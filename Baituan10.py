class NodeDT:
    def __init__(self, heso, somu):
        self.heso = heso
        self.somu = somu
        self.next = None
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def add_node(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node

    def display(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")

# Tạo danh sách liên kết
my_list = LinkedList()

# Thêm các nút vào danh sách
my_list.add_node(poly1)
my_list.add_node(poly2)

# Hiển thị danh sách liên kết
print("Danh sách liên kết:")
my_list.display()

class Polynomial:
    def __init__(self):
        self.head = None

    def add_term(self, heso, somu):
        new_term = NodeDT(heso, somu)
        if not self.head:
            self.head = new_term
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_term

    def display(self):
        current = self.head
        while current:
            print(f"{current.heso}x^{current.somu}", end=" ")
            current = current.next
        print()

    def add(self, other):
        result = Polynomial()
        current1, current2 = self.head, other.head
        while current1 and current2:
            if current1.somu == current2.somu:
                result.add_term(current1.heso + current2.somu, current1.somu)
                current1, current2 = current1.next, current2.next
            elif current1.somu > current2.somu:
                result.add_term(current1.heso, current1.somu)
                current1 = current1.next
            else:
                result.add_term(current2.heso, current2.somu)
                current2 = current2.next

        while current1:
            result.add_term(current1.heso, current1.somu)
            current1 = current1.next

        while current2:
            result.add_term(current2.heso, current2.somu)
            current2 = current2.next

        return result

def create_polynomial():
    # Tạo đa thức từ người dùng
    poly = Polynomial()
    while True:
        try:
            heso = float(input("Nhập hệ số: "))
            somu = int(input("Nhập số mũ: "))
            poly.add_term(heso, somu)
            choice = input("Thêm hạng tử khác? (y/n): ")
            if choice.lower() != 'y':
                break
        except ValueError:
            print("Vui lòng nhập số hợp lệ.")

    return poly

if __name__ == "__main__":
    print("Nhập đa thức 1:")
    poly1 = create_polynomial()
    print("\nNhập đa thức 2:")
    poly2 = create_polynomial()

    print("\nĐa thức 1:")
    poly1.display()
    print("Đa thức 2:")
    poly2.display()

    sum_poly = poly1.add(poly2)
    print("\nTổng của hai đa thức:")
    sum_poly.display()
