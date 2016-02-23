
clear
reset


f(x) = exp(-0.5*x**2)/sqrt(pi*2)

plot 'IstoVx_eta0.dat' w boxes
replot 'IstoVx_eta1.dat' w boxes
replot 'IstoVx_eta2.dat' w boxes
replot f(x)
