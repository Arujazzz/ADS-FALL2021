#include <iostream>
using namespace std;
struct Node {
    int val;
    Node* next;

    Node(int _val) : val(_val), next(nullptr) {}
};
    //Значение, которое будет задавать пользователь
    //Указатель на следующий элемент (по умолчанию nullptr)
    //Конструктор

struct list {
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}

    //Указатель на первый узел
    //Указатель на последний узел
    //Конструктор

    bool is_empty() {
        return first == nullptr;   //Функция проверки наличия узлов в списке
                                   //Это однострочная функция, в которой надо проверить является ли первый узел - пустым
    }

    void push_back(int _val) {      //Функция добавления элемента в конец списка
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void print() {                 //Функция печати всего списка
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    Node* find(int _val) {         //Функция поиска узла в списке по заданному значению
        Node* p = first;
        while (p && p->val != _val) p = p->next;
        return (p && p->val == _val) ? p : nullptr;
    }

    void remove_first() {            //Функция удаления первого узла
        if (is_empty()) return;
        Node* p = first;
        first = p->next;
        delete p;
    }

    void remove_last() {             //Функция удаления последнего узла
        if (is_empty()) return;
        if (first == last) {
            remove_first();
            return;
        }
        Node* p = first;
        while (p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }

    void remove(int _val) {       //Функция удаления узла по заданному значению значению
        if (is_empty()) return;
        if (first->val == _val) {
            remove_first();
            return;
        }
        else if (last->val == _val) {
            remove_last();
            return;
        }
        Node* slow = first;
        Node* fast = first->next;
        while (fast && fast->val != _val) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            cout << "This element does not exist" << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }

    Node* operator[] (const int index) {           //Функция обращения к узлу по индексу
        if (is_empty()) return nullptr;
        Node* p = first;
        for (int i = 0; i < index; i++) {
            p = p->next;
            if (!p) return nullptr;
        }
        return p;
    }
};

int main()
{
    list l;
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
        l.push_back(a[i]);
    }
    int k;
    cin >> k;
    for (int i=0; i<n; i++){
        if (a[i] == k){
            l.remove(k);
        }
    }
    l.print();
    return 0;
}