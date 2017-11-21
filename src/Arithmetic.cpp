/**
* @file Arithmetic.cpp
* @description Aritmetik işlemleri gerçekleştiren sınıf.
* @course Veri Yapıları 2A
* @assignment 2. Ödev
* @date 3 Kasım 2017
* @author "Özgür Adem Işıklı<ozgur.isikli@ogr.sakarya.edu.tr>"
*/

#include "Arithmetic.hpp"


BigNumber* Arithmetic::Sum(BigNumber *a, BigNumber *b) {

    // Yeni bir sonuç kümesi oluşturulur
    BigNumber* result = new BigNumber();

    bool isFinished = false;

    // Hesaplamaya en sağdan başlanır
    Digit *firstA = a->Low();
    Digit *firstB = b->Low();

    // Elde bayrağı varsayılan olarak sıfıra ayarlanır
    int carry = 0;
    do {
        
        // Basamak değerleri elde değeriyle birlikte toplanır
        int total = firstA->value + firstB->value + carry;
        // Elde oluşmuşsa daha sonra kullanılmak üzere saklanır
        carry = total / 10;

        // Sonuç bölümüne sadece net değer yazılır. Her basamak 0-9 arasında değer alıyor çünkü.
        // Ayrıca yazım işlemi sağdan sola doğru yazılır
        //        9.999
        // --> (9)9.999
        result->AddToLeft(total % 10);

        // Bir soldaki basamağa gidilir.
        firstA = firstA->left;
        firstB = firstB->left;

        // Eğer her ikisinde de soldaki basamak boşsa hesaplama bitmiş demektir.
        if (firstA == NULL && firstB == NULL) {
            isFinished = true;
        } else if (firstA == NULL) {
            // Eğer sacece birinin soldaki basamağı yoksa, değerlerden biri daha kısa demektir.
            // O halde ona öylesine sıfır sayısını ilave ederiz ki değer doğru bir şekilde hesaplanabilsin.
            firstA = new Digit();
            firstA->value = 0;
            firstA->left = NULL;                    
        } else if (firstB == NULL) {
            // Eğer sacece birinin soldaki basamağı yoksa, değerlerden biri daha kısa demektir.
            // O halde ona öylesine sıfır sayısını ilave ederiz ki değer doğru bir şekilde hesaplanabilsin.
            firstB = new Digit();
            firstB->value = 0;
            firstB->left = NULL;
        }
    } while(isFinished != true);
    
    if (carry > 0) {
        result->AddToLeft(carry);
    }    

    return result;
}


BigNumber* Arithmetic::GetSubMultiply(Digit* start, int value) {
    // Alt çarpım metodunda, bütün bir sayıyı sadece tek bir basamakla çarparız.
    BigNumber* result = new BigNumber();

    // Varsayılan olarak elde 0 olarak ayarlanır. Tüm çarpım işlemlerinde hesaba katılır.
    int carry = 0;
    
    do {
        // Çarpım, elde değeri ilave edilerek bulunur.
        int total = (start->value * value) + carry;
        // Her basamağa 0-9 arası değer yazılabildiğinden elde hesaplanır.
        // Bir sonraki çarpımda (hemen üst satır) bu toplam olarak ilave edilir. 
        carry = total / 10;
        // Sadece toplamın tek basamaklık sağ tarafı sonuca eklenir. Diğeri elde olarak bir sonraki
        // basamağa aktarılacak.
        result->AddToLeft(total % 10);
        // Sonraki basamak çarpımına geçilir.
        start = start->left;
    } while(start != NULL);

    // Eğer tüm işlemlerin sonunda hala "elde" kaldıysa, bunu en sola eklenir.
    if (carry > 0) {
        result->AddToLeft(carry);
    }

    return result;
}

BigNumber* Arithmetic::Multiply(BigNumber *a, BigNumber *b) {

    // Yeni bir sonuç kümesi oluşturulur. Ancak varsayılan olarak sonuçların
    // toplamı sıfır olacak şekilde ayarlanır. Çarpma işleminde çarpanın basamak
    // sayısı kadar alt toplam vardır;
    //      12
    // x    27
    // =======
    //      84  --> 1. basamak, result ile toplanacak ve sonuç result'a aktarılacak.
    //     24   --> 2. basamak, result ile toplanacak ve sonuç result'a aktarılacak. 
    // 
    // *NOT => Ancak ikinci toplamdaki 24 sayısı aslında 240'dır. En sağdaki basamak
    // etkisi olduğu için yazılmaz. Biz yazıp, sola kaydırma derdinden kurtulacağız.
    BigNumber* result = new BigNumber();
    result->SetValue("0");

    // Hesaplamaya en sağdan başlanır
    Digit *multiplicand = a->Low(); // Çarpılan
    Digit *multiplier = b->Low();   // Çarpan

    // Her çarpım işlemini level'e göre sola kaydırmamız gerek. Bunun için
    // sayının sağ tarafına bir 0 ekliyoruz. Ancak kaç tane sıfır ekleyeceğimizi bu
    // değişken aracılığı ile kontrol ediyoruz.    
    // 
    //      12
    // x    27
    // =======
    //      84  [level => 0]
    //    24(0) [level => 1]
    int level = 0;

    do {

        // Alt çarpım bulunur
        BigNumber *row = GetSubMultiply(multiplicand, multiplier->value);

        // Kaçıncı seviye çarpma olduğuna göre sayının sağ tarafında 0 eklenir.
        for (int index = 0; index < level; index++) {
            row->AddToRight(0);
        }

        // Bir alt seviye çarpımla son çarpım toplanır.
        result = Sum(result, row);

        // Level bir arttırılır. Böylece bir sonraki çarpımda örneğin sayı 2 ise
        // 20 ile çarpılmış olur. Yani özetle basamak değerini kaçırmamaya çalışıyoruz.
        level++;

        // Sonraki basamağa geçilir.
        multiplier = multiplier->left;

    } while(multiplier != NULL);
    
    return result;
}