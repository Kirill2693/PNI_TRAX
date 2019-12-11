#include <iostream>
#include "pars.h"
#include "comp.h"
using namespace std;

int main()
{
    pars p;
    p.setB("05430D083B183F91BCD8193EDF4DE94F00080015BCA408C0163BFB4DAB173F80F5081BC16EA4371cc12d31271d42513d4f4a000000004b000000004c00000000");//нет только кватерниона
    p.pars_data(0);
    p.print_data();
    return 0;
}
