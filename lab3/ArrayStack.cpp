#include <iostream>

#define MAX_SIZE 100

template <typename T> class ArrayStack{

private:
    T* array;
    int current;
public:
    ArrayStack(){
        this->current = -1;
        this->array = new T[MAX_SIZE];
    }

    ~ArrayStack(){
        makenull();
    }
    void push(const T& x){
        array[current+1] =  x;
        current++;

    }

    T pop(){
        if(current>=0)
            return array[current--];

        return T();
    }

    T top(){
        if(current>=0)
            return array[current];

        return T();
    }

    void makenull(){
        delete[] array;
        current = -1;
        this->array = new T[MAX_SIZE];
    }

    bool empty(){
        return current==-1;
    }

};


int main() {
    ArrayStack<int> s;
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

    ArrayStack<std::string> st;

    st.push("123");
    st.push("abc");
    st.push("tod");
    //st.makenull();
    std::cout<<st.pop()<<std::endl;
    std::cout<<st.pop()<<std::endl;
    std::cout<<st.pop()<<std::endl;
    std::cout<<st.pop()<<std::endl;
    std::cout<<st.pop()<<std::endl;


    return 0;
}//
// Created by jakub on 11.11.22.
//
