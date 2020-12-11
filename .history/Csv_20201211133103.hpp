#ifndef CSV_H
#define CSV_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Csv
{

public:
    Csv()
    {
    }

    Csv(string file_name)
    {
        this->file_name = file_name;
    }

    Csv(string file_name, bool headers)
    {
        this->file_name = file_name;
        this->header_bool = headers;
    }

    vector<vector<string>> sort_data(int columna, bool up){

    }

    

    

private:
   string file_name;
   vector<string> headers;
   bool header_bool = false;
   vector<vector<string>> data;
   int data_count;
};

#endif