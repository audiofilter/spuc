
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/cic.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SPUC_cic_int_interpolate_overloads_0_2, interpolate, 0, 2)


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(cic_int)
{
    class_< SPUC::cic<int> >("cic_int", init< const SPUC::cic<int>& >())
        .def(init< optional< char > >())
        .def("reset", &SPUC::cic<int>::reset)
        .def("num_stages", &SPUC::cic<int>::num_stages)
        .def("interpolate", &SPUC::cic<int>::interpolate, SPUC_cic_int_interpolate_overloads_0_2())
        .def("decimate", &SPUC::cic<int>::decimate)
    ;

}

