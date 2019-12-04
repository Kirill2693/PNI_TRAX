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
      int type;
      string name;
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
    {"0", 5, 8,false,1,"kHeading"},
    {"0",24,8,false,1,"kPitch"},
    {"0",25,8,false,1,"kRoll"},
    {"0",79,2,false,2,"kHeadingStatus"},
    {"0",77,32,false,3,"kQuaternion"},
    {"0",7,8,false,1,"kTemperature"},
    {"0",8,2,false,4,"kDistortion"},
    {"0",9,2,false,4,"kCalStatus"},
    {"0",21,8,false,1,"kAccelX"},
    {"0",22,8,false,1,"kAccelY"},
    {"0",23,8,false,1,"kAccelZ"},
    {"0",27,8,false,1,"kMagX"},
    {"0",28,8,false,1,"kMagY"},
    {"0",29,8,false,1,"kMagZ"},
    {"0",74,8,false,1,"kGyroX"},
    {"0",75,8,false,1,"kGyroY"},
    {"0",76,8,false,1,"kGyroZ"}
 };
};

#endif // PARS_H
