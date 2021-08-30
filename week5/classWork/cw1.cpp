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
	void Eat(Fruit f) {
		cout<<this->name<<" eats "<<f.name<<" "<<f.health<<" hp"<<endl;
	}

protected:
	string name = "animal";
};


class Cat: public Animal {
public:
	Cat() {
		name = "Cat";
	}

	void Meow() const {
		cout<<"Meow!"<<endl;
	}

	// void Eat( const Apple& a) const {
	// 	cout<<"Cat eats apple +"<<a.health<<" hp"<<endl;
	// }

	// void Eat( const Orange& a) const {
	// 	cout<<"Cat eats orange +"<<a.health<<" hp"<<endl;
	// }
 };


class Dog :public Animal{
public:
	Dog() {
		name = "Dog";
	}

	// void Eat( const Apple& a) const {
	// 	cout<<"Dog eats apple +"<<a.health<<" hp"<<endl;
	// }

	// void Eat( const Orange& a) const {
	// 	cout<<"Dog eats orange +"<<a.health<<" hp"<<endl;
	// }
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