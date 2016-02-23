## prototipo di grafico x y con barra di errore

clear
reset

##set title "H vs step Algoritmo di Clusterpolis  (L = 100)"


set xlabel "step"
set xrange [0:75]

set ylabel "H"
# set yrange [-2:2]

plot "Confronto_Metro_M.dat" using 1:2 title "M metropolis" w l
replot "Confronto_Metro_M_abs.dat" using 1:2 title "|M| metropolis"  w l
replot "Confronto_Cluster_M.dat" using 1:2 title "M improved cluster" w l
