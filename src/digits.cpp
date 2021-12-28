#include "digits.h"

// static digitA digit0 = {
//     //
//     {
//         //
//         {DEG0, -DEG90},  //
//         {-DEG90, DEG90}, //
//         {-DEG90, DEG90}, //
//         {-DEG90, DEG90}, //
//         {-DEG90, DEG90}, //
//         {DEG90, DEG0}    //
//     },                   //
//     {
//         {DEG180, DEG0},  //
//         {DEG270, DEG90}, //
//         {-DEG90, DEG90}, //
//         {DEG270, DEG90}, //
//         {DEG270, DEG90}, //
//         {DEG180, DEG0}   //
//     },
//     {
//         {DEG180, -DEG90}, //
//         {DEG270, DEG90},  //
//         {-DEG90, DEG90},  //
//         {DEG270, DEG90},  //
//         {DEG270, DEG90},  //
//         {DEG180, DEG90}   //
//     }
//     //
//     //
// };
// static digitA digit1 = {
//     //
//     {
//         //
//         {DEG0, -DEG90},   //
//         {DEG0, DEG90},    //
//         {DEG225, DEG225}, //
//         {DEG225, DEG225}, //
//         {DEG225, DEG225}, //
//         {DEG225, DEG225}  //
//     },                    //
//     {
//         {DEG180, DEG0},   //
//         {DEG180, -DEG90}, //
//         {DEG90, -DEG90},  //
//         {DEG270, DEG90},  //
//         {DEG270, DEG90},  //
//         {DEG90, DEG0}     //
//     },
//     {
//         {DEG180, -DEG90}, //
//         {DEG270, DEG90},  //
//         {-DEG90, DEG90},  //
//         {DEG270, DEG90},  //
//         {DEG270, DEG90},  //
//         {DEG180, DEG90}   //
//     }
//     //
//     //
// };
// static digitA digit2 = {
//     //
//     {
//         //
//         {DEG0, -DEG90},  //
//         {DEG0, DEG90},   //
//         {DEG0, -DEG90},  //
//         {-DEG90, DEG90}, //
//         {-DEG90, DEG90}, //
//         {DEG90, DEG0}    //
//     },                   //
//     {
//         {DEG180, DEG0},   //
//         {DEG270, DEG180}, //
//         {DEG180, DEG90},  //
//         {-DEG90, DEG0},   //
//         {DEG90, DEG0},    //
//         {DEG180, DEG0}    //
//     },
//     {
//         {DEG180, -DEG90}, //
//         {DEG270, DEG90},  //
//         {-DEG90, DEG90},  //
//         {DEG180, DEG90},  //
//         {DEG180, -DEG90}, //
//         {DEG180, DEG90}   //
//     }
//     //
//     //
// };
// static digitA digit3 = {
//     //
//     {
//         //
//         {DEG0, -DEG90}, //
//         {DEG0, DEG90},  //
//         {DEG0, -DEG90}, //
//         {DEG0, DEG90},  //
//         {DEG270, DEG0}, //
//         {DEG270, DEG0}  //
//     },                  //
//     {
//         {DEG180, DEG0},   //
//         {DEG180, -DEG90}, //
//         {DEG180, DEG90},  //
//         {DEG180, -DEG90}, //
//         {DEG180, DEG90},  //
//         {DEG180, DEG0}    //
//     },
//     {
//         {DEG180, -DEG90}, //
//         {DEG270, DEG90},  //
//         {-DEG90, DEG90},  //
//         {DEG270, DEG90},  //
//         {DEG270, DEG90},  //
//         {DEG180, DEG90}   //
//     }
//     //
//     //
// };
// static digitA digit4 = {
//     //
//     {
//         //
//         {DEG0, -DEG90},   //
//         {-DEG90, DEG90},  //
//         {-DEG90, DEG90},  //
//         {DEG0, DEG90},    //
//         {DEG225, DEG225}, //
//         {DEG225, DEG225}  //
//     },                    //
//     {
//         {DEG180, -DEG90}, //
//         {DEG270, DEG90},  //
//         {DEG0, DEG90},    //
//         {DEG270, DEG180}, //
//         {DEG270, DEG90},  //
//         {DEG90, DEG0}     //
//     },
//     {
//         {DEG180, -DEG90}, //
//         {DEG270, DEG90},  //
//         {-DEG90, DEG90},  //
//         {DEG270, DEG90},  //
//         {DEG270, DEG90},  //
//         {DEG180, DEG90}   //
//     }
//     //
//     //
// };
// static digitA digit5 = {
//     //
//     {
//         //
//         {DEG0, -DEG90},  //
//         {-DEG90, DEG90}, //
//         {-DEG90, DEG90}, //
//         {DEG0, DEG90},   //
//         {-DEG90, DEG0},  //
//         {DEG90, DEG0}    //
//     },                   //
//     {
//         {DEG180, DEG0},   //
//         {DEG0, -DEG90},   //
//         {DEG0, DEG90},    //
//         {DEG180, -DEG90}, //
//         {DEG180, DEG90},  //
//         {DEG180, DEG0}    //
//     },
//     {
//         {DEG180, -DEG90}, //
//         {DEG180, DEG90},  //
//         {DEG180, -DEG90}, //
//         {DEG270, DEG90},  //
//         {DEG270, DEG90},  //
//         {DEG180, DEG90}   //
//     }
//     //
//     //
// };
// static digitA digit6 = {
//     //
//     {
//         //
//         {DEG0, -DEG90},  //
//         {-DEG90, DEG90}, //
//         {-DEG90, DEG90}, //
//         {-DEG90, DEG90}, //
//         {-DEG90, DEG90}, //
//         {DEG90, DEG0}    //
//     },                   //
//     {
//         {DEG180, DEG0},  //
//         {DEG270, DEG0},  //
//         {DEG0, DEG90},   //
//         {DEG270, DEG90}, //
//         {DEG270, DEG90}, //
//         {DEG180, DEG0}   //
//     },
//     {
//         {DEG180, -DEG90}, //
//         {DEG180, DEG90},  //
//         {-DEG90, DEG180}, //
//         {DEG270, DEG90},  //
//         {DEG270, DEG90},  //
//         {DEG180, DEG90}   //
//     }
//     //
//     //
// };
// static digitA digit7 = {
//     //
//     {
//         //
//         {DEG0, -DEG90},   //
//         {DEG0, DEG90},    //
//         {DEG225, DEG225}, //
//         {-DEG90, DEG45},  //
//         {-DEG90, DEG90},  //
//         {DEG90, DEG0}     //
//     },                    //
//     {
//         {DEG180, DEG0},   //
//         {DEG270, DEG180}, //
//         {DEG225, DEG90},  //
//         {DEG270, DEG45},  //
//         {DEG270, DEG90},  //
//         {DEG180, DEG90}   //
//     },
//     {
//         {DEG180, -DEG90}, //
//         {DEG270, DEG90},  //
//         {DEG225, DEG90},  //
//         {DEG225, DEG225}, //
//         {DEG225, DEG225}, //
//         {DEG225, DEG225}  //
//     }
//     //
//     //
// };
// static digitA digit8 = {
//     //
//     {
//         //
//         {DEG0, -DEG90},  //
//         {-DEG90, DEG90}, //
//         {DEG90, -DEG45}, //
//         {-DEG90, DEG45}, //
//         {-DEG90, DEG90}, //
//         {DEG90, DEG0}    //
//     },                   //
//     {
//         {DEG180, DEG0},   //
//         {DEG270, -DEG90}, //
//         {DEG90, DEG90},   //
//         {DEG270, -DEG90}, //
//         {DEG90, DEG90},   //
//         {DEG180, DEG0}    //
//     },
//     {
//         {DEG180, -DEG90}, //
//         {DEG270, DEG90},  //
//         {DEG225, DEG90},  //
//         {DEG270, DEG135}, //
//         {DEG270, DEG90},  //
//         {DEG180, DEG90}   //
//     }
//     //
//     //
// };
// static digitA digit9 = {
//     {
//         //
//         {DEG0, -DEG90},  //
//         {-DEG90, DEG90}, //
//         {-DEG90, DEG90}, //
//         {DEG0, DEG90},   //
//         {-DEG90, DEG0},  //
//         {DEG90, DEG0}    //
//     },                   //
//     {
//         {DEG180, DEG0},   //
//         {-DEG90, -DEG90}, //
//         {DEG90, DEG90},   //
//         {DEG270, DEG180}, //
//         {DEG180, DEG90},  //
//         {DEG180, DEG0}    //
//     },
//     {
//         {DEG180, -DEG90}, //
//         {DEG270, DEG90},  //
//         {-DEG90, DEG90},  //
//         {DEG270, DEG90},  //
//         {DEG270, DEG90},  //
//         {DEG180, DEG90}   //
//     }
//     //
//     //
// };

