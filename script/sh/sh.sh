#!/bin/bash
:<<!
【1】
Shell脚本IF条件判断和判断条件总结
https://blog.csdn.net/jasonzeng/article/details/53286384
【2】
http://lovelace.blog.51cto.com/1028430/1211141/
shell脚本是逐行解释运行。不会像其它语言一样先预编译。

command > file	将输出重定向到 file。
command < file	将输入重定向到 file。
command >> file	将输出以追加的方式重定向到 file。

local：
一般用于局部变量声明一般用于局部变量声明,多在在函数内部使用。shell脚本中定义的变量是global的,其作用域从被定义的地方开始
!

function varf()
{
	echo "forf"
	local x=5  			#x=5中间不能有空格
	local str="abcd";	#每一句之后的; 可有可无
	
	declare -i num=9	#定义为整形变量
	let num=num+2		#let, 让sh计算数学运算
	echo $num
	
	local arr=(2 3 4 5)	#定义数组
	echo arr: ${arr[*]}	#打印数组所有元素
	arr[1]=55 			#为数组元素赋值
	echo "第二个元素为：${arr[1]}"	#
	echo '第二个元素为：${arr[1]}'	#' '号中的所有字符以字符串显示
	
}

function sysArg()
{
	echo "sysArg"
	echo "commond: "$0

	for i in $*
	do
		echo $i
	done
}
:<<!
	$? 上一个命令执行状态返回值
	$# 参数的个数
	$* 参数列表
	$@ 参数列表(行排)
	$0 命令本身  脚本本身
!

function forf()
{
	echo "forf"
	local str="a b c d"  #=中间不能有空格
	echo "str:"$str

	for i in $str
	do
		echo $i
	done
	
	for i in $(ls)
	do
		echo "file:$i"
		echo "file:"$i
	done


	sum=0
	for((i = 1; i <= 5; i++))	#C风格，要两个（）包围
	do
		echo $i
	done
	

	for (( i = 1; i <=9; i++ ))  
	do  
		for (( j=1; j <= i; j++ ))  
		do  
			let "temp = i * j"       
			echo -n "$i*$j=$temp  "  
		 done   
		 echo ""   #output newline  
	done  
	
	#以下可以用C语言风格替换 (( ... ))
	sum=0
	for i in {1..4}
	do
		let "sum+=i"
	done
	echo "sum=$sum"
	
	sum=0
	for i in {1..10..2}	#1，3，5，7。。。
	do
		let "sum+=i"
	done
	echo "sum=$sum"	
}
:<<! 多行注释
forf  
a
b
c
d
!

function whilef()
{
	echo "whilef"
	local x=5  #x=5中间不能有空格
	local str="abcd"
	let "x = x + 2" #用”“括起来后，中间的运算就不必有空格 来空开了
	
	i=5
	while((i >= 0))
	do
		echo "$i"
		let "i -= 1"
	done
	
	i=5
	while [ "$i" != 0 ]
	do
		echo "$i"
		let "i -= 1"
	done
	
}

cmd() #function可有可无
{
	res=$(netstat -an | grep '192.168.0.1')	#执行一个命令并获取输出结果
	echo $res
}

iff()
{
	if [ "aa"=="bb" ]
	then
		echo "=="
	else
		echo "!="
	fi
}
:<<!
1、字符串判断
str1 == str2　　　　　　当两个串有相同内容、长度时为真 
str1 != str2　　　　　 当串str1和str2不等时为真 
-n str1　　　　　　　 当串的长度大于0时为真(串非空) 
-z str1　　　　　　　 当串的长度为0时为真(空串) 
str1　　　　　　　　   当串str1为非空时为真

2、数字的判断
- eq 是否相等（例如，if [ 2 –eq 5 ]）
-ne 是否不等
-lt —参数1是否小于参数2 (less than)
-le —参数1是否小于等于参数2
-gt —参数1是否大于参数2	(greater than)
-ge —参数1是否大于等于参数2
-f — 检查某文件是否存在（例如，if [ -f "filename" ]）
-d — 检查目录是否存在

3、文件的判断
-r file　　　　　用户可读为真 
-w file　　　　　用户可写为真 
-x file　　　　　用户可执行为真 
-f file　　　　　文件为正规文件为真 
-d file　　　　　文件为目录为真 
-c file　　　　　文件为字符特殊文件为真 
-b file　　　　　文件为块特殊文件为真 
-s file　　　　　文件大小非0时为真 
-t file　　　　　当文件描述符(默认为1)指定的设备为终端时为真
4、复杂逻辑判断
-a 　 　　　　　 与 
-o　　　　　　　 或 
!　　　　　　　　非
!

