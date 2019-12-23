//
// Created by Anthony Joo on 2019-01-18.
//

#ifndef TIMESPAN_H
#define TIMESPAN_H

#include <iostream>
//#include "TimeSpan.cpp"
using namespace std;

class TimeSpan
{
    friend ostream& operator <<(ostream &outStream, const TimeSpan &duration);
    friend istream& operator >>(istream &inStream, TimeSpan &duration);

public:
    friend ostream& operator <<(ostream &outStream, const TimeSpan &duration);
    friend istream& operator >>(istream &inStream, TimeSpan &duration);
    //
    // Constructors and destructors

    TimeSpan();
    TimeSpan(double seconds);
    TimeSpan(double minutes, double seconds);
    TimeSpan(double hours, double minutes, double seconds);

    //
    //getters and setters
    int getHours() const;
    int getMinutes() const;
    int getSeconds() const;
    bool setTime(int hours, int minutes, int seconds);

    //
    // operator overload
    bool operator==(const TimeSpan &duration) const;
    bool operator!=(const TimeSpan &duration) const;
    TimeSpan operator-(const TimeSpan &duration) const;
    TimeSpan& operator-=(const TimeSpan &duration);
    TimeSpan operator+(const TimeSpan &duration) const;
    TimeSpan& operator+=(const TimeSpan &duration);

    //
    // ostream and istream operator overloading
    /*friend ostream& operator <<(ostream &outStream, const TimeSpan &duration)
    {
        outStream << "Hours: " << duration.getHours() << ", Minutes: " << duration.getMinutes() << ", Seconds: " << duration.getSeconds() << endl;
        return outStream;
    }
    friend istream& operator >>(istream &inStream, TimeSpan &duration)
    {
        cout << "Enter seconds: ";
        inStream >> duration.seconds;
        cout << "Enter minutes: ";
        inStream >> duration.minutes;
        cout << "Enter hours: ";
        inStream >> duration.hours;
        //this->roundAgain(duration);
        return inStream;
    }*/

private:
    // Round a given double to a quarter increment
    double roundToNearestQuarter(double num);

    // round the hours, minutes, and seconds so that they fit the desired constraints
    void round(double &hours, double &minutes, double &seconds);

    //
    // class variables
    double seconds;
    double minutes;
    double hours;
};

#endif //CSS342LAB1_TIMESPAN_H

