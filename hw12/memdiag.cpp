#include <iostream>
using namespace std;

int main()
{
    float minimum, mydata[] = {5., 5., 4., 5., 3., 6.};
    double avg = 0;

    minimum = mydata[0];
    for (int i = 0; i < 6; ++i)
    {
        if (mydata[i] < minimum)
            minimum = mydata[i];
        avg += mydata[i];
    }
    cout << avg;
    avg /= 6;
}