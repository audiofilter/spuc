### Build status - Mac Os X, clang
[![Build Status](https://travis-ci.org/audiofilter/spuc.png)](https://travis-ci.org/audiofilter/spuc)

[![Gitter chat](https://badges.gitter.im/audiofilter/spuc.png)](https://gitter.im/audiofilter/spuc)

This is an update of code that has been on sourceforge for about 14 years. The genesis of this code goes back even further - before decent C++ template support and availability of a useful complex class.

For a lite-weight version please checkout spuclib instead as it does not have the Doxygen generated files like this does
Nor does spuclib have the examples or the python extensions available in audiofilter/pyspuc

More documentation pages here

http://audiofilter.github.io/spuc/
[http://audiofilter.github.io/spuc/]

### Various Sub-projects also on Github

Sub-projects 
PYSPUC 
[![Build Status](https://travis-ci.org/audiofilter/pyspuc.png)](https://travis-ci.org/audiofilter/pyspuc) 
SPUCLIB 
[![Build Status](https://travis-ci.org/audiofilter/spuclib.png)](https://travis-ci.org/audiofilter/spuclib)
SPUC_QPSK
[![Build Status](https://travis-ci.org/audiofilter/spuc_qpsk.png)](https://travis-ci.org/audiofilter/spuc_qpsk)
SPUC_FIXED 
[![Build Status](https://travis-ci.org/audiofilter/spuc_fixed.png)](https://travis-ci.org/audiofilter/spuc_fixed)
SPUC_FILTER 
[![Build Status](https://travis-ci.org/audiofilter/spuc_filter.png)](https://travis-ci.org/audiofilter/spuc_filter)




Since the code on sourceforge, has not compiled for modern compilers for several years, this update fixes compiler errors and other bugs found in more real-life testing. Also various parts have been updated/upgraded.

For now this is merely an update and is sorely lacking in other documentation and / or examples.
Companion projects such as *spuc_filter* and *spuc_fixed* are also available.
The former is a complete example of a gui-based Digital Filter design program

Travis is being used to display the build integrity and uses Clang on Mac OSX 10.9. However, this should also work fine with GCC 4.8

