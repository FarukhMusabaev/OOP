
class Book:
    def __init__(self, author: str, title: str, book_type: str):
        # Проверяем, чтобы автор и название книги были заданы
        if not author or not title:
            raise ValueError("Книга должна иметь автора и название.")
        
        # Проверяем корректность типа книги
        if book_type not in ['художественная', 'техническая']:
            raise ValueError("Тип книги должен быть 'художественная' или 'техническая'.")
        
        self.author = author
        self.title = title
        self.book_type = book_type
    
    def __repr__(self):
        return f"Book(author='{self.author}', title='{self.title}', type='{self.book_type}')"

class Library:
    def __init__(self):
        self.books = []
    
    def add_book(self, book: Book):
        self.books.append(book)
    
    def __repr__(self):
        return f"Library contains {len(self.books)} books: {self.books}"

# Создаем экземпляр библиотеки
library = Library()

# Добавляем несколько книг в библиотеку
library.add_book(Book(author="Джордж Оруэлл", title="1984", book_type="художественная"))
library.add_book(Book(author="Андрей Усачев", title="Теория систем и системный анализ", book_type="техническая"))
library.add_book(Book(author="Герберт Шилдт", title="Java: Полное руководство", book_type="техническая"))
library.add_book(Book(author="Лев Толстой", title="Война и мир", book_type="художественная"))

# Печатаем содержимое библиотеки
print(library)