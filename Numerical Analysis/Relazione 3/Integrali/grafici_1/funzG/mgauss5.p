set xlabel "Numero di punti valutati"
set ylabel "Dispersione dal valore atteso"

plot "MultiGaussordine5"
f(x)=A*x**B 
fit f(x) 'MultiGaussordine5' using 1:2 via A,B
replot f(x)



