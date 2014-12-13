
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/allpass.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(allpass_double)
{
    class_< SPUC::allpass<double,double> >("allpass_double", init< const SPUC::allpass<double,double>& >())
			//        .def(init< std::vector<double>, int >())
			.def(init< optional< long int > >())
			.def_readwrite("stages", &SPUC::allpass<double,double>::stages)
			.def_readwrite("ap", &SPUC::allpass<double,double>::ap)
			.def("get_coefficient", &SPUC::allpass<double,double>::get_coefficient)
			.def("init", &SPUC::allpass<double,double>::init)
			.def("reset", &SPUC::allpass<double,double>::reset)
			.def("set_coeffs", &SPUC::allpass<double,double>::set_coeffs)
			.def("clock", &SPUC::allpass<double,double>::clock)
    ;

}

