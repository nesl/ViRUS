import numpy
import math
import matplotlib.pyplot as plt 

f0 = file('../run/prices_64K_0.txt', 'r')
f1 = file('../run/prices_64K_1.txt', 'r')
f2 = file('../run/prices_64K_2.txt', 'r')
f3 = file('../run/prices_64K_4.csv', 'r')

l0 = f0.readlines()[1:]
l1 = f1.readlines()[1:]
l2 = f2.readlines()[1:]
l3 = f3.readlines()[1:]



for lx in [l1, l2, l3] :
	
	
	print len(l0), len(lx)

	v1 = []
	v2 = []
	abserrs = []
	dists = []

	for i,j in zip(l0,lx):
		fi = float(i)
		fj = float(j)
		v1.append(fi)
		v2.append(fj)
		diff = fi-fj
		abserr = 0
		abserrdiv = 0
		if (fi != 0) :
			abserr = abs(diff)/fi
		dist = pow(diff,2)
		abserrs.append(abserr)
		dists.append(dist)
		

	nrmse = numpy.sum(dists)/len(dists)
	nrmse = math.sqrt(nrmse)
	nrmse = nrmse/(numpy.max(v1)-numpy.min(v1))
	
	mae = numpy.mean(abserrs)
	
	#plt.plot(v1, v2, 'x')
	#plt.show()

	print "mae = ", "{:10.10f}".format(mae*100)
	#print "wce = ", numpy.max(abserrs)*100
	print "rmse = ","{:10.10f}".format(nrmse*100)

