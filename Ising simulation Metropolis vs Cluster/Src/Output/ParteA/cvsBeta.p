## prototipo di grafico x y con barra di errore

clear
reset

set title "C vs beta (valore ottenuto con 1500 campioni per punto)"
set key left top

set xlabel "beta"
	set xrange [0: 0.9]

set ylabel "<c>"
	set yrange [-0.02:2.5]

plot "cvsBeta_N100.dat" using 1:2:3 title "N = 100" w yerrorbars lt 3
replot "cvsBeta_N100.dat" using 1:2 notitle with lines lt 3

set parametric
const=0.4406868
replot const,t lt -2 title "beta_crit"


  
