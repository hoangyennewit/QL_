#include<bits/stdc++.h>
using namespace std;

class VIDEO {
private:
    string video_name;
    string video_type;
    string director_name;
    string actor_name;
    string actress_name;
    int year_of_manufacture;
public:
    void setVidName (string video_name) {
        this->video_name = video_name;
    }
    void setVidType (string video_type) {
        this->video_type = video_type;
    }
    void setDirectorName (string director_name) {
        this->director_name = director_name;
    }
    void setActorName (string actor_name) {
        this->actor_name = actor_name;
    }
    void setActressName (string actress_name) {
        this->actress_name = actress_name;
    }
    void setYearOfManufacture (int year_of_manufacture) {
        this->year_of_manufacture = year_of_manufacture;
    }
    string getVidName () const {
        return video_name;
    }
    string getVidType () const {
        return video_type;
    }
    string getDirectorName () const {
        return director_name;
    }
    string getActorName () const {
        return actor_name;
    }
    string getActressName () const {
        return actress_name;
    }
    int getYearOfManufacture () const {
        return year_of_manufacture;
    }
    friend istream& operator >> (istream& is, VIDEO& video) {
        is.ignore();
        string str;
        getline(is, str);
        video.setVidName(str.substr(0, str.find('#')));
        str = str.substr(str.find('#') + 1);
        video.setVidType(str.substr(0, str.find('#')));
        str = str.substr(str.find('#') + 1);
        video.setDirectorName(str.substr(0, str.find('#'))); 
        str = str.substr(str.find('#') + 1);
        video.setActorName(str.substr(0, str.find('#')));
        str = str.substr(str.find('#') + 1);
        video.setActressName(str.substr(0, str.find('#')));
        str = str.substr(str.find('#') + 1);
        video.setYearOfManufacture(stoi(str));
        return is;
    }
    friend ostream& operator << (ostream& os, const VIDEO& video) {
        os << "Ten phim: " << video.getVidName() << '\n';
        os << "The loai phim: " << video.getVidType() << '\n';
        os << "Ten dao dien: " << video.getDirectorName() << '\n';
        os << "Ten nam chinh: " << video.getActorName() << '\n';
        os << "Ten nu chinh: " << video.getActressName() << '\n';
        os << "Nam xuat ban: " << video.getYearOfManufacture();
        return os;
    }
};

class Node {
private:
    VIDEO data;
    Node* next;
    friend class LinkedList;
public:
    Node(const VIDEO& data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* root;
public:
    LinkedList() : root(nullptr) {}
    /*
    Số lượng bộ phim
    */
    int getSize () const {
        int count = 0;
        for (Node* current = root; current != nullptr; current = current->next) {
            count += 1;
        }
        return count;
    }
    /*
    Thêm 1 video vào cuối danh sách liên kết
    */
    void push_back (const VIDEO& video) {
        if (!root) {
            root = new Node(video);
            return;
        }
        Node* current = root;
        while (current->next)
            current = current->next;
        current->next = new Node(video);
    }
    /*
    Cập nhật lại thể loại phim có tên cho trước
    */
    void update (const string& video_name, const string& video_type) {
        for (Node* current = root; current != nullptr; current = current->next) {
            if (current->data.getVidName() == video_name) {
                current->data.setVidType(video_type);
                break;
            }
        }
    }
    /*
    In danh sách phim
    */
    void disPlay () {
        for (Node* current = root; current != nullptr; current = current->next) {
            cout << current->data << '\n';
        }
    }
    /*
    Tạo file txt từ tên nam diễn viên
    */
    void solveTaskD (const string& actor_name) {
        string fileName = actor_name + ".txt";
        ofstream ofs(fileName, ios::app);
        if (ofs.is_open()) {
            for (Node* current = root; current != nullptr; current = current->next) {
                if (current->data.getActorName() == actor_name)
                    ofs << current->data << ' ';
            }
        }
    }
    /*
    Thống kê số lượng bộ phim và thông tin của các bộ phim cho mỗi đạo diễn
    */
    void solveTaskE () {
        int size = this->getSize();
        cout << "Tong so luong bo phim: " << size << '\n';
        vector<string> directors;
        for (Node* current = root; current != nullptr; current = current->next) {
            if (find(begin(directors), end(directors), current->data.getDirectorName()) == end(directors))
                directors.push_back(current->data.getDirectorName());
        }
        vector<vector<VIDEO>> listVideoOfDirector(directors.size());
        for (int i = 0; i < listVideoOfDirector.size(); ++i) {
            for (Node* current = root; current != nullptr; current = current->next) {
                if (current->data.getDirectorName() == directors[i]) {
                    listVideoOfDirector[i].push_back(current->data);
                }
            }
        }
        for (int i = 0; i < listVideoOfDirector.size(); ++i) {
            string fileName = directors[i] + ".txt";
            ofstream ofs(fileName, ios::app);
            if (ofs.is_open()) {
                for (const VIDEO& video : listVideoOfDirector[i]) {
                    ofs << video << '\n';
                }
            }
        }
    }
    /*
    Thông tin 3 bộ phim mới nhất
    */
    void interChangeSort () {
        for (Node* current = root; current->next != nullptr; current = current->next) {
            for (Node* next = current->next; next != nullptr; next = next->next) {
                if (current->data.getYearOfManufacture() < next->data.getYearOfManufacture()) {
                    swap(current->data, next->data);
                }
            }
        }
    }

    void printThreeLatestVideos () {
        ofstream ofs("PhimMoi.txt");
        if (ofs.is_open()) {
            Node* current = root;
            for (int i = 1; i <= 3; ++i) {
                ofs << current->data << '\n';
                current = current->next;
            }
        }
    }
    /*
    Giải phóng bộ nhớ
    */
    ~LinkedList() {
        while (root) {
            Node* temp = root;
            root = root->next;
            delete temp;
        }
    }
};

void solve () {
    LinkedList List;
    ifstream ifs("Input.txt");
    int n; ifs >> n;
    while (n--) {
        VIDEO video;
        ifs >> video;
        List.push_back(video);
    }
    //b
    string video_name;
    getline(ifs, video_name);
    List.update(video_name, "hinh su");
    //c
    List.disPlay();
    //d
    string actor_name;
    getline(cin, actor_name);
    List.solveTaskD(actor_name);
    //e
    List.solveTaskE();
    //f
    List.interChangeSort();
    List.printThreeLatestVideos();
}

int main () {
    solve();
    return 0;
}