#ifndef CSV_H
#define CSV_H
#include <iostream>
#include <string>
using namespace std;
class Csv
{

public:
    Csv()
    {
    }

    Csv(int x, int y, char nombre)
    {
        this->x = x;
        this->y = y;
        this->nombre = nombre;
    }

    char getNombre()
    {
        return this->nombre;
    }

    int getX()
    {
        return this->x;
    }
    
    int getY()
    {
        return this->y;
    }

    

    

private:
   string file_name;
   vector<string> headers;
   vector<vector<string>> data;
   int data_count;
};

#endif