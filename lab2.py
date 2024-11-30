#Zad 1

# class Publication:
#     def __init__(self):
#         self.title = ""
#         self.price = 0.0

#     def getdata(self):
#         self.title = input("Введите название книги: ")
#         self.price = float(input("Введите цену книги: "))

#     def putdata(self):
#         print(f"Название книги: {self.title}")
#         print(f"Цена книги: {self.price:.2f}")

# class Book(Publication):
#     def __init__(self):
#         super().__init__()
#         self.pages = 0

#     def getdata(self):
#         super().getdata()  # Вызов метода getdata из класса Publication
#         self.pages = int(input("Введите количество страниц в книге: "))

#     def putdata(self):
#         super().putdata()  # Вызов метода putdata из класса Publication
#         print(f"Количество страниц: {self.pages}")

# class Type(Publication):
#     def __init__(self):
#         super().__init__()
#         self.recording_time = 0

#     def getdata(self):
#         super().getdata()  # Вызов метода getdata из класса Publication
#         self.recording_time = int(input("Введите время записи книги в минутах: "))

#     def putdata(self):
#         super().putdata()  # Вызов метода putdata из класса Publication
#         print(f"Время записи: {self.recording_time} минут")


# # Пример использования классов
# book = Book()
# book.getdata()
# book.putdata()

# audio = Type()
# audio.getdata()
# audio.putdata()


#Zad 2
class Publication:
    def __init__(self):
        self.title = ""
        self.price = 0.0

    def getdata(self):
        self.title = input("Введите название книги: ")
        self.price = float(input("Введите цену книги: "))

    def putdata(self):
        print(f"Название книги: {self.title}")
        print(f"Цена книги: {self.price:.2f}")


class Sales:
    def __init__(self):
        # Массив продаж за три месяца
        self.sales = [0.0, 0.0, 0.0]

    def getdata(self):
        # Ввод данных о продажах
        for i in range(3):
            self.sales[i] = float(input(f"Введите продажи за месяц {i + 1}: "))

    def putdata(self):
        # Вывод данных о продажах
        for i in range(3):
            print(f"Продажи за месяц {i + 1}: {self.sales[i]:.2f}")


class Book(Publication, Sales):
    def __init__(self):
        Publication.__init__(self)
        Sales.__init__(self)
        self.pages = 0

    def getdata(self):
        # Ввод данных книги и продаж
        Publication.getdata(self)
        self.pages = int(input("Введите количество страниц в книге: "))
        Sales.getdata(self)

    def putdata(self):
        # Вывод данных книги и продаж
        Publication.putdata(self)
        print(f"Количество страниц: {self.pages}")
        Sales.putdata(self)


class Type(Publication, Sales):
    def __init__(self):
        Publication.__init__(self)
        Sales.__init__(self)
        self.recording_time = 0

    def getdata(self):
        # Ввод данных аудиокниги и продаж
        Publication.getdata(self)
        self.recording_time = int(input("Введите время записи книги в минутах: "))
        Sales.getdata(self)

    def putdata(self):
        # Вывод данных аудиокниги и продаж
        Publication.putdata(self)
        print(f"Время записи: {self.recording_time} минут")
        Sales.putdata(self)


# Пример использования классов
book = Book()
book.getdata()
book.putdata()

audio = Type()
audio.getdata()
audio.putdata()
