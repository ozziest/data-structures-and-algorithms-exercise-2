/**
* @file Stack.cpp
* @description Yığın üzerinde her bir faktöriyel sonucu tutacak olan sınıf.
* @course Veri Yapıları 2A
* @assignment 2. Ödev
* @date 3 Kasım 2017
* @author "Özgür Adem Işıklı<ozgur.isikli@ogr.sakarya.edu.tr>"
*/

#include "Stack.hpp"


Stack::Stack() {
    count = 0;
    top = NULL;
}

Stack::~Stack() {
    if (top != NULL) {
        delete top;        
    }
}

StackValue* Stack::CreateValue(BigNumber *number) {
    StackValue *value = new StackValue();
    value->left = NULL;
    value->number = number;
    value->right = NULL;
    return value;
};

void Stack::Push(BigNumber *number) {
    StackValue *value = CreateValue(number);
    // Eğer en üstte herhangi bir değer yoksa, atanan değeri 
    // doğrudan en üste alıyoruz.
    if (top == NULL) {
        top = value;
    } else {
        // Son eklenini en üstteki değer yapıp gerekli bağlamaları yapıyoruz.
        StackValue *last = top;
        
        value->left = last;
        last->right = value;
        top = value;
    }
    count++;
}

bool Stack::IsEmpty() {
    return top == NULL;
}

int Stack::Count() {
    return count;
}

BigNumber* Stack::Pop() {
    if (top != NULL) {
        // En üstte bir değer varsa, bunu geriye dönüyoruz.
        StackValue *value = top;

        // Ancak hiç değer kalmayana kadar top değişkenini 
        // güncellemek zorundayız.
        if (value->left != NULL) {
            top = value->left;            
        } else {
            top = NULL;
        }

        count --;
        return value->number;
    }

    return new BigNumber();
}

BigNumber* Stack::Get() {
    if (top != NULL) {
        // En üstteki değeri sadece alıyoruz. 
        // Yığın içerisinden kaldırmıyoruz.
        StackValue *value = top;
        return value->number;
    }

    return new BigNumber();
}

void Stack::Print() {
    if (top == NULL) {
        cout << "\n\n";
    } else {
        StackValue *value = top;
        do {
            BigNumber *number = value->number;
            number->Print();
            value = value->left;
        } while(value != NULL);
        cout << "\n\n";    
    }
}