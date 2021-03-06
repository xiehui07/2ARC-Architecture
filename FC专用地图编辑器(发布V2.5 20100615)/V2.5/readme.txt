名称：FC专用地图编辑器（FC MAP EDITER）

版本：2.5

使用说明：

本程序的文件为NMR。NMR文件用于记录CHR文件，DAT文件和COL文件。

另同时生成(与NMR文件同名的)DAT和COL文件。

DAT和COL文件可直接用于FC编程。(用法在本文最后面说明)

建议CHR文件拷贝到NMR的文件夹下。




---------------------------------------------

菜单：

文件-新建 : 新建nmr文件。
文件-打开 : 打开nmr文件，同时读入bin文件和chr文件。
文件-保存 : 保存nmr文件和生成bin文件。
文件-另存为 : 保存为另一文件。
文件-退出 : 直接退出，不提示保存。

地图-刷新 : 刷新地图和CHR。
地图-放大x2 : 地图放大2倍显示。(地图-返回x1 : 地图还原显示。)
地图-全置默认 : 地图全以tile默认值填入。

字模-导入字模 : 选取CHR文件。
字模-选页换页 : (先导入字模才能选页)选取CHR文件上的不同页。如只有1页则不能选。
字模-设定默认值 : 设定tile默认值

配色-导入配色 : 选取COL文件。
配色-#00 : 编辑#00的4色。
配色-#01 : 编辑#01的4色。
配色-#02 : 编辑#02的4色。
配色-#03 : 编辑#03的4色。

帮助 : 略

地图右键为删除。
  （如果“字模单元单选项”为单个读取，则每次删1个字模，否则每次删1个方块，即方型的4个字模）

字模单元右键为字模菜单，同时可以直接选取定“默认值”。


---------------------------------------------

让全屏设定为空白的方法（或全设为某值）

1 先“设定默认值”，选定某空白字模

2 再“全置为默认”，则全屏清为该字模。


---------------------------------------------

字模单元单选项：

1 单个读取：一次选一个字模，一次绘画一个字模。

2 连续方块：一次选4个字模，（方块型的4个字模），屏幕上以相同的方式绘画。但要以屏幕上的方格为单位绘画。(这适用于$2000的D2设为0的方式，设计方便)

3 连续4,竖向绘画方块：一次选4个连续的字模，（长条型），屏幕上以竖向的方式排列绘画。但要以屏幕上的方格为单位绘画。(这适用于$2000的D2设为1的方式，一般为精灵的代码方便才用这个方式)。

4 连续4,横向绘画方块：一次选4个连续的字模，（长条型），屏幕上以横向的方式排列绘画。但要以屏幕上的方格为单位绘画。(这适用于$2000的D2设为0的方式，一般为精灵的代码方便才用这个方式)。


---------------------------------------------
新文件使用次序：
1，(可新建)导入字模，同时选CHR页。
2，调节颜色。
3，点选字模。
4，点选配色号。
5，在地图框（主框）上绘画。
6，保存。
7，退出。

已有文件使用次序：
1，打开nmr文件，
2，调节颜色。
3，点选字模。
4，点选配色号。
5，在地图框（主框）上绘画。
6，保存。
7，退出。

###########################################



生成的文件在FC中的用法：

将DAT文件写入PPU的$2000到$23FF(第1页)，或者$2400到$27FF(第2页)。

其中包括了命名表(屏幕)和属性表(配色表)

另将COLOR写到PPU的$3F00到$3F0F(背景调色板)

##########################################

命令行的使用：
为我的FC专用地图编辑器建立一个快捷方式。
例如（假设程序是放在D盘的）其目标栏是：
D:\FC专用地图编辑器.exe

1 让程序打开最后一次保存的文件。
将其目标栏改写成
D:\FC专用地图编辑器.exe L

2 打开指定的文件，要是我的程序所生成的nmr格式才行(例 D:\aa.nmr)
指令是大写O，不是零0
D:\FC专用地图编辑器.exe O D:\aa.nmr

你也可以在你的程序里使用它了。
##########################################

更新了什么？
V1.0
可用于FC编程,内有使用说明书

V1.1
V1.1 主要增加放大显示功能

V2.0
V2.0 加入配色,并能保存色彩和配色.生成的文件与V1不再兼容.就是多了配色的部分.
增加了色彩文件.
改变了CHR的排列

V2.1
V2.1 加入网格,支持字模的(多方式的)整块选取.将Tile号改成16进制方式显示.


V2.2 
地图右键改为删除键

V2.3
画图与上色同时进行。

V2.4
菜单加上“另存为”项，加粗配色按扭红框。

V2.5
将颜色文件的后缀由color改成col，并兼容原来的color文件。
加入历史记录，可以保存最后一次使用的nmr文件。可以在菜单中打开。
加入命令行的操作指令；O是打开，后面接一个文件名；L是打开最后保存的文件。

完                            维京猎人    2010-06-15