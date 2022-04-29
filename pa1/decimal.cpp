//submit this file only
#include "decimal.h"
using namespace std;
//add your code below
//see FAQ for what you can/cannot do 
Decimal::Decimal(){
    size = 1;
    content = new char[size];
    content[0] = '0';
};

Decimal::Decimal(int input){
    int counter = 0;
    int num = input;
    bool negative = false;
    if(input < 0){
        num = input * -1;
        negative = true;
    }
    else if(input == 0){
        counter = 1;
    }
    while(num >= 1){
        num/=10;
        counter++;
    }
    if(negative){
        num = input * -1;
        size = counter + 1;
        content = new char[size];
        content[0] = '-';
        while(counter > 0){
            char c = '0' + num%10;
            num/=10;
            content[counter--] = c;
        }
    }
    else{
        num = input;
        size = counter;
        content = new char[size];
        while(counter > 0){
            char c = '0' + num%10;
            num/=10;
            content[--counter] = c;
        }
    }    
}; 

Decimal::Decimal(const char* input){
    int counter = 0;
    while(input[counter++]);
    size = --counter;
    content = new char[size];
    for(int i = 0; i < counter; i++){
        content[i] = input[i];
    }
}; 

Decimal::Decimal(const Decimal& another){
    size = another.size;
    content = new char[size];
    for(int i = 0; i < size; i++){
        content[i] = another.content[i];
    }
};

Decimal::~Decimal(){
    delete[] content;
    content = nullptr;
    };

bool Decimal::isNegative() const{
    if(content[0] == '-')
        return true;
    else
        return false;
};

Decimal Decimal::flipSign() const{
    int BUFFERSIZE = size + 1;
    char BUFFER[BUFFERSIZE + 1];
    for(int i = 0; i < BUFFERSIZE; i++)
        BUFFER[i] = '0';
    BUFFER[BUFFERSIZE] = '\0';
    Decimal fliped(BUFFER);
    if(content[0] == '-'){
        fliped.size = size - 1;
        for(int i = 0; i < size-1; i++)
            fliped.content[i] = content[i+1];
    }
    else if(content[0] == '0' && size == 1){
        fliped.size = size;
        fliped.content[0] = content[0];
    }
    else{
        fliped.size = size + 1;
        fliped.content[0] = '-';
        for(int i = size; i > 0; i--)
            fliped.content[i] = content[i-1];
    }
    return fliped;
};

bool Decimal::isLargerThan(const Decimal& another) const{
    if(content[0] != '-' && another.content[0] == '-')
        return true;
    else if(content[0] == '-' && another.content[0] != '-')
        return false;
    else if(content[0] == '-' && another.content[0] == '-'){            //both negative
        if(countDigitsBeforeDP() < another.countDigitsBeforeDP())       //shorter digits be4 dot
            return true;                                                //is laregr
        else if(countDigitsBeforeDP() > another.countDigitsBeforeDP())
            return false;                                               //longer is smaller
        else{
            int digitsbe4 = countDigitsBeforeDP();          //but when the length is the same
            for(int i = 1; i < digitsbe4 + 1; i++){             //find the value of each digit
                if(content[i] < another.content[i])                     //once it is smaller detected first
                    return true;                                        //is larger
                if(content[i] > another.content[i])
                    return false;                                       //but if detected larger first -> smaller
            }                                                           //after testing all digits be4 dot but they are the same
            int digitafter = (countDigitsAfterDP() < another.countDigitsAfterDP())? countDigitsAfterDP() : another.countDigitsAfterDP();
            for(int j = 0; j < digitafter; j++){                        //test digits after (shorter one) dot one by one
                if(content[digitsbe4+2+j] < another.content[digitsbe4+2+j])     //if first detect smaller -> larger
                    return true;
                if(content[digitsbe4+2+j] > another.content[digitsbe4+2+j])     //otherwise, smaller
                    return false;
            }                                                                   //if it is still no result meaning that particular legth digit, the same value again
            if(countDigitsAfterDP() < another.countDigitsAfterDP()){    //use the length difference of digits after
                return true;
            }
            else{
                return false;   //but if after all testing still no result -> both content the same -> return false
            }
        }
    }
    else if(content[0] != '-' && another.content[0] != '-'){            //both positive
        if(countDigitsBeforeDP() < another.countDigitsBeforeDP())
            return false;
        else if(countDigitsBeforeDP() > another.countDigitsBeforeDP())
            return true;
        else{
            int digitsbe4 = countDigitsBeforeDP();
            for(int i = 0; i < digitsbe4; i++){
                if(content[i] < another.content[i])
                    return false;
                if(content[i] > another.content[i])
                    return true;
            }
            int digitafter = (countDigitsAfterDP() < another.countDigitsAfterDP())? countDigitsAfterDP() : another.countDigitsAfterDP();
            for(int j = 0; j < digitafter; j++){
                if(content[digitsbe4+1+j] < another.content[digitsbe4+1+j])
                    return false;
                if(content[digitsbe4+1+j] > another.content[digitsbe4+1+j])
                    return true;
            }
            if(countDigitsAfterDP() > another.countDigitsAfterDP()){
                return true;
            }
            else{
                return false;
            }
        }
    }
    return false;
};

