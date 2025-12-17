#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Circular_LinkedList {
private:
    Node* head;

public:
    Circular_LinkedList() {
        head = NULL;
    }

   
    void insert_End(int value) {
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

  
    void insert_Beginning(int value) {
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
        head = newNode;
    }

    
    void delete_Node(int value) {
        if (head == NULL) return;

        Node* temp = head;
        Node* prev = NULL;

        do {
            if (temp->data == value) break;
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        if (temp->data != value) return;

        
        if (temp == head && temp->next == head) {
            head = NULL;
        }
        
        else if (temp == head) {
            prev = head;
            while (prev->next != head) {
                prev = prev->next;
            }
            head = head->next;
            prev->next = head;
        }
      
        else {
            prev->next = temp->next;
        }

        delete temp;
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
};

int main() {
    Circular_LinkedList myList;


    myList.insert_End(10);
    myList.insert_End(20);
    myList.insert_End(30);
    cout << "After inserting at end: ";
    myList.display();


    myList.insert_Beginning(5);
    cout << "After inserting at beginning: ";
    myList.display();

    myList.delete_Node(20);
    cout << "After deleting 20: ";
    myList.display();


    myList.delete_Node(5);
    cout << "After deleting head (5): ";
    myList.display();

 
    myList.delete_Node(30);
    cout << "After deleting 30: ";
    myList.display();

    return 0;
}
