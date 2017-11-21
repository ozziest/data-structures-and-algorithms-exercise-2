/**
* @file Test.cpp
* @description Uygulamanın genel yürütücüsü.
* @course Veri Yapıları 2A
* @assignment 2. Ödev
* @date 3 Kasım 2017
* @author "Özgür Adem Işıklı<ozgur.isikli@ogr.sakarya.edu.tr>"
*/

#include <iostream>
#include <time.h>
#include "BigNumber.hpp"
#include "Factorial.hpp"

using namespace std;

int main() {

    int userValue;

    Factorial *factorial = new Factorial();
    do {
        
        cout << "Sayi:";
        cin >> userValue;
        
        // Kullanıcıdan eğer 0 değeri gelmişse program sonlandırılır
        if (userValue > 0) {
            clock_t tStart = clock();
            // Faktröriyel hesabı yapılır.
            BigNumber *result = factorial->Calculate(userValue);
            result->Print();
            // Hesaplama süresi ekrana yazdırılır.
            printf("Hesaplama Süresi: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);            
        }

    } 
    while(userValue > 0);    

    cout << "Bellek temizlenerek program sonlandırılıyor...\n";

    delete factorial;
    

    return 0;
}