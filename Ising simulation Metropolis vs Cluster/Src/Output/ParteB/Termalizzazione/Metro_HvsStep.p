## prototipo di grafico x y con barra di errore

clear
reset

set title "H vs step Algoritmo di Metropolis  (L=100)"


set xlabel "step"
# set xrange [0:5]
set log x

set ylabel "H"
# set yrange [-2:2]

plot "Metro_Hvsstep_TH_para.dat" using 1:2 title "beta = 0.01" lt 3 lc 2
replot "Metro_Hvsstep_TH_para.dat" using 1:2 notitle with lines lt 3 lc 2

replot "Metro_Hvsstep_TH_ferro.dat" using 1:2 notitle lt 6 lc 2
replot "Metro_Hvsstep_TH_ferro.dat" using 1:2 notitle with lines lt 6 lc 2

replot "Metro_Hvsstep_Tc_para.dat" using 1:2 title "beta = 0.44" lt 2  lc 3
replot "Metro_Hvsstep_Tc_para.dat" using 1:2 notitle with lines lt 2 lc 3

replot "Metro_Hvsstep_Tc_ferro.dat" using 1:2 notitle "beta = 0.44 " lt 5  lc 3
replot "Metro_Hvsstep_Tc_ferro.dat" using 1:2 notitle with lines lt 5 lc 3

replot "Metro_Hvsstep_TL_para.dat" using 1:2 title "beta = 2.0" lt 1 lc 1
replot "Metro_Hvsstep_TL_para.dat" using 1:2 notitle with lines lt 1 lc 1

replot "Metro_Hvsstep_TL_ferro.dat" using 1:2 notitle  lt 4 lc 1
replot "Metro_Hvsstep_TL_ferro.dat" using 1:2 notitle with lines lt 4 lc 1

