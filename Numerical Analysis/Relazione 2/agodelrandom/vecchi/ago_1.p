set xlabel "N : Numero di lanci"
set ylabel "P stimato"
set term jpeg
set output 'ago_1.jpg'
set style data lines       
plot "ago_1.txt" with errorbars

