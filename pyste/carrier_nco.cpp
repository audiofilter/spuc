
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/carrier_nco.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SPUC_carrier_nco_clock_overloads_0_2, clock, 0, 2)


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(carrier_nco)
{
    class_< SPUC::carrier_nco >("carrier_nco", init<  >())
        .def(init< const SPUC::carrier_nco& >())
        .def("set_frequency", &SPUC::carrier_nco::set_frequency)
        .def("reset_frequency", &SPUC::carrier_nco::reset_frequency)
        .def("get_phase", &SPUC::carrier_nco::get_phase)
        .def("clock", &SPUC::carrier_nco::clock, SPUC_carrier_nco_clock_overloads_0_2())
    ;

}

