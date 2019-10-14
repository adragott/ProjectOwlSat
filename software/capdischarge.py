import numpy as np
import matplotlib.pyplot as pyplot

def discharge():
	Vi = 5.0
	R = 3
	C = 2
	time = np.arange(0, 15, 0.1)
	Vdischarge = Vi * np.exp(-time / (R * C));

	Cdischarge = Vdischarge / R;

	pyplot.plot(time, Vdischarge);
	pyplot.plot(time, Cdischarge);
	pyplot.show()

def charge():
	Vin = 5.0
	time = np.arange(0, 60*1, 0.1)
	C = 2
	R = 2
	Vcharge = Vin * (1 - np.exp(-time / (R * C)))
	Ccharge = Vcharge / R;


	pyplot.plot(time, Vcharge);
	pyplot.plot(time, Ccharge);
	pyplot.show()

charge()
discharge()
