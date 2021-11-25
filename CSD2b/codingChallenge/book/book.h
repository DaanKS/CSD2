#include <iostream>

#pragma once

class Book{
public:
  Book(std::string title);
  ~Book();

  void setTitle(std::string title)
  std::string getTitle();

  void turnToPage(int pageNumber);
  int checkPageNum();


protected:
  int pageNumber;
  std::string title;

private:
  Book();

};
