#include <iostream>
#include "pars.h"
#include "comp.h"
using namespace std;

int main()
{
    pars p;
    p.setB("0541cc000018429c999a");//05_41cc0000_18_429c999a
    string str ="F2";
    p.pars_data(0);
    p.print_data();
    return 0;
}
