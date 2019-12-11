#include "pars.h"
#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;
pars::pars()
{
   std::cout<<" new struct"<<std::endl;
}

int pars::HEX_to_INT(string str)
{
    union ulf
    {
        unsigned long ul;
        int f;
    };
    ulf u;
    stringstream ss(str);
    ss >> hex >> u.ul;
    int result  = u.f;
   // cout<<"hex to int"<<endl;
    //cout<<result<<endl;
    return result;
}

float pars::HEX_to_FLOAT(string str)
{
    union ulf
    {
        unsigned long ul;
        float f;
    };
    ulf u;
    stringstream ss(str);
    ss >> hex >> u.ul;
    float result  = u.f;
    //cout<<"hex to float"<<endl;
    //cout<<result<<endl;
    return result;
}

char pars::HEX_to_CHAR(string str)
{

    int asciiVal = HEX_to_INT(str);
    char asciiChar = static_cast<char>(asciiVal);
    //cout<<"hex to char"<<endl;
    //cout<<asciiChar<<endl;
    return asciiChar;
}

bool pars::HEX_to_BOOL(string str)
{
    bool flag;
    int value = HEX_to_INT(str);

    if(value>0)
    {
      flag = true;
       //cout<<"true"<<endl;
    }
    else
    {
      flag = false;
       //cout<<"true"<<endl;
    }
    return flag;
}
int pars::serch_ID(int id, int pos)
{
    //cout<<"serch_ID"<<endl;
    int find_id;
    string ID;
    string b;
    string a;
   for(pos;pos < buffer.length()-1; pos++)
   {
       b =  buffer[pos];
       a = buffer[pos+1];
       ID = b+a;
      // cout<<ID<<"--"<<pos<<endl;
       find_id = HEX_to_INT(ID);
      //cout<< "id-"<<find_id<<endl;
       if(find_id == id)
       {
        cout<< "id-"<<find_id<<endl;
        break;

       }
   }
   if(pos == buffer.length()-1)
   {
       cout<<"No component"<<endl;
       return -1;
   }
   else if(pos<buffer.length()-1)
   {
       return pos;
   }
}

bool pars::check_data(int pos, int size_d)
{
    bool check = false;
    //cout<<"check_data"<<endl;
    int offset = pos+2+size_d;
    if(offset>buffer.length())
    {
       check = false;
       return false;
    }
    if(offset == buffer.length())
    {
        check =true;
        return true;
    }
    string check_str = buffer.substr(offset,2);
    //cout<<"CHECK ID:  "<<check_str<<endl;
    int id = HEX_to_INT(check_str);
    for(int i =0;i<size;i++)
    {
         //cout<<i<<endl;
         int j = pac[i].id;
        // cout<<"ID"<<j<<endl;
        if(id==pac[i].id)
        {

            //cout<<"Check"<<endl;
            check=true;
            break;
        }
    }
    if(check)
    {
        //cout<<"Check"<<endl;
        return true;
    }
    else
    {
        //cout<<"No Check"<<endl;
        return false;
    }
   }
void pars::pars_data(int i)
{
    cout<<"PARS__________"<<endl;
    for(i;i<size;i++)
    {
        cout<<"New component->"<<pac[i].id<<endl;
        //int position = serch_ID(pac[i].id);
        int position =0;
        int current_position=0;
        bool flag;
        while(current_position != -1)
        {
            current_position = serch_ID(pac[i].id,position);
            cout<<"Position->"<<current_position<<endl;
            flag = check_data(current_position,pac[i].size);
            if(flag)
            {
                break;
            }
            position = current_position+1;
        }

        if(current_position!=-1)
        {
            cout<<"verify"<<endl;
            if(flag)
            {
                cout<<"check"<<endl;
                pac[i].data=buffer.substr(current_position+2,pac[i].size);
                cout<< "DATA:  "<<pac[i].data<<endl;
                pac[i].completed =true;
            }
            else
            {
                cout<<"no check"<<endl;
                pac[i].completed =false;
            }
        }
        else
        {
            cout<<"no find"<<endl;
            pac[i].completed =false;
        }
    }
}

void pars::print_data()
{
    for(int i=0;i<size;i++)
    {
        cout<<"-----------------"<<endl;
        cout<<pac[i].name<<endl;
        if(pac[i].completed)
        {
            switch (pac[i].type)
            {
             case 1:
               cout<<"HEX data: "<<pac[i].data<<endl;
               cout<<"float type"<<endl;
               cout<<HEX_to_FLOAT(pac[i].data)<<endl;
                break;
             case 2:
                cout<<"HEX data: "<<pac[i].data<<endl;
                cout<<"char type"<<endl;
                cout<<HEX_to_CHAR(pac[i].data)<<endl;
                break;
              case 3:
                {
                cout<<"HEX data: "<<pac[i].data<<endl;
                cout<<"bool"<<endl;
                bool out = HEX_to_BOOL(pac[i].data);
                if(out)
                {
                    cout<<"true"<<endl;
                }
                else
                {
                    cout<<"false"<<endl;
                }
                break;
             }
              case 4:
                cout<<"HEX data: "<<pac[i].data<<endl;
                cout<<"float[4]"<<endl;
                print_float4(pac[i].data);
                break;
            }
        }
        else
        {
            cout<<"No data"<<endl;
        }
    }
}

void pars::print_float4(string str)
{
    //cout<<"Float[4]"<<endl;
    float a = HEX_to_FLOAT(str.substr(0,8));
    cout<<a<<endl;
    float b = HEX_to_FLOAT(str.substr(8,8));
    cout<<b<<endl;
    float c = HEX_to_FLOAT(str.substr(16,8));
    cout<<c<<endl;
    float d = HEX_to_FLOAT(str.substr(24,8));
    cout<<d<<endl;
}
