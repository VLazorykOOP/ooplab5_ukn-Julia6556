#include <iostream>
#include <string>

using namespace std;

class Processor {
private:
    int power;

public:
    Processor(int p) {
        power = p;
    }

    int getPower() {
        return power;
    }
};

class Computer {
private:
    string brand;
    float price;
    Processor* processor;

public:
    Computer(string b, float p, Processor* pr) {
        brand = b;
        price = p;
        processor = pr;
    }

    ~Computer() {
        delete processor;
    }

    void print() {
        cout << "Brand: " << brand << endl;
        cout << "Price: " << price << endl;
        cout << "Processor power: " << processor->getPower() << " MHz" << endl;
    }
};

class ComputerWithMonitor : public Computer {
private:
    float monitorSize;

public:
    ComputerWithMonitor(string b, float p, Processor* pr, float ms) : Computer(b, p, pr) {
        monitorSize = ms;
    }

    void print() {
        Computer::print();
        cout << "Monitor size: " << monitorSize << " inches" << endl;
    }
};

int main() {
    Processor* processor = new Processor(3000);
    ComputerWithMonitor* computer = new ComputerWithMonitor("HP", 999.99, processor, 23.5);
    computer->print(); /*Цей код викликає метод print() у об'єкті,
    на який вказує вказівник computer. Він припускає,
    що computer є вказівником на об'єкт класу, який має метод print().*/
    delete computer;
    return 0;
}
