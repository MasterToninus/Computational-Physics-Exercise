## -_-_-_

clear
reset

set title "Funzione di correlazione S0St vs t con algoritmo Swenden Wang a BETA CRITICO"


set xlabel "t"
set xrange [0:100]

set ylabel "CA(t)"
set yrange [0:1]
#set logscale y


plot "Cluster_Tc_S0Stvst_N330.dat" title "L = 330" 	#	w l
#replot "Cluster_Tc_S0Stvst_N320.dat" title "L = 320" 	#	w l
#replot "Cluster_Tc_S0Stvst_N310.dat" title "L = 310" 	#	w l
#	replot "Cluster_Tc_S0Stvst_N300.dat" title "L = 300" 	#	w l
replot "Cluster_Tc_S0Stvst_N290.dat" title "L = 290" 		#	w l
#replot "Cluster_Tc_S0Stvst_N280.dat" title "L = 280" 	#	w l
#replot "Cluster_Tc_S0Stvst_N270.dat" title "L = 270" 	#	w l
replot "Cluster_Tc_S0Stvst_N260.dat" title "L = 260" 	#	w l
#	replot "Cluster_Tc_S0Stvst_N250.dat" title "L = 250" 	#	w l
#replot "Cluster_Tc_S0Stvst_N240.dat" title "L = 240" 	#	w l
replot "Cluster_Tc_S0Stvst_N230.dat" title "L = 230" 	#	w l
#	replot "Cluster_Tc_S0Stvst_N220.dat" title "L = 220" 	#	w l
#	replot "Cluster_Tc_S0Stvst_N210.dat" title "L = 210" 	#	w l
replot "Cluster_Tc_S0Stvst_N200.dat" title "L = 200" 	#	w l
#	replot "Cluster_Tc_S0Stvst_N190.dat" title "L = 190" 	#	w l
#	replot "Cluster_Tc_S0Stvst_N180.dat" title "L = 180" 	#	w l
replot "Cluster_Tc_S0Stvst_N170.dat" title "L = 170" 	#	w l


A=200
f(x) = exp(-x/A)
replot f(x) title"$A"
##fit solo dei primi N punti
N=30
	fit f(x) "Cluster_Tc_S0Stvst_N300.dat" every ::0::N using 1:2:3 via A
	replot f(x) notitle


A=200
B=1
C=1
f(x) = exp(-x/A)*B + C
replot f(x) title"$A"
##fit solo dei primi N punti
N=45
##	fit f(x) "Cluster_Tc_S0Stvst_N330.dat" every ::0::N using 1:2 via A,B,C
##	plot f(x) notitle
##	replot "Cluster_Tc_S0Stvst_N330.dat" title "L = 330" 	#	w l



