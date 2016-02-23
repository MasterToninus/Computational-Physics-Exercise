set xlabel "Numero di punti valutati"
set ylabel "Dispersione dal valore atteso"

plot "MultiGaussordine20"
f(x)=C+B*x**(-A)
fit f(x) 'MultiGaussordine20' using 1:2 via A,B,C
replot f(x)



