#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Subject {
private:
    string subject_id;
    string subject_name;
    int subject_credits;
    double subject_score;
public:
    Subject() {}
    friend istream& operator >> (istream &is, Subject &subject) {
        //cout << "Subject ID: ";
        is >> subject.subject_id;
        //cout << "Subject Name: ";
        is.ignore();
        getline(is, subject.subject_name);
        //cout << "Subject Credits: ";
        is >> subject.subject_credits;
        //cout << "Subject Score: ";
        is >> subject.subject_score;
        return is;
    }
    string getSubjectID () {
        return subject_id;
    }
    string getSubjectName () {
        return subject_name;
    }
    int getSubjectCredits () {
        return subject_credits;
    }
    double getSubjectScore () {
        return subject_score;
    }
};

class Student {
private:
    string student_id;
    string student_name;
    string student_date_of_birth;
    vector<Subject> student_subjects;
public:
    string getStudentID () {
        return student_id;
    }
    string getStudentName () {
        return student_name;
    }
    string getStudentDateOfBirth () {
        return student_date_of_birth;
    }
    vector<Subject> getStudentSubject () {
        return student_subjects;
    }
    friend istream& operator >> (istream &is, Student &student) {
        //cout << "ID of student: ";
        is >> student.student_id;
        //cout << "Name of student: ";
        is.ignore();
        getline(is, student.student_name);
        //cout << "Student's date of birth: ";
        is >> student.student_date_of_birth;
        //cout << "Student's number of subjects: ";
        int size; is >> size;
        student.student_subjects.resize(size);
        for (int i = 0; i < size; ++i) {
            //cout << "Subject" << i + 1 << "\n";
            is >> student.student_subjects[i];
        }
        return is;
    }

    friend ostream& operator << (ostream &os, Student student) {
        os << "ID: " << student.student_id << " | Name: " << student.student_name << " | Date Of Birth: " << student.student_date_of_birth << " | Avg: " << student.avg();
        return os << '\n';
    }

    Student operator = (Student another) {
        this->student_id = another.student_id;
        this->student_name = another.student_name;
        this->student_date_of_birth = another.student_date_of_birth;
        this->student_subjects = another.student_subjects;
        return *this;
    }

    void setStudentName (string name) {
        this->student_name = name;
    }

    double avg () {
        double sum = 0;
        for (Subject subject : student_subjects) {
            sum += subject.getSubjectScore();
        }
        return (double)1.0*sum/(int)(student_subjects.size());
    }

    int getYearOfBirth () {
        size_t pos = student_date_of_birth.find('/');
        string temp = student_date_of_birth.substr(pos + 1);
        return stoi(temp.substr(temp.find('/') + 1));
    }
};

class Solution {
private:
    int n;
    vector<Student> students;
public:
    Solution() {}
    int getSize() {
        return this->n;
    }
    //a
    void init () {
        cin >> n;
        cin.ignore();
        students.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> students[i];
        }
    }
    //b
    void search (string x, string y) {
        for (Student &student : students) {
            if (student.getStudentID() == x) {
                student.setStudentName(y);
            }
        }
    }
    //c
    void insertionSort () {
        for (int i = 1; i < n; ++i) {
            int pos = i;
            Student val = students[i];
            while (pos > 0 && students[pos-1].getStudentName() < val.getStudentName()) {
                students[pos] = students[pos-1];
                pos--;
            }
            students[pos] = val;
        }
    }
    void printListStudent () {
        //cout << "---List Student---\n";
        for (const Student& student : students) {
            cout << student;
        }
    }
    //d
    int binarySearch (string x) {
        int left = 0, right = n - 1;
        while (left <= right) {
            int middle = (left + right)/2;
            if (students[middle].getStudentName() == x) {
                return middle;
            }
            else if (students[middle].getStudentName() > x) {
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }
        return -1;
    }
    void remove (int pos) {
        if (pos != -1)
            students.erase(begin(students) + pos), this->n--;
    }
    //e
    void SelectionSort () {
        int minVal;
        for (int i = 0; i < n; ++i) {
            minVal = i;
            for (int j = i + 1; j < n; ++j) {
                if (students[j].avg() < students[minVal].avg()) {
                    minVal = j;
                }
            }
            if (minVal != i) {
                swap(students[i], students[minVal]);
            }
        }
    }
    //f
    bool isValid (Student student) {
        for (Subject subject : student.getStudentSubject()) {
            if (subject.getSubjectScore() < 5) return false;
        }
        return student.avg() >= 7;
    }
    void printListOfStudentsReceivingScholarships () {
        cout << "List Of Students Receiving Scholarships\n";
        int count = 1;
        for (int i = 0; i < n; ++i) {
            if (isValid(students[i])) {
                cout << count++ << ". " << students[i].getStudentName() << " (" << students[i].avg() << ")\n";
            }
        }
    }
    //g
    int Partition (int left, int right) {
        int i = left - 1, j = right + 1;
        int pivot = students[left].getYearOfBirth();
        while (true) {
            do { --j; } while (students[j].getYearOfBirth() > pivot);
            do { ++i; } while (students[i].getYearOfBirth() < pivot);
            if (i >= j) {
                return j;
            }
            swap(students[i], students[j]);
        }
    }
    void quickSort (int left, int right) {
        if (left >= right) return;
        int mid = Partition(left, right);
        quickSort(left, mid);
        quickSort(mid + 1, right);
    }
};

int main () {
    Solution Lab2_4;
    //a
    Lab2_4.init();
    cout << "Before\n";
    Lab2_4.printListStudent();
    //b
    string x, y;
    cin >> x;
    cin.ignore();
    getline(cin, y);
    Lab2_4.search(x, y);
    //c
    Lab2_4.insertionSort();
    cout << "After insertion sort\n";
    Lab2_4.printListStudent();
    //d
    string X;
    getline(cin, X);
    cout << "After remove " << X << '\n';
    Lab2_4.remove(Lab2_4.binarySearch(X));
    //e
    Lab2_4.SelectionSort();
    cout << "Selection sort with avg\n";
    //f
    Lab2_4.printListOfStudentsReceivingScholarships();
    //g
    Lab2_4.quickSort(0, Lab2_4.getSize() - 1);
    cout << "After quick sort\n";
    Lab2_4.printListStudent();
    return 0;
}

/*Input
5
49.01.104.081
Nguyen Thi A Nha
07/12/1999
3
Toan
Co so toan trong CNTT
4
8.0
Hoa
Hoa dai cuong
3
9.75
Ly
Vat Ly luong tu
3
9.25
47.01.101.111
Pham Gia Bao
15/07/1995
2
GDQP
Duong loi quoc phong an ninh
2
8.5
GDTC
Cau long nang cao
1
10
46.01.103.044
Nhu Thich Thu
15/11/2001
4
GDCT
Triet hoc Mac - Lenin
3
8.0
GDCT
Kinh te chinh tri
3
7.7
GDCT
Chu nghia xa hoi khoa hoc
3
7.5
GDCT
Tu Tuong Ho Chi Minh
3
9.0
45.01.901.113
Vu Thi Cam Tu
11/11/1998
3
AV
Ngoai ngu 1
3
7.8
AV
Ngoai ngu 2
3
8.3
Toan
Toan roi rac
3
9.8
50.01.103.113
Em Nhi Cua Bao
11/12/2006
2
CNTT
Lap trinh co ban
3
7.5
CNTT
Danh sach lien ket quanvh
3
9.5
47.01.101.111
Tran Gia Huy
Nguyen Thi A Nha
*/