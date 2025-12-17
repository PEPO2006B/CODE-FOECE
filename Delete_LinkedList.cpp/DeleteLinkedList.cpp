#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularList {
private:
    Node* head;

public:
  
    CircularList() {
        head = NULL;
    }

   
    void insertEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;

       
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

    
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

 
    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }


    void deleteValue(int value) {
        if (head == NULL) return;

        Node* curr = head;
        Node* prev = NULL;
        do {
            if (curr->data == value)
                break;
            prev = curr;
            curr = curr->next;
        } while (curr != head);

   
        if (curr->data != value) return;

      
        if (curr == head && curr->next == head) {
            delete curr;
            head = NULL;
        }
        
        else if (curr == head) {
            Node* last = head;
            while (last->next != head)
                last = last->next;

            head = head->next;
            last->next = head;
            delete curr;
        }
       
        else {
            prev->next = curr->next;
            delete curr;
        }
    }
};

int main() {
    CircularList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);

    cout << "List after insertion: ";
    list.display();

    list.deleteValue(20);

    cout << "List after deleting 20: ";
    list.display();

    return 0;
}
