#include <iostream>

typedef int element;
struct cell{
    element element;
    cell *next;
};

class Lista{

private: cell *head;

public:
    Lista(){
        this->head = nullptr;
    }

    ~Lista(){}

    void Insert(element x, cell*p){
        if(head == nullptr){
            head = new cell;
            head->element = x;
            head->next = nullptr;

        }
        else if (p!= nullptr){
            cell *tmp;
            tmp= p->next;
            p->next = new cell;
            p->next->element=x;
            p->next->next=tmp;

        }

    }
    void Delete(cell * p){
        if(p!= nullptr) {
            cell *tmp;
            tmp = p->next;
            if (tmp != nullptr)
                p->next = p->next->next;
            else
                p->next = nullptr;

            delete tmp;
        }
    }
    cell * Locate(element x){
        cell *tmp;
        tmp=head;
        while (tmp != nullptr) {
            if (tmp->element == x)
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
        cell *tmp;
        tmp=head;
        while(tmp != nullptr){
            if(tmp->next == p)
                return tmp;

            tmp = tmp->next;
        }
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
            std::cout<<first->element<<" ";
            first = first->next;
        }
        std::cout<<std::endl;
    }
};

int main() {
    Lista l;
    l.Insert(15, new cell);
    l.Insert(1,l.First());
    l.Insert(14,l.Locate(1));
    l.Insert(10,l.Locate(15));
    l.Delete(l.First());
    l.print();
    std::cout<<l.Next(nullptr)<<std::endl;
    std::cout<<l.Previous(nullptr)->element<<std::endl;
    std::cout<<l.Last()->element<<std::endl;

}//
// Created by jakub on 11.11.22.
//
