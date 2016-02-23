## prototipo di grafico x y con barra di errore

clear
reset

set title "Funzione di correlazione CA(t) vs t con algoritmo METROPOLIS (valore ottenuto con ~50000 campioni per punto)"


set xlabel "t"
set xrange [0:150]

set ylabel "CA(t)"
set yrange [0.01:1]

set xtics 5
set mxtics 2.5
set ytics 0.01,0.1

plot "Metro_CAvst_0.dat" title "beta=0.32" 		w l lt 1
replot "Metro_CAvst_1.dat" title "beta=0.39" 	w l
replot "Metro_CAvst_2.dat" title "beta=0.41" 	w l
replot "Metro_CAvst_3.dat" title "beta=0.425" 	w l
replot "Metro_CAvst_4.dat" title "beta critico" 	w l

set log y

A_0= 1.34
f_0(x) = exp(-x/A_0)
replot f_0(x) title "slope = 1.34 " 

A_1= 2.25
f_1(x) = exp(-x/A_1 * 0.4343)
replot f_1(x) title "slope = 0.5 "
