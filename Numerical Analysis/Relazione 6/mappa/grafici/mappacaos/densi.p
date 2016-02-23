set term postscript eps enhanced color solid rounded

set style data boxes
set xtics 0.1
set mxtics 5
set xlabel "Xn"
set ylabel "densitaà di probalitaà P(Xn)dx"
set notitle


set output 'superisto.eps'
set xtics 0.1
set mxtics 5

set style data lines
plot[0:1][0:0.3]"superisto" using 1:2 smooth bezier
set output
!epstopdf superisto.eps && rm superisto.eps

