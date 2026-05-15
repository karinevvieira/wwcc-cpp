#include <iostream>
#include <iomanip>

using namespace std;

const double PI = 3.14159;

// Private class
class Rectangle {
private:
    double length;
    double width;

public:
    // Constructor
    Rectangle(double recLen, double recWidth) {
        length = recLen;
        width = recWidth;
    }

    // Const Getters
    double getLength() const { return length; }
    double getWidth() const { return width; }

    // Setter without validation (Will define outside the class as per instructions)
    void setLength(double newLength);
    void setWidth(double newWidth);

    // Overloaded area() methods
    double area() const {
        return length * width;
    }

    void area(double &result) const {
        result = length * width;
    }

    // Resize() method that scales both dimensions by a factor
    Rectangle& resize(double factor) {
        this->length *= factor;
        this->width *= factor;
        return *this;
    }

    // Print method
    void print() const;
};

// Setters defined outside the class with validation
void Rectangle::setLength(double newLength) {
    if (newLength <= 0) {
        cout << "Error: length cannot be a negative number" << endl;
    }
    else {
        length = newLength;
    }
}

void Rectangle::setWidth(double newWidth) {
    if (newWidth <= 0) {
        cout << "Error: width cannot be a negative number" << endl;
    }
    else {
        width = newWidth;
    }
}

// Print method defined outside the class
void Rectangle::print() const {
    cout << "Rectangle (Length: " << length << ", Width: " << width << ")" << endl;
    cout << "Area: " << area() << endl;
}

class Circle {
private:
    double radius;

public:
    // Constructor
    Circle(double circleRadius) {
        radius = circleRadius;
    }

    // Setter with validation
    void setRadius(double newRadius) {
        if (newRadius < 0) {
            cout << "Error: radius cannot be a negative number" << endl;
            return;
        }
        else {
            radius = newRadius;
        }
    }

    // Const methods for calculation
    double getArea() const {
        return PI * radius * radius;
    }

    double getCircumference() const {
        return 2 * PI * radius;
    }

    // Const methods for printing
    void print() const {
        cout << "\nCircle (Radius: " << radius << ")" << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Circumference: " << getCircumference() << endl; 
    };

    void print(bool displayCalc) const {
        if (displayCalc == true) {
            cout << "\nCircle details: " << endl;
            cout << "  Radius: " << radius << endl;
            cout << "  Area: " << "pi x " << radius << "^2 = " << getArea() << endl;
            cout << "  Circumference: 2 x pi x " << radius << " = " << getCircumference() << endl;
        } 
        else {
            print();
        }
    }
};

/*  In main display the header as in the example
    Create instances of both classes (Rectangle and Circle)
    Test all methods, including the overloaded versions
    Demonstrate method chaining using resize() 
    Create a const object of at least one class and show that const methods work on it
*/
int main() {
    cout << fixed << setprecision(2);
    cout << "SHAPE CALCULATOR" << endl;
    cout << "----------------\n" << endl;

    // Create instances of Rectangle and Circle
    Rectangle rect(5.0, 3.0);
    const Circle constCircle(4.0);

    // Test Rectangle methods
    double recArea;
    rect.area(recArea);
    rect.print();
    cout << "Area via refrence: " << recArea << endl;

    // Test Circle methods
    constCircle.print();
    constCircle.print(true);
    cout << endl;

    // Demonstrate method chaining using resize()
    cout << "Method chaining:" << endl;
    cout << "  Original: Length = " << rect.getLength() << ", Width = " << rect.getWidth() << endl;
    cout << "  After resize(2.0): Length = " << rect.resize(2.0).getLength() << ", Width = " << rect.getWidth() << endl << endl;

    return 0;
}