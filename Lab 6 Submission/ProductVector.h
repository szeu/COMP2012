#ifndef PRODUCTVECTOR_H
#define PRODUCTVECTOR_H

#include <iostream>
#include "Product.h"
using namespace std;

template <typename T> class ProductVector
{
    private:
        T* data;
        int capacity;
        int length;

    public:
        ProductVector(int n = 1) : data(new T[n]), capacity(n), length(0) {}

        // Add the new element to the back.
        void push_back(const T& s) {
            if (capacity <= length) {
                T* temp = new T[capacity * 2];
                for (int i = 0; i < length; i++){
                    temp[i] = data[i];
                }
                delete[] data;
                data = temp;
                capacity *= 2;
            }

            data[length] = s;
            length++;
        }

        void remove(int x) {
            for (int i = x+1; i < length; i++) {
                data[i - 1] = data[i];
            }
            length--;
        }

        int size() const{ return length; }

        void swap(int i, int j) {
            T temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }

        ~ProductVector() {
            if (data) {
                delete[] data;
            }
        }

    /* ===================================================================
        TODO: operator overloading and make member functions
              Refer to the main.cpp.
       =================================================================== */
    
    // TODO: Copy constructor: Perform deep copying
	// Hint: Make use of assignment operator function `operator=`
    ProductVector(const ProductVector<T>& other){
        *this = other;
    }
    // TODO: Remove get_value() fuction and Overload `operator[]` to get the i-th element of vector
    // Hint: 'get_value(i)' will be changed like 'data[i]'
    T operator[](int i){
        return data[i];
    }
    // TODO: Complete sort fuction by ascending order.
    // Hint: Use > operator and swap fuction
    void sort(){
        int i, j;
        bool swapped;
        for (i = 0; i < length-1; i++){
            swapped = false;
            for (j = 0; j < length-i-1; j++){
                if (data[j] > data[j+1]){
                    swap(j, j+1);
                    swapped = true;
                }
            }
            if(swapped == false)
                break;
        }
    }
    // TODO: Complete isExsit fuction and 
    // Hint: Use == operator, if the parameter is in the ProductVector return true or opposite
    template <typename V>
    bool isExist(const V& v) const{
        for(int i = 0; i < capacity; i++){
            if(data[i] == v)
                return true;
        }
        return false;
    }

    // TODO: Overload `operator=` to replace with ProductVector<T> paramenter
    // Hint: Deep copying is required
    // The existing data is replaced as the same elements of parameter.
    // It will be used like A(ProductVector<Book> type) = B(ProductVector<Book> type)
    const ProductVector<T>& operator=(const ProductVector<T>& t){
        if(data){
            delete[] data;
            data = new T[t.capacity];
            for(int i = 0; i < t.capacity; i++)
                data[i] = t.data[i];
        }
        capacity = t.capacity;
        length = t.length;
        return *this;
    }
};

#endif
