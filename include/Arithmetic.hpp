/**
* @file Arithmetic.hpp
* @description Aritmetik işlemlerini yapan sınıfın başlık dosyası
* @course Veri Yapıları 2A
* @assignment 2. Ödev
* @date 3 Kasım 2017
* @author "Özgür Adem Işıklı<ozgur.isikli@ogr.sakarya.edu.tr>"
*/

#ifndef ARITHMETIC_HPP 
#define ARITHMETIC_HPP
#include <iostream>
#include "BigNumber.hpp"

using namespace std;

class Arithmetic {

    private:
        BigNumber* GetSubMultiply(Digit* start, int value);
        
    public:

        BigNumber* Sum(BigNumber *a, BigNumber *b);
        BigNumber* Multiply(BigNumber *a, BigNumber *b);

};

#endif