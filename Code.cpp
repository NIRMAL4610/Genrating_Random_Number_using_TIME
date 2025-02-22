#include <iostream>
#include <ctime>
using namespace std;

int getRandomNumber()
{
    int rannum;
    time_t now = time(0);
    struct tm *local_time = localtime(&now);
    int hour   = local_time->tm_hour % 10;
    int minute = local_time->tm_min % 10;
    int second = local_time->tm_sec % 10;

    if (hour == 0 && minute == 0 && second == 0)
    {
        int day = local_time->tm_mday;
        int month = local_time->tm_mon + 1;  
        int year = local_time->tm_year + 1900;
        rannum = (day + month + year) % 100;  
    }
    else if (second == 0 && minute == 0)
    {
        rannum = (hour + (local_time->tm_mday % 10)) % 100;
    }
    else if (second == 0)
    {
        rannum = (minute * hour) % 100;
    }
    else if (minute == 0)
    {
        rannum = (second * (local_time->tm_sec / 10)) % 100;
    }
    else
    {
        rannum = (minute * second) % 100;
    }
    return rannum;
}

int main()
{
    cout << "Genrated Random Number Using TIME : " << getRandomNumber() << endl; 
}
