/**
* @file Factorial.hpp
* @description Büyük sayılar üzerinde faktöriyel işlemini gerçekleştirecek olan sınıfın başlık dosyası
* @course Veri Yapıları 2A
* @assignment 2. Ödev
* @date 3 Kasım 2017
* @author "Özgür Adem Işıklı<ozgur.isikli@ogr.sakarya.edu.tr>"
*/

#ifndef FACTORIAL_HPP 
#define FACTORIAL_HPP
#include <iostream>
#include "BigNumber.hpp"
#include "Stack.hpp"

using namespace std;

class Factorial {

    private:
        Stack *stack;
        Stack *tempStack;
        BigNumber* GetLowerResult(int startValue);
        
    public:
        Factorial();
        ~Factorial();
        BigNumber* Calculate(int value);
        void PrintStack();

};

#endif