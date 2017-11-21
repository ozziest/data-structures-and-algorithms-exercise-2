/**
* @file StackValue.hpp
* @description Yığıt üzerinde saklanacak her bir büyük sayı sonucunun struct yapısı
* @course Veri Yapıları 2A
* @assignment 2. Ödev
* @date 3 Kasım 2017
* @author "Özgür Adem Işıklı<ozgur.isikli@ogr.sakarya.edu.tr>"
*/

#ifndef STACK_VALUE_HPP 
#define STACK_VALUE_HPP

#include "BigNumber.hpp"

struct StackValue {
    struct StackValue *left;
    BigNumber *number;
    struct StackValue *right;
};

#endif