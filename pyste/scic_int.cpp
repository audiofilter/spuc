
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/scic.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(scic_int)
{
    class_< SPUC::scic<int> >("scic_int", init< const SPUC::scic<int>& >())
        .def(init< optional< char, long int > >())
        .def("num_stages", &SPUC::scic<int>::num_stages)
        .def("decimate", &SPUC::scic<int>::decimate)
    ;

}

