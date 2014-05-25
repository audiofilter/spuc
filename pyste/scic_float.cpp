
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/scic.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(scic_float)
{
    class_< SPUC::scic<float> >("scic_float", init< const SPUC::scic<float>& >())
        .def(init< optional< char, long int > >())
        .def("num_stages", &SPUC::scic<float>::num_stages)
        .def("decimate", &SPUC::scic<float>::decimate)
    ;

}

