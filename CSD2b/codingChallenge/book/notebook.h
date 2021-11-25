#include "book.h"

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
  //TODO MAKE CLASS FOR THE COLOUR - PEN CLASS?
  float penColour[4] = { 0., 0., 0., 1.}; //RGBA
  std::string subject;
  std:string textToWrite;
  
}
