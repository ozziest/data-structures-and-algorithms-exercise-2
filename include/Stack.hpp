/**
* @file Stack.hpp
* @description Yığın üzerinde her bir faktöriyel sonucunu tutacak olan sınıfın başlık dosyası
* @course Veri Yapıları 2A
* @assignment 2. Ödev
* @date 3 Kasım 2017
* @author "Özgür Adem Işıklı<ozgur.isikli@ogr.sakarya.edu.tr>"
*/

#ifndef STACK_HPP 
#define STACK_HPP
#include <iostream>
#include "StackValue.hpp"
#include "BigNumber.hpp"

using namespace std;

class Stack {

    private:
        int count;
        StackValue* top;
        StackValue* CreateValue(BigNumber *number);        
        
    public:
        Stack();
        ~Stack();
        int Count();
        bool IsEmpty();
        void Print();
        void Push(BigNumber *number);
        BigNumber* Get();
        BigNumber* Pop();

};

#endif