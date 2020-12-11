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

    Csv()
    {
        
    }

    

    

private:
   string file_name;
   vector<string> headers;
   bool header_bool;
   vector<vector<string>> data;
   int data_count;
};

#endif