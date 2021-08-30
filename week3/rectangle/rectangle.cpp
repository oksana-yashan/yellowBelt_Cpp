#include <string>
#include <vector>
#include <algorithm>

#include "tests.h"
#include "rectangle.h"
using namespace std;


Rectangle::Rectangle(int width, int height)
{
    width_ = width;
    height_ = height;
}

int Rectangle::GetArea() const {
    return width_ * height_;
}

int Rectangle::GetPerimeter() const {
    return 2 * (width_ + height_);
}

int Rectangle::GetWidth() const { return width_; }
int Rectangle::GetHeight() const { return height_; }






void TestRectangle() {
	Rectangle r(2,4);

	AssertEqual(r.GetPerimeter(), 12, "per");
	AssertEqual(r.GetArea(), 8, "area");

}