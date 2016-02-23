## prototipo di grafico x y con barra di errore

clear
reset

## set title "|M| vs beta (valore ottenuto con 1500 campioni per punto)"
set key left top

set xlabel "beta"
set xrange [0.02:0.9]

set ylabel "<|M|>"
set yrange [-0.01:1.01]
set trange [-0.01:1.01]

plot "MvsBeta_N100.dat" using 1:2:3 title "L = 100" w yerrorbars lt 5 lc 3 lw 2
replot "MvsBeta_N100.dat" using 1:2 notitle with lines lt 1 lc 3			

set parametric
const=0.4406868
replot const,t lt -2 title "beta_crit" 
