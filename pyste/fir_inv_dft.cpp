
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/fir_inv_dft.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(fir_inv_dft)
{
    def("inv_dft", &SPUC::inv_dft);
    def("inv_dft_symmetric", &SPUC::inv_dft_symmetric);
}

