#include <iostream>
#include "Csv.hpp"
using namespace std;
int main(){
    Csv* c = new Csv("laboratorio_train_synth_dengue.csv");
    c->load_file(false);

    c->print_data(); 
}