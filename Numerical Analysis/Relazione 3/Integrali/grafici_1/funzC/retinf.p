set xlabel "Numero di punti valutati"
set ylabel "Dispersione dal valore atteso"

plot "Rettangoli\ Inferiore"
f(x)=C+B*x**(-A)
fit f(x) 'Rettangoli Inferiore' using 1:2 via A,B,C
replot f(x)

