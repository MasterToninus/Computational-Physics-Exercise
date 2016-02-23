set xlabel "Numero di punti valutati"
set ylabel "Dispersione dal valore atteso"

plot "MultiGaussordine5"
f(x)=C+B*x**(-A)
fit f(x) 'MultiGaussordine5' using 1:2 via A,B,C
replot f(x)



