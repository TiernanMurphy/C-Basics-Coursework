#include <cassert>
#include "linked_list.hpp"

bool test_get_head();
bool test_push_front();
bool test_push_back();
bool test_insert();
bool test_search();
bool test_at();
bool test_size();
bool test_remove();
bool test_remove_key();
bool test_remove_value();
bool test_print();
bool test_selection_sort();
bool test_bubble_sort();
bool test_print_stocks();
bool test_is_prime();

int main() {
    cout << "Test Get Head: " << (test_get_head() ? "Passed" : "Failed") << endl
         << "Test Push Front: " << (test_push_front() ? "Passed" : "Failed") << endl
         << "Test Push Back: " << (test_push_back()? "Passed" : "Failed") << endl
         << "Test Insert: " << (test_insert() ? "Passed" : "Failed") << endl
         << "Test Search: " << (test_search() ? "Passed" : "Failed") << endl
         << "Test At: " << (test_at() ? "Passed" : "Failed") << endl
         << "Test Size: " << (test_size() ? "Passed" : "Failed") << endl
         << "Test Remove: " << (test_remove() ? "Passed" : "Failed") << endl
         << "Test Remove Key: " << (test_remove_key() ? "Passed" : "Failed") << endl
         << "Test Remove Value: " << (test_remove_value() ? "Passed" : "Failed") << endl
         << "Test Print: " << (test_print() ? "Passed" : "Failed") << endl
         << "Test Selection Sort: " << (test_selection_sort() ? "Passed" : "Failed") << endl
         << "Test Bubble Sort: " << (test_bubble_sort() ? "Passed" : "Failed") << endl
         << "Test Print Stocks: " << (test_print_stocks() ? "Passed" : "Failed") << endl
         << "Test Is Prime: " << (test_is_prime() ? "Passed" : "Failed") << endl;
}


bool test_get_head() {
    LinkedList list;

    list.push_front(1, 100);
    list.push_front(2, 200);

    Node* head = list.get_head();
    assert(head->key == 2);
    assert(head->key != 1);
    return true;
}

bool test_push_front() {
    LinkedList list;
    list.push_front(1, 100);
    list.push_front(2, 200);

    assert(list.size() == 2);
    assert(list.size() != 1);
    return true;
}

bool test_push_back() {
    LinkedList list;
    list.push_back(1, 100);
    list.push_back(2, 100);

    assert(list.size() == 2);
    assert(list.size() != 1);
    return true;
}

bool test_insert() {
    LinkedList list;
    list.push_back(1, 100);
    list.push_back(2, 200);
    list.insert(3, 300, 1);

    Node* node = list.at(1);
    assert(node->key == 3);
    assert(node->key != 2);
    return true;
}

bool test_search() {
    LinkedList list;
    list.push_back(1, 100);
    list.push_back(2, 200);
    int value = list.search(2);

    assert(value == 200);
    assert(value != 100);
    return true;
}

bool test_at() {
    LinkedList list;
    list.push_back(1, 100);
    list.push_back(2, 200);
    Node* node = list.at(1);

    assert(node->key == 2 && node->value == 200);
    assert(node->key != 1 && node->value != 100);
    return true;
}

bool test_size() {
    LinkedList list;
    list.push_back(1, 100);
    list.push_back(2, 200);

    assert(list.size() == 2);
    assert(list.size() != 4);
    return true;
}

bool test_remove() {
    LinkedList list;
    list.push_back(1, 100);
    list.push_back(2, 200);
    list.remove(0);

    Node* head = list.get_head();
    assert(head->key == 2 && head->value == 200);
    assert(head->key != 1 && head->value != 100);
    return true;
}

bool test_remove_key() {
    LinkedList list;
    list.push_back(1, 100);
    list.push_back(2, 200);
    list.remove_key(1);

    Node* head = list.get_head();
    assert(head->key == 2 && head->value == 200);
    assert(head->key != 1 && head->value != 100);
    return true;
}

bool test_remove_value() {
    LinkedList list;
    list.push_back(1, 100);
    list.push_back(2, 200);
    list.remove_value(100);

    Node* head = list.get_head();
    assert(head->key == 2 && head->value == 200);
    assert(head->key != 1 && head->value != 100);
    return true;
}

bool test_print() {
    LinkedList list;
    list.push_back(1, 100);
    list.push_back(2, 200);
    string result = list.to_string();
    string output = "1, 100.000000, 2, 200.000000, ";

    assert(result == output);
    assert(result != "test");
    return true;
}

bool test_selection_sort() {
    LinkedList list;
    list.push_back(2, 200);
    list.push_back(1, 100);
    list.selection_sort();
    string result = list.to_string();
    string output = "1, 100.000000, 2, 200.000000, ";

    assert(result == output);
    assert(result != "2, 200.000000, 1, 100.000000, ");
    return true;
}

bool test_bubble_sort() {
    LinkedList list;
    list.push_back(2, 200);
    list.push_back(1, 100);
    list.bubble_sort();
    string result = list.to_string();
    string output = "1, 100.000000, 2, 200.000000, ";

    assert(result == output);
    assert(result != "2, 200.000000, 1, 100.000000, ");
    return true;
}

bool test_print_stocks() {
    LinkedList list;
    list.push_back(1, 100);
    list.push_back(2, 200);
    string result = list.stocks_string();
    string output = "Price of 3 Shares in NASDAQ's 15 Largest Companies\n"
                    "\t1: $300.000000\n"
                    "\t2: $600.000000\n";

    assert(result == output);
    assert(result != "test");
    return true;
}

bool test_is_prime() {
    LinkedList list;
    assert(list.is_prime(2));
    assert(!list.is_prime(10));
    return true;
}