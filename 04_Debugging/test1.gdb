break range.c:37 if i % 5 == 0
command 1
    echo @@@
    print start
    echo @@@
    print stop
    echo @@@
    print step
    echo @@@
    print i
    continue
end

run 1 12 > /dev/null

quit