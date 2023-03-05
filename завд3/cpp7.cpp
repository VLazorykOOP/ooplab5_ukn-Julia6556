#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(const string& name, int age) : name(name), age(age) {
        cout << "Person " << name << " has been created" << endl; //повідомляю про створення
    }
    Person(const Person& other) : name(other.name), age(other.age) {
        cout << "Person " << name << " has been copied" << endl; //оголошую, що використую існуючі дані
    }
    Person& operator=(const Person& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
        }
        cout << "Person " << name << " has been assigned" << endl; //повідомляю про присвоєння
        return *this;
    }
    virtual ~Person() {
        cout << "Person " << name << " has been destroyed" << endl; //повідомляю про видалення
    }
    virtual void display() const { /*функція використовується для відображення (виводу) даних об'єкта
        в консоль або в інший вихідний потік. Ключове слово virtual вказує на те, 
        що ця функція може бути перевизначена в похідних класах.*/
        cout << "Name: " << name << ", Age: " << age;
    }
    virtual void input() {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cin.ignore();
    }
    friend ostream& operator<<(ostream& os, const Person& person) {
        os << "Name: " << person.name << ", Age: " << person.age;
        return os; /*перевизначений оператор виводу в потік. Викликається функція, яка записує в потік os
        інформацію про ім'я та вік цієї особи. Після цього функція повертає змінну os, 
        що дозволяє подальше використання оператора виводу в потік для інших об'єктів.*/
    }
    friend istream& operator>>(istream& is, Person& person) {
        cout << "Enter name: ";
        getline(is, person.name);
        cout << "Enter age: ";
        is >> person.age;
        is.ignore();
        return is;
    }
};

class Employee : public Person {
private:
    string position;
    double salary;
public:
    Employee(const string& name, int age, const string& position, double salary)
        : Person(name, age), position(position), salary(salary) {
        cout << "Employee " << name << " has been created" << endl;
    }
    Employee(const Employee& other) : Person(other), position(other.position), salary(other.salary) {
        cout << "Employee " << name << " has been copied" << endl;
    }
    Employee& operator=(const Employee& other) {
        if (this != &other) {
            Person::operator=(other);
            position = other.position;
            salary = other.salary;
        }
        cout << "Employee " << name << " has been assigned" << endl;
        return *this;
    }
    virtual ~Employee() {
        cout << "Employee " << name << " has been destroyed" << endl;
    }
    virtual void display() const {
        Person::display();
        cout << ", Position: " << position << ", Salary: " << salary;
    }
    virtual void input() {
        Person::input();
        cout << "Enter position: ";
        getline(cin, position);/*продовжує читання рядка до тих пір,
        поки не досягне символу нового рядка або не буде досягнутий максимальний розмір рядка.*/
        cout << "Enter salary: ";
        cin >> salary;
        cin.ignore();/*видаляє один символ з буфера введення, 
        щоб забезпечити наступне читання введення з потоку*/
    }
    friend ostream& operator<<(ostream& os, const Employee& employee) {
        os << static_cast<const Person&>(employee) << ", Position: " << employee.position << ", Salary: " <<
            employee.salary;
        return os; /* В даному випадку, os - це потік виведення, в який записується форматований рядок
        з даними про об'єкт. Після запису даних у потік, оператор << повертає цей потік, щоб дозволити
        подальшу його обробку, наприклад, використання в ланцюжку виведення даних в консоль або у файл.*/
    }
    friend istream& operator>>(istream& is, Employee& employee) {
        is >> static_cast<Person&>(employee); /*У цьому рядку коду відбувається виконання перевантаженого оператора введення
        з потоку operator>> для базового класу Person з використанням віртуальної функції input(). Проте, для того щоб
        забезпечити правильну роботу, ми мусимо використати static_cast, щоб звернути об'єкт employee класу Employee
        до його базового класу Person, тобто явно перетворити тип об'єкту від Employee& до Person&. Це дозволяє
        передати усі необхідні дані для ініціалізації об'єкту базового класу з потоку введення, які зберігаються
        у полях базового класу Person.*/
        cout << "Enter position: ";
        getline(is, employee.position);
        cout << "Enter salary: ";
        is >> employee.salary;// зчитування значення поля salary об'єкту employee
        is.ignore();
        return is;
    }
};

int main() {
    Person person("Anton", 25);
    cout << person << endl;
    Employee employee("Sofia", 30, "Manager", 5000.0);
    cout << employee << endl;

    Person* ptr = &employee;
    ptr->display();/*викликає метод display() для об'єкту, на який вказує вказівник ptr.
    Це виклик віртуальної функції, що означає, що метод display() буде виконано для об'єкту,
    створеного з конкретного класу, на який вказує ptr, а не з базового класу. Якщо клас Person
    містить віртуальний метод display(), а клас Employee перевизначає його, то виклик методу display()
    через вказівник на Person викличе метод display() з класу Employee.*/
}
    
