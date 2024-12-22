#include <iostream>
template <typename T>
// int x = 1;
T maxi(T x, T y){
    static int u = 0;
    u++;
    std::cout<<u<<'\n';
    return ((x>=y)?x:y);
}
// int maxii(int x, int y){
//     static int u = 0;
//     u++;
//     std::cout<<u<<'\n';
//     return ((x>=y)?x:y);
// }
int main()
{
    std::cout<<maxii(4,5)<<'\n';
    std::cout<<maxii(4,5)<<'\n';
    std::cout<<maxii(4,5)<<'\n';
    std::cout<<maxii(4,5)<<'\n';
    return 0;
}