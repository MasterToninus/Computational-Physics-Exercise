set term postscript eps enhanced color solid rounded


set style data lines 
set xlabel "frequenza " 
set ylabel "modulo della trasformata" 
set pointsize 0.7




set output 'spettro_pendolo1.eps'
set title "Spettro del Pendolo" 
set notitle
plot[0:0.5][0:1000]   "spettro_pendolo1"
set output
!epstopdf spettro_pendolo1.eps && rm spettro_pendolo1.eps

set output 'spettro_pendolo2.eps'
set title "Spettro del Pendolo" 
set notitle
plot[0:0.7][0:1000]   "spettro_pendolo2"
set output
!epstopdf spettro_pendolo2.eps && rm spettro_pendolo2.eps

set output 'spettro_pendolo3.eps'
set title "Spettro del Pendolo" 
set notitle
plot[0:0.5][0:1000]   "spettro_pendolo3"
set output
!epstopdf spettro_pendolo3.eps && rm spettro_pendolo3.eps

set output 'spettro_pendolo4.eps'
set title "Spettro del Pendolo" 
set notitle
plot[0:0.5][0:1000]  "spettro_pendolo4"
set output
!epstopdf spettro_pendolo4.eps && rm spettro_pendolo4.eps

set output 'confronto.eps'
set title "confronto" 
set notitle
plot[0:0.6][0:1000]   "spettro_pendolo3" , "spettro_pendolo2" , "spettro_pendolo1" 
set output
!epstopdf confronto.eps && rm confronto.eps
