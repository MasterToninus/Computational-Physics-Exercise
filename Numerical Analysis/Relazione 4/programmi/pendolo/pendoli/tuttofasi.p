set term postscript eps enhanced color solid rounded

set style data points
set style function lines 
set xlabel "angolo Theta(t) [rad]" 
set ylabel "velocità angolare Omega(t) [rad/s]"
set pointsize 0.01

set output 'semplicefasi.eps'
plot  "semplicefasi" 
set output
!epstopdf semplicefasi.eps && rm semplicefasi.eps


set output 'forzatofasi.eps'
plot  "forzatofasi" 
set output
!epstopdf forzatofasi.eps && rm forzatofasi.eps

set output 'smorzatofasi.eps'
plot  "smorzatofasi" 
set output
!epstopdf smorzatofasi.eps && rm smorzatofasi.eps

set output 'completofasi.eps'
plot  "completofasi" 
set output
!epstopdf completofasi.eps && rm completofasi.eps