Decimal Decimal::add(const Decimal& another) const{
    int BUFFER_BEFORE = (countDigitsBeforeDP() > another.countDigitsBeforeDP())? countDigitsBeforeDP() : another.countDigitsBeforeDP(); 
    int BUFFER_AFTER = (countDigitsAfterDP() > another.countDigitsAfterDP())? countDigitsAfterDP() : another.countDigitsAfterDP(); 
    int BUFFERSIZE = BUFFER_BEFORE + BUFFER_AFTER + 3;
    char BUFFER[BUFFERSIZE + 1];
    for(int i = 0; i < BUFFERSIZE; i++)
        BUFFER[i] = '0';
    BUFFER[BUFFERSIZE] = '\0';
    Decimal sum(BUFFER);
    Decimal *self, *other, *flipNegative, *subtractResult; 
    bool carry = false, decimal = false, removeExtra0 = false, addNegative = false;
    int lastIndex, firstIndex, length = 0;
    int self_digitsAfter, other_digitsAfter, self_digitsBefore, other_digitsBefore;
    if(content[0] != '-' && another.content[0] == '-'){         //self(+), another(-)
        flipNegative = new Decimal(another.flipSign());         //flip another
        subtractResult = new Decimal(subtract(*flipNegative));  //sum = self - (+)another
        Decimal result(*subtractResult);
        delete flipNegative;
        delete subtractResult;
        return result;
    }
    else if(content[0] == '-' && another.content[0] != '-'){    //self(-), another(+)
        flipNegative = new Decimal(flipSign());                 //flip self
        subtractResult = new Decimal(another.subtract(*flipNegative));      //sum = another - (+)self
        Decimal result(*subtractResult);
        delete flipNegative;
        delete subtractResult;
        return result;
    }
    else{
        if(content[0] != '-' && another.content[0] != '-'){    //self(+), another(+)
            addNegative = false;
            self = new Decimal(*this);
            other = new Decimal(another);
        }
        else{                                                       //self(-), another(-)
            addNegative = true;
            self = new Decimal(flipSign());
            other = new Decimal(another.flipSign());
        }
        self_digitsAfter = self->countDigitsAfterDP();
        other_digitsAfter = other->countDigitsAfterDP();
        self_digitsBefore = self->countDigitsBeforeDP();
        other_digitsBefore = other->countDigitsBeforeDP();
        if(self_digitsAfter > other_digitsAfter){        //compare length after dot
            lastIndex = self_digitsAfter;                           //and pud extra digit to sum
            decimal = true;     //when there is different, meaning the sum must have decimal place
            do{
                for(int i = 0; i < length; i++)     //move one place rightward to empty [0]
                    sum.content[length - i] = sum.content[length - 1 - i];
                length++;       //the sum content array have one more digit added
                sum.content[0] = self->content[self->size - length];    //add pud to [0]
                lastIndex--;    //indicate finish pudded one digit
            }while(lastIndex > other_digitsAfter);
        }
        else if(self_digitsAfter < other_digitsAfter){
            lastIndex = other_digitsAfter;
            decimal = true;
            do{
                for(int i = 0; i < length; i++)
                    sum.content[length - i] = sum.content[length - 1 - i];
                length++;
                sum.content[0] = other->content[other->size - length];
                lastIndex--;
            }while(lastIndex > self_digitsAfter);
        }
        else{
            lastIndex = self_digitsAfter;   //condition when both have the same no. of decimal places
            if(lastIndex != 0)                      //or, both are integers with lastIndex = 0
                decimal = true;
        }
        while(lastIndex > 0){   //calculate the sum of values at duplicated index and put it into sum[0]
            for(int i = 0; i < length; i++)
                    sum.content[length - i] = sum.content[length - 1 - i];
            int add = self->content[self_digitsBefore + lastIndex] + other->content[other_digitsBefore + lastIndex];
            add = add - '0' - '0';
            if(carry){
                add++;
                carry = false;
            }
            if(add >= 10){
                carry = true;
                add-=10;
            }
            length++;
            sum.content[0] = add + '0';
            lastIndex--;
        }   //until all decimal places are placed
        if(decimal){    //test whether the sum have decimal places
            for(int i = 0; i < length; i++)
                    sum.content[length - i] = sum.content[length - 1 - i];
            length++;
            sum.content[0] = '.';
            removeExtra0 = true;
        }
        firstIndex = (self_digitsBefore > other_digitsBefore)? self_digitsBefore : other_digitsBefore;
        int differentIndex = (self_digitsBefore > other_digitsBefore)? self_digitsBefore - other_digitsBefore : other_digitsBefore - self_digitsBefore;
        while(firstIndex > 0){
            for(int i = 0; i < length; i++)
                sum.content[length - i] = sum.content[length - 1 - i];
            int add;
            if(self_digitsBefore > other_digitsBefore){
                if((firstIndex - differentIndex) > 0)
                    add = self->content[firstIndex - 1] + other->content[firstIndex - differentIndex - 1] - '0' - '0';
                else
                    add = self->content[firstIndex - 1] - '0';
            }
            else if(self_digitsBefore < other_digitsBefore){
                if((firstIndex - differentIndex) > 0)
                    add = self->content[firstIndex - differentIndex - 1] + other->content[firstIndex - 1] - '0' - '0';
                else
                    add = other->content[firstIndex - 1] - '0';
            }
            else{
                add = self->content[firstIndex - 1] + other->content[firstIndex - 1] - '0' - '0';
            }
            if(carry){
                add++;
                carry = false;
            }
            if(add >= 10){
                carry = true;
                add-=10;
            }
            length++;
            sum.content[0] = add + '0';
            firstIndex--;
        }
        if(carry){
            for(int i = 0; i < length; i++)
                    sum.content[length - i] = sum.content[length - 1 - i];
            sum.content[0] = '1';
            length++;
            carry = false;
        }
        if(addNegative){
            for(int i = 0; i < length; i++)
                    sum.content[length - i] = sum.content[length - 1 - i];
            sum.content[0] = '-';
            length++;
            addNegative = false;
        }
        while(removeExtra0){
            if(sum.content[length - 1] == '0')
                length--;
            else if(sum.content[length - 1] == '.'){
                length--;
                break;
            }
            else 
                break;
        }
        sum.size = length;
        delete self;
        delete other;
    }
    return sum;
};

