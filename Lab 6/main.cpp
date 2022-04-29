#include <iostream>
#include <string>

#include "Book.h"
#include "Toy.h"
#include "ProductVector.h"
using namespace std;

int main() {
    cout << "1. Make vectors and test" << endl;
    cout << "===================================== " << endl;
    cout << endl;
    
    cout << "1-1 Type1 int " << endl;
    ProductVector<int> int_vector;
    int_vector.push_back(3);
    int_vector.push_back(9);
    int_vector.push_back(2);
    int_vector.push_back(8);
    int_vector.push_back(6);
    int_vector.push_back(5);

    cout << "int_vector[1]: " << int_vector[1] << endl;
    cout << "size: " << int_vector.size() << endl;

    cout << "===================================== " << endl;
    cout << endl;
    cout << "1-2 Type2 Book " << endl;
    ProductVector<Book> book_vector;

    book_vector.push_back(Book(1000.0, "Book 1", "Fiction", "ABC publisher", 1));
    book_vector.push_back(Book(200.0, "Book 2", "Fiction", "ABC publisher", 0.9));
    book_vector.push_back(Book(700.0, "Book 3", "Fiction", "ABC publisher", 0.3));
    book_vector.push_back(Book(400.0, "Book 4", "Fiction", "ABC publisher", 0.7));
    book_vector.push_back(Book(500.0, "Book 5", "Fiction", "ABC publisher", 0.5));
    
    cout << "book_vector[1]: " << book_vector[1] << endl;
    cout << "size: " << book_vector.size() << endl;

    cout << "===================================== " << endl;
    cout << endl;
    cout << "1-3 Type3 Toy " << endl;
    ProductVector<Toy> toy_vector;
    toy_vector.push_back(Toy(200, "Unicorn", "CCC Manufacturer", false));
    toy_vector.push_back(Toy (800, "Spider", "CCC Manufacturer", true));
    toy_vector.push_back(Toy(100, "Snake", "CCC Manufacturer", true));
    toy_vector.push_back(Toy(500, "Lion", "CCC Manufacturer", false));
    
    cout << "toy_vector[1]: " << toy_vector[1] << endl;
    cout << "size: " << toy_vector.size() << endl;

    cout << "===================================== " << endl;
    cout << "===================================== " << endl;
    cout << endl;
    cout << "2. Compare price using operator overloading" << endl;
    cout << "compare : " << int_vector[0] << " " << int_vector[1] << endl;
    cout << ((int_vector[0] > int_vector[1]) ? int_vector[0] : int_vector[1]) << " is bigger." << endl;
    
    cout << "compare : " << book_vector[0] << " " << book_vector[1] << endl;
    cout << ((book_vector[0] > book_vector[1]) ? book_vector[0] : book_vector[1]) << " is expensive." << endl;
    
    cout << "compare : " << toy_vector[0] << " " << toy_vector[1] << endl;
    cout << ((toy_vector[0] > toy_vector[1]) ? toy_vector[0] : toy_vector[1]) << " is expensive." << endl;

    cout << "compare : " << book_vector[0] << " " << toy_vector[1] << endl;
    cout << ((book_vector[0] > toy_vector[1]) ? book_vector[0].get_product_name() : toy_vector[1].get_product_name()) << " is expensive." << endl;

    cout << "compare : " << toy_vector[0] << " " << book_vector[1] << endl;
    cout << ((toy_vector[0] > book_vector[1]) ? toy_vector[0].get_product_name() : book_vector[1].get_product_name()) << " is expensive." << endl;

    cout << "compare : " << book_vector[0] << " " << 300 << endl;
    cout << ((book_vector[0] > 300) ? book_vector[0].get_product_name() : "300") << " is expensive." << endl;
    
    cout << "compare : " << toy_vector[0] << " " << 800 << endl;
    cout << ((toy_vector[0] > 800) ? toy_vector[0].get_product_name() : "800") << " is expensive." << endl;

    cout << "===================================== " << endl;
    cout << "===================================== " << endl;
    cout << endl;
    cout << "3. Sorting " << endl;

    cout << "3-1 before sorting int_vector " << endl;
    for (int i = 0; i < int_vector.size(); i++) {
        cout << int_vector[i] << " ";
    }

    cout << endl;
    cout << "after sorting int_vector " << endl;
    int_vector.sort();
    for (int i = 0; i < int_vector.size(); i++) {
        cout << int_vector[i] << " ";
    }
    cout << endl;
    cout << "===================================== " << endl;
    cout << endl;

    cout << "3-2 before sorting book_vector " << endl;
    for (int i = 0; i < book_vector.size(); i++) {
        cout << book_vector[i] << " ";
        cout << book_vector[i].get_retail_price() << " ";
        cout << endl;
    }
    
    cout << endl;
    cout << "after sorting book_vector " << endl;
    book_vector.sort();
    for (int i = 0; i < book_vector.size(); i++) {
        cout << book_vector[i] << " ";
        cout << book_vector[i].get_retail_price() << " ";
        cout << endl;
    }

    cout << endl;
    cout << "===================================== " << endl;
    cout << endl;

    cout << "3-3 before sorting toy_vector " << endl;
    for (int i = 0; i < toy_vector.size(); i++) {
        cout << toy_vector[i] << " ";
        cout << toy_vector[i].get_retail_price() << " ";
        cout << endl;
    }
    
    cout << endl;
    cout << "after sorting toy_vector " << endl;
    toy_vector.sort();
    for (int i = 0; i < toy_vector.size(); i++) {
        cout << toy_vector[i] << " ";
        cout << toy_vector[i].get_retail_price() << " ";
        cout << endl;
    }

    cout << "===================================== " << endl;
    cout << "===================================== " << endl;
    cout << endl;
    cout << "4. isExist " << endl;

    cout << "9 is in the int_vector: " << (int_vector.isExist(9)? "Yes" : "No") << endl;
    cout << "13 is in the int_vector: " << (int_vector.isExist(13)? "Yes" : "No") << endl;
    cout << "Book 4 is in the book_vector: " << (book_vector.isExist("Book 4")? "Yes" : "No") << endl;
    cout << "c++ is in the book_vector: " << (book_vector.isExist("c++")? "Yes" : "No") << endl;
    cout << "Duck is in the toy_vector: " << (toy_vector.isExist("Duck")? "Yes" : "No") << endl;
    cout << "Lion is in the toy_vector: " << (toy_vector.isExist("Lion")? "Yes" : "No") << endl;

    cout << "===================================== " << endl;
    cout << "===================================== " << endl;
    cout << endl;
    cout << "5. Modify vector " << endl;
    ProductVector<Book> book_vector2;

    for (int i = 0; i < 4; i++) {
        book_vector2.push_back(Book(i*150.0, "Book_" + to_string(i * 10), "SF", "HKUST publisher", 0.1*i));
    }

    for (int i = 0; i < book_vector2.size(); i++) {
        cout << book_vector2[i] << " ";
        cout << book_vector2[i].get_retail_price() << " ";
        cout << endl;
    }

    cout << endl;
    cout << "========== update book_vector============" << endl;
    cout << endl;
    book_vector = book_vector2;
    for (int i = 0; i < book_vector.size(); i++) {
        cout << book_vector[i] << " ";
        cout << book_vector[i].get_retail_price() << " ";
        cout << endl;
    }
    
    return 0;
}