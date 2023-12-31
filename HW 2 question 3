#include <iostream>
#include <cmath>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int num, int den) : numerator(num), denominator(den) {
        simplify();
    }

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    void setNumerator(int num) {
        numerator = num;
        simplify();
    }

    void setDenominator(int den) {
        if (den != 0) {
            denominator = den;
            simplify();
        } else {
            std::cerr << "Error: Denominator cannot be zero." << std::endl;
        }
    }

    
    Fraction& operator+=(const Fraction& other) {
        numerator = numerator * other.denominator + other.numerator * denominator;
        denominator *= other.denominator;
        simplify();
        return *this;
    }

    Fraction& operator-=(const Fraction& other) {
        numerator = numerator * other.denominator - other.numerator * denominator;
        denominator *= other.denominator;
        simplify();
        return *this;
    }

    Fraction& operator*=(const Fraction& other) {
        numerator *= other.numerator;
        denominator *= other.denominator;
        simplify();
        return *this;
    }

    Fraction& operator/=(const Fraction& other) {
        if (other.numerator != 0) {
            numerator *= other.denominator;
            denominator *= other.numerator;
            simplify();
        } else {
            std::cerr << "Error: Division by zero." << std::endl;
        }
        return *this;
    }


    Fraction operator+(const Fraction& other) const {
        Fraction result(*this);
        result += other;
        return result;
    }

    Fraction operator-(const Fraction& other) const {
        Fraction result(*this);
        result -= other;
        return result;
    }

    Fraction operator*(const Fraction& other) const {
        Fraction result(*this);
        result *= other;
        return result;
    }

    Fraction operator/(const Fraction& other) const {
        Fraction result(*this);
        result /= other;
        return result;
    }


    double toDouble() const {
        return static_cast<double>(numerator) / denominator;
    }


    friend std::ostream& operator<<(std::ostream& out, const Fraction& frac) {
        out << frac.numerator << '/' << frac.denominator;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Fraction& frac) {
        char slash;
        in >> frac.numerator >> slash >> frac.denominator;
        frac.simplify();
        return in;
    }

private:
    
    void simplify() {
        int gcd_val = gcd(std::abs(numerator), denominator);
        numerator /= gcd_val;
        denominator /= gcd_val;

        
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

   
    int gcd(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return std::abs(a);
    }
};

int main() {
    Fraction a;
    Fraction b;
    
    std::cout << "Enter value of a = " << std::endl;
    std::cin >> a;

    std::cout << "Enter value of b = " << std::endl;
    std::cin >> b;
      
    std::cout << "Entered Fractions: a = " << a << ", b = " << b << std::endl;

    
    Fraction sum = a + b;
    Fraction difference = a - b;
    Fraction product = a * b;
    Fraction quotient = a / b;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Quotient: " << quotient << std::endl;
    std::cout << "a as double: " << a.toDouble() << std::endl;

    return 0;
}
