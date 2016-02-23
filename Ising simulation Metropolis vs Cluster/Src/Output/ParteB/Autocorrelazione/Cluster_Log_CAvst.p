## prototipo di grafico x y con barra di errore

clear
reset

set title "Funzione di correlazione CA(t) vs t con algoritmo SWENDEN-WANG (valore ottenuto con ~5000 campioni per punto)"


set xlabel "t"


set ylabel "CA(t)"

 set xrange [0:20]
 set yrange [0.05:1]
set xtics 5
set ytics 0,0.1

plot "Cluster_CAvst_0.dat" title "beta=0.32" 		w l lt 1 
replot "Cluster_CAvst_1.dat" title "beta=0.39" 	w l				lt 2
replot "Cluster_CAvst_2.dat" title "beta=0.41" 	w l				lt 3
replot "Cluster_CAvst_3.dat" title "beta=0.425" 	w l			lt 4
replot "Cluster_CAvst_4.dat" title "beta critico" 	w l			lt 5

g(x) = exp(-2)
replot g(x) title "( e^-2)" lt -2

set log y

A= 40
B = 0.05225

f(x) = B*exp(-x/A)
#fit f(x) "Cluster_Tc_SoStvsT_N300.dat" via A,B
replot f(x) title "slope = 40 "


replot

