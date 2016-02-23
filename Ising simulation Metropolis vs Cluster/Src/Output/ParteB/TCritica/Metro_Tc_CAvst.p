## -_-_-_

clear
reset

set title "Funzione di correlazione CA(t) vs t con algoritmo Metropolis a BETA CRITICO"


set xlabel "t"
set xrange [0:50]

set ylabel "CA(t)"
#set yrange [-1:1.2]
#set log y


plot "Metro_Tc_CAvst_N120.dat" title "N = 120" 		w l
#replot "Metro_Tc_CAvst_N105.dat" title "N = 105" 		w l
replot "Metro_Tc_CAvst_N90.dat" title "N = 90" 		w l
#replot "Metro_Tc_CAvst_N75.dat" title "N = 75" 		w l
replot "Metro_Tc_CAvst_N60.dat" title "N = 60" 		w l
replot "Metro_Tc_CAvst_N45.dat" title "N = 45" 		w l
#replot "Metro_Tc_CAvst_N30.dat" title "N = 30" 		w l
replot "Metro_Tc_CAvst_N15.dat" title "N = 15" 		w l




