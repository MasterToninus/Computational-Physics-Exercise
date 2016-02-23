## prototipo di grafico x y con barra di errore

clear
reset

set title "Sigma_H vs beta ( con m=12 ampiezza campione di binning)"


set xlabel "Beta"
# set xrange [0:5]

set ylabel "Sigma_M"
# set yrange [-2:2]

plot "H_SigmaJackvsBeta_N80.dat" using 1:2 	title "Jacknife N=80" w lines lw 1 lc 1  
replot "H_SigmaBinvsBeta_N80.dat" using 1:2	title "Binning N=80" w lines lw 3 lc 1 

replot "H_SigmaJackvsBeta_N60.dat" using 1:2 	title "Jacknife N=60" w lines lw 1 lc 3
replot "H_SigmaBinvsBeta_N60.dat" using 1:2	title "Binning N=60" w lines lt 7 lw 3 lc 3


