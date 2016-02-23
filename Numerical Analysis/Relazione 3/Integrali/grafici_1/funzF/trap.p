set xlabel "Numero di punti valutati"
set ylabel "Dispersione dal valore atteso"
plot "Trapezi"
f(x)=C+B*x**(-A)
A=1
fit f(x) 'Trapezi' using 1:2 via A,B,C
replot f(x)



