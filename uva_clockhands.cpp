#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int hours, minutes;


    while(scanf("%d:%d", &hours, &minutes) && hours+minutes){
        // convert hours to angles
        double o = (double)hours + ((double)minutes/60.000);
        double hourangles = o*30.00;

        int mins = minutes*6;

        double angle = abs(hourangles - (double)mins);


        if(angle > 180) angle = 360 - (angle);

        printf("%.3lf\n", angle);
    }
    return 0;
}
