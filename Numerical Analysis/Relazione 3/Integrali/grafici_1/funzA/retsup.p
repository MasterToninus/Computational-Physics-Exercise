set xlabel "Numero di punti valutati"
set ylabel "Dispersione dal valore atteso"
plot"Rettangoli\ Superiore"
f(x)=B*(x**A)
fit f(x) 'Rettangoli Superiore' using 1:2 via A,B
replot f(x)


