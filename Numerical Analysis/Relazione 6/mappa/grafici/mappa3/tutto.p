reset

set term postscript eps enhanced color solid rounded
set pointsize 0.5
set style data lp
set xlabel "numero di iterazione n"
set ylabel "Xn"
set notitle
set point 0
set mxtics 5




set output 'r=1.eps'
plot "r=1" pt 4
set output
!epstopdf r=1.eps && rm r=1.eps

set output 'r=2.eps'
plot[0:20][0:0.55] "r=2" pt 4
set output
!epstopdf r=2.eps && rm r=2.eps

set output 'r=3.eps'
plot "r=3" pt 4
set output
!epstopdf r=3.eps && rm r=3.eps

unset key
set mxtics 5

set output '2punti.eps'
plot[0:20][0.5:0.82] "2punti_2" pt 4 lt 1,"2punti_1" pt 4 lt 1,"2punti"pt 4  lt 7
set output
!epstopdf 2punti.eps && rm 2punti.eps

set output '4punti.eps'
plot[0:20][0.32:0.93] "4punti_1" pt 4 lt 1,"4punti_2" pt 4 lt 1,"4punti_3" pt 4 lt 1,"4punti_4" pt 4 lt 1,"4punti"pt 4  lt 7
set output
!epstopdf 4punti.eps && rm 4punti.eps

set output '8punti.eps'
plot[0:40][0.3:0.92] "8punti_1" pt 4 lt 1,"8punti_2" pt 4 lt 1,"8punti_3" pt 4 lt 1,"8punti_4" pt 4 lt 1,"8punti_5" pt 4 lt 1,"8punti_6" pt 4 lt 1,"8punti_7" pt 4 lt 1,"8punti_8" pt 4 lt 1,"8punti" pt 4 lt 7
set output
!epstopdf 8punti.eps && rm 8punti.eps
