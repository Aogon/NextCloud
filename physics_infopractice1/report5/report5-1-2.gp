set term png
set output 'report5-1-2.png'
set title 'Changes in number of air molecules'
set xlabel 'time'
set ylabel 'N'
set xrange[0:100000]
set yrange[0:10000]
plot 'report5-1-2.dat' u 1:2 w l lw 1 title 'N1', 'report5-1-2.dat' u 1:3 w l lw 1 title 'N2', 'report5-1-2.dat' u 1:4 w l lw 1  title 'N3'