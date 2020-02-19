
#!/bin/sh

dir=.
cd hans
for i in `ls ${dir}`
do
   echo 'file:'${i} |sed 's/_zh_Hans.conf//'
   cat ${i}|sed '/^[[:space:]]*$/d'   |tr -d '\r'
done

#tr -d '\r' : 去掉每行末尾的 ^M 
#\t 便于excel中粘贴