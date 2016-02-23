set term postscript eps enhanced color solid rounded


set style data impulses 
set xlabel "frequenza " 
set ylabel "power spectrum" 
set pointsize 0.08


set output 'confronto.eps'
set title "Trasformata fourier Gaussiana" 
set notitle
plot[0:15][0:1e-10]  "sottocampionato", "criticocampionato", "sovracampionato"
set output
!epstopdf confronto.eps && rm confronto.eps

