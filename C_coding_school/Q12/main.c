#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
	char title[51];
	char author[51];
	int year;
}Book;

void printBook(Book book);
void printBooks(const Book books[], int count);
Book findOldestBook(const Book books[], int count);
int countBooksByAuthor(const Book books[], int count, const char* author);

int main() {
	// Array of 93 books with pre-filled data (Curtesy of ChatGpt :) )
	struct Book books[] = {
		{"The Great Gatsby", "F. Scott Fitzgerald", 1925},
		{"Tender is the Night", "F. Scott Fitzgerald", 1934},
		{"This Side of Paradise", "F. Scott Fitzgerald", 1920},
		{"1984", "George Orwell", 1949},
		{"Animal Farm", "George Orwell", 1945},
		{"Homage to Catalonia", "George Orwell", 1938},
		{"To Kill a Mockingbird", "Harper Lee", 1960},
		{"Go Set a Watchman", "Harper Lee", 2015},
		{"Brave New World", "Aldous Huxley", 1932},
		{"Island", "Aldous Huxley", 1962},
		{"The Catcher in the Rye", "J.D. Salinger", 1951},
		{"Nine Stories", "J.D. Salinger", 1953},
		{"Franny and Zooey", "J.D. Salinger", 1961},
		{"Moby Dick", "Herman Melville", 1851},
		{"Billy Budd", "Herman Melville", 1924},
		{"Pride and Prejudice", "Jane Austen", 1813},
		{"Sense and Sensibility", "Jane Austen", 1811},
		{"Emma", "Jane Austen", 1815},
		{"The Lord of the Rings", "J.R.R. Tolkien", 1954},
		{"The Hobbit", "J.R.R. Tolkien", 1937},
		{"Silmarillion", "J.R.R. Tolkien", 1977},
		{"Jane Eyre", "Charlotte Bronte", 1847},
		{"Shirley", "Charlotte Bronte", 1849},
		{"Villette", "Charlotte Bronte", 1853},
		{"Wuthering Heights", "Emily Bronte", 1847},
		{"Agnes Grey", "Anne Bronte", 1847},
		{"The Tenant of Wildfell Hall", "Anne Bronte", 1848},
		{"Dracula", "Bram Stoker", 1897},
		{"The Lair of the White Worm", "Bram Stoker", 1911},
		{"Great Expectations", "Charles Dickens", 1861},
		{"Oliver Twist", "Charles Dickens", 1837},
		{"David Copperfield", "Charles Dickens", 1850},
		{"Bleak House", "Charles Dickens", 1853},
		{"A Tale of Two Cities", "Charles Dickens", 1859},
		{"War and Peace", "Leo Tolstoy", 1869},
		{"Anna Karenina", "Leo Tolstoy", 1878},
		{"The Death of Ivan Ilyich", "Leo Tolstoy", 1886},
		{"Crime and Punishment", "Fyodor Dostoevsky", 1866},
		{"The Brothers Karamazov", "Fyodor Dostoevsky", 1880},
		{"Notes from Underground", "Fyodor Dostoevsky", 1864},
		{"The Idiot", "Fyodor Dostoevsky", 1869},
		{"Don Quixote", "Miguel de Cervantes", 1605},
		{"The Alchemist", "Paulo Coelho", 1988},
		{"Eleven Minutes", "Paulo Coelho", 2003},
		{"The Pilgrimage", "Paulo Coelho", 1987},
		{"The Zahir", "Paulo Coelho", 2005},
		{"The Catch-22", "Joseph Heller", 1961},
		{"Something Happened", "Joseph Heller", 1974},
		{"Slaughterhouse-Five", "Kurt Vonnegut", 1969},
		{"Cat's Cradle", "Kurt Vonnegut", 1963},
		{"Breakfast of Champions", "Kurt Vonnegut", 1973},
		{"The Road", "Cormac McCarthy", 2006},
		{"Blood Meridian", "Cormac McCarthy", 1985},
		{"No Country for Old Men", "Cormac McCarthy", 2005},
		{"Beloved", "Toni Morrison", 1987},
		{"Song of Solomon", "Toni Morrison", 1977},
		{"The Bluest Eye", "Toni Morrison", 1970},
		{"Sula", "Toni Morrison", 1973},
		{"Invisible Man", "Ralph Ellison", 1952},
		{"The Grapes of Wrath", "John Steinbeck", 1939},
		{"Of Mice and Men", "John Steinbeck", 1937},
		{"East of Eden", "John Steinbeck", 1952},
		{"The Pearl", "John Steinbeck", 1947},
		{"Cannery Row", "John Steinbeck", 1945},
		{"Frankenstein", "Mary Shelley", 1818},
		{"The Last Man", "Mary Shelley", 1826},
		{"The Scarlet Letter", "Nathaniel Hawthorne", 1850},
		{"The House of the Seven Gables", "Nathaniel Hawthorne", 1851},
		{"Middlesex", "Jeffrey Eugenides", 2002},
		{"The Virgin Suicides", "Jeffrey Eugenides", 1993},
		{"White Teeth", "Zadie Smith", 2000},
		{"On Beauty", "Zadie Smith", 2005},
		{"Swing Time", "Zadie Smith", 2016},
		{"Life of Pi", "Yann Martel", 2001},
		{"Beatrice and Virgil", "Yann Martel", 2010},
		{"The Kite Runner", "Khaled Hosseini", 2003},
		{"A Thousand Splendid Suns", "Khaled Hosseini", 2007},
		{"And the Mountains Echoed", "Khaled Hosseini", 2013},
		{"Ulysses", "James Joyce", 1922},
		{"Dubliners", "James Joyce", 1914},
		{"A Portrait of the Artist as a Young Man", "James Joyce", 1916},
		{"The Old Man and the Sea", "Ernest Hemingway", 1952},
		{"For Whom the Bell Tolls", "Ernest Hemingway", 1940},
		{"A Farewell to Arms", "Ernest Hemingway", 1929},
		{"The Sun Also Rises", "Ernest Hemingway", 1926},
		{"As I Lay Dying", "William Faulkner", 1930},
		{"The Sound and the Fury", "William Faulkner", 1929},
		{"Light in August", "William Faulkner", 1932},
		{"The Handmaid's Tale", "Margaret Atwood", 1985},
		{"Oryx and Crake", "Margaret Atwood", 2003},
		{"The Testaments", "Margaret Atwood", 2019},
		{"Fahrenheit 451", "Ray Bradbury", 1953},
		{"The Martian Chronicles", "Ray Bradbury", 1950}
	};

	// Print all books
	printf("Books in the Library:\n");
	printBooks(books, _countof(books));

	// Find and print the oldest book
	Book oldest = findOldestBook(books, _countof(books));
	printf("\nThe oldest book is:\n");
	printBook(oldest);

	// Count books by a specific author
	char author[] = "George Orwell";
	int count = countBooksByAuthor(books, _countof(books), author);
	printf("\nNumber of books by %s: %d\n", author, count);

	return 0;
}

// Function implementations
void printBook(Book book) {
	printf("Title: %s , Trthor: %s , Published in the year: %d \n",book.title ,book.author,book.year);
}

void printBooks(const Book books[], int count) 
{
	for (int i = 0; i < count; i++)  //lets run on all books
	{
        printBook(books[i]);
    }
}

Book findOldestBook(const Book books[], int count) {
	Book theolders = books[0];
	for (int i = 1; i < count; i++) 
	{
        if (books[i].year < theolders.year)
		{
            theolders = books[i];
        }
    }
	return theolders;
}

int countBooksByAuthor(const Book books[], int count, const char* author) 
{
	int BooksByArthur = 0;
	for (int i = 0; i < count; i++)
	{
		if (strcmp(books[i].author, author) == 0) //compere strings
		{
        	BooksByArthur++; 
        }
    }
    return BooksByArthur;	
}
