set xlabel "Numero di punti valutati"
set ylabel "Dispersione dal valore atteso"
plot "Simpson"
f(x)=A+B*x
fit f(x) 'Simpson' using 1:2 via A,B
replot f(x)



