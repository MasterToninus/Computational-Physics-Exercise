set xlabel "Numero di punti valutati"
set ylabel "Dispersione dal valore atteso"
plot "Trapezi"
f(x)=A*x**B
fit f(x) 'Trapezi' using 1:2 via A,B
replot f(x)



