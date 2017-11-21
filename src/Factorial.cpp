/**
* @file Factorial.cpp
* @description Büyük sayılar üzerinde faktöriyel işlemlerini gerçekleştirecek olan sınıfın implementasyonu
* @course Veri Yapıları 2A
* @assignment 2. Ödev
* @date 3 Kasım 2017
* @author "Özgür Adem Işıklı<ozgur.isikli@ogr.sakarya.edu.tr>"
*/

#include "Factorial.hpp"
#include "Arithmetic.hpp"
#include "BigNumber.hpp"

Factorial::Factorial() {
    stack = new Stack();

    // Varsayılan olarak 0 faktöriyelin sonucu yığıt üzerine atılıyor.
    // Çünkü sıfırı çıkış için kullandık.
    BigNumber *first = new BigNumber();
    first->SetValue("1");
    stack->Push(first);
}

Factorial::~Factorial() {
    delete stack;

    if (tempStack != NULL) {
        delete tempStack;
    }
}

BigNumber* Factorial::GetLowerResult(int startValue) {
    tempStack = new Stack();
    int stackSize = stack->Count();
    
    // Stack üzerindeki değerleri, üstten başlayarak geçici stack
    // bölmesine aktarıyoruz.
    for (int index = stackSize; index > startValue + 1; index--) {
        BigNumber *number = stack->Pop();
        tempStack->Push(number);
    }

    // Ulaşmak istediğimiz faktöriyel sonucunu alıyoruz.
    BigNumber *result = stack->Get();

    // Yedeğe aktardıklarımızı tekrar ana stack değişkenimize aktarıyoruz.
    for (int index = 1; index < stackSize - startValue; index++) {
        BigNumber *number = tempStack->Pop();
        stack->Push(number);
    }

    return result;
}


BigNumber* Factorial::Calculate(int value) {

    // Eğer faktöriyel değeri istenen değişken, yığıt uzunluğundan küçükse,
    // demek ki bu değeri daha önceden hesaplamışız. O yüzden daha önceden
    // hesaplanan değeri doğrudan geri döndürüyoruz. 
    if (value < stack->Count()) {
        return GetLowerResult(value);
    }

    // Çarpma işlemi için bir aritmetik sınıfı kullanıyoruz.
    // Bu sınıf özel olarak oluşturduğumuz ve büyük sayıları tutmaya 
    // yarayan BigNumber nesnelerini birbirleriyle çarpabiliyor. 
    Arithmetic *math = new Arithmetic();    

    // En son hesaplanan değeri alıyoruz ki aynı hesapları tekrar tekrar yapmayalım.
    BigNumber *result = stack->Get();
    
    for (int index = stack->Count(); index <= value; index++) {
        
        // Üzerinde işlem yapacağımız sayıyı büyük sayı sınıfına aktarıyoruz.
        BigNumber *item = new BigNumber();
        item->SetValue(std::to_string(index));

        // Elimizdeki büyük sayıyı son sonucumuzla çarpıyoruz.
        result = math->Multiply(result, item);

        // Hesaplanan faktöriyel değerini stack üzerine aktarıyoruz.
        stack->Push(result);
    }

    return result;
}

void Factorial::PrintStack() {
    stack->Print();
}