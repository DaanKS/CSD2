//
// Created by Dean on 21/02/2022.
//

class History{
public:
    History();
    ~History();

    double tick(double inputSample);

protected:
    double inputSample = 0;
    double previousSample = 0;
};
