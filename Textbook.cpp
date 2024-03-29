/*
DYLAN DEOKINANDAN
PROJECT 4
March 24, 2023
In Manual, Novel, and Textbook subclasses. I added a display function and displayFilter function specific to each class.
*/
#include "Textbook.hpp"


/**
  Default constructor.
  Default-initializes all private members. 
  Booleans are default-initialized to False
*/
Textbook::Textbook(): has_review_questions_{false}, grade_level_{NONE}, subject_{""}
{	
}

/**
  Parameterized constructor.
  @param     : The title of the book (a string)
  @param     : The author of the book (a string)
  @param     : The number of pages in the book (a positive integer)
  @param     : A flag indicating whether the book is in digital form 
                with DEFAULT VALUE False (a Boolean)
  @param     : The subject of the book (a string)
  @param     : The grade level of the book (of type grade_level) 
                with DEFAULT VALUE NONE
  @param     : A boolean to indicate whether the book has review 
                questions with DEFAULT VALUE False
  @post      : The private members are set to the values of the 
                corresponding parameters.
*/
Textbook::Textbook(std::string name, std::string author, int page_count, std::string subject, bool is_digital, grade_level grade, bool has_review): 
                   Book(name, author, page_count, is_digital), 
                    has_review_questions_{has_review}, grade_level_{grade}, subject_{subject}
{
}


/**
  @param  : a reference to a string representing the the subject of the book
  @post   : sets the private member variable to the value of the parameter
**/
void Textbook::setSubject(const std::string& subject){
  subject_ = subject;
}


/**
  @return  : the subject of the textbook
**/
std::string Textbook::getSubject() const
{
  return subject_;
} 

/**
  @param  : a reference to a grade_level
  @post   : sets the private member variable to the value of the parameter
**/
void Textbook::setGradeLevel(const grade_level& level){
  if(level > NONE && level <= COLLEGE){
      grade_level_ = level;
  }
  else{
    grade_level_ = NONE;
  }
}

/**
  @return  : a string representative of the grade_level 
            (e.g. if the grade level is JUNIOR_HIGH, 
            it returns "JUNIOR HIGH")
**/
std::string Textbook::getGradeLevel() const
{
  if(grade_level_ == NONE){
    return "NONE";
  }
  else if(grade_level_ == ELEMENTARY){
    return "ELEMENTARY";
  }
  else if(grade_level_ == JUNIOR_HIGH){
    return "JUNIOR HIGH";
  }
  else if (grade_level_ == HIGH_SCHOOL){
    return "HIGH SCHOOL";
  }
  else {
    return "COLLEGE";
  }
}

/**
  @post   : sets the review question flag to True
**/
void Textbook::setReviewQuestions(){
  has_review_questions_ = true;
}

/**
  @return  : the flag indicating if the texbook has review questions
**/
bool Textbook::checkReviewQuestions() const
{
  return has_review_questions_;
}

/**
@post     : displays Textbook data in the form:
"[title_] is written by [author_] for [grade_level_] students. Subject: [subject_]. [It has/ It does not have] review questions. Page Count: [page_count_]. [It is / It is not] available digitally.\n" 
*/ 
void Textbook::display()
{
std::string review_qs="It has";
if(!has_review_questions_)
{
  review_qs="It does not have";
}
std::string digital = "It is";
  if(!is_digital_)
  {
      digital = "It is not";
  }

std::cout<< title_ <<" is written by "<< author_ <<" for "<<getGradeLevel()<<" students. Subject: "<<subject_<<". "<<review_qs<<" review questions. Page Count: "<<page_count_<<". "<<digital<<" available digitally.\n";
 }


/**
  @param    : a reference to a string key to match the subject of the Textbook
  @post     : calls display() if the key argument is equal to subject_ (e.g. "mathematics")   
  */
 void Textbook::displayFilter(std::string key)
{
if(key==subject_)
{
  display();
}
}