void Decimal::addToSelf(const Decimal& another){
    Decimal temp(add(another));
    delete[] this->content;     
    this->size = temp.size;
    this->content = new char[this->size];
    for(int i = 0; i < this->size; i++){
        this->content[i] = temp.content[i];
    }
}; 

Decimal Decimal::multiplyByPowerOfTen(int power) const{
    int BUFFERSIZE = size + power;
    char BUFFER[BUFFERSIZE + 1];
    for(int i = 0; i < BUFFERSIZE; i++)
        BUFFER[i] = '0';
    BUFFER[BUFFERSIZE] = '\0';
    Decimal product(BUFFER);
    for(int j = 0; j < size; j++)
        product.content[j] = content[j];
    product.size = size;
    if(power == 0)
        return *this;
    int lastIndex = product.countDigitsAfterDP();
    if(lastIndex > 0){
        int dotIndex;
        while(lastIndex > 0 && power > 0){
            for(int j = 0; j < product.size; j++){
                if(product.content[j] == '.'){
                    dotIndex = j;
                    break;
                }
            }
            char temp = product.content[dotIndex + 1];
            product.content[dotIndex + 1] = '.';
            product.content[dotIndex] = temp;
            lastIndex--;
            power--;
        }
        if(lastIndex == 0)
            product.size--;
    }
    while(power > 0){
        product.content[product.size] = '0';
        product.size++;
        power--;
    }
    return product;
};

