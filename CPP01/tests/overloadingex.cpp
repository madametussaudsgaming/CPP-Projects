#include <bits/stdc++.h>
using namespace std;

class Integer {
private:
    int i;

public:
    // Parameterised constructor
    Integer(int i = 0)
    {
        this->i = i;
    }

    // Overloading the prefix operator
    Integer& operator--()
    {
        --i;
        // returned value should be a reference to *this
        return *this;
    }

    // Function to display the value of i
    void display()
    {
        cout << "i = " << i << endl;
    }
};

// Driver function
int main()
{
    Integer i1(3);

    cout << "Before decrement: ";
    i1.display();

    // Using the pre-decrement operator
    Integer i2 = --i1;

    cout << "After pre decrement: " << endl;
    cout << "i1: ";
    i1.display();
    cout << "i2: ";
    i2.display();
}