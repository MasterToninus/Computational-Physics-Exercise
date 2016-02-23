
clear
reset


f(x) = exp(-0.5*x**2)/sqrt(pi*2)

plot 'IstoVx_TD_rho0.dat' w boxes
replot 'IstoVx_TD_rho1.dat' w boxes
replot 'IstoVx_TD_rho2.dat' w boxes
replot f(x)