Decimal Decimal::multiplyBySingleDigit(int multiplier) const{
    Decimal product;
    if(multiplier == 0)
        return product;
    int lastIndex = countDigitsAfterDP(), firstIndex = countDigitsBeforeDP(), currentIndex = size - 1;
    bool addNegative = false;
    if(content[0] == '-')
        addNegative = true;
    if(lastIndex > 0){
        while(lastIndex > 0){
            int indexProduct = (content[currentIndex] - '0')* multiplier, counter = 0;
            while(indexProduct >= 1){
                indexProduct/=10;
                counter++;
            }
            indexProduct = (content[currentIndex] - '0')* multiplier;
            char char_form[lastIndex + 3];
            char_form[lastIndex + 2] = '\0';
            if(counter == 2){
                if(lastIndex != 1){
                    char_form[lastIndex + 1] = indexProduct%10 + '0';
                    char_form[lastIndex] = indexProduct/10 + '0';
                    for(int i = 2; i < lastIndex; i++)
                        char_form[i] = '0';
                    char_form[1] = '.';
                    char_form[0] = '0';
                }
                else{
                    char_form[2] = indexProduct%10 + '0';
                    char_form[1] = '.';
                    char_form[0] = indexProduct/10 + '0';
                }
            }
            else{
                char_form[lastIndex + 1] = indexProduct + '0';
                for(int i = 2; i < lastIndex + 1; i++)
                    char_form[i] = '0';
                char_form[1] = '.';
                char_form[0] = '0'; 
            }
            Decimal iProduct(char_form);
            product.addToSelf(iProduct);
            lastIndex--;
            currentIndex--;
        }
        currentIndex--;
    }
    int m = 0;
    while(m < firstIndex){
        int indexProduct = (content[currentIndex] - '0')* multiplier;
        Decimal iProduct(indexProduct);
        product.addToSelf(iProduct.multiplyByPowerOfTen(m));
        m++;
        currentIndex--;
    }
    if(addNegative){
        char temp_content[product.size+1];
        for(int i = 1; i < product.size+1; i++)
            temp_content[i] = product.content[i-1];
        temp_content[0] = '-';
        delete[] product.content;
        product.size = product.size + 1;
        product.content = new char[product.size];
        for(int n = 0; n < product.size; n++){
            product.content[n] = temp_content[n];
        }
    }   
    return product;
};

Decimal Decimal::multiply(const Decimal& another) const{
    Decimal finalProduct;
    if(another.content[0] == '0' && another.size == 1)
        return finalProduct;
    int self_lastIndex = countDigitsAfterDP();
    int another_lastIndex = another.countDigitsAfterDP(), another_index = another.countDigitsBeforeDP() + another_lastIndex;
    Decimal *self;
    Decimal *other;
    bool addNegative = false;
    if(content[0] != '-' && another.content[0] != '-'){
        self = new Decimal(multiplyByPowerOfTen(self_lastIndex));
        other = new Decimal(another.multiplyByPowerOfTen(another_lastIndex));
        addNegative = false;
    }
    else if(content[0] == '-' && another.content[0] == '-'){
        self = new Decimal(flipSign().multiplyByPowerOfTen(self_lastIndex));
        other = new Decimal(another.flipSign().multiplyByPowerOfTen(another_lastIndex));
        addNegative = false;
    }
    else if(content[0] != '-' && another.content[0] == '-'){
        self = new Decimal(multiplyByPowerOfTen(self_lastIndex));
        other = new Decimal(another.flipSign().multiplyByPowerOfTen(another_lastIndex));
        addNegative = true;
    }
    else{
        self = new Decimal(flipSign().multiplyByPowerOfTen(self_lastIndex));
        other = new Decimal(another.multiplyByPowerOfTen(another_lastIndex));
        addNegative = true;
    }
    for(int i = 0; i < other->size; i++){
        int multiplier = other->content[i] - '0';
        Decimal product(self->multiplyBySingleDigit(multiplier));
        if(another_index == 0)
            continue;
        Decimal mulBy10(product.multiplyByPowerOfTen(--another_index));
        finalProduct.addToSelf(mulBy10);
    }
    if(self_lastIndex != 0 || another_lastIndex != 0){
        char temp_content[finalProduct.size+1];
        for(int i = 0; i < finalProduct.size; i++)
            temp_content[i] = finalProduct.content[i];
        delete[] finalProduct.content;
        finalProduct.content = new char[finalProduct.size+1];
        for(int n = 0; n < finalProduct.size; n++){
            finalProduct.content[n] = temp_content[n];
        }
        for(int i = 0; i < self_lastIndex + another_lastIndex; i++)
            finalProduct.content[finalProduct.size - i] = finalProduct.content[finalProduct.size - 1 - i]; //////
        finalProduct.content[finalProduct.size - (self_lastIndex + another_lastIndex)] = '.';
        finalProduct.size++;
        while(finalProduct.countDigitsAfterDP() > 0){
            if(finalProduct.content[finalProduct.size - 1] == '0')
                finalProduct.size--;
            else if(finalProduct.content[finalProduct.size - 1] == '.'){
                finalProduct.size--;
                break;
            }
            else 
                break;
        }
    }
    if(addNegative){
        char temp_content[finalProduct.size+1];
        for(int i = 1; i < finalProduct.size+1; i++)
            temp_content[i] = finalProduct.content[i-1];
        temp_content[0] = '-';
        delete[] finalProduct.content;
        finalProduct.size = finalProduct.size + 1;
        finalProduct.content = new char[finalProduct.size];
        for(int n = 0; n < finalProduct.size; n++){
            finalProduct.content[n] = temp_content[n];
        }
    }
    if(finalProduct.content[finalProduct.size - 1] == '.'){
        finalProduct.size--;
    }    
    delete self;
    delete other;
    return finalProduct;
};

