// #include <iostream> 
// #include <vector> 
// #include <memory> 
// #include <clocale>

// using namespace std;

// class Detail {
// protected:
// 	Detail() { cout << "Деталь создана" << endl; }

// 	template<typename T>
// 	friend shared_ptr<T> create();

// public:
// 	virtual ~Detail() { cout << "Деталь уничтожена" << endl; } virtual void show() const {
// 		cout << "Это Деталь." << endl;
// 	}
// };

// class Assembly : public Detail {
// protected:
// 	Assembly() { cout << "Сборка создана" << endl; }

// 	template<typename T>
// 	friend shared_ptr<T> create();

// public:
// 	~Assembly() override { cout << "Сборка уничтожена" << endl; }

// 	void show() const override {
// 		cout << "Это Сборка." << endl;
// 	}
// };

// template<typename T> shared_ptr<T> create() {
// 	return shared_ptr<T>(new T());
// }

// int main() {
// 	setlocale(LC_ALL, "RU");

// 	vector<shared_ptr<Detail>> storage;

// 	// Создаем объекты, используя шаблонную дружественную функцию storage.push_back(create<Detail>()); storage.push_back(create<Assembly>());

// 	// Показываем объекты
// 	for (const auto& item : storage) {
// 		item->show();
// 	}

// 	return 0;
// }





// #include <iostream> #include <vector> #include <memory> #include <cstdlib> #include <ctime> #include <clocale>

// using namespace std;

// class Base { public:
// virtual ~Base() { cout << "Base уничтожен" << endl; } virtual void show() const {
// cout << "Это объект класса Base." << endl;
// }
// };

// class Derived : public Base { public:
// void show() const override {
// cout << "Это объект класса Derived." << endl;
// }

// ~Derived() override { cout << "Derived уничтожен" << endl; }

// };

// // Функция для добавления объектов в хранилище
// void add(shared_ptr<Base> obj, vector<shared_ptr<Base>>& storage) { storage.push_back(obj);
// }

// int main() { setlocale(LC_ALL, "RU");

// srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел vector<shared_ptr<Base>> storage;

// // Цикл создания случайных объектов Base или Derived for (int i = 0; i < 5; ++i) {
// int random_value = rand();
// if (random_value % 2 == 0) {
// // Создаем объект Base add(make_shared<Base>(), storage);
// }
// else {
// // Создаем объект Derived add(make_shared<Derived>(), storage);
// }
// }

// // Показываем объекты из хранилища for (const auto& item : storage) {
// item->show();
// }

// return 0;
// }

