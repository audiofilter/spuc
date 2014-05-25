
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/timing_nco.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SPUC_timing_nco_run_overloads_0_2, run, 0, 2)


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(timing_nco)
{
    class_< SPUC::timing_nco >("timing_nco", init<  >())
        .def(init< const SPUC::timing_nco& >())
        .def("set_frequency", &SPUC::timing_nco::set_frequency)
        .def("reset_frequency", &SPUC::timing_nco::reset_frequency)
        .def("get_off1", &SPUC::timing_nco::get_off1)
        .def("get_off2", &SPUC::timing_nco::get_off2)
        .def("get_phase1", &SPUC::timing_nco::get_phase1)
        .def("get_phase2", &SPUC::timing_nco::get_phase2)
        .def("run", &SPUC::timing_nco::run, SPUC_timing_nco_run_overloads_0_2())
        .def("residual_phase", &SPUC::timing_nco::residual_phase)
    ;

}

