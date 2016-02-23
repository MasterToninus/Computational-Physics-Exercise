
clear
reset

set title "M vs beta con errore ( Vari Algoritmi)"


set xlabel "beta"
#set xrange [0.05:0.75]

set ylabel "<O>"
#set yrange [0:1]

plot "Metro_M.dat" using 1:2:3 title "<M> METROPOLIS" w yerrorbars
replot "Metro_M_abs.dat" using 1:2:3 title "<|M|> METROPOLIS" w yerrorbars
replot "Cluster_M.dat" using 1:2:3 title "<|M|> CLUSTER" w yerrorbars
