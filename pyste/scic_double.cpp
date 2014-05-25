
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/scic.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(scic_double)
{
    class_< SPUC::scic<double> >("scic_double", init< const SPUC::scic<double>& >())
        .def(init< optional< char, long int > >())
        .def("num_stages", &SPUC::scic<double>::num_stages)
        .def("decimate", &SPUC::scic<double>::decimate)
    ;

}

