#ifndef PARSER_H
#define PARSER_H
#include <string.h>
using namespace std;

class parser
{
public:
    parser()
    {
        pack = {
            {
                "0",
                25,
                5,
                false
            }
        };
    }

private:
      struct component
      {
          string data;
          int ID;
          int size;
          bool find;
      };
     component pack[1];

};

#endif // PARSER_H
