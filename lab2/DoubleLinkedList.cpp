#include<iostream>
template <typename T> class LinkedList{


    struct cell{
        T x = T();
        cell* next = nullptr;
        cell* prev = nullptr;

    };


protected:
    cell *head;

public:
    LinkedList(){
        this->head = nullptr;
    }



    void Insert(T x, cell*p){

        if(head == nullptr){
            head = new cell;
            head->x = x;
            head->prev = nullptr;
            head->next = nullptr;

        }
        else if (p!= nullptr){
            cell *tmp;
            tmp= p->next;
            p->next = new cell;
            p->next->x=x;
            p->next->prev = p;
            p->next->next=tmp;

            if(tmp!= nullptr)
                tmp->prev= p->next;
        }

    }
    void Delete(cell * p){
        if(p!= nullptr) {
            if (p->next != nullptr){
                if(p->next->next == nullptr){
                    p->next = nullptr;
                    delete p->next;
                }
                else{
                    cell * tmp;
                    tmp = p->next->next;
                    delete p->next;
                    p->next = tmp;
                    tmp->prev = p;
                }
            }
        }
    }
    cell * Locate(T x){
        cell *tmp;
        tmp=head;
        while (tmp != nullptr) {
            if (tmp->x == x)
                return tmp;
            tmp=tmp->next;
        }
        return nullptr;
    }
    cell * First(){
        return head;
    }

    static cell * Next(cell * p){
        return p!= nullptr? p->next : nullptr;
    }

    cell * Previous(cell * p){

        if(p!= nullptr)
            return p->prev;

        return nullptr;
    }

    cell * Last(){
        cell * tmp;
        tmp = head;
        while (tmp != nullptr){
            if(tmp->next!= nullptr)
                tmp = tmp->next;
            else
                break;
        }
        return tmp;
    }

    void print(){
        cell * first = head;
        while (first != nullptr){
            std::cout<<first->x<<" ";
            first = first->next;
        }
        std::cout<<std::endl;
    }

};
int main(){
    LinkedList<int> l;
    l.Insert(2, nullptr);
    l.Insert(1,l.Locate(2));
    l.Insert(3,l.Locate(2));
    l.Insert(5,l.Locate(1));
    l.Delete(l.Locate(3));
    l.Insert(4,l.Locate(5));
    l.Delete(l.Locate(3));
    std::cout<<l.Previous(l.Locate(5))<<std::endl;
    l.print();
    LinkedList<std::string> ls;
    ls.Insert("hi", nullptr);
    ls.Insert("abc",ls.Locate("hi"));
    ls.print();
    ls.Delete(ls.Locate("hi"));
    ls.print();


}

