set xlabel "Numero di punti valutati"
set ylabel "Dispersione dal valore atteso"
plot "Simpson"
f(x)=C+B*x**(-A)
A=3
fit f(x) 'Simpson' using 1:2 via A,B,C
replot f(x)
