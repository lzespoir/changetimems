# changetimems
When setting the time, we often encounter situations where there is a difference of several seconds compared to the time server. However, using the `date` command directly for adjustment can be hard to control since I haven't found a better way. Therefore, I wrote a small tool that allows adjusting the system time by milliseconds.
我们在设置时间的时候经常会遇到和时间服务器相差几号秒的情况，但是用date直接设置又难以控制，因为我没有找到更好的方式，因此写了一个小工具，可以按毫秒增减系统时间。

+ 代表在时间戳基础上增加时间
- 代表在时间戳基础上减少时间

编译：
gcc changetimems.c  -o ./changetimems

示例：
./changetimems +1

支持小数

没有做精确的控制，太离谱的数可能出错。
