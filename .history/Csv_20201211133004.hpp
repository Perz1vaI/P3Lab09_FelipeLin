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

    

    

private:
   string file_name;
   vector<string> headers;
   bool header_bool = FALSE;
   vector<vector<string>> data;
   int data_count;
};

#endif