static digitA digitArray[10] = {
    //
    //
    {
        //
        {
            //
            {DEG0, -DEG90},  //
            {-DEG90, DEG90}, //
            {-DEG90, DEG90}, //
            {-DEG90, DEG90}, //
            {-DEG90, DEG90}, //
            {DEG90, DEG0}    //
       },                   //
        {
            {DEG180, DEG0},  //
            {DEG270, DEG90}, //
            {-DEG90, DEG90}, //
            {DEG270, DEG90}, //
            {DEG270, DEG90}, //
            {DEG180, DEG0}   //
        },
        {
            {DEG180, -DEG90}, //
            {DEG270, DEG90},  //
            {-DEG90, DEG90},  //
            {DEG270, DEG90},  //
            {DEG270, DEG90},  //
            {DEG180, DEG90}   //
        }
        //
        //
    },
    {
        //
        {
            //
            {DEG0, -DEG90},   //
            {DEG0, DEG90},    //
            {DEG225, DEG225}, //
            {DEG225, DEG225}, //
            {DEG225, DEG225}, //
            {DEG225, DEG225}  //
        },                    //
        {
            {DEG180, DEG0},   //
            {DEG180, -DEG90}, //
            {DEG90, -DEG90},  //
            {DEG270, DEG90},  //
            {DEG270, DEG90},  //
            {DEG90, DEG0}     //
        },
        {
            {DEG180, -DEG90}, //
            {DEG270, DEG90},  //
            {-DEG90, DEG90},  //
            {DEG270, DEG90},  //
            {DEG270, DEG90},  //
            {DEG180, DEG90}   //
        }
        //
        //
    },
    {
        //
        {
            //
            {DEG0, -DEG90},  //
            {DEG0, DEG90},   //
            {DEG0, -DEG90},  //
            {-DEG90, DEG90}, //
            {-DEG90, DEG90}, //
            {DEG90, DEG0}    //
        },                   //
        {
            {DEG180, DEG0},   //
            {DEG270, DEG180}, //
            {DEG180, DEG90},  //
            {-DEG90, DEG0},   //
            {DEG90, DEG0},    //
            {DEG180, DEG0}    //
        },
        {
            {DEG180, -DEG90}, //
            {DEG270, DEG90},  //
            {-DEG90, DEG90},  //
            {DEG180, DEG90},  //
            {DEG180, -DEG90}, //
            {DEG180, DEG90}   //
        }
        //
    },
    {
        //
        {
            //
            {DEG0, -DEG90}, //
            {DEG0, DEG90},  //
            {DEG0, -DEG90}, //
            {DEG0, DEG90},  //
            {DEG270, DEG0}, //
            {DEG90, DEG0}  //
        },                  //
        {
            {DEG180, DEG0},   //
            {DEG180, -DEG90}, //
            {DEG180, DEG90},  //
            {DEG180, -DEG90}, //
            {DEG180, DEG90},  //
            {DEG180, DEG0}    //
        },
        {
            {DEG180, -DEG90}, //
            {DEG270, DEG90},  //
            {-DEG90, DEG90},  //
            {DEG270, DEG90},  //
            {DEG270, DEG90},  //
            {DEG180, DEG90}   //
        }
        //
    },
    {
        //
        {
            //
            {DEG0, -DEG90},   //
            {-DEG90, DEG90},  //
            {-DEG90, DEG90},  //
            {DEG0, DEG90},    //
            {DEG225, DEG225}, //
            {DEG225, DEG225}  //
        },                    //
        {
            {DEG180, -DEG90}, //
            {DEG270, DEG90},  //
            {DEG0, DEG90},    //
            {DEG270, DEG180}, //
            {DEG270, DEG90},  //
            {DEG90, DEG0}     //
        },
        {
            {DEG180, -DEG90}, //
            {DEG270, DEG90},  //
            {-DEG90, DEG90},  //
            {DEG270, DEG90},  //
            {DEG270, DEG90},  //
            {DEG180, DEG90}   //
        }
        //
    },
    {
        //
        {
            //
            {DEG0, -DEG90},  //
            {-DEG90, DEG90}, //
            {-DEG90, DEG90}, //
            {DEG0, DEG90},   //
            {-DEG90, DEG0},  //
            {DEG90, DEG0}    //
        },                   //
        {
            {DEG180, DEG0},   //
            {DEG0, -DEG90},   //
            {DEG0, DEG90},    //
            {DEG180, -DEG90}, //
            {DEG180, DEG90},  //
            {DEG180, DEG0}    //
        },
        {
            {DEG180, -DEG90}, //
            {DEG180, DEG90},  //
            {DEG180, -DEG90}, //
            {DEG270, DEG90},  //
            {DEG270, DEG90},  //
            {DEG180, DEG90}   //
        }
        //
    },
    {
        //
        {
            //
            {DEG0, -DEG90},  //
            {-DEG90, DEG90}, //
            {-DEG90, DEG90}, //
            {-DEG90, DEG90}, //
            {-DEG90, DEG90}, //
            {DEG90, DEG0}    //
        },                   //
        {
            {DEG180, DEG0},  //
            {DEG270, DEG0},  //
            {DEG0, DEG90},   //
            {DEG270, DEG90}, //
            {DEG270, DEG90}, //
            {DEG180, DEG0}   //
        },
        {
            {DEG180, -DEG90}, //
            {DEG180, DEG90},  //
            {-DEG90, DEG180}, //
            {DEG270, DEG90},  //
            {DEG270, DEG90},  //
            {DEG180, DEG90}   //
        }
        //
    },
    {
        //
        {
            //
            {DEG0, -DEG90},   //
            {DEG0, DEG90},    //
            {DEG225, DEG225}, //
            {-DEG90, DEG45},  //
            {-DEG90, DEG90},  //
            {DEG90, DEG0}     //
        },                    //
        {
            {DEG180, DEG0},   //
            {DEG270, DEG180}, //
            {DEG225, DEG90},  //
            {DEG270, DEG45},  //
            {DEG270, DEG90},  //
            {DEG180, DEG90}   //
        },
        {
            {DEG180, -DEG90}, //
            {DEG270, DEG90},  //
            {DEG225, DEG90},  //
            {DEG225, DEG225}, //
            {DEG225, DEG225}, //
            {DEG225, DEG225}  //
        }
        //
    },
    {
        //
        {
            //
            {DEG0, -DEG90},  //
            {-DEG90, DEG90}, //
            {DEG90, -DEG45}, //
            {-DEG90, DEG45}, //
            {-DEG90, DEG90}, //
            {DEG90, DEG0}    //
        },                   //
        {
            {DEG180, DEG0},   //
            {DEG270, -DEG90}, //
            {DEG90, DEG90},   //
            {DEG270, -DEG90}, //
            {DEG90, DEG90},   //
            {DEG180, DEG0}    //
        },
        {
            {DEG180, -DEG90}, //
            {DEG270, DEG90},  //
            {DEG225, DEG90},  //
            {DEG270, DEG135}, //
            {DEG270, DEG90},  //
            {DEG180, DEG90}   //
        }
        //
    },
    {
        {
            //
            {DEG0, -DEG90},  //
            {-DEG90, DEG90}, //
            {-DEG90, DEG90}, //
            {DEG0, DEG90},   //
            {-DEG90, DEG0},  //
            {DEG90, DEG0}    //
        },                   //
        {
            {DEG180, DEG0},   //
            {-DEG90, -DEG90}, //
            {DEG90, DEG90},   //
            {DEG270, DEG180}, //
            {DEG180, DEG90},  //
            {DEG180, DEG0}    //
        },
        {
            {DEG180, -DEG90}, //
            {DEG270, DEG90},  //
            {-DEG90, DEG90},  //
            {DEG270, DEG90},  //
            {DEG270, DEG90},  //
            {DEG180, DEG90}   //
        }
        //
    }};

digitA *getDigitPtr(uint8_t digit) {
  if (digit > 9) {
    return nullptr;
  }
   return &(digitArray[digit]);
 }
