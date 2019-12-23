//
// Created by Anthony Joo on 2019-01-18.
//

#include <iostream>
#include "TimeSpan.h"
#include <cmath>

// Constructor for object declaration with no parameters
TimeSpan::TimeSpan()
{
    this->seconds = 0;
    this->minutes = 0;
    this->hours = 0;
}

// Constructor for object declaration with only "seconds" parameter
TimeSpan::TimeSpan(double seconds)
{
    round(hours, minutes, seconds);
    this->seconds = (int)seconds;
    this->minutes = 0;
    this->hours = 0;
}

// Constructor for object declaration with only two parameters ("minutes", "seconds")
TimeSpan::TimeSpan(double minutes, double seconds)
{
    round(hours, minutes, seconds);
    this->seconds = (int)seconds;
    this->minutes = (int)minutes;
    this->hours = 0;
}

// Constructor for object declaration with three parameters ("hours", "minutes", "seconds")
TimeSpan::TimeSpan(double hours, double minutes, double seconds)
{
    hours = roundToNearestQuarter(hours);
    minutes += ((hours - (int)(hours / 1)) / .25) * 15;
    round(hours, minutes, seconds);
    this->seconds = (int)seconds;
    this->minutes = (int)minutes;
    this->hours = (int)hours;
}

// returns the "seconds" value
int TimeSpan::getSeconds() const
{
    return seconds;
}

// return the "minutes" value
int TimeSpan::getMinutes() const
{
    return minutes;
}

// return the "hours" value
int TimeSpan::getHours() const
{
    return hours;
}

// returns true if setting the time with the given parameters is successful
bool TimeSpan::setTime(int hours, int minutes, int seconds)
{
    return (minutes < 60 && minutes >= 0 && seconds < 60 && seconds >= 0 && hours >= 0);
}

// operator overloading of "=="
bool TimeSpan::operator==(const TimeSpan &duration) const
{
    return (this->seconds == duration.seconds && this->minutes == duration.minutes && this->hours == duration.hours);
}

// operator overloading of "!="
bool TimeSpan::operator!=(const TimeSpan &duration) const
{
    return (this->seconds != duration.seconds || this->minutes != duration.minutes || this->hours != duration.hours);
}

// operator overloading of "+"
TimeSpan TimeSpan::operator+(const TimeSpan &duration) const
{
    TimeSpan replace;
    replace.seconds = this->seconds + duration.seconds;
    replace.minutes = this->minutes + duration.minutes;
    replace.hours = this->hours + duration.hours;
    return replace;
}

// operator overloading of "+="
TimeSpan& TimeSpan::operator+=(const TimeSpan &duration)
{
    TimeSpan replace;
    this->seconds = this->seconds + duration.seconds;
    this->minutes = this->minutes + duration.minutes;
    this->hours = this->hours + duration.hours;
    return *this;
}

// operator overloading of "-"
TimeSpan TimeSpan::operator-(const TimeSpan &duration) const
{
    TimeSpan replace;
    replace.seconds = this->seconds - duration.seconds;
    replace.minutes = this->minutes - duration.minutes;
    replace.hours = this->hours - duration.hours;
    return replace;
}

// operator overloading of "-="
TimeSpan& TimeSpan::operator-=(const TimeSpan &duration)
{
    TimeSpan replace;
    this->seconds = this->seconds - duration.seconds;
    this->minutes = this->minutes - duration.minutes;
    this->hours = this->hours - duration.hours;
    return *this;
}

// rounds the given double to the nearest quarter step
double TimeSpan::roundToNearestQuarter(double num)
{
    int n = num * 4;
    return (double)n/4;
}

// round the hours, minutes, and seconds values so they fit he given constraints
void TimeSpan::round(double &hours, double &minutes, double &seconds)
{
    while(!setTime(hours, minutes, seconds))
    {
        if (seconds >= 60)
        {
            int val = seconds / 60;
            minutes += val;
            seconds -= val * 60;
        }
        if (minutes >= 60)
        {
            int val = minutes / 60;
            hours += val;
            minutes -= val * 60;
        }
        if (minutes < 0) {
            while (minutes < 0) {
                hours -= 1;
                minutes += 60;
            }
        }
        if (seconds < 0) {
            while (seconds < 0) {
                minutes -= 1;
                seconds += 60;
            }
        }
    }
}

ostream& operator <<(ostream &outStream, const TimeSpan &duration)
{
    outStream << "Hours: " << duration.getHours() << ", Minutes: " << duration.getMinutes() << ", Seconds: " << duration.getSeconds() << endl;
    return outStream;
}

istream& operator >>(istream &inStream, TimeSpan &duration)
{
    cout << "Enter seconds: ";
    inStream >> duration.seconds;
    cout << "Enter minutes: ";
    inStream >> duration.minutes;
    cout << "Enter hours: ";
    inStream >> duration.hours;
    int n = duration.hours * 4;
    duration.hours = (double)n/4;
    duration.minutes += ((duration.hours - (int)(duration.hours / 1)) / .25) * 15;
    while(duration.minutes >= 60 || duration.minutes < 0 || duration.seconds >= 60 || duration.seconds < 0 || duration.hours < 0)
    {
        if (duration.seconds >= 60)
        {
            int val = duration.seconds / 60;
            duration.minutes += val;
            duration.seconds -= val * 60;
        }
        if (duration.minutes >= 60)
        {
            int val = duration.minutes / 60;
            duration.hours += val;
            duration.minutes -= val * 60;
        }
        if (duration.minutes < 0)
        {
            while (duration.minutes < 0) {
                duration.hours -= 1;
                duration.minutes += 60;
            }
        }
        if (duration.seconds < 0)
        {
            while (duration.seconds < 0) {
                duration.minutes -= 1;
                duration.seconds += 60;
            }
        }
    }
    return inStream;
}