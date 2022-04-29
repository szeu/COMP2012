#include <iostream>
using namespace std;
class Vector {
    int x, y;
    public:
    Vector(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void operator=(const Vector& v) {
        x = v.x;
        y = v.y;
}
};
int main() {
    Vector a(1,2), b(3,4), c(5,6);
    a = b;
}