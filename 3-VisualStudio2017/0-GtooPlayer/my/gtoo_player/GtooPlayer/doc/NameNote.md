# 变量名

小驼峰

int mStudentCount = 1;

函数名称

void setMimeTypeFilters(const QStringList &filters);

# 类型名

大驼峰

class MyExample
{

}
枚举变量——大驼峰

enum ExampleType



## 代码规范

1. 以小写字母m（member的首字母）开头的变量表示类的成员变量

int mSensor;
int mTrackingState;
std::mutex mMutexMode;


2. mp开头的变量表示指针（pointer）型类成员变量

Tracking* mpTracker;
LocalMapping* mpLocalMapper;
LoopClosing* mpLoopCloser;
Viewer* mpViewer;

3. mb开头的变量表示布尔（bool）型类成员变量
bool mbOnlyTracking;

4. mv开头的变量表示向量（vector）型类成员变量；

std::vector<int> mvIniLastMatches;
std::vector<cv::Point3f> mvIniP3D;


5. mpt开头的变量表示指针（pointer）型类成员变量，并且它是一个线程（thread）；

std::thread* mptLocalMapping;
std::thread* mptLoopClosing;
std::thread* mptViewer;

ml开头的变量表示列表（list）型类成员变量；
mlp开头的变量表示列表（list）型类成员变量，并且它的元素类型是指针（pointer）；
mlb开头的变量表示列表（list）型类成员变量，并且它的元素类型是布尔型（bool）；

list<double> mlFrameTimes;
list<bool> mlbLost;
list<cv::Mat> mlRelativeFramePoses;
list<KeyFrame*> mlpReferences;

6. 信号与槽的命名方式
小驼峰
```c++
// 定义信号
signal:
void sigSendMessage(void){}
// 实现函数
void GtooPlayer::sigSendMessage(void) {}


// 定义槽函数
public slots:
void slotForwardPlay (void){}
// 实现槽函数
void GtooPlayer::slotForwardPlay(void) {}

```
