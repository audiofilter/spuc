import numpy
import matplotlib.pyplot as plt
from pyspuc.spuc_filtdes import filtdes

pts = int(100)

x = numpy.ndarray([pts],dtype=float)

s = "Remez FIR"

pass_edge = float(0.1)
trans = float(0.1)
stop_dBs = float(20.0)

taps = int(25)
bits = int(16)
order = int(5)
alpha = float(0.1)

filtdes(x,s,pts,pass_edge,trans,stop_dBs, taps, bits, order, alpha)

plt.plot(x)
plt.show()
#print x
