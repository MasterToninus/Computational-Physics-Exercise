
clear
reset


plot 'HmediovsStep_rho0.dat' w line
replot 'HmediovsStep_rho1.dat' w line
replot 'HmediovsStep_rho2.dat' w line

replot 'HistvsStep_rho0.dat' w line
replot 'HistvsStep_rho1.dat' w line
replot 'HistvsStep_rho2.dat' w line



replot - sqrt(pi/2)
