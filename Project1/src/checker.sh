while ./gen 5 5 1000 >in && time ./Solution1 <in >out1 && time ./Solution2 <in >out2 && time ./Solution3 <in >out3 && diff -w ./out1 ./out2 && diff -w ./out2 ./out3 ; do echo Accepted\! ;done

