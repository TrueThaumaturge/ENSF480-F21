#include <string>
using namespace std;

class Moveable {
    public:
        virtual void forward(int n) = 0;
        virtual void backward(int n) = 0;
}

class Resizeable {
    public:
        virtual void enlarge(int n) = 0;
        virtual void shrink(int n) = 0;
}

class Vehicle : public Moveable, public Resizeable {
    protected:
        string name;
    public:
        virtual Vehicle(string name) = 0;
        virtual void move() = 0;
}

class Car final : public Vehicle {
    private:
        int seats;
    public:
        Car(int seats, string name);
        void turn();

        void forward(int n);
        void backward(int n);

        void enlarge(int n);
        void shrink(int n);

        void move();
}