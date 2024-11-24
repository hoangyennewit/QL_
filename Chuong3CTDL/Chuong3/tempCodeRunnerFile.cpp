void printPrimeNum() {
        Node* curr = head;
        bool found = false;
        while (curr){
            if (isPrime(curr->data)){
                found = true;
                cout << curr->data << ' ';
            }
            curr = curr->next;
        }
        if (!found) {
            cout << "Danh sach khong co so nguyen to!";
        }
    }