#include "linked_list.hpp"

// Node default constructor
Node::Node() : key(0), value(0), next(nullptr) {
}

// Node parameterized constructor
Node::Node(int k, double v) : key(k), value(v) {
    next = nullptr;
}

// LinkedList default constructor
LinkedList::LinkedList() : head(nullptr) {
}

// LinkedList deconstructor
LinkedList::~LinkedList() {
    Node* iter = head;
    while (iter) {
        Node* next = iter->next;
        delete iter;
        iter = next;
    }
}

// returns pointer to head of linked list
Node* LinkedList::get_head() const { return head; }

// adds node to front of linked list
void LinkedList::push_front(int key, double value) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->value = value;

    newNode->next = head;
    head = newNode;
}

// adds node to back of linked list
void LinkedList::push_back(int key, double value) {
    Node* new_node = new Node(key, value);

    if(head == nullptr) {
        head = new_node;
    } else {
        Node* iter;
        for(iter = head; iter->next != nullptr; iter = iter->next);
        iter->next = new_node;
    }
}

// inserts a new node at specified index
void LinkedList::insert(int key, double value, int index) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->value = value;

    if (index == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    for (int i = 0; current != nullptr && i < index - 1; ++i) {
        current = current->next;
    }

    if (current == nullptr) {
        // Index is out of bounds — handle as needed
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// searches for key (parameter), returns value
double LinkedList::search(int key) {
    Node* iter = head;
    while(iter != nullptr) {
        if(iter->key == key) {
            return iter->value; // key found, return value
        }
        iter = iter->next;
    }

    return -1; // key not found
}

// returns a pointer to the node at specified index of linked list
Node* LinkedList::at(int index) {
    Node* current = head;
    int count = 0;

    while(current != nullptr) {
        if(count == index) {
            return current; // found node at index
        }
        count++;
        current = current->next; // check next node
    }

    return nullptr; // index out of bounds
}

// returns size of linked list
int LinkedList::size() {
    int count = 0;
    for(Node* iter=head; iter!=nullptr; iter=iter->next) { count++; }
    return count;
}

// removes node at specified index
bool LinkedList::remove(int index) {
    if(head == nullptr) return false; // empty list

    if(index == 0) {
        // removing head
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* current = head;
    Node* previous = nullptr;
    int count = 0;

    while(current != nullptr && count < index) {
        previous = current;
        current = current->next;
        count++;
    }

    if(current == nullptr) {
        // index is out of bounds
        return false;
    }

    // unlink and delete
    previous->next = current->next;
    delete current;

    return true;
}

// removes first node with specified key
bool LinkedList::remove_key(int key) {
    if (head == nullptr) return false; // empty list

    if (head->key == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true; // removed
    }

    Node* prev = head;
    Node* current = head->next;

    while (current != nullptr) {
        if (current->key == key) {
            prev->next = current->next;
            delete current;
            return true; // removed first match
        }
        prev = current;
        current = current->next;
    }

    return false; // not found
}

// removes first node with specified value
bool LinkedList::remove_value(double value) {
    if(head == nullptr) { return false; } // empty list

    if(head->value == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* prev = head;
    Node* current = head->next;

    while(current != nullptr) {
        if(current->value == value) {
            prev->next = current->next;
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false;
}

// prints key and value for each node
void LinkedList::print() {
    Node* iter = head;
    while(iter != nullptr) {
        cout << "key: " << iter->key << ", value: " << iter->value << endl;
        iter = iter->next;
    }
}

// sorts linked list based on keys, using selection sort
void LinkedList::selection_sort() {
    Node* start = head;

    while (start != nullptr) {
        Node* minNode = start;
        Node* iter = start->next;

        // Find the node with the minimum key in the unsorted portion
        while (iter != nullptr) {
            if (iter->key < minNode->key) {
                minNode = iter;
            }
            iter = iter->next;
        }

        // Swap key and value data between start and minNode
        if (minNode != start) {
            std::swap(start->key, minNode->key);
            std::swap(start->value, minNode->value);
        }

        // Move to next position
        start = start->next;
    }
}

// sorts linked list based on keys, using bubble sort
void LinkedList::bubble_sort() {
    if (head == nullptr) return; // empty list

    bool swapped;

    do {
        swapped = false;
        Node* current = head;

        while (current->next != nullptr) {
            if (current->key > current->next->key) {
                // Swap keys and values of adjacent nodes
                std::swap(current->key, current->next->key);
                std::swap(current->value, current->next->value);
                swapped = true;
            }
            current = current->next;
        }

    } while (swapped);
}

// prints NASDAQ stocks info
void LinkedList::print_stocks() {
    Node* iter = head;
    cout << "Price of 3 Shares in NASDAQ's 15 Largest Companies\n";
    while(iter != nullptr) {
        cout << "\t" << iter->key << ": $" << iter->value * 3 << endl;
        iter = iter->next;
    }
}

// checks if a given number is prime
bool LinkedList::is_prime(int num) {
   if (num <= 1) return false;
   if (num == 2) return true;
   if (num % 2 == 0) return false;
   float midpoint = sqrt(num);
   for(int i = 3; i <= midpoint; i += 2) {
       if(num % i == 0) return false;
   }
   return true;
}

string LinkedList::to_string() {
    string result = "";
    Node* iter = head;
    while(iter != nullptr) {
        result += std::to_string(iter->key) + ", " + std::to_string(iter->value) + ", ";
        iter = iter->next;
    }
    return result;
}

string LinkedList::stocks_string() {
    string result = "Price of 3 Shares in NASDAQ's 15 Largest Companies\n";
    Node* iter = head;
    while(iter != nullptr) {
        result += "\t" + std::to_string(iter->key) + ": $" + std::to_string(iter->value * 3) + "\n";
        iter = iter->next;
    }
    return result;
}

// solves project's first problem
void problem_one() {
    LinkedList primes;
    int twentiethPrime = 71;
    double inverse;
    double sum = 0;

    for(int i = 0; i <= twentiethPrime; i++) {
        if(primes.is_prime(i)) {
            inverse = 1.0 / i;
            sum += inverse;
        }
    }
    cout << "sum of first 20 inverted primes = " << sum << endl;
}

// solves project's second problem
void problem_two() {
    LinkedList calendar;

    calendar.push_back(1, 365.25);
    calendar.push_back(2, 365);

    double difference = 10000 * (365.25 - 365); // difference between two methods over 10000 years

    cout << "maximum difference of " << difference << " years\n";
}

// solve project's third problem
void problem_three() {
    LinkedList stocks;

    // adding 15 most valuable companies to linked list
    stocks.push_back(1, 477.40);
    stocks.push_back(2, 143.85);
    stocks.push_back(3, 201.00);
    stocks.push_back(4, 209.69);
    stocks.push_back(5, 167.73);
    stocks.push_back(6, 682.35);
    stocks.push_back(7, 249.99);
    stocks.push_back(8, 484.85);
    stocks.push_back(9, 322.16);
    stocks.push_back(10, 96.12);
    stocks.push_back(11, 275);
    stocks.push_back(12, 762.73);
    stocks.push_back(13, 338.57);
    stocks.push_back(14, 205.17);
    stocks.push_back(15, 1231);

    stocks.print_stocks(); // outputting price of 3 shares for each company
}