## prototipo di grafico x y con barra di errore

clear
reset

set title "Funzione di correlazione CA(t) vs t con algoritmo METROPOLIS (valore ottenuto con ~50000 campioni per punto, L = 100)"


set xlabel "t"
# set xrange [0:5]

set ylabel "CA(t)"
# set yrange [-2:2]

set xtics 5
set mxtics 2.5
set ytics 0,0.1

plot[0:100] "Metro_CAvst_0.dat" title "beta=0.32" 		w l
replot "Metro_CAvst_1.dat" title "beta=0.39" 	w l
replot "Metro_CAvst_2.dat" title "beta=0.41" 	w l
replot "Metro_CAvst_3.dat" title "beta=0.425" 	w l
replot "Metro_CAvst_4.dat" title "beta critico" 	w l

f(x) = exp(-2)
replot f(x) title "( e^-2)" lt -2
