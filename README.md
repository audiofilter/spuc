SPUC - Signal Processing Using C++
================================================================================

### Build status - Mac Os X, clang
[![Build Status](https://travis-ci.org/audiofilter/spuc.png)](https://travis-ci.org/audiofilter/spuc)

[![Gitter chat](https://badges.gitter.im/audiofilter/spuc.png)](https://gitter.im/audiofilter/spuc)

This is an update of code that has been on sourceforge for about 14 years. The genesis of this code goes back even further - before decent C++ template support and availability of a useful complex class.

**Note: boost no longer required, unless building python extensions**

**Also most files now use MIT License (check each file)**

For a lite-weight version please checkout spuclib instead as it does not have the Doxygen generated files like this does.

Nor does spuclib have the examples or the python extensions available in audiofilter/pyspuc

Library documentation pages here : http://audiofilter.github.io/spuc/

----
### Various Sub-projects also on Github

PYSPUC - python bindings for spuclib
[![Build Status](https://travis-ci.org/audiofilter/pyspuc.png)](https://travis-ci.org/audiofilter/pyspuc) 

SPUCLIB - CMake build of various libraries without examples, etc
[![Build Status](https://travis-ci.org/audiofilter/spuclib.png)](https://travis-ci.org/audiofilter/spuclib)

SPUC_QPSK - QPSK simulation
[![Build Status](https://travis-ci.org/audiofilter/spuc_qpsk.png)](https://travis-ci.org/audiofilter/spuc_qpsk)

SPUC_FIXED - Fixed point class similiar to SystemC
[![Build Status](https://travis-ci.org/audiofilter/spuc_fixed.png)](https://travis-ci.org/audiofilter/spuc_fixed)

SPUC_FILTER - Demo of QT based GUI filter design based on SPUCLIB
[![Build Status](https://travis-ci.org/audiofilter/spuc_filter.png)](https://travis-ci.org/audiofilter/spuc_filter)


----

### Background Info

Since the code on sourceforge, has not compiled for modern compilers for several years, this update fixes compiler errors and other bugs found in more real-life testing. Also various parts have been updated/upgraded.

For now this is merely an update and is lacking in other documentation and / or examples.

In addition to very very basic examples, there are some in graphic_examples that can be compiled and display data using OpenGL
For this purpose the cpplot project files are added as a subdirectory.
This should work fine on a Mac if you have Boost installed.
The examples display impulse responses for various filters.
There is also an example that display BER for an MLSE Equalizer as noise is added to the input.

Travis is being used to display the build integrity and uses Clang on Mac OSX 10.9. However, this should also work fine with GCC 4.8

----


### Information (details on http://audiofilter.github.io/spuc/ )

SPUC was originally written since early C++ had no complex class as part of a standard. In addition we needed a complex class to support handling fixed-point data types to model real hardware in digital communication ASICs.
After that many filtering classes and functions were added. This allowed trading off stopband and cut-off without having to go to Matlab to recalculate coefficients. So of the filter types supported are

* Butterworth
* Chebyshev
* Elliptic
* Maximally flat FIR
* Remez Equiripple
* Raised Cosine FIR
* Gaussian FIR
* CIC
* Notch filter
* Cut/Boost Filter
* Halfband/Subband IIR filters
	   
Digital Filter types are either FIR or IIR Filters. To separate filter design from filter usage, there are typically different classes involved rather than putting everything into one class.

Thus there is 

* a FIR coefficient class and an IIR coefficient class
* Separate functions that calculate coefficients for the Classic IIR Filters:
	* Butterworth
	* Chebyshev			
	* Elliptic
* Separate functions that calculate coefficients for the various FIR Filters as noted above

Then typically separate classes that can implement these filters

* For IIR filters design can be broken down to biquad sections which is what is typically used in hard-ware

In addition to digital filtering this library handles resampling using

* Polyphase filtering approach
* Cascaded Integrate Comb filters (or CIC filters)
* Irrational resampling with Farrow & Lagrange based filters

================================================================================

#### Equalizers

* FIR Adaptive filters
	* FIR only
	* FIR with Decision Feedback Estimator

* Recursive Least Squares Estimator

* Maximum Likelihood Sequence Estimators
	* MLSD
	* DDFSE
	* RSDFSE

================================================================================

#### Digital Communication Building Blocks

* Phase lock loops + various discriminators
	* For carrier frequency acquistion and tracking
	* For Symbol timing synchronization

* Cordic processor
* QPSK, QAM Single Carrier Modulators/Demodulators
* OFDM 
* Convolutional Encoder + Viterbi Decoder

* Fading Channel




----
### Examples - QPSK BER Simulation for various SNR ratios in AWGN

![QPSK BER](BER.png "QPSK BER example")


----
### A QT App for filter design - Use mouse to shape filters 

http://github.com/audiofilter/spuc_filter

![Demo App in SPUC filter](app.png "Filter example using QT")


-----
### Requirements
* cmake
* boost for graphic examples 

### Building

```sh
mkdir build
cd build
cmake ..
make
```

Extra switches to CMake enable the various examples to be built


* SPUC_BUILD_ALL - Build everything
* SPUC_BUILD_EXAMPLES - Build the examples
* SPUC_BUILD_PLOT_EXAMPLES - Build the examples that plot using python/matplotlib embedded
* SPUC_BUILD_GRAPHIC_EXAMPLES - Build the examples that requires gl,opengl, etc
* SPUC_BUILD_PYTHON_EXTENSION - Build python extensions
