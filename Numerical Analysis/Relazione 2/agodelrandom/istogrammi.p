set xlabel "dispersione dal valore vero"
set ylabel "conteggio dei risultati"
set term jpeg
set output 'isto.jpg'
set key off # Unless you really want a key
f(x)=A*exp(B*x*x)
fit f(x) 'myHistogramData.txt' using 1:2 via A,B
plot f(x) with li 6
plot  'myHistogramData.txt' with boxes
