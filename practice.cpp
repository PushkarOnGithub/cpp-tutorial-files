#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Student{
    public:
    int rollNumber;

    private:
    int age;

    public:
    Student(int a, int rollNumber){
        cout<<"Constructor 1 used"<<endl;
        age = a;
        this -> rollNumber = rollNumber;
    }

    Student(int r){
        cout<<"Constructor 2 used"<<endl;
        rollNumber = r;
    }

    void setage(int a){
        if(a>0){
            age = a;
        }
    }
};

class Fraction{
    private:
    int denominator;
    int numerator;

    public:
    Fraction(int numerator, int denominator){
        this -> numerator = numerator;
        this -> denominator = denominator;
    }

    void print(){
        cout<<this -> numerator<<"/"<<denominator<<endl;
    }

    void add(Fraction f2){
        int lcm = denominator*(f2.denominator);
        int x = lcm/denominator;
        int y = lcm/f2.denominator;
        int num = (x*numerator) + (y*f2.numerator);
        this -> denominator = lcm;
        this -> numerator = num;
    }

    Fraction operator*(Fraction const &f2){
        int num = this -> numerator * f2.numerator;
        int den = this -> denominator * f2.denominator;
        Fraction fnew(num, den);
        // fnew.simplify();
        return fnew;
    }
};


class ComplexNumbers{
    private:
    int real;
    int imaginary;
    int const r;

    public:

    void print(){
        cout<<real<<" + "<<imaginary<<"i"<<endl;
       }

    void add(ComplexNumbers c){
        real += c.real;
        imaginary += c.imaginary;
    }

    void substract(ComplexNumbers c){
        real -= c.real;
        imaginary -= c.imaginary;
    }

    void multiply(ComplexNumbers c){
        real = real*(c.imaginary) - imaginary*(c.real);
        imaginary = imaginary*(c.real) + real*(c.imaginary);
    }

    //constructors

    ComplexNumbers(int r, int i) : r(this -> r) {
        real = r;
        imaginary = i;
    }
};

class Books{
    static int no_books;

    public:
    char name[100];
    char author[100];

    static int getno(){
        return name;
        // return no_books;

    }
}


int main(int argc, char const *argv[])
{
    Student s1(456);
    s1.rollNumber = 101;
    s1.setage(10);
    cout<<s1.rollNumber<<endl;

    Student s2(12, 102);
    cout<<s2.rollNumber<<endl;
    s2.setage(10);
    return 0;
}
