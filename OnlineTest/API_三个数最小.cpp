int min_of3(int x, int y, int z)
{
    if(x > y)
        x = y;
    return (z<x) ? z:x;
}