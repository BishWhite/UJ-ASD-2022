#include <iostream>

#define MAX_SIZE 100

template <typename T> class ArrayList{

private:
    T* array;

    int current;
public:
    ArrayList(){
        this->current = 0;
        this->array = new T[MAX_SIZE];
    }

    ~ArrayList(){
        delete [] this->array;
        this->current = 0;
    }

    bool Insert(const T& x, int p){
        if(p>=MAX_SIZE || p>current || p<0)
            return false;
        if(p == current){
            array[p] = x;
            current++;
            return true;
        }

        for(int i=current-1;i>=p;i--){
            array[i+1] = array[i];
        }
        array[p] = x;
        current++;
        return true;
    }

    bool Delete(int p){
        if(p>=MAX_SIZE || p>=current || p<0)
            return false;
        for(int i=p;i<current-1;i++)
            array[i] = array[i+1];
        array[current-1] = 0;
        current--;
        return true;
    }
    int Locate(const T& x){
        for(int i=0;i<current;i++){
            if(array[i] == x)
                return i;
        }
        return this->End();

    }
    int First(){
        return current==0 ? -1:0;
    }
    int End(){
        return this->current;
    }

    int Next(int p){
        return p+1<current ? p+1 : -1;
    }

    int Previous(int p){
        return (p>=1 && p<=current) ? p-1 : -1;
    }

    T& Retrieve(int p){
        if((p<0 || p>=current))
            throw std::out_of_range("Wrong index.");
        return this->array[p];
    }
    T& Retrieve(int p) const{
        if((p<0 || p>=current))
            throw std::out_of_range("Wrong index.");
        return this->array[p];
    }

    void print(){
        for(int i=0;i<current;i++){
            std::cout<<array[i]<<" ";
        }
        std::cout<<std::endl;
    }
};


int main() {

    ArrayList<int> l;
    l.Insert(0, 0);
    l.Insert(3,1);
    l.Insert(10,2);
    l.Insert(12,3);
    std::cout<<l.Retrieve(3)<<std::endl;
    l.Delete(3);

    std::cout<<l.First()<<std::endl;
    l.print();



    ArrayList<std::string>l2;

    std::string s = "kotek";

    std::string s1 = "aaa";

    l2.Insert(s,0);
    l2.Insert(s1, 0);
    l2.print();
    std::cout<<l2.Locate("kotek")<<std::endl;

    return 0;
}

//
// Created by jakub on 11.11.22.
