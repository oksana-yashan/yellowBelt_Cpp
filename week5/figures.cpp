#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

 

class Figure {
public:
    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Triangle : public Figure {
public:
    Triangle(int a, int b, int c) : _a(a), _b(b), _c(c) {
        cout<<"Constructor Triangle"<<endl;
    }

    virtual string Name() const override {
        return "Triangle";
    }

    virtual double Perimeter() const override {
        return _a+_b+_c;
    }

    virtual double Area() const override {
        double p = Perimeter()/2;
        return sqrt(p*(p-_a)*(p-_b)*(p-_c));
    }
private:
    int _a,_b,_c;
};


class Rectangle : public Figure {
public:
    Rectangle(int a, int b) : _a(a), _b(b) {}

    virtual string Name() const override {
        return "Rectangle";
    }

    virtual double Perimeter() const override {
        return (_a+_b)*2;
    }

    virtual double Area() const override {
        return _a*_b;
    }
private:
    int _a,_b;
};


class Circle : public Figure {
public:
    Circle (int r) : _r(r) {}

    virtual string Name() const override {
        return "Circle";
    }

    virtual double Perimeter() const override {
        return 2*3.14*_r;
    }

    virtual double Area() const override {
        return 3.14*_r*_r;
    }
private:
    int _r;
};
 

shared_ptr<Figure> CreateFigure(istream& is) {
    string oper;
    shared_ptr<Figure> f;

    is>>oper;
    cout<<oper;
    if (oper == "RECT") {
        int a, b;
        is>>a>>b;
        f = make_shared<Rectangle> (a, b);
    }
    else if (oper == "TRIANGLE") {
        int a, b, c;
        is>>a>>b>>c;
        cout<<a<<b<<c<<";";
        f = make_shared<Triangle> (a, b, c);
    }
    else if (oper == "CIRCLE") {
        int r;
        is>>r;
        f = make_shared<Circle> (r);
    }

    return f;

}


int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}