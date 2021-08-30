

#include <iostream>
using namespace std;




class X {
public:
    void setProtectedMember(int value) {
        protected_ = value;
    }
protected:
    int  protected_;
    void protectedFunction(int value) {
        private_ = value;
    }
private:
    int private_;
};

class Y : public X {
public:
    void setProtected(int value) {
        protected_ = value;
    }
    void getProtected() {
        cout << protected_<< "\n";
    }
    void useProtectedFunction(int value) {
        protectedFunction(value);
    }
};


int main() {

    X x;
    Y y;

    // x.protected_ = 3;   error
    x.setProtectedMember(0);
    // x.useProtectedFunction(5);   //access from outside forbidden

    y.setProtected(1);
    y.useProtectedFunction(1);
    y.getProtected();

    return 0;
}