#ifndef GLOBALENUMATED_H
#define GLOBALENUMATED_H

#include <QString>

class GlobalEnumated
{


public:
    GlobalEnumated();

    //trace range
    typedef enum
    {
        range0_24 = 0,
        range0_30,
        range15_15
    }eRangeValue;

   QString range0_24Txt;
   QString range0_30Txt;
   QString range15_15Txt;

   //edge type
   typedef enum
   {
       fallingEdge = 0,
       risingEdge
   }eEdge;
};

#endif // GLOBALENUMATED_H
