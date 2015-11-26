#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_include
#include <cmath>  // for floor
#ifdef USE_ASSERT
#include <cassert>
#define SPUC_ASSERT(expr) assert(expr);
#else
#define SPUC_ASSERT(expr) ((void)0)
#endif
#include <spuc/spuc_typedefs.h>
namespace SPUC {
//! Copyright (c) 1993-2005 Tony Kirke
//! \author = Tony Kirke
//
/*! \mainpage
 <H1>DSP Templates</H1>
 <P><B>Motivation:Why use C++ for DSP Simulation/Modeling?</B>
         <P>Todays IC and system designers typically use either C or costly
         2<SUP>nd</SUP> party tools to simulate/model Digital Signal Processing
         algorithms. While the latter are well suited for modeling "hardwired" DSP blocks
         with rather simplistic dataflows, they are very inefficient for modeling the control logic that is often
 required in todays DSP applications (such as ADSL or V.34 modems).
         while C is well suited to control logic type structures (if,else, case, etc.), it is not highly desireable for
 manipulation of complex
         or user defined data types (such as fixed width integers).
         </P>
         <P><I>C++ bridges this gap and is the underlying language of choice
         for the cumbersome GUI based tools.</I></P>
         <HR>

         <P><B>Objective</B></P>
         <P>The objective of DSP Templates is to provide DSP Algorithm designer with simple, efficient and reusable DSP
 building block objects. Thus allowing a transition from System design to implementation in either programmable DSP
 chips or hardwired DSP logic. While Matlab is perhaps the most useful available tool for this purpose, it can be quite
 slow for simulation and it favors a matrix/block based approach rather than the sample by sample simulations that are
 often most useful for communications systems design. Also Matlab is generally awkward or inefficient when dealing with
 several interactive feedback loops where C/C++ is perhaps the most useful environment. For bit-accurate simulations
 (for VLSI design) C/C++ generally outperforms and is easier to manipulate than Matlab or other GUI-based tools.</P>
         <P>This Class Library</P>
         <ul> <li> 1) basic building blocks such as complex data types, Fixed-bit width integer classes, pure-delay
 blocks, etc.
         <li> 2) Basic DSP building blocks such as FIR, IIR, Allpass, Running Average, Lagrange interpolation filters,
 NCO, Cordic rotator.
         <li> 3) Several communications functions such as timing, phase and frequency discriminators for BPSK/QPSK
 signals.
         <li> 4) Other miscellaneous DSP/Communications related functions/classes.
         <li> 5) Ability to design several types of FIR and IIR filters
         <li> 6) Various adaptive equalizer classes
         <li> 7) This library now includes code from IT 3.7.0.
     <li> 8) Capitalized and uppercase class names are classes not originally in DSP Templates
         </ul>

         <P>The classes are designed so that they can be used in a simple straight forward manner. For example, a FIR
 would be initialized with its tap weights and then simply a member function would be called every time a sample is
 input or an output is required.</p>

         <P>Before discussing why C++ is better than C for DSP programming. Let's look at some of the pros and cons
         for C++ vs. the alternatives.</p>

         <P><B>Pros</B></p>
         <ul><li>  The common alternatives are very costly (Alta's SPW, Synopsys Cossap etc.)
         <li>    Long learning times/training not required for C++ programmers.
         <li>   For complex simulations, C++ is more efficient and yields shorter run times.
         <li>   Ideal for modeling a combination of control logic and hardwired DSP blocks.
         <li>   Code entry can be faster than GUI based tools.
         <li>  Looks closer to Verilog/VHDL than alternative tools.
         <li>  C/C++ has a large user base.
         <li>  Lots of freely available C/C++ code.
         <li>  Infinitely customizable.
         <li>  Portable to different platforms.
         <li>  Can take advantage of Windows GUIs if desired.
         </ul>

         <P><B>Cons</B></p>
         <ul><li>    No standardization!
         <li>    Lack of documentation.
         <li>    Not user friendly/ No GUI.
         <li>    Potential portability problems.
         <li>    No technical support.
         </ul>

         <P>Please see links such as those below for why to use C++ over C in general.</p>
         <BR><A HREF="http://www.cantrip.org/cpp.html">Nathan Myers C++ Articles</A>
         <BR><A HREF="http://math.nist.gov/pozo/c++class/">C++ Programming for Scientists Course (PDF) from NIST</A>
         <BR><A HREF="http://math.nist.gov/pozo/">Various C++ Math classes from Roldan Pozo at NIST</A>
         <P><B>Advantages of C++ over C</B>
         <UL>
         <LI>Object Oriented Language</LI>
         <LI>Abstract Data typing</LI>
         <LI>Inheritance</LI>
         <LI>Polymorphism</LI>
         <LI>Comments do not extend over more than one line</LI>
         <LI>Variables can be declared anywhere.</LI>
         <LI>Dynamic memory allocation is simpler.</LI>
         <LI>Function Overloading</LI>
         </UL>

         <P><B>C++ allows templates and operator overloading.</B>
         <BR>For example, we can define a complex data type based on templates. Then this class can be used whether we
 need floating point (double), integer, or user defined fixed bit width data types.This not only requires less code to
 document/debug, but also through operator overloading we can make the code much easier to read and potentially make the
 look and feel very close to a Hardware Description Language (HDL)such as Verilog or VHDL. Also this style makes it much
 easier to change your programs data types (from floating point -> integer -> fixed bit width for example), without
 having to change every line of code.
         <P><B>C++ allows for much better interfaces between classes or DSP blocks.</B>
         <BR>Because C++ supports initialization through constructors
         and there can be a variety of member functions, data can be handled in
         a much smoother manner than C. With data hiding, the code becomes much
         simpler to read, allowing a high level look at the code.

         <P><B>Inheritance</B>
         <BR>Inheritance helps you to re-use code.You can derive new types or classes from an old one and make changes
 only where you need them. This promotes code re-use.
         <P><B>Classes</B>
         <UL><LI>Hide complexity.</LI>
         <LI>Create a more convenient object oriented interfaces</LI>
         <LI>Can create more than one instance of a structure.</LI>
         <LI>Similar to C structure but can include functions.</LI>
         <LI>Data abstraction and hiding allows changes to be localized to one section.</LI>
         <LI>Private, Protected, Public members</LI></UL>

         <P><B>For Hardware Modeling</B>
         <BR>C++ can be made to replicate hardware much easier than C.
         Functions and variables can be localised to each block (hiding complexity) in the same way that Verilog /VHDL
 does.
         Easier to have a hierarchical structure.
         Classes can be instantiated in same manner as in a HDL (C makes this difficult).
         New chip designs can inherit subblocks or a large section from an old design. Only the new or changed blocks
 need to be coded. Also the interfaces to the chip can remain the same if desired. When classes are designed in this
 manner it is quite easy to see the difference between objects.


*/
//! \namespace SPUC - DSP Templates using C++ - A DSP library
//! includes code from other sources including IT++ 3.7.0
//! \author Tony Kirke,  Copyright(c) 2006
#ifndef PI
#define PI M_PI
#endif
#define TWOPI 2*M_PI
#define HALFPI 0.5*M_PI
#define QUARTPI 0.25*M_PI

// log2 is in tgmath.h on linux but not in MSVC
#ifndef _TGMATH_H
#define OM_LN2 1.0 / 0.69314718055994530942 /* 1.0/(log_e 2) */
#define log2(n) log(n) * OM_LN2
#endif

// one-line functions
#ifndef MAX
template <typename T> T MAX(T a, T b) { return a < b ? b : a; }
#endif
#ifndef MIN
template <typename T> T MIN(T a, T b) { return a < b ? a : b; }
#endif
#ifndef ABS
template <typename T> T ABS(T a) { return a < 0 ? -a : a; }
#endif
template <typename T> T SQR(T a) { return a * a; }
template <typename T> T SGN(T a) { return a < 0 ? -(T)1 : (T)1; }
// macros

#define MASK_LOW(n) ((1 << n) - 1)
#define MASK_BIT(n) (1 << n)
#define MASK_NEG_HI(n) (-1 << (32 - n))

#define SPUC_TOLONG(x) (long) floor(x + 0.5)
#define SPUC_TOINT(x) (int) floor(x + 0.5)

//! \defgroup base Base classes and functions
//! \defgroup traits Traits classes and functions
//! \defgroup base Base classes and functions
//! \defgroup Allpass Allpass filters
//! \defgroup fir FIR filters
//! \defgroup iir IIR filters
//! \defgroup interpolation Interpolation filters
//! \defgroup misc Miscellaneous DSP
//! \defgroup equalizers Equalization classes And functions
//! \defgroup fec Forward Error Correcting Codes
//! \defgroup comm Communication classes And functions
//! \defgroup PLL   Phase lock loop functions
//! \defgroup btsc  BTSC related classes and functions
//! \defgroup interl Interleavers
//! \defgroup windfunc Windows
//! \defgroup sim Simulation classes And functions
//! \defgroup errorhandlingfunc Error handling functions
//! \defgroup classes SPUC non-template classes
//! \defgroup complex_templates SPUC complex templates
//! \defgroup double_templates SPUC double templates
//! \defgroup double_utemplates SPUC double templates restricted
//! \defgroup functions SPUC functions
//! \defgroup misc SPUC misc stuff
//! \defgroup n_templates SPUC templates with numeric parameters
//! \defgroup real_double_templates SPUC double templates with real parameters
//! \defgroup real_templates SPUC templates with real parameters
//! \defgroup templates SPUC templates
//! \defgroup template_functions SPUC templates functions
//! \defgroup types SPUC basic types
}  // namespace SPUC
