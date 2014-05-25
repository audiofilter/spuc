
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>

// Includes ====================================================================
#include <spuc/root_raised_cosine_imp.h>

// Using =======================================================================
using namespace boost::python;

// Module ======================================================================
BOOST_PYTHON_MODULE(root_raised_cosine_imp)
{
    def("root_raised_cosine_imp", &SPUC::root_raised_cosine_imp);
}

