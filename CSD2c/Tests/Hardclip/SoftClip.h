#ifndef _SOFTCLIP_H_
#define _SOFTCLIP_H_

#include <iostream>

//Class Initiation
class Softclip{
//acces specifier
public:
  Softclip();
  ~Softclip();
//Calculation
void Soft();
double Clip();

//setters and getters
void setDrive();
int getDrive();

//Catching the inbuf[i]
double Catch(double input);

//Acces specifier
protected:
//variabeles
double sampletje;
double sample;
 int drive;
double input;
};

#endif
