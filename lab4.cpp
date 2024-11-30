#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// Базовый класс
class Transport {
public:
    virtual void display() const {
        cout << "Это средство передвижения." << endl;
    }
    virtual ~Transport() {} // Виртуальный деструктор
};

// Велосипед
class Bicycle : public Transport {
public:
    void display() const override {
        cout << "Это велосипед." << endl;
    }
};

// Автомобиль
class Car : public Transport {
public:
    void display() const override {
        cout << "Это автомобиль." << endl;
    }
};

// Грузовик
class Truck : public Transport {
public:
    void display() const override {
        cout << "Это грузовик." << endl;
    }
};

// Шаблонный класс
template <typename T>
class ObjectArray {
private:
    vector<T*> objects; 
    size_t maxSize;     // Максимальный размер массива

public:
    ObjectArray(size_t maxSize) : maxSize(maxSize) {}

    void add(T* obj) {
        if (objects.size() >= maxSize) {
            throw length_error("Превышен максимальный размер массива!");
        }
        objects.push_back(obj);
    }

    T* operator[](size_t index) {
        if (index >= objects.size()) {
            throw out_of_range("Индекс вне диапазона.");
        }
        return objects[index];
    }

    size_t getMaxSize() const {
        return maxSize;
    }

    ~ObjectArray() {
        for (T* obj : objects) {
            delete obj; // Освобождаем память
        }
    }
};

int main() {
    setlocale(LC_ALL, "RU");

    try {
        ObjectArray<Transport> transports(3); // Устанавливаем максимальный размер массива

        // Добавляем объекты
        transports.add(new Bicycle());
        transports.add(new Car());
        transports.add(new Truck());
        transports.add(new Truck());

        // Выводим информацию о каждом объекте
        for (size_t i = 0; i < transports.getMaxSize(); ++i) {
            try {
                transports[i]->display();
            }
            catch (const out_of_range& e) {
                cout << "Пустой слот." << endl;
            }
        }

        // Превышаем лимит
        transports.add(new Truck());
        transports[10]->display(); // Вызывает исключение

    }
    catch (const length_error& e) {
        cerr << "Ошибка размера: " << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cerr << "Ошибка диапазона: " << e.what() << endl;
    }
    

    return 0;
}
