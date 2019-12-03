#ifndef PARS_H
#define PARS_H
#include <iostream>
#include "comp.h"
#include <string.h>
#include <sstream>
using namespace std;
class pars 
{
public:

    pars();
    struct component
    {

      string data;
      int id;
      int size;
      bool completed;
      string type;
    };

    void setB(std::string str)
    {
        buffer = str;
        cout<<"enter sring"<<endl;
        cout<<str<<endl;
    }
   int HEX_to_INT(string str);
   float HEX_to_FLOAT(string str);
   char HEX_to_CHAR(string str);
   bool HEX_to_BOOL(string str);
   int serch_ID(int id);
   bool check_data(int pos, int size_d);
   void pars_data(int i);
   void print_data();
   void print_float4(string str);
private:

std::string buffer;
int size = 17;
component pac[17] = {
    {"0", 5, 8,false,"float"},
    {"0",24,8,false,"float"},
    {"0",25,8,false,"float"},
    {"0",79,2,false,"char"},
    {"0",77,32,false,"float4"},
    {"0",7,8,false,"float"},
    {"0",8,2,false,"bool"},
    {"0",9,2,false,"bool"},
    {"0",21,8,false,"float"},
    {"0",22,8,false,"float"},
    {"0",23,8,false,"float"},
    {"0",27,8,false,"float"},
    {"0",28,8,false,"float"},
    {"0",29,8,false,"float"},
    {"0",74,8,false,"float"},
    {"0",75,8,false,"float"},
    {"0",76,8,false,"float"}
 };
};

#endif // PARS_H
