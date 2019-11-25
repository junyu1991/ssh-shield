#ifndef SQLITEHEADER
#define SQLITEHEADER

//攻击者ip缓存表，用于对攻击ip进行计数
struct attack_ip_cache {
	char *username; //攻击者使用的用户名
	char *ip; //攻击者的ip
	int count; //攻击者的试错次数
	long start_time; //攻击者开始攻击的时间
};

//已添加到防火墙黑名单中ip
struct block_ip_table {
	char *ip; //攻击者ip
	long block_time; //攻击者被添加到黑名单中的时间
};

//用于保存所有被添加到过黑名单中的攻击者ip信息
struct attack_ip {
	char *username; //攻击者使用的用户名
	char *ip; //攻击者的ip
	int count; //攻击者的试错次数
	long start_time; //攻击者开始攻击的时间
	long add_time; //攻击者被添加到黑名单中的时间
};

/**
* 初始化数据库：连接数据库，若表不存在则创建表
*/
void init_database();

//从数据库中查询需要从防火墙黑名单删除的ip
void get_ip2remove(char **ips);
/**
* 向数据库中添加从日志文件中获取的attacker ip，block_ips是需要添加到防火墙黑名单中的ip,
* 每次添加时就查询数据库中是否已经有达到需要添加到黑名单中的ip
**/
void add_cache_block_ip(char *add_ip, char **block_ips);

/**
* 向防火墙名单中添加攻击者ip，并调用add_attack_ip(struct attack_ip *aips)函数向数据库中添加攻击者信息
*/
void add_ip_to_block(struct block_ip_table *bit);

/**
* 向数据库中添加攻击者信息
*/
void add_attack_ip(struct attack_ip *aips);

/**
* 从防火墙中移除拦截的ip
*/
void remove_block_ip(char **ips);

#endif