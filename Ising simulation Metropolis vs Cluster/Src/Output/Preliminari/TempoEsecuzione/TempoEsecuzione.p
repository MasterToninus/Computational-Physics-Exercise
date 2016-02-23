

clear
reset



set title "Tempo Esecuzione vs L"
set key left top

set xlabel "L"
set xrange [5:80]

set ylabel "t_esec (secondi)"
#set yrange [0:1]

plot "Cluster_TimevsN.dat" using 1:2 title "Algoritmo Swenden Wang"	lw 3
replot "Metro_TimevsN.dat" using 1:2 title "Algoritmo Metropolis"	lw 3
#replot "Cluster_V2_TimevsN.dat" using 1:2 title "Algoritmo Swenden Wang versione 2"	

f1(x) = a1*(x**b1)            # define the function to be fit
      a1 = 1; b1 = 1;            # initial guess for a1 and b1
fit f1(x) 'Cluster_TimevsN.dat' using 1:2 via a1, b1
replot f1(x) lw 1.5



