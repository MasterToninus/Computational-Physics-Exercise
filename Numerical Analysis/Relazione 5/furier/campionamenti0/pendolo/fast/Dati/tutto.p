set term postscript eps enhanced color solid rounded
set output 'spettro_tutto.eps'

set pointsize 0.7
set xlabel "frequenza [Hz]"
set ylabel  "|H(f)|"
set notitle
set style data lines

plot[0:0.8][0:1000]   "spettro_pendolo1","spettro_pendolo2","spettro_pendolo3","spettro_pendolo4" ls 5
set output
!epstopdf spettro_tutto.eps && rm spettro_tutto.eps


set output 'spettro_caos.eps'
plot[0:0.8][0:1000]   "spettro_pendolo1","spettro_pendolo2","spettro_pendolo3"
set output
!epstopdf spettro_caos.eps && rm spettro_caos.eps

set output 'spettro_pendoli.eps'
plot[0:0.8][0:1000]   "spettro_linearizzato","spettro_semplice","spettro_pendolo1"
set output
!epstopdf spettro_pendoli.eps && rm spettro_pendoli.eps

set output 'spettro_pendoli_2.eps'
plot[0.1:0.2][0:1000]   "spettro_linearizzato","spettro_semplice","spettro_pendolo1"
set output
!epstopdf spettro_pendoli_2.eps && rm spettro_pendoli_2.eps
