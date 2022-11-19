#include <iostream>


template <typename T> class PointerQueue{
    struct node{
        T value = T();
        node* next = nullptr;
    };
private:
    node* head;
    node* last;
    int current=0;
public:

    PointerQueue(){
        this->head= new node;
        this->last= head;

    }

    ~PointerQueue(){
        makenull();
    }

    void put(const T& x){
        if(current==0){
            head->value=x;
            head->next= nullptr;
            current++;
        }
        else{
            node* newCell = new node;
            newCell->value = x;
            newCell->next = nullptr;
            last->next = newCell;
            last = last->next;
            current++;
        }

    }

    T get(){
        if(empty())
            return T();

        T tmp = head->value;
        node* tmp1 = head;
        head = head->next;
        delete tmp1;
        current--;
        return tmp;
    }

    T front(){
        if(current>0)
            return head->value;

        return T();
    }

    void makenull(){
        while(current>0){
            node* tmp = head;
            head = head->next;
            delete tmp;
            current--;
        }



    }

    bool empty(){
        return current==0;
    }

    void print(){
        node*tmp = head;
        std::cout<<"queue: ";
        while (tmp != nullptr){
            std::cout<<tmp->value<<" ";
            tmp = tmp->next;
        }
        std::cout<<std::endl;
    }

};

int main() {
    PointerQueue<int> s;
    std::cout<<"Empty: "<<s.empty()<<std::endl;
    s.put(1);
    s.put(10);
    s.put(14);
    s.put(2);
    s.print();
    std::cout<<"Front: "<<s.front()<<std::endl;
    std::cout<<s.get()<<std::endl;
    std::cout<<s.get()<<std::endl;
    std::cout<<"Empty: "<<s.empty()<<std::endl;
    //s.makenull();
    std::cout<<s.front()<<std::endl;
    std::cout<<s.get()<<std::endl;
    std::cout<<s.front()<<std::endl;
    std::cout<<s.get()<<std::endl;
    s.makenull();
    std::cout<<s.front()<<std::endl;
    std::cout<<s.get()<<std::endl;

    PointerQueue<std::string> st;
    //std::cout<<st.empty()<<std::endl;
    st.put("123");
    st.put("abc");
    st.put("tod");
    st.print();
    st.makenull();
    st.print();
    std::cout<<st.front()<<std::endl;
    std::cout<<st.get()<<std::endl;
    std::cout<<st.get()<<std::endl;
    std::cout<<st.get()<<std::endl;
    std::cout<<st.get()<<std::endl;

    return 0;
}

//
// Created by jakub on 11.11.22.
//
