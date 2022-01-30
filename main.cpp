#include <iostream>

using namespace std;

struct Node {
public:
    int data;
    Node *next;

    Node() {

        this->next = nullptr;
        this->data = -1;
    }

    Node(int data) : data(data) {}

    Node(int data, Node *next) : data(data), next(next) {}
};


class CLL {
public:
    Node *start, *trv;

    void putTRVatBeg() {
        trv = start;
    }

    void putTRVatEnd() {
        putTRVatBeg();
        if (start == nullptr) {
            trv = nullptr;
            return;
        }
        while (trv->next != start) {
            trv = trv->next;
        }
    }

    void putTRVatSecLast() {
        putTRVatBeg();
        if (start->next == start) {
            return;
        }
        if (start == nullptr) {
            trv = nullptr;
            return;
        }
        while (trv->next->next != start) {
            trv = trv->next;
        }
    }

    void putTRVatNth(int pos) {
        if (start == nullptr) {
            cout << "Underflow";
            return;
        } else if (pos > getLast() || pos < 1) {
            cout << "Invalid Position";
            return;
        } else {
            putTRVatBeg();
            int currentPos = 1;
            while (currentPos != pos) {
                trv = trv->next;
                currentPos++;
            }
            return;
        }
    }

    CLL() {
        start = nullptr;
    }


    void insertAtBeg(int data) {
        if (start == nullptr) {
            Node *tmp = new Node(data);
            start = tmp;
            tmp->next = start;
        } else {
            putTRVatEnd();
            Node *tmp = new Node(data, start);
            trv->next = tmp;
            start = tmp;
        }
    }

    void insertAtEnd(int data) {
        if (start == nullptr) {
            insertAtBeg(data);
            return;
        } else {
            putTRVatEnd();
            Node *tmp = new Node(data, start);
            trv->next = tmp;
        }
    }

    void insertAtNth(int data, int pos) {
        if (pos < 1 || pos > getLast() + 1) {
            cout << "Invalid Position!" << endl;
            return;
        } else if (pos == 1) {
            insertAtBeg(data);
            return;
        } else if (pos == getLast() + 1) {
            insertAtEnd(data);
        } else {
            int currentPos = 1;
            putTRVatBeg();
            while (currentPos != pos - 1) {
                trv = trv->next;
                currentPos++;
            }
            Node *tmp = new Node(data, trv->next);
            trv->next = tmp;
        }
    }

    int getLast() {
        int count = 0;
        if (start == nullptr) {
            cout << "Underflow" << endl;
            return count;
        } else {
            putTRVatBeg();
            do {
                count++;
                trv = trv->next;
            } while (trv != start);

        }
        return count;
    }

    void printCLL() {

        if (start == nullptr) {
            cout << "Underflow" << endl;
            return;
        } else {
            putTRVatBeg();
            do {
                cout << trv->data;
                if (trv == start)
                    cout << "^";
                cout << " -> ";
                trv = trv->next;
            } while (trv != start);
            cout << "| " << start->data << "^ -> ..." << endl;


        }
    }

    void deleteAtBeg() {
        if (start == nullptr) {
            cout << "Underflow" << endl;
            return;
        } else if (start->next == start) {
            Node *tmp = start;
            free(tmp);
            start = nullptr;
        } else {
            putTRVatEnd();
            Node *tmp = start;
            start = start->next;
            trv->next = start;
            free(tmp);
        }
    }

    void deleteAtEnd() {
        if (start == nullptr) {
            cout << "Underflow" << endl;
            return;
        } else if (start->next == start) {
            Node *tmp = start;
            free(tmp);
            start = nullptr;
        } else {
            putTRVatSecLast();
            Node *tmp = trv->next;
            trv->next = start;
            free(tmp);
        }
    }

    void deleteAtNth(int pos) {
        if (start == nullptr) {
            cout << "Underflow" << endl;
            return;
        } else if (pos < 1 || pos > getLast()) {
            cout << "Invalid Position" << endl;
            return;
        } else if (pos == 1) {
            deleteAtBeg();
        } else if (pos == getLast()) {
            deleteAtEnd();
        } else {
            putTRVatNth(pos - 1);
            Node *tmp = trv->next;
            trv->next = trv->next->next;
            free(tmp);
        }
    }


};

int main() {
    CLL c1;
    c1.insertAtBeg(5);
    c1.insertAtBeg(8);
    c1.insertAtBeg(3);
    c1.insertAtEnd(69);
    c1.insertAtNth(699, 6);
    c1.insertAtBeg(9);
    c1.printCLL();
    c1.deleteAtNth(5);
    c1.printCLL();
    return 0;
}
