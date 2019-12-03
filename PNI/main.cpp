#include <iostream>
#include "pars.h"
#include "comp.h"
using namespace std;

int main()
{
    pars p;
    p.setB("ugfjfubF125jhbf09F2000935");
    string str ="F2";
   // int i = p.HEX_to_INT(str);
   // cout<<i<<endl;
    //cout<<"searc id-----------------------"<<endl;
    //int position = p.serch_ID(241);
    //cout<<position<<endl;
    //bool dt = p.check_data(position,8);
    p.pars_data(0);
    return 0;
}
