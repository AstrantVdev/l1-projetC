//
// Created by 33611 on 12/04/2023.
//

#include "id.h"



unsigned int get_next_id()
{
    static int global_id = 1;
    return global_id++;
}
