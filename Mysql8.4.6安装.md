# 在 Centos Stream 10 安装 Mysql8.4.6

## 🔽 第一步: 下载Mysql8.4.6
打开下载地址:https://dev.mysql.com/downloads/mysql/

![image.png](https://raw.githubusercontent.com/bucketio/img1/main/2025/10/10/1760035244447-87e807a1-6347-4dce-85bf-7db32a3cce6d.png 'image.png')

版本选择8.4.6 LTS
操作系统选择 Red Hat Lnterprise Linux / Oracle Linux
选择操作系统版本 Red Hat Lnterprise Linux / Oracle Linux10(x86,64-bit)

将下载mysql-8.4.6-1.el10.x86_64.rpm-bundle.tar存放到 /opt/mysql/目录下,如果mysql没有,使用mkdir穿甲mysql目录

## 📁  第二步: 解压mysql-8.4.6-1.el10.x86_64.rpm-bundle.tar


```language
tar -xvf mysql-8.4.6-1.el10.x86_64.rpm-bundle.tar -C mysql
ls
```

mysql-community-client-8.4.6-1.el10.x86_64.rpm
mysql-community-client-debuginfo-8.4.6-1.el10.x86_64.rpm
mysql-community-client-plugins-8.4.6-1.el10.x86_64.rpm
mysql-community-client-plugins-debuginfo-8.4.6-1.el10.x86_64.rpm
mysql-community-common-8.4.6-1.el10.x86_64.rpm
mysql-community-debuginfo-8.4.6-1.el10.x86_64.rpm
mysql-community-debugsource-8.4.6-1.el10.x86_64.rpm
mysql-community-devel-8.4.6-1.el10.x86_64.rpm
mysql-community-icu-data-files-8.4.6-1.el10.x86_64.rpm
mysql-community-libs-8.4.6-1.el10.x86_64.rpm
mysql-community-libs-debuginfo-8.4.6-1.el10.x86_64.rpm
mysql-community-server-8.4.6-1.el10.x86_64.rpm
mysql-community-server-debug-8.4.6-1.el10.x86_64.rpm
mysql-community-server-debug-debuginfo-8.4.6-1.el10.x86_64.rpm
mysql-community-server-debuginfo-8.4.6-1.el10.x86_64.rpm
mysql-community-test-8.4.6-1.el10.x86_64.rpm
mysql-community-test-debuginfo-8.4.6-1.el10.x86_64.rpm

按顺序安装:
```
rpm -ivh mysql-community-common-8.4.6-1.el10.x86_64.rpm 
rpm -ivh mysql-community-icu-data-files-8.4.6-1.el10.x86_64.rpm 
rpm -ivh mysql-community-client-plugins-8.4.6-1.el10.x86_64.rpm 
rpm -ivh mysql-community-libs-8.4.6-1.el10.x86_64.rpm 
rpm -ivh mysql-community-client-8.4.6-1.el10.x86_64.rpm
rpm -ivh mysql-community-server-8.4.6-1.el10.x86_64.rpm 

```
## ▶第三步: 启动mysql服务
```
systemctl start mysqld
```
获取mysql默认密码
```
cat /var/log/mysqld.log
```
![image.png](https://raw.githubusercontent.com/bucketio/img18/main/2025/10/10/1760036333351-cafc4383-6abe-4d1c-9461-a0e0be190470.png 'image.png')

## ⚙第四步: 修改mysql默认密码
```
登录到mysql数据库: mysql -u root -p , 修改密码校验策略
SET GLOBAL validate_password.policy=0;
SET GLOBAL validate_password.length=1;
ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY 'root';
grant all privileges on *.* to 'root'@'%' with grant option;
FLUSH PRIVILEGES;
```

