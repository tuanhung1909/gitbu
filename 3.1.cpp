#include <iostream>
#include<string.h>
using namespace std;

struct SinhVien { 
    char maSV[8]; 
    char hoTen[50]; 
    int gioiTinh;
    Ngay ngaySinh;
    char diaChi[100]; 
    char lop[12];
    char khoa[7]; 
    };
struct Ngay { 
    int ngay, thang, nam; 
    }; 
struct Node { 
    SinhVien data; 
    Node *link; 
    }; 
struct List { 
    Node *first; 
    Node *last; 
    };
Node *createNode(SinhVien student) {
    Node *newNode = new Node;
    newNode->data = student;
    newNode->link = NULL;
    return newNode;
}
void insertStudent(List *list, SinhVien student) {
    Node *newNode = createNode(student);

    Node *current = list->first;
    Node *prev = NULL;
    while (current && strcmp(current->data.maSV, student.maSV) < 0) {
        prev = current;
        current = current->link;
    }

    if (prev) {
        prev->link = newNode;
    } else {
        list->first = newNode;
    }

    newNode->link = current;

    if (!current) {
        list->last = newNode;
    }
}
void printList(List *list) {
    if (list->first == NULL) {
        cout << "Danh sach sinh vien trong!" << endl;
        return;
    }

    Node *current = list->first;
    while (current) {
        cout << "MSSV: " << current->data.maSV << endl;
        cout << "Ho ten: " << current->data.hoTen << endl;
        cout << "Gioi tinh: " << (current->data.gioiTinh ? "Male" : "Female") << endl;
        cout << "Ngay sinh: " << current->data.ngaySinh.ngay << "/" << current->data.ngaySinh.thang << "/" << current->data.ngaySinh.nam << endl;
        cout << "Dia chi: " << current->data.diaChi << endl;
        cout << "Lop: " << current->data.lop << endl;
        cout << "Khoa: " << current->data.khoa << endl;
        cout << "--------------------------------------" << endl;
        current = current->link;
    }
}
void findStudentsSameDOB(List *list) {
    if (list->first == NULL) {
        cout << "Danh sach sinh vien trong!" << endl;
        return;
    }

    Node *current = list->first;
    while (current) {
        string DOB = to_string(current->data.ngaySinh.ngay) + "/" + to_string(current->data.ngaySinh.thang) + "/" + to_string(current->data.ngaySinh.nam);
        Node *sameDOBNodes = NULL;
        Node *temp = current->link;
        while (temp) {
            string tempDOB = to_string(temp->data.ngaySinh.ngay) + "/" + to_string(temp->data.ngaySinh.thang) + "/" + to_string(temp->data.ngaySinh.nam);
            if (tempDOB == DOB) {
                temp->link = sameDOBNodes;
                sameDOBNodes = temp;
                temp = temp->link;
            } else {
                temp = temp->link;
            }
        }

        if (sameDOBNodes) {
            cout << "Sinh vien co cung ngay sinh " << DOB << ":" << endl;
            Node *printNode = sameDOBNodes;
            while (printNode) {
                cout << "MSSV: " << printNode->data.maSV << endl;
                cout << "Ho ten: " << printNode->data.hoTen << endl;
                cout << "Gioi tinh: " << (printNode->data.gioiTinh ? "Male" : "Female") << endl;
                cout << "Ngay sinh: " << printNode->data.ngaySinh.ngay << "/" << printNode->data.ngaySinh.thang << "/" << printNode->data.ngaySinh.nam << endl;
                cout << "Dia chi: " << printNode->data.diaChi << endl;
                cout << "Lop: " << printNode->data.lop << endl;
                cout << "Khoa: " << printNode->data.khoa << endl;
                cout << "--------------------------------------" << endl;
                printNode = printNode->link;
            }
        }

        current = current->link;
    }
}
void removeStudentsSameDOB(List *list) {
    if (list->first == NULL) {
        cout << "Danh sach sinh vien trong!" << endl;
        return;
    }

    Node *current = list->first;
    Node *prev = NULL;
    while (current) {
        string DOB = to_string(current->data.ngaySinh.ngay) + "/" + to_string(current->data.ngaySinh.thang) + "/" + to_string(current->data.ngaySinh.nam);

        Node *sameDOBNodes = NULL;
        Node *temp = current->link;
        while (temp) {
            string tempDOB = to_string(temp->data.ngaySinh.ngay) + "/" + to_string(temp->data.ngaySinh.thang) + "/" + to_string(temp->data.ngaySinh.nam);
            if (tempDOB == DOB) {
                temp->link = sameDOBNodes;
                sameDOBNodes = temp;
                temp = temp->link;
            } else {
                temp = temp->link;
            }
        }

        if (sameDOBNodes) {
            if (prev) {
                prev->link = sameDOBNodes;
            } else {
                list->first = sameDOBNodes;
            }

            current = sameDOBNodes->link;

            Node *toDelete = sameDOBNodes;
            while (toDelete) {
                sameDOBNodes = toDelete->link;
                delete toDelete;
                toDelete = sameDOBNodes;
            }
        } else {
            prev = current;
            current = current->link;
        }
    }
}
int main() {
    List listSV;
    listSV.first = NULL;
    listSV.last = NULL;

    int choice;
    do {
        cout << "\nMENU QUAN LY SINH VIEN" << endl;
        cout << "1. Nhap sinh vien moi" << endl;
        cout << "2. In danh sach sinh vien" << endl;
        cout << "3. Tim sinh vien theo ngay sinh" << endl;
        cout << "4. Xoa sinh vien cung ngay sinh" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1:
                SinhVien newStudent;
                cout << "\nNhap thong tin sinh vien moi:" << endl;
                cout << "MSSV: ";
                cin >> newStudent.maSV;
                cout << "Ho ten: ";
                cin.ignore(); 
                getline(cin, newStudent.hoTen);
                cout << "Gioi tinh (Male = 1, Female = 0): ";
                cin >> newStudent.gioiTinh;
                cout << "Ngay sinh (d/m/y): ";
                cin >> newStudent.ngaySinh.ngay >> newStudent.ngaySinh.thang >> newStudent.ngaySinh.nam;
                cout << "Dia chi: ";
                cin.ignore(); 
                getline(cin, newStudent.diaChi);
                cout << "Lop: ";
                getline(cin, newStudent.lop);
                cout << "Khoa: ";
                getline(cin, newStudent.khoa);

                insertStudent(&listSV, newStudent);
                break;

            case 2:
                cout << "\nDanh sach sinh vien:" << endl;
                printList(&listSV);
                break;

            case 3:
                cout << "\nNhap ngay sinh (d/m/y): ";
                int day, month, year;
                cin >> day >> month >> year;

                cout << "\nSinh vien co cung ngay sinh " << day << "/" << month << "/" << year << ":" << endl;
                findStudentsSameDOB(&listSV, day , month, year);
                break;

            case 4:
                removeStudentsSameDOB(&listSV);
                cout << "\nSinh vien cung ngay sinh da duoc loai bo khoi danh sach!" << endl;
                break;

            case 0:
                cout << "\nThoat chuong trinh!" << endl;
                break;

            default:
                break;
        }
    } while (choice != 0);

    Node *current = listSV.first;
    while (current) {
        Node *next = current->link;
        delete current;
        current = next;
    }

    return 0;
}
