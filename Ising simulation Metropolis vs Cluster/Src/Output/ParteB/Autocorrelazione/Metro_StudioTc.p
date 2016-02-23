## -_-_-_

clear
reset

set title "Funzione di correlazione CA(t) vs t con algoritmo METROPOLIS"


set xlabel "t"
set xrange [0:50]

set ylabel "CA(t)"
#set yrange [-1:1.2]
#set log y

Tau_100=0.25
A=0.02
f(x)=exp(-x/Tau_100)


plot[0:50] "Metro_Cavst_Tc_N100.dat" title "N = 100" 	#	w l
fit f(x) "Metro_Cavst_Tc_N100.dat" using 1:2 via Tau_100
replot f(x)

replot "Metro_Cavst_Tc_N95.dat" title "N = 95" 	#	w l
replot "Metro_Cavst_Tc_N90.dat" title "N = 90" 	#	w l
replot "Metro_Cavst_Tc_N85.dat" title "N = 85" 	#	w l
replot "Metro_Cavst_Tc_N80.dat" title "N = 80" 	#	w l
replot "Metro_Cavst_Tc_N75.dat" title "N = 75" 	#	w l
replot "Metro_Cavst_Tc_N70.dat" title "N = 70" 	#	w l
replot "Metro_Cavst_Tc_N65.dat" title "N = 65" 	#	w l
replot "Metro_Cavst_Tc_N60.dat" title "N = 60" 	#	w l
replot "Metro_Cavst_Tc_N55.dat" title "N = 55" 	#	w l
replot "Metro_Cavst_Tc_N50.dat" title "N = 50" 	#	w l
replot "Metro_Cavst_Tc_N45.dat" title "N = 45" 	#	w l
replot "Metro_Cavst_Tc_N40.dat" title "N = 40" 	#	w l
replot "Metro_Cavst_Tc_N35.dat" title "N = 35" 	#	w l
replot "Metro_Cavst_Tc_N30.dat" title "N = 30" 	#	w l




