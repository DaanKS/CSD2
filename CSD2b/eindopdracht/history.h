//Single Sample delay object

class History{
public:
  History();
  ~History();

  float tick(float inputSample);

private:
  float inputSample;
  float previousSample;
};
