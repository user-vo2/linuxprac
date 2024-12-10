break range.c:37 if i >= start + step * 27 && i <= start + step * 34
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

run > /dev/null -100 100 3
quit