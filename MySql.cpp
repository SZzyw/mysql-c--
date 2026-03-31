#include "MySql.h"

MySql::MySql(const char *host, const char *user, const char *passwd, const char *db,
             unsigned int port, const char *unix_socket, unsigned long client_flag)
{
    mysql = mysql_init(nullptr);
    if (mysql == nullptr)
    {
        printf("mysql_init() error\n");
        return;
    }

    mysql = mysql_real_connect(mysql, host, user, passwd, db, port, unix_socket, client_flag);
    if (mysql == nullptr)
    {
        printf("mysql_real_connect() error: %s\n", mysql_error(mysql));
        return;
    }

    mysql_set_character_set(mysql, "utf8");
}

MySql::~MySql()
{
    if (mysql != nullptr)
    {
        mysql_close(mysql);
    }
}

void MySql::mysqlInsert(std::string str)
{
    if (getMysql() == false)
        return;

    int ret = mysql_query(mysql, str.c_str());
    if (ret != 0)
    {
        printf("mysql_query() failed: %s\n", mysql_error(mysql));
        return;
    }
    std::cout << "insert success!" << std::endl;
}

void MySql::mysqlUpdate(std::string str)
{
    if (getMysql() == false)
        return;

    int ret = mysql_query(mysql, str.c_str());
    if (ret != 0)
    {
        printf("mysql_query() failed: %s\n", mysql_error(mysql));
        return;
    }
    std::cout << "update success!" << std::endl;
}

std::vector<std::vector<std::string>> MySql::mysqlQuery(std::string str)
{
    std::vector<std::vector<std::string>> result;

    if (getMysql() == false)
        return result;

    int ret = mysql_query(mysql, str.c_str());
    if (ret != 0)
    {
        printf("mysql_query() failed: %s\n", mysql_error(mysql));
        return result;
    }

    MYSQL_RES *res = mysql_store_result(mysql);
    if (res == nullptr)
    {
        printf("mysql_store_result() failed: %s\n", mysql_error(mysql));
        return result;
    }

    int num = mysql_num_fields(res);
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res)) != nullptr)
    {
        std::vector<std::string> line;
        for (int i = 0; i < num; ++i)
        {
            line.push_back(row[i] == nullptr ? "" : row[i]);
        }
        result.push_back(line);
    }

    mysql_free_result(res);
    std::cout << "query success!" << std::endl;
    return result;
}

void MySql::mysqlDelete(std::string str)
{
    if (getMysql() == false)
        return;

    int ret = mysql_query(mysql, str.c_str());
    if (ret != 0)
    {
        printf("mysql_query() failed: %s\n", mysql_error(mysql));
        return;
    }
    std::cout << "delete success!" << std::endl;
}

bool MySql::getMysql()
{
    if (mysql == nullptr)
    {
        std::cout << "mysql is nullptr" << std::endl;
        return false;
    }
    return true;
}