set xlabel "Numero di punti valutati"
set ylabel "Dispersione dal valore atteso"

plot "MultiGaussordine5"
f(x)=x**A 
fit f(x) 'MultiGaussordine5' using 1:2 via A
replot f(x)



