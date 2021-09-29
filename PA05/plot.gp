set terminal png size 1000, 1000
set output "results.png"
set xlabel "array size"
set ylabel "# comparisons"
plot "./results.dat" using 1:2 title "iter." with lines, \
     ""              using 1:3 title "recur." with lines, \
     ""              using 1:4 title "log(n)" with lines