Decimal Decimal::subtract(const Decimal& another) const{
    int BUFFER_BEFORE = (countDigitsBeforeDP() > another.countDigitsBeforeDP())? countDigitsBeforeDP() : another.countDigitsBeforeDP(); 
    int BUFFER_AFTER = (countDigitsAfterDP() > another.countDigitsAfterDP())? countDigitsAfterDP() : another.countDigitsAfterDP(); 
    int BUFFERSIZE = BUFFER_BEFORE + BUFFER_AFTER + 3;
    char BUFFER[BUFFERSIZE + 1];
    for(int i = 0; i < BUFFERSIZE; i++)
        BUFFER[i] = '0';
    BUFFER[BUFFERSIZE] = '\0';
    Decimal sub(BUFFER);
    Decimal *self, *other, *flipNegative, *addResult; 
    bool carry = false, decimal = false, removeExtra0 = false, addNegative = false;
    int lastIndex, firstIndex, length = 0;
    int self_digitsAfter, other_digitsAfter, self_digitsBefore, other_digitsBefore;
    if(content[0] != '-' && another.content[0] == '-'){         //self(+), another(-)
        flipNegative = new Decimal(another.flipSign());         //flip another
        addResult = new Decimal(add(*flipNegative));            //subtract = self + (+)another
        Decimal result = *addResult;
        delete flipNegative;
        delete addResult;
        return result;
    }
    else if(content[0] == '-' && another.content[0] != '-'){    //self(-), another(+)
        flipNegative = new Decimal(another.flipSign());                 //flip self
        addResult = new Decimal(add(*flipNegative));    //sub = self + (-)another
        Decimal result = *addResult;
        delete flipNegative;
        delete addResult;
        return result;
    }
    else{
        if(content[0] != '-' && another.content[0] != '-'){
            if(isLargerThan(another)){   //self always larger than other
                addNegative = false;
                self = new Decimal(*this);
                other = new Decimal(another);
            }
            else{
                addNegative  = true;
                self = new Decimal(another);
                other = new Decimal(*this);
            }   
        }
        else{
            if((flipSign()).isLargerThan(another.flipSign())){   //self always larger than other
                addNegative = true;
                self = new Decimal(flipSign());
                other = new Decimal(another.flipSign());
            }
            else{
                addNegative  = false;
                self = new Decimal(another.flipSign());
                other = new Decimal(flipSign());
            }
        }
        self_digitsAfter = self->countDigitsAfterDP();
        other_digitsAfter = other->countDigitsAfterDP();
        self_digitsBefore = self->countDigitsBeforeDP();
        other_digitsBefore = other->countDigitsBeforeDP();
        if(self_digitsAfter > other_digitsAfter){      //8.97-2.6
            lastIndex = self_digitsAfter;
            decimal = true;
            do{
                for(int i = 0; i < length; i++)
                    sub.content[length - i] = sub.content[length - 1 - i];
                length++;
                sub.content[0] = self->content[self->size - length];
                lastIndex--;
            }while(lastIndex > other_digitsAfter);
        }
        else if(self_digitsAfter < other_digitsAfter && self_digitsAfter != 0){    //8.9-2.67
            lastIndex = other_digitsAfter;
            decimal = true;
            int differentIndex = other_digitsAfter - self_digitsAfter;
            char temp_self_content[self->size + differentIndex];
            for(int j = 0; j < self->size; j++)
                temp_self_content[j] = self->content[j];
            for(int j = 0; j < differentIndex; j++)
                temp_self_content[self->size + j] = '0';
            delete[] self->content;
            self->content = new char[self->size + differentIndex];
            for(int n = 0; n < self->size + differentIndex; n++)
                self->content[n] = temp_self_content[n];
            self->size = self->size + differentIndex;                  
        }
        else if(self_digitsAfter < other_digitsAfter && self_digitsAfter == 0){    //325-8.97
            lastIndex = other_digitsAfter;
            decimal = true;
            int differentIndex = other_digitsAfter - self_digitsAfter;
            char temp_self_content[self->size + differentIndex + 1];
            for(int j = 0; j < self->size; j++)
                temp_self_content[j] = self->content[j];
            temp_self_content[self->size] = '.';
            for(int j = 0; j < differentIndex; j++)
                temp_self_content[self->size + j + 1] = '0';
            delete[] self->content;
            self->content = new char[self->size + differentIndex + 1];
            for(int n = 0; n < self->size + differentIndex + 1; n++)
                self->content[n] = temp_self_content[n];
            self->size = other->size;
        }
        else{
            lastIndex = self_digitsAfter;   //325-100 (decimal = false), 5.43-2.45 (decimal = true)
            if(lastIndex != 0)
                decimal = true;
        }
        //start calculation value at same length
        while(lastIndex > 0){
            for(int i = 0; i < length; i++)
                sub.content[length - i] = sub.content[length - 1 - i];
            int minus = 0;
            if(carry){
                minus--;
                carry = false;
            }
            if(self->content[self_digitsBefore + lastIndex] < other->content[other_digitsBefore + lastIndex]){
                carry = true;
                minus += ((10 + self->content[self_digitsBefore + lastIndex]) - other->content[other_digitsBefore + lastIndex]);
            }
            else{
                minus += self->content[self_digitsBefore + lastIndex] - other->content[other_digitsBefore + lastIndex];
            }
            length++;
            sub.content[0] = minus + '0';
            lastIndex--;
        }
        if(decimal){    //test whether the sum have decimal places
            for(int i = 0; i < length; i++)
                sub.content[length - i] = sub.content[length - 1 - i];
            length++;
            sub.content[0] = '.';
            removeExtra0 = true;
        }
        firstIndex = self_digitsBefore;
        int duplicatedIndex = other_digitsBefore;
        while(firstIndex > 0){
            for(int i = 0; i < length; i++)
                sub.content[length - i] = sub.content[length - 1 - i];
            int minus = 0;
            if(carry){
                minus--;
                carry = false;
            }
            if(duplicatedIndex > 0){
                if(self->content[firstIndex - 1] < other->content[duplicatedIndex - 1]){
                    carry = true;
                    minus += ((10 + self->content[firstIndex - 1]) - other->content[duplicatedIndex - 1]);
                }
                else
                    minus += self->content[firstIndex - 1] - other->content[duplicatedIndex - 1];
            }
            else{
                minus += self->content[firstIndex - 1] - '0';
                if(minus < 0){
                    carry = true;
                    minus += 10;
                }
            }
            duplicatedIndex--;
            length++;
            sub.content[0] = minus + '0';
            firstIndex--;
        }
        while(sub.content[0] == '0' && length > 1){
            if(sub.content[1] == '.')
                break;
            for(int i = 0; i < length - 1; i++)
                sub.content[i] = sub.content[i+1];
            length--;
        }
        while(removeExtra0){
            if(sub.content[length - 1] == '0')
                length--;
            else if(sub.content[length - 1] == '.'){
                length--;
                break;
            }
            else 
                break;
        }
        if(addNegative && (sub.content[0] != '0' || length > 1)){
            for(int i = 0; i < length; i++)
                sub.content[length - i] = sub.content[length - 1 - i];
            sub.content[0] = '-';
            length++;
            addNegative = false;
        }
        sub.size = length;
        delete self;
        delete other;
    }
    return sub;
};

int Decimal::countDigitsBeforeDP() const{
    int index;
    for(index = 0; index < size; index++){
        if(content[index] == '.')
            break;
    }
    if(content[0] == '-'){
        return index - 1;
    }
    return index;
};

int Decimal::countDigitsAfterDP() const{
    int index;
    for(index = 0; index < size; index++){
        if(content[index] == '.')
            break;
    }
    if(index == size)
        return 0;
    return size - index - 1;
};