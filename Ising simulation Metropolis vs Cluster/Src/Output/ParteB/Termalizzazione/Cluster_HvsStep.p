## prototipo di grafico x y con barra di errore

clear
reset

set title "H vs step Algoritmo di Clusterpolis  (L = 100)"


set xlabel "step"
set xrange [0:50]

set ylabel "H"
set yrange [-2.1:0.1]

plot "Cluster_Hvsstep_TH_para.dat" using 1:2 title "beta = 0.33" lt 3 lc 2
replot "Cluster_Hvsstep_TH_para.dat" using 1:2 notitle with lines lt 3 lc 2

replot "Cluster_Hvsstep_TH_ferro.dat" using 1:2 notitle lt 6 lc 2
replot "Cluster_Hvsstep_TH_ferro.dat" using 1:2 notitle with lines lt 6 lc 2

replot "Cluster_Hvsstep_Tc_para.dat" using 1:2 title "beta = 0.44" lt 2  lc 3
replot "Cluster_Hvsstep_Tc_para.dat" using 1:2 notitle with lines lt 2 lc 3

replot "Cluster_Hvsstep_Tc_ferro.dat" using 1:2 notitle "beta = 0.44 " lt 5  lc 3
replot "Cluster_Hvsstep_Tc_ferro.dat" using 1:2 notitle with lines lt 5 lc 3

replot "Cluster_Hvsstep_TL_para.dat" using 1:2 title "beta = 0.7" lt 1 lc 1
replot "Cluster_Hvsstep_TL_para.dat" using 1:2 notitle with lines lt 1 lc 1

replot "Cluster_Hvsstep_TL_ferro.dat" using 1:2 notitle  lt 4 lc 1
replot "Cluster_Hvsstep_TL_ferro.dat" using 1:2 notitle with lines lt 4 lc 1
