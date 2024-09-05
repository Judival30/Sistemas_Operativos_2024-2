#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Clase base Figura
class Figura
{
private:
    string color;

public:
    virtual double area() const = 0;
    virtual double perimetro() const = 0;

    void setColor(const string &s)
    {
        color = s;
    }
    string getColor() const
    {
        return color;
    }
};

// Clase derivada Circulo con herencia pública
class Circulo : public Figura
{
private:
    double radio;

public:
    Circulo() {}
    Circulo(double r)
    {
        radio = r;
    }
    double perimetro() const override
    {
        return 2 * 3.14 * radio;
    }
    double area() const override
    {
        return 3.14 * radio * radio;
    }
};

// Clase derivada Cuadrado con herencia pública
class Cuadrado : public Figura
{
private:
    double lado;

public:
    Cuadrado() {}
    Cuadrado(double l)
    {
        lado = l;
    }
    double perimetro() const override
    {
        return lado * 4;
    }
    double area() const override
    {
        return lado * lado;
    }
};

// Clase derivada Rectangulo con herencia pública
class Rectangulo : public Figura
{
private:
    double base;
    double altura;

public:
    Rectangulo() {}
    Rectangulo(double b, double h)
    {
        base = b;
        altura = h;
    }
    double perimetro() const override
    {
        return 2 * (base + altura);
    }
    double area() const override
    {
        return base * altura;
    }
};

// Clase derivada Triangulo con herencia pública
class Triangulo : public Figura
{
private:
    double altura;
    double base;

public:
    Triangulo() {}
    Triangulo(double h, double a)
    {
        altura = h;
        base = a;
    }

    double area() const override
    {
        return (base * altura) / 2;
    }

    double perimetro() const override
    {
        return base * 3;
    }
};

int main()
{
    Rectangulo rect(5.0, 3.0);
    rect.setColor("Red");
    cout << "Rectangulo color: " << rect.getColor() << endl;
    cout << "Area: " << rect.area() << endl;
    cout << "Perimetro: " << rect.perimetro() << endl;
    cout << endl;

    Cuadrado sq(4.0);
    sq.setColor("Blue");
    cout << "Cuadrado color: " << sq.getColor() << endl;
    cout << "Area: " << sq.area() << endl;
    cout << "Perimetro: " << sq.perimetro() << endl;
    cout << endl;

    Triangulo tri(3.0, 4.0);
    tri.setColor("Green");
    cout << "Triangulo color: " << tri.getColor() << endl;
    cout << "Area: " << tri.area() << endl;
    cout << "Perimetro: " << tri.perimetro() << endl;
    cout << endl;

    return 0;
}
