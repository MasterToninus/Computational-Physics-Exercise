set xlabel "Numero di punti valutati"
set ylabel "Dispersione dal valore atteso"

plot "MultiGaussordine20"
f(x)=A*(x**B)
fit f(x) 'MultiGaussordine20' using 1:2 via A,B
replot f(x)



