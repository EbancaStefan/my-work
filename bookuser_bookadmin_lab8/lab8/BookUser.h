#pragma once
#include "Book.h"
#include "BookRepo.h"
#include <vector>
#include <memory>
#include <string>
/*
a.See the books from the database having a given genre(if the genre is empty, see all the books),
one by one.When the user chooses this option, the data of the first book(title, author, genre,year and description) is displayed.

b.If the user likes the book description, he / she can choose to add this book to his / her to listen list.

c.If the description is not satisfactory, the user can choose to ignore the bookand to continue to the next one.
In this case, the information corresponding to the next book is shownand the user is again offered the possibility to add it to the to read list.
This can continue as long as the user wants, as when arriving to the end of the list of books with the given genre, if the user chooses
next, the application will again show the first book.

d.Delete a book from the to listen list, after the user “read” the book.

e.See the to listen list.*/



