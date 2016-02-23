set term postscript eps enhanced color solid rounded

set title "traiettoria di 3 pendoli con frequenza delle forzanti  variate di 0.0005 N  \n CASO CAOTICO" 
set notitle

set style data lines 
set xlabel "tempo [s]" 
set ylabel "h[t]" 
set pointsize 0.08


set output 'filtrazione.eps'
plot[0:20]   "filtro","rumore"
set output
!epstopdf filtrazione.eps && rm filtrazione.eps

