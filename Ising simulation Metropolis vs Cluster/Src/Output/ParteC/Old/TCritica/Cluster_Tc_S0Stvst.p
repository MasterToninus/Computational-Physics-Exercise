## -_-_-_

clear
reset

set title "Funzione di correlazione S0St vs t con algoritmo Swenden Wang a BETA CRITICO"


set xlabel "t"
set xrange [0:100]

set ylabel "CA(t)"
set yrange [0:1]
#set logscale y


plot "Cluster_Tc_S0Stvst_N250.dat" u 1:(sqrt($2))	 title "L = 250" 		#	w l
replot "Cluster_Tc_S0Stvst_N250.dat" title "L = 250" 	#u 1:(sqrt($2))	#	w l

A=250/4
B=1
C=0
f(x) = exp(-x/A)*B+C
replot f(x) title"$A"
##fit solo dei primi N punti
N=60
	fit f(x) "Cluster_Tc_S0Stvst_N250.dat" every ::0::N using 1:2 via A,B,C
	replot f(x) notitle
#	replot "Cluster_Tc_S0Stvst_N250.dat" title "L = 50" 	#	w l

