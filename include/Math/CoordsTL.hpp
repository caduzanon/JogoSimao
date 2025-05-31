#pragma once
/*
Código feito pelo ex-monitor Matheus Burda. 
Classe Coords (template!) para lidar com coordenadas e realizar operações nestas.
*/
#include <iostream>

namespace Math {

    template <typename TL>
    class Coords {
    public:
        TL x;
        TL y;

    public:
        Coords(TL x, TL y);
        Coords();
        ~Coords() { }

        void operator=(Coords<TL> other);
        void operator+=(Coords<TL> other);
        void operator-=(Coords<TL> other);
        void operator*=(double scalar);
        void operator/=(double scalar);

        Coords<TL> operator+(Coords<TL> other);
        Coords<TL> operator-(Coords<TL> other);
        Coords<TL> operator*(Coords<TL> other);
        Coords<TL> operator*(double scalar);
        Coords<TL> operator/(Coords<TL> other);
        Coords<TL> operator/(double scalar);
    };

    typedef Coords<double> CoordsD;
    typedef Coords<float> CoordsF;
    typedef Coords<int> CoordsI;
    typedef Coords<unsigned int> CoordsU;

    template <typename TL>
    Coords<TL>::Coords(TL x, TL y) :
    x(x),
    y(y) { }

    template <typename TL>
    Coords<TL>::Coords() {
        this->x = 0;
        this->y = 0;
    }

    template <typename TL>
    void Coords<TL>::operator=(Coords<TL> other) {
        this->x = other.x;
        this->y = other.y;
    }

    template <typename TL>
    void Coords<TL>::operator+=(Coords<TL> other) {
        this->x += other.x;
        this->y += other.y;
    }

    template <typename TL>
    void Coords<TL>::operator-=(Coords<TL> other) {
        this->x -= other.x;
        this->y -= other.y;
    }

    template <typename TL>
    void Coords<TL>::operator*=(double scalar) {
        this->x = this->x * scalar;
        this->y = this->y * scalar;
    }

    template <typename TL>
    void Coords<TL>::operator/=(double scalar) {
        if (scalar == 0.0f) {
            std::cout << "ERROR: Cannot divide by zero." << std::endl;
            exit(1);
        }
        this->x /= scalar;
        this->y /= scalar;
    }

    template <typename TL>
    Coords<TL> Coords<TL>::operator+(Coords<TL> other) {
        return Coords<TL>(this->x + other.x, this->y + other.y);
    }

    template <typename TL>
    Coords<TL> Coords<TL>::operator-(Coords<TL> other) {
        return Coords<TL>(this->x - other.x, this->y - other.y);
    }

    template <typename TL>
    Coords<TL> Coords<TL>::operator*(Coords<TL> other) {
        return Coords<TL>(this->x * other.x, this->y * other.y);
    }

    template <typename TL>
    Coords<TL> Coords<TL>::operator*(double scalar) {
        return Coords<TL>(this->x * scalar, this->y * scalar);
    }

    template <typename TL>
    Coords<TL> Coords<TL>::operator/(Coords<TL> other) {
        if (other.x == 0.0f || other.y == 0.0f) {
            std::cout << "ERROR: Cannot divide by zero." << std::endl;
            exit(1);
        }
        return Coords<TL>(this->x / other.x, this->y / other.y);
    }

    template <typename TL>
    Coords<TL> Coords<TL>::operator/(double scalar) {
        if (scalar == 0.0f) {
            std::cout << "ERROR: Cannot divide by zero." << std::endl;
            exit(1);
        }

        return Coords<TL>(this->x / scalar, this->y / scalar);
    }

}