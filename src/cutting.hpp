#ifndef __CUTTING_HPP__
#     define __CUTTING_HPP__
#include "myriaworld.h"

namespace myriaworld
{
    void determine_cuttings(triangle_graph& g);
    void flatten(triangle_graph& g, double fact);
}
#endif /* __CUTTING_HPP__ */