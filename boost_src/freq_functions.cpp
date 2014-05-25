
// Boost Includes ==============================================================
#include <boost/python.hpp>
#include <boost/cstdint.hpp>
#include <boost/python/def.hpp>
#include <boost/python/args.hpp>
#include <boost/python/overloads.hpp>


#include <spuc/ptr_freqz.h>

// Using =======================================================================
using namespace boost::python;


// Module ======================================================================
BOOST_PYTHON_MODULE(freq_functions)
{
  def("freqz_mag",&SPUC::ptr_freqz_mag_point<double>);
}
