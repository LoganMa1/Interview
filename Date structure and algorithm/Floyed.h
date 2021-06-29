#ifndef _FLOYED_
#define _FLOYED_
#include <vector>


void floyed(std::vector<std::vector<double >> & arr, int m)
{
    int row = arr.size(),col = arr[0].size();
    for(int i=1; i<=m;i++)
    {
        for(int j=1; j<row; j++)
        {
            for(int k=1; k<col; k++)
            {
                if(i!=k&&k!=j&&i!=j&&arr[j][k]>arr[j][i]+arr[i][k])
                    arr[j][k] = arr[j][i]+arr[i][k];
            }
        }
    }
}


double get_min(const std::vector<std::vector<double >> & arr,int s,int e)
{
    return arr[s][e];
}
#endif