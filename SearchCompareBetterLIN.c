int LinSearch(int array[N], int x){
int i = 0;
while (i < N)
{
    if(array[i]==x)
    {
    return i;
    }
i = i + 1;
}
return -1;
}