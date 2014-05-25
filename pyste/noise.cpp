
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/noise.h>

// Using =======================================================================
using namespace boost::python;

// Declarations ================================================================
namespace  {

BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(SPUC_noise_set_seed_overloads_0_1, set_seed, 0, 1)


}// namespace 


// Module ======================================================================
BOOST_PYTHON_MODULE(noise)
{
    class_< SPUC::noise >("noise", init< const SPUC::noise& >())
        .def(init< optional< SPUC::float_type > >())
        .def("gauss", &SPUC::noise::gauss)
        .def("Cgauss", &SPUC::noise::Cgauss)
        .def("uni", &SPUC::noise::uni)
        .def("uniform", &SPUC::noise::uniform)
        .def("set_seed", &SPUC::noise::set_seed, SPUC_noise_set_seed_overloads_0_1())
    ;

}

