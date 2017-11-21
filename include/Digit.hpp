/**
* @file Digit.hpp
* @description Büyük sayının her bir basamak değerini tutacak olan struct yapısı
* @course Veri Yapıları 2A
* @assignment 2. Ödev
* @date 3 Kasım 2017
* @author "Özgür Adem Işıklı<ozgur.isikli@ogr.sakarya.edu.tr>"
*/

#ifndef DIGIT_HPP 
#define DIGIT_HPP

struct Digit {
    struct Digit *left;
    int value;
    struct Digit *right;
};

#endif