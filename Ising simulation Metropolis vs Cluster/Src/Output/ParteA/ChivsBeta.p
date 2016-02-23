## prototipo di grafico x y con barra di errore

clear
reset

set title "Chi vs beta (valore ottenuto con 1500 campioni per punto)"


set xlabel "beta" font "Times-Italic,28" 
	set xrange [0.1: 0.7]

set ylabel "<Chi>" font "Times-Italic,28"
set yrange [0:170]

plot "ChivsBeta_N100.dat" using 1:2:3 title "N = 100" w yerrorbars lt 3
replot "ChivsBeta_N100.dat" using 1:2 notitle with lines lt 3



set parametric
set trange [0:170]

const=0.4406868
replot const,t lt -2 title "beta_crit"
  
