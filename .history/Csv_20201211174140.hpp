#ifndef CSV_H
#define CSV_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
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
        this->header_bool = false;
    }

    Csv(string file_name, bool headers)
    {
        this->file_name = file_name;
        this->header_bool = headers;
    }

    vector<vector<string> > sort_data(int columna, bool up)
    {
        Csv temporal;
        if (up)
        {
            for (int i = 0; i < data.size(); i++)
            {
                if (data.at(i).at(columna) > data.at(i + 1).at(columna))
                {
                    temporal.get_data().at(i).at(columna) = data.at(i).at(columna);
                    data.at(i).at(columna) = data.at(i + 1).at(columna);
                    data.at(i + 1).at(columna) = temporal.get_data().at(i).at(columna);
                }
            }
        }
        else
        {
            for (int i = 0; i < data.size(); i++)
            {
                if (data.at(i).at(columna) < data.at(i + 1).at(columna))
                {
                    temporal.get_data().at(i).at(columna) = data.at(i).at(columna);
                    data.at(i).at(columna) = data.at(i + 1).at(columna);
                    data.at(i + 1).at(columna) = temporal.get_data().at(i).at(columna);
                }
            }
        }

        return data;
    }

    vector<string> get_column(int index)
    {
        vector<string> vector_temp;
        for (int i = 0; i < data.size(); i++)
        {
            vector_temp.push_back(data.at(i).at(index));
        }
        return vector_temp;
    }

    vector<string> get_row(int index)
    {

        return data.at(index);
    }

    vector<string> get_max(int columna)
    {
        vector<string> vector_temp;

        for (int i = 0; i < data.size(); i++)
        {
            if (i + 1 == data.size())
            {
                break;
            }
            else if (data.at(i).at(columna) > data.at(i + 1).at(columna))
            {
                vector_temp = data.at(i);
            }
        }

        return vector_temp;
    }

    vector<string> get_min(int columna)
    {
        vector<string> vector_temp;

        for (int i = 0; i < data.size(); i++)
        {
            if (i + 1 == data.size())
            {
                break;
            }
            else if (data.at(i).at(columna) < data.at(i + 1).at(columna))
            {
                vector_temp = data.at(i);
            }
        }

        return vector_temp;
    }

    string token(string cadena, string divisor, int pos)
    {
        if (cadena.size() > 0)
        {
            char oracion[cadena.size()];
            for (int i = 0; i <= cadena.size(); i++)
            {
                oracion[i] = cadena[i];
            }
            char *ptrtoken;
            int num = 1;
            const char *d = divisor.c_str();
            ptrtoken = strtok(oracion, d);
            while (ptrtoken)
            {
                if (num == pos)
                {
                    return ptrtoken;
                }
                ptrtoken = strtok(NULL, d);
                num++;
            }
            return "";
        }
        else
        {
            return "";
        }
    }

    void print_data()
    {
        fstream Leer;
        string linea;
        string archivo = "./";
        Leer.open(archivo + file_name);

        while (!Leer.eof())
        {
            getline(Leer, linea);
            if (linea.size() > 0)
            {

                for (int i = 0; i < 23; i++)
                {
                    cout << token(linea, ",", i) << " ";
                }
            }
        }
        Leer.close();
    }

    void truncate_row(int index)
    {
        data.at(index).pop_back();
    }

    void truncate_column(int index)
    {
        for (int i = 0; i < data.size(); i++)
        {
            data.at(i).at(index).pop_back();
        }
    }

    Csv concat(Csv file, string file_name)
    {
    }

    void write_file()
    {
        ofstream guardar;
        string archivo = "./";
        guardar.open(archivo + file_name, ios::app);
        for (int i = 0; i < data.size(); i++)
        {
            for (int j = 0; j < data.at(i).size(); j++)
            {
                guardar << data[i][j];
            }
            guardar << endl;
        }

        guardar.close();
    }

    void load_file(bool headers)
    {
        string line,line2;
        int cont_i=0,cont_j=0;
        if (headers)
        {
        }
        else
        {
            ifstream cargar;
            string archivo = "./";
            cargar.open(archivo + file_name, ios::in);
            if (cargar.is_open())
            {

                while (!cargar.eof())
                {
                    cargar >> line;
                    for (int i = 0; i < line.size(); i++)
                    {
                        line2 = token(line, ",", i);
                        
                         data[cont_i][cont_j].push_back("hola");
                         
                         cont_i++; 
                         cont_j++;
                        
                    }
                }
            }
            cargar.close();
        }
    }

    string get_file_name()
    {
        return this->file_name;
    }

    void set_file_name(string file_name)
    {
        this->file_name = file_name;
    }

    vector<string> get_headers()
    {
        return headers;
    }

    vector<vector<string> > get_data()
    {
        return data;
    }

    int get_data_count()
    {
        return data_count;
    }

private:
    string file_name;
    vector<string> headers;
    bool header_bool;
    vector<vector<string> > data;
    int data_count;
};

#endif