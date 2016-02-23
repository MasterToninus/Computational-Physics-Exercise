## prototipo di grafico x y con barra di errore

clear
reset

set title "TauH vs X (serie trocata a step 10000)"


set xlabel "X"
set xrange [-0.15: 0.15]

set ylabel "Tau"
# set yrange [-2:2]

plot "Metro_TauHvsX.dat" title "Metropolis" 	w l
replot "Cluster_TauHvsX.dat" title "Swen.-Wang" w l
f(x)=1./abs(x)
#replot f(x)



