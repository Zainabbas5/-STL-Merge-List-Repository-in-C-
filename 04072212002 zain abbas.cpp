#include<iostream>
using namespace std;

template<typename T>
struct dnode {
    dnode<T>* prev;
    T data;
    dnode<T>* next;
};

template<typename T>
class list {
private:
    dnode<T>* Front;
    dnode<T>* Back;
    int n;

public:
    list() {
        Front = Back = NULL;
        n = 0;
    }

    ~list() {
        clear();
    }

    void push_front(const T& val) {
        dnode<T>* tempnew;
        tempnew = new dnode<T>;

        if (tempnew == NULL) {
            throw("list overflow");
        }

        tempnew->data = val;
        tempnew->prev = NULL;

        if (Front == NULL) {
            Front = Back = tempnew;
            tempnew->next = NULL;
        }
        else {
            tempnew->next = Front;
            Front->prev = tempnew;
            Front = tempnew;
        }

        n++;
    }

    void push_back(const T& val) {
        dnode<T>* tempnew;
        tempnew = new dnode<T>;

        if (tempnew == NULL) {
            throw("list overflow");
        }

        tempnew->data = val;
        tempnew->next = NULL;

        if (Back == NULL) {
            Front = Back = tempnew;
            tempnew->prev = NULL;
        }
        else {
            tempnew->prev = Back;
            Back->next = tempnew;
            Back = tempnew;
        }

        n++;
    }

    T front() {
        if (Front == NULL) {
            throw("list underflow");
        }

        return Front->data;
    }

    T back() {
        if (Back == NULL) {
            throw("list underflow");
        }

        return Back->data;
    }

    void pop_front() {
        if (Front == NULL) {
            throw("List Underflow!");
        }

        if (Front == Back) {
            delete Front;
            Front = Back = NULL;
        }
        else {
            Front = Front->next;
            delete Front->prev;
            Front->prev = NULL;
        }
    }

    void pop_back() {

        if (Front == NULL) {
            throw("List Underflow!");
        }

        if (Front == Back) {
            delete Back;
            Front = Back = NULL;
        }
        else {
            Back = Back->prev;
            delete Back->next;
            Back->next = NULL;
        }
    }

    bool empty() const {
        return Front == NULL;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    bool mergeList(list& list2) {
       
        
            if (list2.Front == NULL) {        // If list2 is empty,
                throw("list underflow");    
            }

            if (Front == NULL) {          // If list1 is empty,
                Front = list2.Front;
                Back = list2.Back;
            }
            else {                            // Connect the Back of list1 to the Front of list2
                Back->next = list2.Front;
                list2.Front->prev = Back;
                Back = list2.Back;
            }

            n += list2.n;                   // Update the size of list1 and clear list2
            list2.Front = NULL;
            list2.Back = NULL;
            list2.n = 0;

            // Bubble Sort
            if (Front == NULL) {
                throw("list underflow");
            }
        
        dnode<T>* current;
        dnode<T>* end = NULL;
        bool last = true;

        while (last)
        {
            last = false;
            current = Front;

            while (current->next != end) {
                if (current->data > current->next->data) {
                    // Swap the elements
                    T temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    last = true;
                }
                current = current->next;
            }
            end = current;
        }
    }
};

int main() {
    list<int> l1;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(10);
    l1.push_back(15);
    list<int> l2;
     l2.push_back(5);
    l2.push_back(10);
    l2.push_back(20);
    
    try {
        l1.mergeList(l2);
    }
    catch (const string& error) {
        cout << error << endl;
    }

    while (!l1.empty()) {
        cout << l1.front() <<" ";
        l1.pop_front();
    }
    cout << endl;
    return 0;
}
