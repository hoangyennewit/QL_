#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Student {
private:
    string student_id, student_name, student_class, student_date_of_birth;
    double student_avg;
public:
    void setID(string student_id) {
        this->student_id = student_id;
    }
    void setName(string student_name) {
        this->student_name = student_name;
    }
    void setClass(string student_class) {
        this->student_class = student_class;
    }
    void setDateOfBirth(string student_date_of_birth) {
        this->student_date_of_birth = student_date_of_birth;
    }
    void setAvg(double student_avg) {
        this->student_avg = student_avg;
    }
    string getID() const {
        return student_id;
    }
    string getName() const {
        return student_name;
    }
    string getClass() const {
        return student_class;
    }
    string getDateOfBirth() const {
        return student_date_of_birth;
    }
    double getAvg() const {
        return student_avg;
    }
    friend istream& operator >> (istream& is, Student& student) {
        is >> student.student_id;
        is.ignore();
        getline(is, student.student_name);
        is >> student.student_class;
        is >> student.student_date_of_birth;
        is >> student.student_avg;
        return is;
    }
    friend ostream& operator << (ostream& os, const Student& student) {
        os << "Ho va ten: " << student.getName() << '\n';
        os << "MSSV: " << student.getID() << '\n';
        os << "Lop: " << student.getClass() << '\n';
        os << "Ngay sinh: " << student.getDateOfBirth() << '\n';
        os << "Diem trung binh: " << student.getAvg();
        return os;
    }
    Student operator = (const Student& another) {
        this->setID(another.getID());
        this->setName(another.getName());
        this->setClass(another.getClass());
        this->setDateOfBirth(another.getDateOfBirth());
        this->setAvg(another.getAvg());
        return *this;
    }
    bool operator == (const Student& another) const {
        return getID() == another.getID() &&
            getName() == another.getName() &&
            getClass() == another.getClass() &&
            getDateOfBirth() == another.getDateOfBirth() &&
            getAvg() == another.getAvg();
    }
};

class Node {
private:
    Student data;
    Node* next;
    friend class LinkedList;
public:
    Node(const Student& data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* root;
public:
    LinkedList() : root(nullptr) {}
    /*
    Thêm 1 sinh viên vào cuối
    */
    void push_back(const Student& student) {
        if (!root) {
            root = new Node(student);
        }
        else {
            Node* current = root;
            while (current->next) {
                current = current->next;
            }
            current->next = new Node(student);
        }
    }
    /*
    Xóa sinh viên đầu tiên
    */
    void pop_front() {
        if (!root) return;
        Node* temp = root;
        root = root->next;
        delete temp;
    }
    /*
    In danh sách sinh viên có điểm trung bình lớn hơn hoặc bằng số điểm cho trước
    */
    void disPlay(double score) {
        for (Node* current = root; current != nullptr; current = current->next) {
            if (current->data.getAvg() >= score) {
                cout << current->data << '\n';
            }
        }
    }
    /*
    Tìm kiếm tuần tự thông tin của một sinh viên theo mã số sinh viên
    */
    Student* Search(const string& student_id) {
        for (Node* current = root; current != nullptr; current = current->next) {
            if (current->data.getID() == student_id) {
                return &current->data;
            }
        }
        return nullptr;
    }
    /*
    Sắp xếp danh sách sinh viên tăng dần theo mã số sinh viên
    */
    void selectionSort() {
        Node* ptr = nullptr;
        for (Node* current = root; current->next != nullptr; current = current->next) {
            ptr = current;
            for (Node* next = current->next; next != nullptr; next = next->next) {
                if (ptr->data.getID() > next->data.getID()) {
                    ptr = next;
                }
            }
            if (ptr != current)
                swap(current->data, ptr->data);
        }
    }
    /*
    Tìm kiếm nhị phân thông tin của một sinh viên theo mã số sinh viên
    */
    Student* binarySearch(const string& student_id) {
        vector<Student*> students;
        for (Node* current = root; current != nullptr; current = current->next) {
            students.push_back(&(current->data));
        }
        if (students.empty()) return nullptr;
        int left = 0, right = students.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (students[mid]->getID() == student_id)
                return students[mid];
            if (students[mid]->getID() > student_id)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return nullptr;
    }
    /*
    Xóa sinh viên có mã số sinh viên là mã số sinh viên cho trước
    */
    void remove(const string& student_id) {
        if (!root) {
            cout << "Khong xoa duoc\n";
            return;
        }
        Student* reject = this->binarySearch(student_id);
        if (!reject) {
            cout << "Khong xoa duoc\n";
            return;
        }
        if (root->data == *reject) {
            this->pop_front();
            cout << "Da xoa\n";
            return;
        }
        Node* current = root;
        while (current->next != nullptr) {
            if (current->next->data == *reject) {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
                cout << "Da xoa\n";
                return;
            }
            current = current->next;
        }
    }
    /*
    Cập nhật điểm trung bình của sinh viên có mã số sinh viên cho trước
    */
    void update(const string& student_id, const double& score) {
        Student* student = binarySearch(student_id);
        if (!student) {
            cout << "Khong the cap nhat";
            return;
        }
        student->setAvg(score);
        cout << "Cap nhat thanh cong!";
    }
    /*
    Giải phóng dữ liệu
    */
    void clear() {
        while (root) {
            Node* temp = root;
            root = root->next;
            delete temp;
        }
    }
    ~LinkedList() {
        this->clear();
    }
};

int main() {
    LinkedList List;
    //a
    int n; cin >> n;
    cin.ignore();
    for (int i = 1; i <= n; ++i) {
        Student temp;
        cin >> temp;
        List.push_back(temp);
    }
    //b
    cout << "Danh sach sinh vien\n";
    List.disPlay(0.0);
    //c
    cout << "Danh sach sinh vien co diem trung binh khong nho hon 5:\n";
    List.disPlay(5.0);
    //d
    string id1;
    cin >> id1;
    cout << "Thong tin cua sinh vien co ma so " << id1 << '\n';
    Student* student_id1 = List.Search(id1);
    if (student_id1)
        cout << *student_id1 << '\n';
    else
        cout << "Khong tim thay!\n";
    //e
    List.selectionSort();
    cout << "Danh sach sinh vien sau khi sap xep tang dan theo ma sinh vien\n";
    List.disPlay(0.0);
    //f
    string id2;
    cin >> id2;
    cout << "Thong tin cua sinh vien co ma so " << id2 << '\n';
    Student* student_id2 = List.binarySearch(id2);
    if (student_id2)
        cout << *student_id2 << '\n';
    else
        cout << "Khong tim thay!\n";
    //g
    string id3;
    cin >> id3;
    cout << "Xoa sinh vien co ma so " << id3 << " dang co trang thai: ";
    List.remove(id3);
    //h
    string id4;
    double score;
    cin >> id4;
    cin >> score;
    cout << "Cap nhat diem cua sinh vien co ma so " << id4 << " dang co trang thai: ";
    List.update(id4, score);
    cout << '\n';
    cout << "Danh sach sinh vien sau chuong trinh\n";
    List.disPlay(0.0);
    return 0;
}