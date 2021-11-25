#include "book.h"
#include "pen.h"

#pragma once

class Notebook : public Book{
public:
  Notebook();
  Notebook(std::string subject);
  ~Notebook();

  void setPenColour(float penColour);
  float getPenColour();

  void setSubject(std::string subject);
  std::string getSubject();

  void write(std::string textToWrite);

protected:
  Pen* pen;

  std::string subject;
  std:string textToWrite;

}
