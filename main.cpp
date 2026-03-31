#include "MySql.h"
int main()
{
    MySql mysql("localhost","root","zyw780922","acm",0,nullptr,0);
    std::vector<std::vector<std::string>> ans=mysql.mysqlQuery(R"(select * from test;)");
    for(auto it1:ans)
        for(auto it2:it1)
            std::cout<<it2<<std::endl;
    return 0;
}