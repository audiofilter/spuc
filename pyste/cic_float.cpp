
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/cic.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SPUC_cic_float_interpolate_overloads_0_2, interpolate, 0, 2)


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(cic_float)
{
    class_< SPUC::cic<float> >("cic_float", init< const SPUC::cic<float>& >())
        .def(init< optional< char > >())
        .def("reset", &SPUC::cic<float>::reset)
        .def("num_stages", &SPUC::cic<float>::num_stages)
        .def("interpolate", &SPUC::cic<float>::interpolate, SPUC_cic_float_interpolate_overloads_0_2())
        .def("decimate", &SPUC::cic<float>::decimate)
    ;

}

