set xlabel "Numero di punti valutati"
set ylabel "Dispersione dal valore atteso"
plot "Simpson"
f(x)=A*(x**B)
fit f(x) 'Simpson' using 1:2 via B,A
replot f(x)
