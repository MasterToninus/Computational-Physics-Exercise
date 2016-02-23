## prototipo di grafico x y con barra di errore

clear
reset

set title "Sigma_M vs beta ( con m=12 ampiezza campione di binning)"


set xlabel "Beta"
set xrange [0.35:0.52]

set ylabel "Sigma_M"
# set yrange [-2:2]

plot "M_SigmaJackvsBeta_N80.dat" using 1:2 	title "Jacknife N=80" w lines lw 1 lc 1  
replot "M_SigmaBinvsBeta_N80.dat" using 1:2	title "Binning N=80" w lines lw 3 lc 1 

replot "M_SigmaJackvsBeta_N60.dat" using 1:2 	title "Jacknife N=60" w lines lw 1 lc 3  
replot "M_SigmaBinvsBeta_N60.dat" using 1:2	title "Binning N=60" w lines lw 3 lc 3 


