set title "4 iterazioni consecutive con r=3"
set xlabel " valore x0"
set ylabel " valore xn"
set style data lines
plot "n=1"
replot "n=2"
replot "n=3"
replot "n=4"
