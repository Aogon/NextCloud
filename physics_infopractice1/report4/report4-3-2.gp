set title 'Monte Carlo method for caluclating Integral'
set xlabel 'I'
set ylabel 'Number'
set autoscale
set xrange[2.7:3.5]
#set yrange[0:11]
plot 'report4-3-2.dat' index 0 u 2:3 title 'N = 100' with boxes, 'report4-3-2.dat' index 1 u 2:3 title 'N = 1000' with boxes, 'report4-3-2.dat' index 2 u 2:3 title 'N = 10000' with boxes, 'report4-3-2.dat' index 3 u 2:3 title 'N = 100000' with boxes