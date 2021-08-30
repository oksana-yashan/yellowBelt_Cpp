#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Person {
public:

    Person(string& name, const string& job) : Name(name), Job(job) { }

    virtual void Walk(string& destination) const {
        cout <<Job<< ": " << Name << " walks to: " << destination << endl;
    }

    const string Name;
    const string Job;
};



class Student : public Person {
public:

    Student(string name, string favouriteSong) : Person(name, "Student"), FavouriteSong(favouriteSong) {}
    
    void Learn() {
        cout << "Student: " << Name << " learns" << endl;
    }
    
    void SingSong() const {
            cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
        }
    
    virtual void Walk(string& destination) const override {
        Person::Walk(destination);
        SingSong();
    }

    

    const string FavouriteSong;
};


class Teacher : public Person {
public:

    Teacher(string name, string subject) : Person(name, "Teacher"), Subject(subject) { }

    void Teach() {
        cout << "Teacher: " << Name << " teaches: " << Subject << endl;
    }

    virtual void Walk(string& destination) const override {
        Person::Walk(destination);    
    }

public:
    const string Subject;
};


class Policeman : public Person {
public:
    Policeman(string name) : Person(name, "Policeman") { }

    void Check(Person p) {
        cout << "Policeman: " << Name << " checks "<<p.Job<<". "<<p.Job<<"'s name is: " << p.Name << endl;
    }

    virtual void Walk(string& destination) const override {
        Person::Walk(destination);    
    }

};


void VisitPlaces(Person p, vector<string> places) {
    for (auto pl : places) {
        p.Walk(pl);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    t.Teach();
    return 0;
}
