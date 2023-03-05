#include <iostream>
#include <string>
using namespace std;

// клас "точка"
class Point {
protected:
    double x, y;
public:
    // конструктор за замовчуванням
    Point() {
        x = 0;
        y = 0;
    }

    // конструктор з параметрами
    Point(double a, double b) {
        x = a;
        y = b;
    }

    // деструктор
    ~Point() {}

    // функція друку
    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    // функції перепризначення координат
    void setX(double a) { x = a; }
    void setY(double b) { y = b; }
};

// клас "кольорова точка"
class ColorPoint : public Point {
protected:
    string color;
public:
    // конструктор за замовчуванням
    ColorPoint() {
        x = 0;
        y = 0;
        color = "red";
    }

    // конструктор з параметрами
    ColorPoint(double a, double b, string c) {
        x = a;
        y = b;
        color = c;
    }

    // деструктор
    ~ColorPoint() {}

    // функція друку
    void print() {
        Point::print(); // виклик функції друку батьківського класу
        cout << color << endl;
    }

    // функції перепризначення координат та кольору
    void setX(double a) { x = a; }
    void setY(double b) { y = b; }
    void setColor(string c) { color = c; }
};

int main() {
    int choice;
    double x, y;
    string color;

    // Меню взаємодії з користувачем
    while (true) {


        cout << "1. Створити об'єкт класу \"точка\" з конструктором за замовчуванням" << endl;
        cout << "2. Створити об'єкт класу \"точка\" з конструктором з параметрами" << endl;
        cout << "3. Створити об'єкт класу \"кольорова точка\" з конструктором за замовчуванням" << endl;
        cout << "4. Створити об'єкт класу \"кольорова точка\" з конструктором з параметрами" << endl;
        cout << "5. Змінити координати об'єкту класу \"кольорова точка" << endl;
        cout << "6. Змінити колір об'єкту класу \"кольоровова точка" << endl;
        cout << "7. Вийти з програми" << endl;
        cout << "Виберіть опцію: ";
        cin >> choice;
        switch (choice) {
        case 1:
        {
            Point p;
            p.print();
            break;
        }
        case 2:
        {
            cout << "Введіть координати точки (x, y): ";
            cin >> x >> y;
            if (cin.fail()) { // перевірка на помилку вводу
                cout << "Неправильний ввід! Спробуйте ще раз." << endl;
                cin.clear(); // очистка потоку вводу
                cin.ignore(10000, '\n'); // пропустити введені символи до кінця рядка
                break;
            }
            Point p(x, y);
            p.print();
            break;
        }
        case 3:
        {
            ColorPoint cp;
            cp.print();
            break;
        }
        case 4:
        {
            cout << "Введіть координати точки (x, y): ";
            cin >> x >> y;
            if (cin.fail()) { // перевірка на помилку вводу
                cout << "Неправильний ввід! Спробуйте ще раз." << endl;
                cin.clear(); // очистка потоку вводу
                cin.ignore(10000, '\n'); // пропустити введені символи до кінця рядка
                break;
            }
            cout << "Введіть колір точки: ";
            cin >> color;
            ColorPoint cp(x, y, color);
            cp.print();
            break;
        }
        case 5:
        {
            double newX, newY;
            cout << "Введіть нові координати точки (x, y): ";
            cin >> newX >> newY;
            ColorPoint cp;
            cp.setX(newX);
            cp.setY(newY);
            cp.print();
            break;
        }
        case 6:
        {
            string newColor;
            cout << "Введіть новий колір точки: ";
            cin >> newColor;
            ColorPoint cp;
            cp.setColor(newColor);
            cp.print();
            break;
        }
        case 7:
        {
            cout << "До побачення!" << endl;
            return 0;
        }
        default:
        {
            cout << "Неправильний вибір! Спробуйте ще раз." << endl;
            break;
        }
        }
    }
}

   

