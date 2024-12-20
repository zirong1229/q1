#include <iostream>
#include <string>

using namespace std;

struct Drink {
    string name;      
    bool tem;    
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
        cout << "Temperature: " << (temp->data.tem ? "Hot" : "Cold") << "\n";
        cout << "Price: " << temp->data.price << " NT\n";
        cout << "Shelf Life: " << temp->data.shelfLife << " years\n";
        cout << "---------------------\n";
        temp = temp->next; 
    }
}


void filterDrinks(const Node* head, bool desiredTemperature, int maxPrice) {
    const Node* temp = head;
    bool found = false;

    while (temp != nullptr) {
        if (temp->data.tem == desiredTemperature && temp->data.price <= maxPrice) {
            cout << "Name: " << temp->data.name << "\n";
            cout << "Temperature: " << (temp->data.tem ? "Hot" : "Cold") << "\n";
            cout << "Price: " << temp->data.price << " NT\n";
            cout << "Shelf Life: " << temp->data.shelfLife << " years\n";
            cout << "---------------------\n";
            found = true;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "No drinks match the given criteria.\n";
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

    string tempInput;
    int maxPrice;
    cout << "Enter temperature (hot/cold): ";
    cin >> tempInput;
    cout << "Enter maximum price: ";
    cin >> maxPrice;

    bool desiredTemperature = (tempInput == "hot");

    cout << "\nFiltered Drinks:\n";
    cout << "==============================\n";
    filterDrinks(head, desiredTemperature, maxPrice);

    freeList(head);

    return 0;
}
