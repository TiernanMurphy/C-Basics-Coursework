#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <utility>

using namespace std;

class Node {
    public:
        int key;
        double value;
        Node* next;
        Node();
        Node(int k, double v);
};

class LinkedList {
    public:
        LinkedList();
        ~LinkedList();
        Node* get_head() const;
        void push_front(int key, double value);
        void push_back(int key, double value);
        void insert(int key, double value, int index);
        double search(int key);
        Node* at(int index);
        int size();
        bool remove(int index);
        bool remove_key(int key);
        bool remove_value(double value);
        void print();
        void selection_sort();
        void bubble_sort();
        // question functions
        void print_stocks();
        bool is_prime(int num);
        string to_string();
        string stocks_string();
    private:
        Node* head;
};

void problem_one();
void problem_two();
void problem_three();


#endif