#include <iostream>
#include <string>

using namespace std;

struct Drink {
    string name;      
    bool isHot;      
    int price;
    double shelfLife; 
};


struct Node {
    Drink data;      
    Node* next;    
};


void append(Node*& head, const Drink& drink) {
    Node* newNode = new Node{drink, nullptr};
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(const Node* head) {
    const Node* temp = head;
    while (temp != nullptr) {
        cout << "Name: " << temp->data.name << "\n";
        cout << "Temperature: " << (temp->data.isHot ? "Hot" : "Cold") << "\n";
        cout << "Price: " << temp->data.price << " NT\n";
        cout << "Shelf Life: " << temp->data.shelfLife << " years\n";
        cout << "---------------------\n";
        temp = temp->next;
    }
}

void deleteDrink(Node*& head, const string& drinkName) {
    if (head == nullptr) {
        cout << "The list is empty. No drink to delete.\n";
        return;
    }

    if (head->data.name == drinkName) {
        Node* temp = head;
        head = head->next; 
        delete temp;     
        cout << "Drink \"" << drinkName << "\" has been deleted.\n";
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data.name != drinkName) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = temp->next; 
        delete temp;               
        cout << "Drink \"" << drinkName << "\" has been deleted.\n";
    } else {
        cout << "Drink \"" << drinkName << "\" not found in the list.\n";
    }
}

void freeList(Node*& head) {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
}

int main() {
    Node* head = nullptr;

    append(head, {"green tea", false, 26, 0.5});
    append(head, {"coffee", true, 22, 2.08});
    append(head, {"juice", false, 18, 0.83});
    append(head, {"corn soup", true, 30, 1.0});
    append(head, {"adzuki bean soup", true, 35, 0.91});


    string drinkName;
    cout << "\nEnter the name of the drink to delete: ";
    cin >> drinkName;

    deleteDrink(head, drinkName);

    cout << "\nUpdated Drinks List:\n";
    cout << "==============================\n";
    printList(head);


    freeList(head);

    return 0;
}
