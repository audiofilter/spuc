
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/cic.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SPUC_cic_double_interpolate_overloads_0_2, interpolate, 0, 2)


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(cic_double)
{
    class_< SPUC::cic<double> >("cic_double", init< const SPUC::cic<double>& >())
        .def(init< optional< char > >())
        .def("reset", &SPUC::cic<double>::reset)
        .def("num_stages", &SPUC::cic<double>::num_stages)
        .def("interpolate", &SPUC::cic<double>::interpolate, SPUC_cic_double_interpolate_overloads_0_2())
        .def("decimate", &SPUC::cic<double>::decimate)
    ;

}

