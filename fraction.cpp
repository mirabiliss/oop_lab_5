#include "fraction.h"

Fraction::Fraction()
{
    this->num = 0;
    this->den = 1;
}

Fraction::Fraction(int num, int den)
{
    this->num = num;
    this->den = den;
}

Fraction::Fraction(int num)
{
    this->num = num;
    this->den = 1;
}

int Fraction::getNum() const
{
    return num;
}

void Fraction::setNum(int value)
{
    num = value;
}

int Fraction::getDen() const
{
    return den;
}

void Fraction::setDen(int value)
{
    den = value;
}

Fraction Fraction::add(const Fraction &other)
{
    Fraction res(this->getNum() * other.getDen() +
                 other.getNum() * this->getDen(),
                 this->getDen() * other.getDen());
    res.cut();
    return res;
}

Fraction Fraction::subtract(const Fraction &other)
{
    Fraction res(this->getNum() * other.getDen() -
                 other.getNum() * this->getDen(),
                 this->getDen() * other.getDen());
    res.cut();
    return res;
}

Fraction Fraction::multiply(const Fraction &other)
{
    Fraction res(this->getNum() * other.getNum(),
                 this->getDen() * other.getDen());
    res.cut();
    return res;
}

Fraction Fraction::divide(const Fraction &other)
{
    Fraction second = other;
    second.turn();
    Fraction res = this->multiply(second);
    return res;
}

int find_gcd(int a, int b){
    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    else if (a == b)
        return a;
    else if (a > b)
        return find_gcd(a - b, b);
    else
        return find_gcd(a, b - a);
}

void Fraction::cut()
{
    int gcd = find_gcd(this->getNum(), this->getDen());
    Fraction res(this->getNum() / gcd, this->getDen() / gcd);
    this->setNum(res.getNum());
    this->setDen(res.getDen());
}

void Fraction::turn()
{
    Fraction res(this->getDen(), this->getNum());
    this->setNum(res.getNum());
    this->setDen(res.getDen());
}
