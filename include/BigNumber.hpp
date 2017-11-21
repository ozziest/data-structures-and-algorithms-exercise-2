/**
* @file BigNumber.hpp
* @description Büyük bir sayıyı dizi olarak tutacak olan sınıfın başlık bilgileri.
* @course Veri Yapıları 2A
* @assignment 2. Ödev
* @date 3 Kasım 2017
* @author "Özgür Adem Işıklı<ozgur.isikli@ogr.sakarya.edu.tr>"
*/

#ifndef BIG_NUMBER_HPP 
#define BIG_NUMBER_HPP
#include <iostream>
#include "Digit.hpp"

using namespace std;

class BigNumber {

    private:
        bool logStatus;
        Digit* low;
        Digit* high;            
        Digit* CreateDigit(int value);

    public:
        BigNumber();
        ~BigNumber();
        void SetValue(string value);
        void AddToRight(int value);
        void AddToLeft(int value);
        void Print();
        Digit* Low();
        Digit* High();

};

#endif