# gnuplotの設定
set xlabel "ステップ数"
set logscale xy #両対数グラフ
plot "report1-2.dat" using 1:3 with linespoints title "error" #プロット