#include <iostream>
using namespace std;


struct Fruit {
	int health = 0;
	string name = "fruit";
};

struct Apple: public Fruit {
	Apple() {
		health = 10;
		name = "apple";
	}	
};


struct Orange: public Fruit {
	Orange() {
		health = 5;
		name = "orange";
	}
};


class Animal {

public:
	const string name;

	Animal(const string& n ) : name(n) {
	}

	void Eat(Fruit f) {
		cout<<this->name<<" eats "<<f.name<<" "<<f.health<<" hp"<<endl;
	}

// protected:
// 	string name = "animal";
};


class Cat: public Animal {
public:
	Cat() : Animal("Cat"){
	}

	void Meow() const {
		cout<<"Meow!"<<endl;
	}

 };


class Dog :public Animal{
public:
	Dog() : Animal("Dog") {
	}
 };


void MakeMeal(Animal& a, Fruit& f ){
	a.Eat(f);
	// a.name += "***";
}


int main() {

	Cat c;
	c.Meow();
	Apple a;
	Orange o;


	c.Eat(a);
	c.Eat(o);

	Dog d;
	d.Eat(a);
	d.Eat(o);

	MakeMeal(d, a);
	MakeMeal(d, a);
	return 0;
}