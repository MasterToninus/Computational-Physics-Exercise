
set pointsize 0.0001
set xlabel "parametro r"
set ylabel "Xn"
set notitle

unset tics

x = 3.5699340125
y0 = 0.4996
y1 = 0.4999
set format x "%10.9g"
set arrow 1 from x,y1 to x,y0  
set xtics (x)
plot[3.56993000:3.56993800][y0:y1]"ottava_biforcazione" ls 3
