#include <iostream>

using namespace std;

class Animal {
public:
    Animal(const string& n) : Name(n) { }

    const string Name;
};


class Dog : public Animal {
public:
    Dog(const string& name) : Animal(name) {}

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};

int main() {
    Dog dog("Tom");
    cout<<dog.Name<<endl;
    dog.Bark();

    return 0;
}