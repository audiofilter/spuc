CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE "DEBUG")
ENDIF()
PROJECT("spuc_extensions")
Message("project spuc_extensions")

IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
set(CMAKE_CXX_FLAGS "-Wall -std=c++11 ")
ENDIF()

SET(EXTS agc
allpass_1aq1
allpass_1aq2
bit
allpass_double
base_demod_double
bit_scrambler
bpsk_ber_test
builtin
butterworth_allpass
butterworth_fir
butterworth_iir
carrier_nco
cfft
chebyshev_iir
cic_double
circ_buffer_double
complex_double
complex_float
complex_long
conjr_double
cordic_double
cutboost_double
delay_double
create_remez_lpfir
data_conv_encoder
delay_float
delay_int
dqpsk
fft
elliptic_allpass
elliptic_iir
fading_channel
farrow_double
farrow_upsampler
find_roots
fir_inv_dft
fir_coeff_double
fir_coeff_float
gaussian_fir
idft
ifft
iir_2nd_double
iir_allpass1_cascade_double
iir_allpass1_double
iir_allpass2_double
iir_coeff
iir_comb_double
iir_delay_allpass1_double
iir_df_double
iir_double
iir_exp1_double
iir_float
iir_hpf_double
iir_int
iir_lpf_double
iir_shelf_double
lagrange_double
lms_dfe_double
loop_filter_double
magsqr_double
matrix_complex_double
matrix_complex_float
matrix_complex_int
matrix_complex_long
matrix_double
matrix_float
matrix_int
matrix_long
max_pn
misc
nco
noise
notch_allpass_double
notch_iir_double
qam_conv_decoder
qam_mod
qam_soft_decision
qam_tx_double
qnoise
qpsk_ber_test
qpsk_discriminators
qpsk_double
#qpsk_variable_double
quad_data_double
quantiser_double
raised_cosine_imp
real_template_functions_double
real_template_functions_float
real_template_functions_long
remez_fir
#resampler_double
rls_double
root_raised_cosine_imp
rounder_double
rv_stat
saturater_double
scic_double
sigma_delta
sim_qam_double
sim_qpsk_double
sim_qpsk_float
sim_qpsk_int
sum_and_dump_double
sum_and_dump_float
template_array_functions_double
template_array_functions_complex_float
template_array_functions_float
timing_nco
vco_double
template_array_functions_complex_long
template_array_functions_long
template_functions_complex_double
template_functions_complex_float
template_functions_complex_long
template_functions_double
template_functions_float
template_functions_long
viterbi
window
iir_hpf1_double
iir_lpf1_double
allpass_1_double
allpass_2nd_double
complex_int
convolutional_interleaver_double
dvb_conv_encoder
fir_adapt_double
iir_1st_double
iir_allpass1_halfband_double
mle_double
ofdm_data_encoder
quantizer_double
running_sum_double
signbitr_double
sim_qpsk_variable_double
template_array_functions_complex_double
)

SET(B_EXTS freq_functions spuc_audio spuc_filtdes)
 
FIND_PACKAGE(Boost)
IF(Boost_FOUND)
IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
   # Mac OS X specific code
   SET(OperatingSystem "Mac OS X")
   SET(Boost_USE_STATIC_LIBS ON)
   SET(Boost_USE_MULTITHREADED ON)
ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") 
SET(Boost_USE_STATIC_RUNTIME OFF)
FIND_PACKAGE(Boost COMPONENTS python)

FIND_PACKAGE(PythonLibs REQUIRED)
INCLUDE_DIRECTORIES("${Boost_INCLUDE_DIRS}" ${PYTHON_INCLUDE_DIRS} "/usr/include" "../spuclib")
LINK_DIRECTORIES(${PYTHON_LIBRARY_DIRS} ${Boost_LIBRARY_DIRS} ${CMAKE_CURRENT_LIST_DIR}/../spuclib/build)
 
EXECUTE_PROCESS( COMMAND python -c "from distutils.sysconfig import get_python_lib; print get_python_lib()" OUTPUT_VARIABLE PYTHON_SITE_PACKAGES OUTPUT_STRIP_TRAILING_WHITESPACE)
 
  
FILE(WRITE test_imports "# for testing if imports are ok\n") 

FOREACH(mod ${EXTS})
  FILE(APPEND test_imports "import pyspuc.${mod}\n")
  SET(SRC ../pyste/${mod}.cpp)
  ADD_LIBRARY(${mod} SHARED ${SRC})
  TARGET_LINK_LIBRARIES(${mod} spuc spuc_filt spuc_types ${Boost_LIBRARIES} ${PYTHON_LIBRARIES} )
  SET_TARGET_PROPERTIES(${mod} PROPERTIES PREFIX "")
  SET(LIBRARY_OUTPUT_PATH "../pyspuc")
#  SET(LIBRARY_OUTPUT_PATH ${PYTHON_SITE_PACKAGES}/pyspuc)
ENDFOREACH(mod ${EXTS})
FOREACH(mod ${B_EXTS})
  FILE(APPEND test_imports "import pyspuc.${mod}\n")
  SET(SRC ../boost_src/${mod}.cpp)
  ADD_LIBRARY(${mod} SHARED ${SRC})
  TARGET_LINK_LIBRARIES(${mod} spuc spuc_filt spuc_types ${Boost_LIBRARIES} ${PYTHON_LIBRARIES} )
  SET_TARGET_PROPERTIES(${mod} PROPERTIES PREFIX "")
  SET(LIBRARY_OUTPUT_PATH "../pyspuc")
#  SET(LIBRARY_OUTPUT_PATH ${PYTHON_SITE_PACKAGES}/pyspuc)
ENDFOREACH(mod ${EXTS})

ELSEIF(NOT Boost_FOUND)
  MESSAGE(FATAL_ERROR "Unable to find correct Boost version. Did you set BOOST_ROOT?")
ENDIF()


#ADD_CUSTOM_TARGET(CP_INIT)
ADD_CUSTOM_COMMAND(TARGET filtdes POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_LIST_DIR}/__init__.py  ../pyspuc)
#COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_LIST_DIR}/__init__.py  ${PYTHON_SITE_PACKAGES}/pyspuc)


ADD_DEFINITIONS("-Wall -fPIC -DSPUCBOOST")
