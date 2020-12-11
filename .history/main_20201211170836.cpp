#include <iostream>
#include "Csv.hpp"
using namespace std;
int main(){
    cout << "hola 0" << endl;
    //Csv* c = new Csv("laboratorio_train_synth_dengue.csv");
    Csv* c = new Csv("completo_train_synth_dengue.csv");
    cout << "hola 1" << endl;
    //c->set_file_name("completo_train_syth_dengue.csv");
    cout << "hola 2" << endl;
    //c->load_file(false);
    cout << "hola 3" << endl;

    c->sort_data(2,true);

    c->print_data(); 
}