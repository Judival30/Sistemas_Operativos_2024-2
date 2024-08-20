#include <iostream>

using namespace std;

class Figura
{
private:
    string color;
    double area;
    double perimetro;

public:
    Figura() {};
    Figura(string c)
    {
        color = c;
    }
    virtual double area();
    virtual double perimetro();
    virtual void changeColor();
    void printInfo()
    {
        printf("Area: %f\nPerimetro: %f\n", area, perimetro);
        cout << color << endl;
    }
    void setPerimetro(double per)
    {
        perimetro = per;
    }
    void setArea(double a)
    {
        area = a;
    }
    void setColor(string &s)
    {
        color = s;
    }
};

class Circulo : Figura
{
private:
    double radio;

public:
    Circulo() {}
    Circulo(double r, string c) : Figura(c)
    {
        radio = r;
    }
    double perimetro() override
    {
        double perimetro = 2 * 3.14 * radio;
        setPerimetro(perimetro);
        return perimetro;
    }
    double area() override
    {
        double area = 3.14 * radio * radio;
        setArea(area);
        return area;
    }
    void printrInfo()
    {
        printf("Circulo\nRadio: %d\n", radio);
        printInfo();
    }
};

class Cuadrado : Figura
{
private:
    double lado;

public:
    Cuadrado() {}
    Cuadrado(double l, string c) : Figura(c)
    {
        lado = l;
    }
    double perimetro() override
    {
        double perimetro = lado * 4;
        setPerimetro(perimetro);
        return perimetro;
    }
    double area() override
    {
        double area = lado * lado;
        setArea(area);
        return area;
    }
};

class Rectagulo : Figura
{
private:
    double base;
    double altura;

public:
    Rectagulo() {}
    Rectagulo(double b, double h, string c) : Figura(c)
    {
        base = b;
        altura = h;
    }
    double perimetro() override
    {
        double perimetro = base * 2 + altura * 2;
        setPerimetro(perimetro);
        return perimetro;
    }
    double area() override
    {
        double area = base * altura;
        setArea(area);
        return area;
    }
};

class Triangulo : Figura
{
private:
    double altura;
    double base;

public:
    Triangulo();
    Triangulo(double h, double a, string c) : Figura(c)
    {
        altura = h;
        base = a;
    }

    double area()
    {
        double area = (base * altura) / 2;
        setArea(area);
        return area;
    }

    double perimetro()
    {
        double perimetro = base * 3;
        setPerimetro(perimetro);
        return perimetro;
    }
};

int main()
{
    Circulo circulo(5.0, "rojo");
    circulo.printrInfo();

    return 0;
}
