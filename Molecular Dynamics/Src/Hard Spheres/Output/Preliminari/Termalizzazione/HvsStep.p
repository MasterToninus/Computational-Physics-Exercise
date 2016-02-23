
clear
reset


plot 'HmediovsStep_eta0.dat' w line
replot 'HmediovsStep_eta1.dat' w line
replot 'HmediovsStep_eta2.dat' w line

replot 'HistvsStep_eta0.dat' w line
replot 'HistvsStep_eta1.dat' w line
replot 'HistvsStep_eta2.dat' w line



replot - sqrt(pi/2)
