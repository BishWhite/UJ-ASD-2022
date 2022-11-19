#include <iostream>
#define MAX_SIZE 100

template <typename T> class ArrayQueue{

private:
    int current;
    T*array;
    int head;

public:


    ArrayQueue(){
        this->array = new T[MAX_SIZE];
        this->current = 0;
        this->head = 0;
    }

    ~ArrayQueue(){
        makenull();
    }

    bool put(const T& x){
        if(current>=MAX_SIZE)
            return false;
        array[(head+current)%MAX_SIZE] = x;
        current++;
        return true;
    }

    T get(){
        if(empty())
            return T();
        int tmp = head;
        head = (head+1)%MAX_SIZE;
        current--;
        return array[tmp];
    }

    T front(){
        if(empty())
            return T();

        return array[head];
    }

    void makenull(){
        delete[] array;
        current = 0;
        this->array = new T[MAX_SIZE];
    }

    bool empty(){
        return current==0;
    }

    void print(){
        int i = 0;
        std::cout<<"queue: ";
        while(i<current){
            std::cout<<array[(head+i)%MAX_SIZE]<<" ";
            i++;
        }
        std::cout<<std::endl;
    }

};

int main() {
    ArrayQueue<int> s;
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
    //s.makenull();
    std::cout<<s.front()<<std::endl;
    std::cout<<s.get()<<std::endl;

    ArrayQueue<std::string> st;
    //std::cout<<st.empty()<<std::endl;
    st.put("123");
    st.put("abc");
    st.put("tod");
    st.print();
    //st.makenull();
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
//
// Created by jakub on 15.11.22.
//
