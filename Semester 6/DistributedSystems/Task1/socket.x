struct variables {
    int a;
    int array_Y <>;
    int len;
};

struct minMax {
    int min;
    int max;
};

struct  ginomeno
{
    int resultArray <>;
};


program SOCKET_PROG {
    version SOCKET_VER {
        double AVERAGE(variables) = 1;
        minMax MIN_MAX(variables) = 2;
        ginomeno MULTIPLY(variables) = 3;
    } = 1;
} = 0x23451111;