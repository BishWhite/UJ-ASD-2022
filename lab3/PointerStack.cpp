#include <iostream>

/*template<typename T> struct node{
    T value;
    node<T>* next;
};
*/
template <typename T> class PointerStack{
    struct node{
        T value = T();
        node* next = nullptr;
    };
private:
    node* head;

public:

    int current=0;
    PointerStack(){
        this->head= nullptr;

    }

    ~PointerStack(){
        makenull();
    }

    void push(const T& x){
        if(current==0){
            head = new node;
            head->value=x;
            current++;
        }
        else{
            node* newCell = new node;
            newCell->value = x;
            newCell->next=head;
            head = newCell;
            current++;
        }

    }

    T pop(){
        if(empty())
            return T();

        T tmp = head->value;
        node* tmp1 = head;
        head = head->next;
        delete tmp1;
        current--;

        return tmp;
    }

    T top(){
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

};

int main() {
    PointerStack<int> s;
    std::cout<<s.empty()<<std::endl;
    s.push(1);
    s.push(10);
    s.push(14);
    s.push(2);
    std::cout<<s.top()<<std::endl;
    std::cout<<s.pop()<<std::endl;
    std::cout<<s.top()<<std::endl;
    std::cout<<s.empty()<<std::endl;
    //s.makenull();
    std::cout<<s.top()<<std::endl;
    std::cout<<s.pop()<<std::endl;
    std::cout<<s.top()<<std::endl;
    std::cout<<s.pop()<<std::endl;
    s.makenull();
    std::cout<<s.top()<<std::endl;
    std::cout<<s.pop()<<std::endl;

    PointerStack<std::string> st;
    //std::cout<<st.empty()<<std::endl;
    st.push("123");
    st.push("abc");
    st.push("tod");
    //st.makenull();
    std::cout<<st.top()<<std::endl;
    std::cout<<st.pop()<<std::endl;
    std::cout<<st.pop()<<std::endl;
    std::cout<<st.pop()<<std::endl;
    std::cout<<st.pop()<<std::endl;

    return 0;
}//
// Created by jakub on 11.11.22.
//
