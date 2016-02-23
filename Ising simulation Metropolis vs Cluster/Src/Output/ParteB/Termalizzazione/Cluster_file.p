##set title "H vs step Algoritmo di Clusterpolis  (L = 100)"

clear
reset

set terminal postscript eps size 18cm,18cm enhanced color \
    font 'Helvetica,25' linewidth 1.5
set output 'Cluster.eps'
set pointsize 1.45


unset xtics
unset ytics

set multiplot layout 2,1 
##############
unset title
set tmargin 1
set bmargin 1.5
# set lmargin 3
set rmargin 2


set log x
set xlabel " step" offset 0,1.5
#set xrange [0:50]

set ylabel "H" offset 3.5 rotate by 0
 set yrange [-2.1:0.1]

set grid
# unset border
 set xzeroaxis lc -1 lt -1 lw 1
 set yzeroaxis lc -1 lt -1 lw 1
set xtics nomirror
set ytics nomirror

plot "Cluster_Hvsstep_TH_para.dat" using 1:2 title "beta = 0.33" lt 3 lc 2	 lw 2.5 ,   "Cluster_Hvsstep_TH_para.dat" using 1:2 notitle with lines lt 3 lc 2  lw 2.5 ,	  "Cluster_Hvsstep_TH_ferro.dat" using 1:2 notitle lt 6 lc 2	 lw 2.5 ,		"Cluster_Hvsstep_TH_ferro.dat" using 1:2 notitle with lines lt 6 lc 2	 lw 2.5 ,	"Cluster_Hvsstep_Tc_para.dat" using 1:2 title "beta = 0.44" lt 2  lc 3	 lw 2.5 ,	"Cluster_Hvsstep_Tc_para.dat" using 1:2 notitle with lines lt 2 lc 3	 lw 2.5 ,	"Cluster_Hvsstep_Tc_ferro.dat" using 1:2 notitle "beta = 0.44 " lt 5  lc 3	 lw 2.5 ,	"Cluster_Hvsstep_Tc_ferro.dat" using 1:2 notitle with lines lt 5 lc 3	 lw 2.5 ,  "Cluster_Hvsstep_TL_para.dat" using 1:2 title "beta = 0.7" lt 1 lc 1  lw 2.5 ,  "Cluster_Hvsstep_TL_para.dat" using 1:2 notitle with lines lt 1 lc 1  lw 2.5 ,  "Cluster_Hvsstep_TL_ferro.dat" using 1:2 notitle  lt 4 lc 1			 lw 2.5 ,  "Cluster_Hvsstep_TL_ferro.dat" using 1:2 notitle with lines lt 4 lc 1	

##############
unset title
set tmargin 1
set bmargin 2.35
# set lmargin 3
set rmargin 2

set log x
set xlabel " step" offset 0,1.5
#set xrange [0:50]

set ylabel "|M|" offset 3.5 rotate by 0
 set yrange [-0.1:1.1]

set grid
# unset border
 set xzeroaxis lc -1 lt -1 lw 1
 set yzeroaxis lc -1 lt -1 lw 1
set xtics nomirror
set ytics nomirror

plot "Cluster_Mvsstep_TL_para.dat" using 1:2 title "beta = 0.7" lt 1 lc 1  lw 2.5  , "Cluster_Mvsstep_TL_para.dat" using 1:2 notitle with lines lt 1 lc 1  lw 2.5 , "Cluster_Mvsstep_TL_ferro.dat" using 1:2 notitle  lt 4 lc 1  lw 2.5 , "Cluster_Mvsstep_TL_ferro.dat" using 1:2 notitle with lines lt 4 lc 1  lw 2.5 , "Cluster_Mvsstep_Tc_para.dat" using 1:2 title "beta = 0.44" lt 2  lc 3  lw 2.5 , "Cluster_Mvsstep_Tc_para.dat" using 1:2 notitle with lines lt 2 lc 3  lw 2.5 , "Cluster_Mvsstep_Tc_ferro.dat" using 1:2 notitle "beta = 0.44 " lt 5  lc 3  lw 2.5 , "Cluster_Mvsstep_Tc_ferro.dat" using 1:2 notitle with lines lt 5 lc 3  lw 2.5 , "Cluster_Mvsstep_TH_para.dat" using 1:2 title "beta = 0.33" lt 3 lc 2  lw 2.5 , "Cluster_Mvsstep_TH_para.dat" using 1:2 notitle with lines lt 3 lc 2  lw 2.5 , "Cluster_Mvsstep_TH_ferro.dat" using 1:2 notitle lt 6 lc 2  lw 2.5 , "Cluster_Mvsstep_TH_ferro.dat" using 1:2 notitle with lines lt 6 lc 2

##############

unset multiplot
set output '|epstopdf Cluster.eps'

set term x11
set output
