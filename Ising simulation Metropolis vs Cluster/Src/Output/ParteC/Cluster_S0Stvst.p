

clear
reset

set title "<S0 St> vs t (Cluster)"


set xlabel "t"
set xrange [0:100]

set ylabel "<S0 St>"
#set yrange [-0.001:0.06]

plot "Cluster_S0Stvst_0.dat" using 1:2:3 title "beta = 0.01 " w yerrorbars 	
replot "Cluster_S0Stvst_1.dat" using 1:2:3 title "beta = 0.21 " with yerrorbars		 ### A =1 N=3
replot "Cluster_S0Stvst_2.dat" using 1:2:3 title "beta = 0.41 " with yerrorbars		 ### A =7 N=27
replot "Cluster_S0Stvst_4.dat" using 1:2:3 title "beta = 0.42 " with yerrorbars		 ### A =1 N=42
replot "Cluster_S0Stvst_5.dat" using 1:2:3 title "beta = 0.425 " with yerrorbars	 ### A =1 N=50
replot "Cluster_S0Stvst_6.dat" using 1:2:3 title "beta = 0.43 " with yerrorbars	     ### A =1 N=60
replot "Cluster_S0Stvst_7.dat" using 1:2:3 title "beta = 0.435 " with yerrorbars	 ### A =1 N=60
replot "Cluster_S0Stvst_8.dat" using 1:2:3 title "beta_critica " with yerrorbars	 ### A =1	

replot "Cluster_S0Stvst_3.dat" using 1:2:3 title "beta = 0.61 " with yerrorbars	 ### A =1



A=100
f(x)= exp(-x/A)
replot f(x) notitle

replot exp(-1) lc 0 lt 7
##fit solo dei primi N punti
N=95
	fit f(x) "Cluster_S0Stvst_8.dat" every ::0::N using 1:2:3 via A
	replot f(x) notitle
