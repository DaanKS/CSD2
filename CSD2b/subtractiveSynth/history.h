//Single Sample delay object

class History{
public:
  History();
  ~History();

  double tick(double inputSample);

private:
  double inputSample;
  double previousSample;
};