addf()
{
	if [ $# -eq 2 ]	#用" [ ] "来表示条件测试。注意这里的空格很重要。要确保方括号的空格。
	then
		echo $[$1+$2]	#[]号，函数的返回结果就是echo $[$1+$2]，return只是返回执行状态
	elif [ $# -eq 1 ]	#错：elif[$# -eq 1]，三个地方都有空格！
	then
		echo $1
	else
		echo "bad pra"
	fi
	#错：return $[$1+$2]
}

#shell读文件并把文件的内容输出到控制台
mycat()
{
	while read line
	do
		echo $line
	done << $1
}

test()
{
	varf
	sysArg $* #将系统参数传给某个函数
	forf
	
	whilef
	
	cmd;

	#调用并获取函数返回值
	ret1=`cmd`;	
	echo $ret
	
	num=`addf 5555 3`
	echo $num	#返回5558
	
	num1=$(addf 5555 3)
	echo $num1	#返回5558
	
	info=`ls /`	#执行一个命令并获取输出结果
	echo $info;
	
	echo $?		# $?是最近已执行命令的退出状态，范围是0到255
	
	iff;

	mycat < ../tmp.tmp.cpp
	
	echo $(( 25 / 5))	#(( )) 复合命令 可以计算一个算术表达式的值，

}

buildroo()
{
	echo "buildroo"
	dir=(
	"../" 
	"../")

	if [ "$1" == "-a" ] 
	# 1. == 号两边必须要有空格!不然错误,$1与==得区分开来
	# 2. $1加双引号避免不使用参数时: build.sh: line 9: [: ==: unary operator expected
	then
		echo "all"
	else
		for s in ${dir[@]}
		do
			ls "$s"
		done
	fi
}


setProcValByFor()
{
	#多行命令在一行中运行：用；号隔开。
	for i in $(ls /proc/sys/net/ipv6/conf/);do echo 9 > /proc/sys/net/ipv6/conf/$i/max_addresses;done
	for i in {1..5}; do ls; done

}

shellBasicFunction()
{
	#1、$LINENO 是当前行号。
	echo $LINENO
	
	#2、2>&1  重定向错误后才能获取错误.  2>&1 的意思就是将标准错误重定向到标准输出。
	res=`mysql -h*** -e "insert into ***" 2>&1`
	echo "res:"$res
	
}

delOutDateDirectory()
{
	#删除某个目录下，所有早于7天前创建的文件夹
	find /data/robot_hdfs/*robot/ws_lahuo_*  -type d  -mtime +7 -exec rm -rf '{}' \;
}

#mycat tmp.tmp.sh

findCodeCommit()
{
	#包含mysql库$(LIB_DB_DAO) ，且在7月23号之后在svn、git下有提交的代码梳理

	#查找所有makefile文件 | 过滤出这些文件中包含LIB_DB_DAO的文件 | 删除每一行 头部、尾部的无用信息 输出到文件
	find . -name makefile | xargs grep LIB_DB_DAO | sed 's/makefile.*//' | sed 's/\.//' > ~fish/my/has_db_dao_lib	
	
	#查看svn在{2019-7-23}到{2019-9-10} 这个时间范围内的提交，列举出修改后的文件 | 过滤出包含 application 的行 输出到文件
	svn log -r {2019-7-23}:{2019-9-10} -v | grep application > ~fish/my/svn_commit
	
	#查看git在2019-9-10 12:00:00 这个时间之后的提交，--stat列举出修改后的文件 | 过滤出包含 application 的行 输出到文件
	git log --after="2019-9-10 12:00:00" --stat | grep application > ~fish/git_commit
	
	#找出所有has_db_dao_lib文件中在svn的提交里有被包含的行
	for i in $(cat has_db_dao_lib);do grep $i svn_commit ;done
	
	#找出所有has_db_dao_lib文件中在git的提交里有被包含的行
	for i in $(cat has_db_dao_lib);do grep $i git_commit ;done
	
	#一行函数，命令行里可直接粘贴执行：
	chg_core(){ echo -e "\ncommand help:\nchange_ore <process_name> <core_size>";  for pid in $(ps aux | grep ${1:-1} | grep -v "grep" | tr -s ' ' | cut -d' ' -f 2); do prlimit --core=${2:-1} --pid $pid;done; };chg_core mail_work 8888888
	
}

dailySkill()
{
	#【】重启/usr/local/services下面的所有服务
	for dir in $(ls | grep spp);do echo `./$dir/admin/restart.sh graceful`;done
	
	#【】重启/usr/local/services下面的所有服务，并发执行
	for dir in $(ls | grep spp);do `./$dir/admin/restart.sh graceful`& done
	
	#把当前机器的各个服务占用CPU负载排序
	for i in $(ps axu | grep _worker | grep -v grep | awk '{print $11}' |sort | uniq); do ps axu | grep $i | awk '{total+=$3}; END {print total ":\t\t\t" $11}';done | sort -k 1 -nr
}








