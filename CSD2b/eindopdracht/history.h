//Single Sample delay object

class History{
public:
  History();
  ~History();

  double tick(double inputSample);

protected:
  double inputSample;
  double previousSample;
};
