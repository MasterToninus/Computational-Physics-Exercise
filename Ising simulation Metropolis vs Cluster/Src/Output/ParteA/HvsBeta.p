## prototipo di grafico x y con barra di errore

clear
reset

##set title "<H/V> vs beta (valore ottenuto con 1500 campioni per punto)"


set xlabel "Beta"
set xrange [0.02:0.9]

set ylabel "<H>"
set yrange [-2.02:0]
set trange [-2.02:0]

plot "HvsBeta_N100.dat" using 1:2:3 title "L = 100" w yerrorbars lt 7 lc 3 lw 2
replot "HvsBeta_N100.dat" using 1:2 notitle with lines lt 1 lc 3

set parametric
const=0.4406868
replot const,t lt -2 title "beta_crit" 
