/*
DYLAN DEOKINANDAN
PROJECT 4
I WORKED SO HARD AND NOTHING HAPPENED
*/
#include "Book.hpp"
#include "Novel.hpp"
#include "Textbook.hpp"
#include "Manual.hpp"
#include "LibraryRecord.hpp"
int main()
{

std::string fileName="dataset.csv";
LibraryRecord library(fileName);
library.displayFilter("Air");

}

