//
// Created by 33611 on 12/04/2023.
//

#include "id.h"

unsigned int global_id = 1;

unsigned int get_next_id()
{
    return global_id++;
}
