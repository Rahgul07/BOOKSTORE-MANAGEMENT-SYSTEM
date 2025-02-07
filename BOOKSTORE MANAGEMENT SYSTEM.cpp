#include <iostream>
#include <string>

struct Book
{
	std::string title;
	std::string author;
	double price;
	Book *next;
	Book *prev;
};

class Bookstore
{
private:
	Book *head;

public:
	Bookstore()
	{
		head = nullptr;
	}

	void addBook(const std::string &title, const std::string &author, double price)
	{
		Book *newBook = new Book;
		newBook->title = title;
		newBook->author = author;
		newBook->price = price;

		if (head == nullptr)
		{
			newBook->prev = nullptr;
			newBook->next = nullptr;
			head = newBook;
		}
		else
		{
			newBook->next = head;
			newBook->next->prev = newBook;
			newBook->prev = nullptr;
			head = newBook;
		}
		std::cout << "Book added successfully.\n";
	}
	void removeBook(const std::string &title)
	{
		Book *current = head;

		while (current != nullptr)
		{
			if (current->title == title)
			{
				if (current->prev != nullptr)
				{
					current->prev->next = current->next;
				}
				else
				{
					head = current->next;
				}
				if (current->next != nullptr)
				{
					current->next->prev = current->prev;
				}
				delete current;
				std::cout << "Book removed successfully.\n";
				return;
			}
			current = current->next;
		}
		std::cout << "Book not found.\n";
	}

	void displayBooks()
	{
		Book *current = head;

		if (current == nullptr)
		{
			std::cout << "No books in the bookstore.\n";
			return;
		}

		std::cout << "List of Books:\n";
		while (current != nullptr)
		{
			std::cout << "Title: " << current->title << "\n";
			std::cout << "Author: " << current->author << "\n";
			std::cout << "Price: $" << current->price << "\n";
			std::cout << "------------------------\n";
			current = current->next;
		}
	}

	void sortBooksByPrice()
	{
		Book *current = head;
		Book *sorted = nullptr;

		while (current != nullptr)
		{
			Book *next = current->next;
			insertSortedByPrice(current, sorted);
			current = next;
		}

		head = sorted;
		std::cout << "Books sorted by price.\n";
	}

private:
	void insertSortedByPrice(Book *newBook, Book *&sorted)
	{
		if (sorted == nullptr || sorted->price >= newBook->price)
		{
			newBook->next = sorted;
			newBook->prev = nullptr;
			if (sorted != nullptr)
			{
				sorted->prev = newBook;
			}
			sorted = newBook;
		}
		else
		{
			Book *current = sorted;
			while (current->next != nullptr && current->next->price < newBook->price)
			{
				current = current->next;
			}
			newBook->next = current->next;
			newBook->prev = current;
			if (current->next != nullptr)
			{
				current->next->prev = newBook;
			}
			current->next = newBook;
		}
	}
};

int main()
{
	Bookstore bookstore;
	int choice;

	do
	{
		std::cout << "Bookstore Management System\n";
		std::cout << "1. Add Book\n";
		std::cout << "2. Remove Book\n";
		std::cout << "3. Display Books\n";
		std::cout << "4. Sort Books by Price\n";
		std::cout << "5. Exit\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice)
		{
		case 1:
		{
			std::string title, author;
			double price;
			std::cout << "Enter Book Title: ";
			std::cin.ignore();
			std::getline(std::cin, title);
			std::cout << "Enter Author: ";
			std::getline(std::cin, author);
			std::cout << "Enter Price: $";
			std::cin >> price;
			bookstore.addBook(title, author, price);
		}
		break;
		case 2:
		{
			std::string title;
			std::cout << "Enter Book Title to Remove: ";
			std::cin.ignore();
			std::getline(std::cin, title);
			bookstore.removeBook(title);
		}
		break;
		case 3:
			bookstore.displayBooks();
			break;
		case 4:
			bookstore.sortBooksByPrice();
			break;
		case 5:
			std::cout << "Exiting the program.\n";
			break;
		default:
			std::cout << "Invalid choice. Please try again.\n";




		}

		int main (
				}
	} while (choice != 5);

	return 0;
}
