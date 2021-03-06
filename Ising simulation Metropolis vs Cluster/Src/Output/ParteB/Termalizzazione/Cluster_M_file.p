## prototipo di grafico x y con barra di errore


##set title "M vs step Algoritmo di Cluster  (L = 100)"

plot "Cluster_Mvsstep_TL_para.dat" using 1:2 title "beta = 0.7" lt 1 lc 1
replot "Cluster_Mvsstep_TL_para.dat" using 1:2 notitle with lines lt 1 lc 1

replot "Cluster_Mvsstep_TL_ferro.dat" using 1:2 notitle  lt 4 lc 1
replot "Cluster_Mvsstep_TL_ferro.dat" using 1:2 notitle with lines lt 4 lc 1

replot "Cluster_Mvsstep_Tc_para.dat" using 1:2 title "beta = 0.44" lt 2  lc 3
replot "Cluster_Mvsstep_Tc_para.dat" using 1:2 notitle with lines lt 2 lc 3

replot "Cluster_Mvsstep_Tc_ferro.dat" using 1:2 notitle "beta = 0.44 " lt 5  lc 3
replot "Cluster_Mvsstep_Tc_ferro.dat" using 1:2 notitle with lines lt 5 lc 3

replot "Cluster_Mvsstep_TH_para.dat" using 1:2 title "beta = 0.33" lt 3 lc 2
replot "Cluster_Mvsstep_TH_para.dat" using 1:2 notitle with lines lt 3 lc 2

replot "Cluster_Mvsstep_TH_ferro.dat" using 1:2 notitle lt 6 lc 2
replot "Cluster_Mvsstep_TH_ferro.dat" using 1:2 notitle with lines lt 6 lc 2

set terminal postscript eps size 16cm,9cm enhanced color \
    font 'Helvetica,25' linewidth 1.5
set pointsize 1.45

#set title "M{/Symbol a} vs step Algoritmo di Metropolis  (L=100)"
set grid

set log x
set xlabel " step" offset 0,1.5
#set xrange [0:50]

set ylabel "|M|" offset 3.5 rotate by 90
 set yrange [-0.1:1.1]

set xtics nomirror
set ytics nomirror

set output 'Cluster_M.eps'
replot
set output '|epstopdf Cluster_M.eps'

set term x11
set output


