 

# 第八章 IO库



## IO类

### IO库读写标准类型

* iostream
  * istream  wistream  从流读取数据
  * ostream wostream 向流写入数据
  * iostream wiostream  读写流
* fstream
  * ifstream wifstream 从文件读取数据
  * ofstream wostream 向文件写入数据
  * fstream wfstream 读写文件
* sstream
  * istringstream wistringstream 从string读取数据
  * ostringstream wostringstream 向string写入数据
  * stringstream wstringstream 读写string
* 关系： 继承机制
  * 可以像使用istream对象一样来使用ifstream和istringstream，使用istream的cin>>读取数据，我们也可以使用ifstream和istringstream的cin>>从他们对象中读取数据
  * 可以像使用ostream对象一样来使用ofstream和ostringstream，使用ostream的cout<<写入数据，我们也可以使用ofstream和ostringstream的cout<<往对象写入数据

### 条件状态

* iostate提供了条件状态的功能

  iostate状态数值：

* badbit：表示流已崩溃的状态；默认iostate值为 4

* failbit：表示流的IO操作失败；默认iostate值为2

* eofbit：表示流到达文件或读取的末尾；默认iostate值为1

* goodbit：表示流操作正常；**默认iostate值为0**（没有消息就是最好的消息）

  函数：

* **bad**：检测是否触发（置位）badbit，如果触发，则返回true

* **fail**：检测是否触发（置位）failbit或者badbit，如果触发，则返回true

* **eof**：检测是否触发（置位）eofbit，如果触发，则返回true

* **good**：流处于有效状态，返回true

* **clear**：所有状态清零（复位），置为有效

* **clear**（flags）：指定流的flags条件清零，其他不变

* **setstate**（flags）：指定流的flags条件清零，其他不变

* **rdstate**：返回当前流状态，iostate值

示例：

goodbit表示输入正确，没有遇到错误 goodstate置为 1

```cpp
cin >> num;
cout << "goodstate: " << cin.good() << ", goodbit: " << cin.goodbit << endl;
cout << "failstate: " << cin.fail() << ", failbit: " << cin.failbit << endl;
cout << "eofstate: " << cin.eof() << ", eofbit: " << cin.eofbit << endl;
cout << "badstate: " << cin.bad() << ", badbit: " << cin.badbit << endl;
cout << num << endl;
```

![1659598688297](C:\Users\woshishuaige\AppData\Roaming\Typora\typora-user-images\1659598688297.png)

badbit表示系统级错误，触发条件很低

eofbit表示遇到结尾或者结束字符：^Z是windows的输入结束（CTRL+Z）触发eofbit，**会同时触发failbit和eofbit**
![1659598735256](C:\Users\woshishuaige\AppData\Roaming\Typora\typora-user-images\1659598735256.png)

failbit表示输入错误：a字母不是int型，触发failbit

![1659598856457](C:\Users\woshishuaige\AppData\Roaming\Typora\typora-user-images\1659598856457.png)

* 管理条件状态： 测试案例

  * rdstate：记录

  * setstate：复位

  * clear：清除  

    ```cpp
    void iostate_test(istream& in) {
    	// 流状态打印
    	cout << "goodstate: " << in.good() << ", goodbit: " << in.goodbit << endl;
    	cout << "failstate: " << in.fail() << ", failbit: " << in.failbit << endl;
    	cout << "eofstate: " << in.eof() << ", eofbit: " << in.eofbit << endl;
    	cout << "badstate: " << in.bad() << ", badbit: " << in.badbit << endl;
    	cout << endl;
    }
    void Input_Test() {
    	int value;
    	while (cin >> value) {
    		iostate_test(cin);
    	}									//假设触发eofbit错误 
    
    	auto old_state = cin.rdstate();			// 记录当前错误状态
    	iostate_test(cin);
    
    	cout << "清除全部错误:\n";
    	cin.clear();						// 流状态复位，即错误位全部清除，恢复正常
    	iostate_test(cin);
    
    	cout << "清除failbit错误:\n";
    	cin.setstate(old_state);					// 还原错误，导致eofbit置位
    	cin.clear(cin.rdstate() & ~cin.failbit);	// 流状态复位，failbit复位，但不会复位其他状态
    	iostate_test(cin);
    
    	cout << "清除failbit和eofbit错误:\n";
    	cin.setstate(old_state);					// 设置错误，导致eofbit置位
    	cin.clear(cin.rdstate() & ~cin.failbit & ~cin.eofbit); // 流状态复位，failbit和badbit复位
    	iostate_test(cin);
    
    	cout << "还原原始eofbit错误:\n";
    	cin.setstate(old_state); // 设置为原来错误状态，导致failbit和eofbit置位
    	iostate_test(cin);
    
    	int temp = 0;
    	return;
    }
    int main()
    {
    	Input_Test();
    	return 0;
    }
    
    ```

    ![1659599405559](C:\Users\woshishuaige\AppData\Roaming\Typora\typora-user-images\1659599405559.png)

### 管理缓冲区

* unibuf：在每次输出操作后都刷新缓冲区
* nounitbuf：使其恢复正常
* tie：关联输入流和输出流

## 文件输入输出

### 使用文件流对象：

* 加上 include <fstream>头文件

* 对要求使用基类对象的地方，可以用继承类型的对象来调用，例如在istream&的地方传递ifstream；在ostream&的地方传递ofstream
* 成员函数open和close：open打开文件，失败返回failbit状态，要进行open的检查操作，close关闭文件**，操作完一个文件后一定要关闭**

### 文件的模式

* in：读模式

* out：写模式

* app：每次写操作前定位到文件末尾

* ate：打开文件后立刻定位到文件末尾

* trunc：截断文件

* binary：二进制形式进行IO

  注意：

* 保存ofstream原有内容的**唯一方式**：显式指定app或者in模式

* 每次文件open时如果**不指定模式**，则对于ofstream，**自动输出和截断文件**

  ```cpp
  ifstream in(argv[1]);
  ofstream out(argv[2],ios_base::app);	//指定追加与输出
  ```

## string流

* str：返回istring stream的拷贝

* str（s）：将string s拷贝到istringstream中 

* 使用istringstream：头文件 include <sstream> 从istringstream读取数据

  ```cpp
  	istringstream in("546 5 9 5 da我爱你 hhhh");
  	int a;
  	while (in >> a)
  	{
  		cout << a << " ";
  	}
  	cin.clear();
  ```

* 使用ostringstream：向ostringstream对象输出数据：

  ```cpp
  	ostringstream outstring;
  	outstring << "我爱你" << endl;
  	cout << outstring.str() << endl;
  ```

  