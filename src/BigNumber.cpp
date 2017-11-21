/**
* @file BigNumber.cpp
* @description Büyük bir sayısı dizi olarak tutma işlemini gerçekleştiren sınıf.
* @course Veri Yapıları 2A
* @assignment 2. Ödev
* @date 3 Kasım 2017
* @author "Özgür Adem Işıklı<ozgur.isikli@ogr.sakarya.edu.tr>"
*/

#include "BigNumber.hpp"

BigNumber::BigNumber() {
    low = NULL;
    high = NULL;
}

BigNumber::~BigNumber() {
    if (low != NULL) {
        delete low;        
    }
    if (high != NULL) {
        delete high;        
    }
}

Digit* BigNumber::CreateDigit(int value) {
    Digit* digit = new Digit();
    digit->left = NULL;
    digit->value = value;
    digit->right = NULL;
    return digit;
}

void BigNumber::Print() {
    // 999.999
    // H --> L
    Digit *digit = high;
    do {
        cout << digit->value;
        digit = digit->right;
    } while(digit != NULL);
    cout << "\n\n";
}

void BigNumber::SetValue(string value) {
    // cout << "SetValue: " << value << "\n";
    int lenght = value.size();
    for (int index = 0; index < lenght; index++) {
        AddToRight(atoi(value.substr(index, 1).c_str()));
    }
}

void BigNumber::AddToRight(int value) {
    Digit* digit = CreateDigit(value);

    if (high == NULL) {
        high = digit;
        low = digit;
    } else {
        Digit *first = low;

        digit->left = first;
        first->right = digit;
        low = digit;
    }
}

void BigNumber::AddToLeft(int value) {
    Digit* digit = CreateDigit(value);

    if (high == NULL) {
        high = digit;
        low = digit;
    } else {
        Digit *last = high;

        digit->right = last;
        last->left = digit;
        high = digit;
    }
}

Digit* BigNumber::Low() {
    return low;
}

Digit* BigNumber::High() {
    return high;
}
