#ifndef MYSQL_H
#define MYSQL_H
#include <iostream>
#include <mysql.h>
#include <string>
#include <vector>

class MySql{
public:
    MySql(const char *host,const char *user,const char *passwd,const char *db,unsigned int port,const char *unix_socket,unsigned long client_flag);

    ~MySql();

    void mysqlInsert(std::string str);

    void mysqlUpdate(std::string str);

    std::vector<std::vector<std::string>> mysqlQuery(std::string str);

    void mysqlDelete(std::string str);
private:
    MYSQL *mysql;           // mysql_init() 函数的返回值
    const char *host;       // mysql服务器的主机地址, 写IP地址即可
                            // localhost, null -> 代表本地连接
    const char *user;       // 连接mysql服务器的用户名, 默认: root 
    const char *passwd;     // 连接mysql服务器用户对应的密码, root用户的密码
    const char *db;         // 要使用的数据库的名字
    unsigned int port;      // 连接的mysql服务器监听的端口
                            // 如果==0, 使用mysql的默认端口3306, !=0, 使用指定的这个端口
    const char *unix_socket;// 本地套接字, 不使用指定为 NULL
    unsigned long client_flag; // 通常指定为0
};
#endif // MYSQL_CPP_MYSQL_H
