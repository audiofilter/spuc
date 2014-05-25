
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/raised_cosine_imp.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(raised_cosine_imp)
{
    def("raised_cosine_imp", &SPUC::raised_cosine_imp);
}

