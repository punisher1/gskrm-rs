
#include <time.h>
#ifdef GSKAPI_EXPORTS
#define GSKAPI __declspec(dllexport)
#else
#define GSKAPI __declspec(dllimport)
#endif

//#define CSHARP_USE
//GSK 数据通信实例定义
typedef void *HINSGSKRM;
typedef unsigned char BYTE;

/* 错误码定义, 大于等于 0x8000 的错误码是 PC 端产生错误码 */
#define NCRM_NOERR 0x0000             // 成功，没有错误
#define NCRM_ERR_CNC_REFUSE 0x0001    // 该操作被CNC拒绝,
#define NCRM_ERR_CNC_ENGROSS 0x0002   // CNC正和其他机器通讯,被占用
#define NCRM_ERR_INVALIDCMD 0x0003    // 无效的命令
#define NCRM_ERR_INVALIDCMDPRM 0x0004 // 无效指令参数
#define NCRM_ERR_WRONGCMDFMT 0x0005   // 错误的指令格式
#define NCRM_ERR_LEVEL 0x0006         // CNC的权限限制进行该操作
#define NCRM_ERR_CNCMODE 0x0007       // 当前CNC 工作模式或工作状态下不允许该操作
#define NCRM_ERR_OUTRANGE 0x0008      // 所设置的数据超出范围
#define NCRM_ERR_CNCFAILURE 0x0009    // CNC 端执行指定操作失败
#define NCRM_ERR_FILEINUSE 0x000A     // 文件正在使用,不能操作
#define NCRM_ERR_FILELIMIT 0x000B     // 文件数量超出上限
#define NCRM_ERR_NOFREESPACE 0x000C   // 存储空间不足
#define NCRM_ERR_OPEN_CNCFILE 0x000D  // 打开CNC文件出错
#define NCRM_ERR_CLOSE_CNCFILE 0x000E // 关闭CNC文件出错
#define NCRM_ERR_DATA_READONLY 0x000F // 数据写保护或只读
#define NCRM_ERR_PROCESSING 0x0010    // CNC正在处理，需等待完成

#define RMDATA_NOERR 0x0000              // 未发生错误
#define RMDATA_ERR_SEND 0x1001           // 发送数据出错
#define RMDATA_ERR_TIMEOUT 0x1002        // 超时等待
#define RMDATA_ERR_CREATESOCK 0x1003     // 创建SOCK出错
#define RMDATA_ERR_CREATEEVENT 0x1004    // 创建事件句柄
#define RMDATA_ERR_CREATETHREAD 0x1005   // 创建通讯线程出错
#define RMDATA_ERR_EVENTSEL 0x1006       // 选择同步事件
#define RMDATA_ERR_UNCONNECT 0x1007      // 创建连接失败
#define RMDATA_ERR_NOCONNECT 0x1008      // 未连接
#define RMDATA_ERR_WORKING 0x1009        // 已经在工作(即之前已经连接或启动服务)
#define RMDATA_ERR_INVALIDDATA 0x100a    // 无效的数据类型
#define RMDATA_ERR_ALLOC_MEM 0x100b      // 申请内存失败
#define RMDATA_ERR_QUEUE_FULL 0x100c     // 发送队列已满
#define RMDATA_ERR_MAXCOUNT 0x100d       // 请求的数据个数超过最大数
#define RMDATA_ERR_CRC16 0x100e          // CRC16校验出错
#define RMDATA_ERR_SLAVEBUSY 0x100f      // 从站忙(正进行文件通讯等处理)
#define NCRM_ERR_CONNECT_REPEAT 0x8000   // 重复连接
#define NCRM_ERR_CONNECT_NIMIETY 0x8001  // 超过最多连接数
#define NCRM_ERR_TIMEOUT_WITH_CNC 0x8002 // 和CNC通讯超时
#define NCRM_ERR_SEND_DATA 0x8006        // 错误码, 发送出错
#define NCRM_ERR_REFUSED 0x8007          // 命令或请求被拒绝
#define NCRM_ERR_NO_THIS_CNC 0x8008      // 指定的CNC不存在
#define NCRM_ERR_MUST_CONNECT 0x8009     // 首先必须连接才能进行指定的操作
#define NCRM_ERR_FAIL_SENDTO_CNC 0x800A  // 向CNC发送数据失败
#define NCRM_ERR_ALLOC_MEM 0x800B        // 申请缓冲区失败
#define NCRM_ERR_QUEUE_SEND 0x800C       // 发送队列已满
#define NCRM_ERR_PLC_STOP 0x800D         ///<< 错误码， PLC停止运行
#define NCRM_ERR_COMFAILURE 0x8010       // 通讯中出错
#define NCRM_ERR_OPEN_LOCALFILE 0x8011   // 打开本地文件出错
#define NCRM_ERR_READ_LOCALFILE 0x8012   // 读取本地文件出错
#define NCRM_ERR_WRITE_LOCALFILE 0x8013  // 写本地文件出错
#define NCRM_ERR_NOSTD_FILENAME 0x8014   // 非标准的CNC文件名
#define NCRM_ERR_CANCELTRANS 0x8015      // 传输中被取消
#define NCRM_ERR_RESPOND 0x8016          // 无效的回复
#define NCRM_ERR_INVALIDHANDLE 0x8017    // 无效的句柄

/*CNC工作方式定义*/
#define CNC_MODE_EDIT 0   //编辑方式
#define CNC_MODE_MEM 1    //自动方式
#define CNC_MODE_MDI 2    //MDI方式
#define CNC_MODE_DNC 3    //DNC方式
#define CNC_MODE_JOG 4    //手动方式
#define CNC_MODE_HANDLE 5 //手轮方式
#define CNC_MODE_REF 6    //回参考点方式

/*CNC运行状态定义*/
#define CNC_STATE_RESET 0 //复位状态
#define CNC_STATE_STOP 1  //停止状态
#define CNC_STATE_RUN 2   //运行状态
#define CNC_STATE_HOLD 3  //暂停状态

/*坐标类型定义*/
#define COORD_TYPE_ABS 0 //绝对坐标
#define COORD_TYPE_REL 1 //相对坐标
#define COORD_TYPE_MAC 2 //机床坐标
#define COORD_TYPE_REM 3 //余移动量

#ifdef __cplusplus
extern "C"
{
#endif

  /********** 通讯管理 ************/

  /*
功  能：创建GSK数据通信实例
参  数：cncIPAddr : CNC 的IP 地址
参  数：type : 通讯模式  0为UDP,1为TCP
返回值：成功返回通信实例句柄，出错返回NULL
*/
  GSKAPI HINSGSKRM GSKRM_CreateInstance(unsigned char cncIPAddr[4], int type);
  GSKAPI HINSGSKRM GSKRM_CreateInstanceExt(unsigned char cncIPAddr[4], int type);

  /*
功  能：关闭GSK数据通信实例
参  数：hInst: GSK数据通信实例句柄
返回值：无
*/
  GSKAPI void GSKRM_CloseInstance(HINSGSKRM hInst);

  /*
功  能：设置通信超时时间
参  数：hInst:  GSK数据通信实例句柄
		overtime: 通信超时时间，单位ms
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_SetOvertime(HINSGSKRM hInst, unsigned int overtime);

  /*
功  能：客户端获取自身的以太网通讯读写权限
参  数： hInst:  GSK数据通信实例句柄
	pPurview: 用于存放获得的读写权限，0:拒绝访问数据; 1:只允许读取；2:允许读取和写入
		  返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetRMPurview(HINSGSKRM hInst, int *pPurview);

  /*
功  能：客户端设置自身的以太网通讯读写权限-高级权限下使用
参  数： hInst:  GSK数据通信实例句柄
	pPurview: 用于存放获得的读写权限，0:拒绝访问数据; 1:只允许读取；2:允许读取和写入
		  返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_SetRMPurview(HINSGSKRM hInst, int pPurview);

  /*
功  能：获取CNC型号名称
参  数：hInst:  GSK数据通信实例句柄
		typeName: 用于存放获得的CNC型号名称，数组大小应大于等于32
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetCncTypeName(HINSGSKRM hInst, char typeName[32]);

  /*
功  能：查询实例的连接状态
参  数：hInst: CNC远程诊断通信实例句柄
返回值：连接状态，-1:无效实例； 0:未连接; 1:已经连接 
*/
  GSKAPI int GSKRM_GetConnectState(HINSGSKRM hInst);

  /********** 实时信息 ************/
  /*
功  能： 获取当前通道
参  数： hInst:  GSK数据通信实例句柄
		HIWORD(*maxPathInfo): 用于存放获得的总通道数
		LOWORD(*maxPathInfo): 用于存放当前的通道

返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetCncPathInfo(HINSGSKRM hInst, int *maxPathInfo);

  /*
功  能：获取CNC当前工作方式(编辑、自动、MDI等)
参  数：hInst:  GSK数据通信实例句柄
		pWorkMode: 存放获得的工作方式
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetWorkMode(HINSGSKRM hInst, unsigned int *pWorkMode);

  /*
功  能：获取CNC当前工作方式(编辑、自动、MDI等) -通道类型
参  数：hInst:  GSK数据通信实例句柄
		pWorkMode: 存放获得的工作方式
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetWorkMode_path(HINSGSKRM hInst, BYTE path, unsigned int *pWorkMode);

  /*
功  能：获取CNC当前运行状态(复位、停止、运行、暂停)
参  数：hInst:  GSK数据通信实例句柄
		pCncState: 存放获得的运行状态
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetCncState(HINSGSKRM hInst, unsigned int *pCncState);

  /*
功  能：获取CNC当前运行状态(复位、停止、运行、暂停) - 区分通道
参  数：hInst:  GSK数据通信实例句柄
pCncState: 存放获得的运行状态
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetCncState_path(HINSGSKRM hInst, BYTE path, unsigned int *pCncState);

  /*
功  能：获取CNC当前急停状态
参  数：hInst:  GSK数据通信实例句柄
pCncEsp: 存放获得的运行状态
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetEspState(HINSGSKRM hInst, unsigned int *pCncEsp);

  /*
功  能：获取CNC当前运行行号
参  数：hInst:  GSK数据通信实例句柄
plineNo: 存放获得的运行状态
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetRunLineNo(HINSGSKRM hInst, unsigned int *plineNo);

  /*
功  能：获取CNC当前运行行号 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
plineNo: 存放获得的运行状态
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetRunLineNo_path(HINSGSKRM hInst, BYTE path, unsigned int *plineNo);

  /*
功  能：获取当前运行CNC程序名
参  数：hInst:  GSK数据通信实例句柄
		filename: 数组，用于存放获得的文件名
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetRunCncProgName(HINSGSKRM hInst, char filename[32]);

  /*
功  能：获取当前运行CNC主程序名
参  数：hInst:  GSK数据通信实例句柄
		filename: 数组，用于存放获得的文件名
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetMainCncProgName(HINSGSKRM hInst, char filename[32]);

  /*
功  能：获取当前运行CNC程序名  - 区分通道
参  数：hInst:  GSK数据通信实例句柄
filename: 数组，用于存放获得的文件名
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetRunCncProgName_path(HINSGSKRM hInst, BYTE path, char filename[32]);

  /*
功  能：获取当前运行CNC主程序名 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
filename: 数组，用于存放获得的文件名
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetMainCncProgName_path(HINSGSKRM hInst, BYTE path, char filename[32]);

  /*
功  能：获取当前运行CNC程序名 及行号
参  数：hInst:  GSK数据通信实例句柄
filename: 数组，用于存放获得的文件名
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetRunCncProgNameLineNo(HINSGSKRM hInst, char filename[32], unsigned int *lineNo);

  /*
功  能：获取当前运行CNC程序名，以及当前执行行号 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
filename: 数组，用于存放获得的文件名
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetRunCncProgNameLineNo_path(HINSGSKRM hInst, BYTE path, char filename[32], unsigned int *lineNo);

  /*
功  能：获取CNC当前有效轴数(即界面显示的轴数)
参  数：hInst:  GSK数据通信实例句柄
		pAxisCount: 存放获得的轴数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetAvailAxisCount(HINSGSKRM hInst, unsigned int *pAxisCount);

  /*
功  能：获取CNC当前有效轴数(即界面显示的轴数) -区分通道
参  数：hInst:  GSK数据通信实例句柄
		pAxisCount: 存放获得的轴数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetAvailAxisCount_path(HINSGSKRM hInst, BYTE path, unsigned int *pAxisCount);

  /*
功  能： 获取当前有效轴的轴名
参  数：hInst:  GSK数据通信实例句柄
		type: 坐标类型
		axisName: 数组，用于存放获得的轴名
		axisCount: 需要获取轴名的轴数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetAvailAxisName(HINSGSKRM hInst, int type, char axisName[], unsigned int axisCount);

  /*
功  能： 获取当前有效轴的轴名 -区分通道
参  数： hInst:  GSK数据通信实例句柄
		type: 坐标类型
		axisName: 数组，用于存放获得的轴名
		axisCount: 需要获取轴名的轴数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetAvailAxisName_path(HINSGSKRM hInst, BYTE path, int type, char axisName[], unsigned int axisCount);

  /*
功  能：获取当前有效轴的坐标
参  数：hInst:  GSK数据通信实例句柄
		type: 坐标类型
		coord: 数组，用于存放获得的坐标值
		axisCount: 需要获取坐标的轴数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetAvailAxisCoordinate(HINSGSKRM hInst, int type, float coord[], unsigned int axisCount);

  /*
功  能：获取当前有效轴的坐标(高精度)  - 区分通道
参  数：hInst:  GSK数据通信实例句柄
		type: 坐标类型
		coord: 数组，用于存放获得的坐标值
		axisCount: 需要获取坐标的轴数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetAvailAxisCoordinate_path(HINSGSKRM hInst, unsigned int path, int type, double coord[], unsigned int axisCount);

  /*
功  能：获取当前有效轴的单位
参  数：hInst:  GSK数据通信实例句柄
		type: 坐标类型
		units: 数组，用于存放获得的单位,0为公制,1为英制,2为旋转轴
		axisCount: 需要获取单位的轴数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetAvailAxisUnits(HINSGSKRM hInst, int type, unsigned int units[], unsigned int axisCount);

  /*
功  能：获取当前有效轴的单位  - 区分通道
参  数：hInst:  GSK数据通信实例句柄
		units: 数组，用于存放获得的单位,0为公制,1为英制,2为旋转轴
		axisCount: 需要获取单位的轴数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetAvailAxisUnits_path(HINSGSKRM hInst, BYTE path, int type, unsigned int units[], unsigned int axisCount);

  /*
功  能：获取当前加工件数
参  数：hInst:  GSK数据通信实例句柄
		pPartCount: 用于存放获得的加工件数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetPartCount(HINSGSKRM hInst, unsigned long *pPartCount);

  /*
功  能：获取当前加工件数 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
		pPartCount: 用于存放获得的加工件数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetPartCount_path(HINSGSKRM hInst, BYTE path, unsigned long *pPartCount);

  /*
功  能：获取当前运行时间，单位为秒
参  数：hInst:  GSK数据通信实例句柄
		pRunTime: 用于存放获得的运行时间
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetRunTime(HINSGSKRM hInst, unsigned long *pRunTime);

  /*
功  能：获取当前运行时间，单位为秒 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
		pRunTime: 用于存放获得的运行时间
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetRunTime_path(HINSGSKRM hInst, BYTE path, unsigned long *pRunTime);

  /*
功  能：获取当前切削时间，单位为秒
参  数：hInst:  GSK数据通信实例句柄
		pCutTime: 用于存放获得的运行时间
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetCutTime(HINSGSKRM hInst, unsigned long *pCutTime);

  /*
功  能：获取当前切削时间，单位为秒 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
pCutTime: 用于存放获得的运行时间
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetCutTime_path(HINSGSKRM hInst, BYTE path, unsigned long *pCutTime);

  /*
功  能：获取当前坐标小数点个数
参  数：hInst:  GSK数据通信实例句柄
pDecPoint: 用于存放坐标小数点个数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetFecPoint(HINSGSKRM hInst, unsigned int *pDecPoint);

  /*
功  能：获取当前坐标小数点个数 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
pDecPoint: 用于存放坐标小数点个数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetFecPoint_path(HINSGSKRM hInst, BYTE path, unsigned int *pDecPoint);
  /*
功  能： 获取当前编程进给速度
参  数： hInst:  GSK数据通信实例句柄
		pFeedSpeed: 用于存放获得的编程进给速度
返回值：成功返回0, 否则返回错误码
	*/
  GSKAPI int GSKRM_GetFeedSpeedProg(HINSGSKRM hInst, double *pFeedSpeed);

  /*
功  能： 获取当前编程进给速度 - 区分通道
参  数： hInst:  GSK数据通信实例句柄
		pFeedSpeed: 用于存放获得的编程进给速度
			返回值：成功返回0, 否则返回错误码
	*/
  GSKAPI int GSKRM_GetFeedSpeedProg_path(HINSGSKRM hInst, BYTE path, double *pFeedSpeed);

  /*
功  能： 获取当前实际进给速度
参  数： hInst:  GSK数据通信实例句柄
		pFeedSpeed: 用于存放获得的实际进给速度
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetFeedSpeedAct(HINSGSKRM hInst, double *pFeedSpeed);

  /*
功  能： 获取当前实际进给速度 - 区分通道
参  数： hInst:  GSK数据通信实例句柄
		pFeedSpeed: 用于存放获得的实际进给速度
					返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetFeedSpeedAct_path(HINSGSKRM hInst, BYTE path, double *pFeedSpeed);

  /*
功  能： 获取当前进给倍率
参  数： hInst:  GSK数据通信实例句柄
		 pFeedRate: 用于存放获得的进给倍率
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetFeedRate(HINSGSKRM hInst, double *pFeedRate);

  /*
功  能： 获取当前进给倍率 - 区分通道
参  数： hInst:  GSK数据通信实例句柄
		 pFeedRate: 用于存放获得的进给倍率
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetFeedRate_path(HINSGSKRM hInst, BYTE path, double *pFeedRate);

  /*
功  能： 获取主轴编程转速
参  数： hInst:  GSK数据通信实例句柄
		 spdnum: 主轴号, 从1开始, spdnum=1表示主轴1
		 pSpdSpeed: 用于存放获得的主轴编程转速
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetSpindleSpeedProg(HINSGSKRM hInst, int spdnum, double *pSpdSpeed);

  /*
功  能： 获取主轴编程转速 - 区分通道
参  数： hInst:  GSK数据通信实例句柄
		 spdnum: 主轴号, 从1开始, spdnum=1表示主轴1
		 pSpdSpeed: 用于存放获得的主轴编程转速
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetSpindleSpeedProg_path(HINSGSKRM hInst, BYTE path, int spdnum, double *pSpdSpeed);

  /*
功  能： 获取当前进给倍率 - 区分通道
参  数： hInst:  GSK数据通信实例句柄
		 pFeedRate: 用于存放获得的进给倍率
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetFeedRate_path(HINSGSKRM hInst, BYTE path, double *pFeedRate);

  /*
功  能： 获取当前主轴实际转速
参  数： hInst:  GSK数据通信实例句柄
         spdnum: 主轴号, 从1开始, spdnum=1表示主轴1
		 pSpdSpeed: 用于存放获得的主轴实际转速
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetSpindleSpeedAct(HINSGSKRM hInst, int spdnum, double *pSpdSpeed);

  /*
功  能： 获取当前主轴实际转速 - 区分通道
参  数： hInst:  GSK数据通信实例句柄
         spdnum: 主轴号, 从1开始, spdnum=1表示主轴1
		 pSpdSpeed: 用于存放获得的主轴实际转速
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetSpindleSpeedAct_path(HINSGSKRM hInst, BYTE path, int spdnum, double *pSpdSpeed);

  /*
功  能： 获取当前主轴倍率
参  数： hInst:  GSK数据通信实例句柄
		 pSpdRate: 用于存放获得的主轴倍率
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetSpindleRate(HINSGSKRM hInst, double *pSpdRate);

  /*
功  能： 获取当前主轴倍率 - 区分通道
参  数： hInst:  GSK数据通信实例句柄
		 pSpdRate: 用于存放获得的主轴倍率
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetSpindleRate_path(HINSGSKRM hInst, BYTE path, double *pSpdRate);

  /*
功  能：获取当前快速倍率
参  数：hInst:  GSK数据通信实例句柄
		pFastRate: 用于存放获得的快速倍率
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetFastRate(HINSGSKRM hInst, double *pFastRate);

  /*
功  能：获取当前快速倍率 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
		pFastRate: 用于存放获得的快速倍率
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetFastRate_path(HINSGSKRM hInst, BYTE path, double *pFastRate);

  /*
功  能：获取当前手动倍率
参  数：hInst:  GSK数据通信实例句柄
		pFastRate: 用于存放获得的手动倍率
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetJogRate(HINSGSKRM hInst, double *pFastRate);

  /*
功  能：获取当前手动倍率 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
		pFastRate: 用于存放获得的手动倍率
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetJogRate_path(HINSGSKRM hInst, BYTE path, double *pFastRate);

  /*
功  能：获取当前手轮倍率
参  数：hInst:  GSK数据通信实例句柄
		pHWRate: 用于存放获得的主轴倍率
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetHandWheelRate(HINSGSKRM hInst, double *pHWRate);

  /*
功  能：获取当前手轮倍率 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
		pHWRate: 用于存放获得的主轴倍率
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetHandWheelRate_path(HINSGSKRM hInst, BYTE path, double *pHWRate);

  /*
功  能：获取当前刀具刀补号
参  数：hInst:  GSK数据通信实例句柄
		pToolOff: 用于存放获得的刀具刀补号,最低字节为刀补号，第二个字节为刀具号,
				 高位的两个字节暂时保留
返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_GetToolOffNum(HINSGSKRM hInst, unsigned long *pToolOff);

  /*
功  能：获取当前刀具刀补号 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
		pToolOff: 用于存放获得的刀具刀补号,最低字节为刀补号，第二个字节为刀具号,
				 高位的两个字节暂时保留
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetToolOffNum_path(HINSGSKRM hInst, BYTE path, unsigned long *pToolOff);

  /*
功  能：获取G模态信息
参  数：hInst:  GSK数据通信实例句柄
		codeList: 数组用于存放获得的G指令值列表
		listLen: 用于指定数组codeList 的大小
		pCodeCount: 用于存放实际获取的G模态数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetGCodeMode(HINSGSKRM hInst, unsigned short codeList[], int listLen, int *pCodeCount);

  /*
功  能：获取G模态信息 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
		codeList: 数组用于存放获得的G指令值列表
		listLen: 用于指定数组codeList 的大小
		pCodeCount: 用于存放实际获取的G模态数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetGCodeMode_path(HINSGSKRM hInst, BYTE path, unsigned short codeList[], int listLen, int *pCodeCount);

  /*
功  能：获取M模态信息
参  数：hInst:  GSK数据通信实例句柄
		codeList: 数组用于存放获得的M指令值列表
		listLen: 用于指定数组codeList 的大小
		pCodeCount: 用于存放实际获取的M模态数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetMCodeMode(HINSGSKRM hInst, unsigned short codeList[], int listLen, int *pCodeCount);

  /*
功  能：获取M模态信息 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
		codeList: 数组用于存放获得的M指令值列表
		listLen: 用于指定数组codeList 的大小
		pCodeCount: 用于存放实际获取的M模态数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetMCodeMode_path(HINSGSKRM hInst, BYTE path, unsigned short codeList[], int listLen, int *pCodeCount);

  /*
功  能：获取CNC报警号数
参  数：hInst:  GSK数据通信实例句柄
		ErrNum: 用于存放获得的报警号(最后结束为-1,注意申请的要比最大报警数多1个)
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetAlarmNum(HINSGSKRM hInst, int ErrNum[]);

  /************参数读写************/

  /*
功  能：获得参数值
参  数：hInst: GSK数据通信实例句柄
		num: 参数序号
		axisspd: 轴号或主轴号，如是轴型参数为轴号，如是主轴型参数为主轴号，其他类型参数该形参不起作用,设置为0即可
		pValue: 用于存放获得的参数值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetParamValue(HINSGSKRM hInst, unsigned short num, int axisspd, int *pValue);

  /*
功  能：设置参数值
参  数：hInst: GSK数据通信实例句柄
		num: 参数序号
		axisspd: 轴号或主轴号，如是轴型参数为轴号，如是主轴型参数为主轴号，其他类型参数该形参不起作用,设置为0即可
		value: 参数值，位型的参数只有低8位有效
返回值：成功返回0, 否则返回错误码
		*/
  GSKAPI int GSKRM_SetParamValue(HINSGSKRM hInst, unsigned short num, int axisspd, int vaule);

  /*
	功  能：获得参数值（双精度）
	参  数：hInst: GSK数据通信实例句柄
	num: 参数序号
	axisspd: 轴号或主轴号，如是轴型参数为轴号，如是主轴型参数为主轴号，其他类型参数该形参不起作用,设置为0即可
	v1: 特殊类型参数预留( 1Byte )
	v2: 特殊类型参数预留( 1Byte )
	pValue: 用于存放获得的参数值
	返回值：成功返回0, 否则返回错误码
	*/
  GSKAPI int GSKRM_GetParamDoubleValue(HINSGSKRM hInst, unsigned short num, int axisspd, int v1, int v2, double *pValue);

  /*
	功  能：获得参数值（双精度）
	参  数：hInst: GSK数据通信实例句柄
	num: 参数序号
	axisspd: 轴号或主轴号，如是轴型参数为轴号，如是主轴型参数为主轴号，其他类型参数该形参不起作用,设置为0即可
	v1: 特殊类型参数预留( 1Byte )
	v2: 特殊类型参数预留( 1Byte )
	pValue: 用于存放获得的参数值
	返回值：成功返回0, 否则返回错误码
	*/
  GSKAPI int GSKRM_GetParamDoubleValue_path(HINSGSKRM hInst, int path, unsigned short num, int axisspd, int v1, int v2, double *pValue);

  /*
	功  能：设置参数值（双精度）
	参  数：hInst: GSK数据通信实例句柄
	num: 参数序号
	axisspd: 轴号或主轴号，如是轴型参数为轴号，如是主轴型参数为主轴号，其他类型参数该形参不起作用,设置为0即可
	bitMask: 位掩码
	v1: 预留参数值(1byte)
	value: 参数值
	返回值：成功返回0, 否则返回错误码
	*/
  GSKAPI int GSKRM_SetParamDoubleValue(HINSGSKRM hInst, unsigned short num, int axisspd, int bitMask, int v1, double value);

  /*
	功  能：设置参数值（双精度）
	参  数：hInst: GSK数据通信实例句柄
	num: 参数序号
	axisspd: 轴号或主轴号，如是轴型参数为轴号，如是主轴型参数为主轴号，其他类型参数该形参不起作用,设置为0即可
	bitMask: 位掩码( 1Byte )
	v1: 特殊类型参数预留( 1Byte )
	value: 参数值
	返回值：成功返回0, 否则返回错误码
	*/
  GSKAPI int GSKRM_SetParamDoubleValue_path(HINSGSKRM hInst, int path, unsigned short num, int axisspd, int bitMask, int v1, double value);

  /*
	功  能：设置参数某一位的值(该接口只对位型参数有效)
	参  数：hInst: GSK数据通信实例句柄
	num: 参数序号
	axisspd: 轴号或主轴号，如是轴型参数为轴号，如是主轴型参数为主轴号，其他类型参数该形参不起作用,设置为0即可
	bit: 位号
	value: 参数值，只能设置0和1，如果设置为非0值，则按1处理
	返回值：成功返回0, 否则返回错误码
	*/
  GSKAPI int GSKRM_SetParamBitValue(HINSGSKRM hInst, unsigned short num, int axisspd, int bit, unsigned char value);

  /********** 刀补读写 ************/

  /*
	功  能：获取刀补数据项个数
	参  数：hInst:  GSK数据通信实例句柄
		pCount: 用于存放获得的刀补数据项个数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetToolOffsetCount(HINSGSKRM hInst, int *pCount);

  /*
功  能：获取长度偏置值
参  数：hInst:  GSK数据通信实例句柄
		index: 刀偏号
		axis: 轴号
		pValue: 用于存放获得的长度偏置值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetToolOffsetL(HINSGSKRM hInst, int index, int axis, float *pValue);

  /*
功  能：获取长度偏置值
参  数：hInst:  GSK数据通信实例句柄
		start: 起始刀偏号
		count: 获取的刀偏数量
		axis: 轴号
		pValue: 用于存放获得的长度偏置值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetToolOffsetLEx(HINSGSKRM hInst, int start, int count, int axis, float *pValue);

  /*
功  能：获取长度偏置值 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
		index: 刀偏号
		axis: 轴号
		pValue: 用于存放获得的长度偏置值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetToolOffsetL_path(HINSGSKRM hInst, BYTE path, int index, int axis, float *pValue);

  /*
功  能：获取长度偏置值 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
		start: 起始刀偏号
		count: 获取的刀偏数量
		axis: 轴号
		pValue: 用于存放获得的长度偏置值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetToolOffsetLEx_path(HINSGSKRM hInst, BYTE path, int start, int count, int axis, float *pValue);

  /*
功  能：获取长度磨损值
参  数：hInst:  GSK数据通信实例句柄
		index: 刀偏号
		axis: 轴号
		pValue: 用于存放获得的磨损值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetToolAbrL(HINSGSKRM hInst, int index, int axis, float *pValue);

  /*
功  能：获取长度磨损值 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
		index: 刀偏号
		axis: 轴号
		pValue: 用于存放获得的磨损值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetToolAbrL_path(HINSGSKRM hInst, BYTE path, int index, int axis, float *pValue);

  /*
功  能：获取刀尖半径值
参  数：hInst:  GSK数据通信实例句柄
		index: 刀偏号
		pValue: 用于存放获得的刀尖半径值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetToolOffsetR(HINSGSKRM hInst, int index, float *pValue);

  /*
功  能：获取刀尖半径值 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
index: 刀偏号
		pValue: 用于存放获得的刀尖半径值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetToolOffsetR_path(HINSGSKRM hInst, BYTE path, int index, float *pValue);

  /*
功  能：获取刀尖半径磨损值
参  数：hInst:  GSK数据通信实例句柄
		index: 刀偏号
		pValue: 用于存放获得的刀尖半径磨损值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetToolAbrR(HINSGSKRM hInst, int index, float *pValue);

  /*
功  能：获取刀尖半径磨损值 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
		index: 刀偏号
		pValue: 用于存放获得的刀尖半径磨损值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetToolAbrR_path(HINSGSKRM hInst, BYTE path, int index, float *pValue);

  /*
功  能：获取刀尖方向
参  数：hInst:  GSK数据通信实例句柄
		index: 刀偏号
		pToolDir: 用于存放获得的刀尖方向
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetToolEdge(HINSGSKRM hInst, int index, int *pToolDir);

  /*
功  能：获取刀尖方向 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
index: 刀偏号
		pToolDir: 用于存放获得的刀尖方向
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetToolEdge_path(HINSGSKRM hInst, BYTE path, int index, int *pToolDir);

  /*
功  能：设置长度偏置值
参  数：hInst:  GSK数据通信实例句柄
		index: 刀偏号
		axis: 轴号
		value:长度偏置值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_SetToolOffsetL(HINSGSKRM hInst, int index, int axis, float value);

  /*
功  能：设置长度偏置值 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
		index: 刀偏号
		axis: 轴号
		value:长度偏置值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_SetToolOffsetL_path(HINSGSKRM hInst, BYTE path, int index, int axis, float value);

  /*
功  能：设置长度磨损值
参  数：hInst:  GSK数据通信实例句柄
		index: 刀偏号
		axis: 轴号
		value: 磨损值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_SetToolAbrL(HINSGSKRM hInst, int index, int axis, float value);

  /*
功  能：设置长度磨损值 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
		index: 刀偏号
		axis: 轴号
		value: 磨损值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_SetToolAbrL_path(HINSGSKRM hInst, BYTE path, int index, int axis, float value);

  /*
功  能：设置刀尖半径值
参  数：hInst:  GSK数据通信实例句柄
		index: 刀偏号
		value: 用刀尖半径值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_SetToolOffsetR(HINSGSKRM hInst, int index, float value);

  /*
功  能：设置刀尖半径值 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
index: 刀偏号
		value: 用刀尖半径值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_SetToolOffsetR_path(HINSGSKRM hInst, BYTE path, int index, float value);

  /*
功  能：设置刀尖半径磨损值
参  数：hInst:  GSK数据通信实例句柄
		index: 刀偏号
		value: 刀尖半径磨损值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_SetToolAbrR(HINSGSKRM hInst, int index, float value);

  /*
功  能：设置刀尖半径磨损值 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
index: 刀偏号
		value: 刀尖半径磨损值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_SetToolAbrR_path(HINSGSKRM hInst, BYTE path, int index, float value);

  /*
功  能：设置刀尖方向
参  数：hInst:  GSK数据通信实例句柄
		index: 刀偏号
		toolDir: 刀尖方向
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_SetToolEdge(HINSGSKRM hInst, int index, int toolDir);

  /*
功  能：设置刀尖方向 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
index: 刀偏号
		toolDir: 刀尖方向
	返回值：成功返回0, 否则返回错误码
	*/
  GSKAPI int GSKRM_SetToolEdge_path(HINSGSKRM hInst, BYTE path, int index, int toolDir);

  /*
	功  能：获取刀补值（双精度）
	参  数：hInst:  GSK数据通信实例句柄
	index: 刀补号
	axisspd: 轴号
	type: 值类型（0：长度偏置 1：长度磨损 2：刀尖半径 3：刀尖半径磨损 4：刀尖方向）
	返回值：成功返回0, 否则返回错误码
	*/
  GSKAPI int GSKRM_GetToolOffsetDoubleValue(HINSGSKRM hInst, int index, int axisspd, int type, double *pValue);

  /*
	功  能：获取刀补值（双精度） - 区分通道
	参  数：hInst:  GSK数据通信实例句柄
	index: 刀补号
	axisspd: 轴号
	type: 值类型（0：长度偏置 1：长度磨损 2：刀尖半径 3：刀尖半径磨损 4：刀尖方向）
	返回值：成功返回0, 否则返回错误码
	*/
  GSKAPI int GSKRM_GetToolOffsetDoubleValue_path(HINSGSKRM hInst, int path, int index, int axisspd, int type, double *pValue);

  /*
	功  能：设置刀补值（双精度）
	参  数：hInst:  GSK数据通信实例句柄
	index: 刀补号
	axisspd: 轴号
	type: 值类型（0：长度偏置 1：长度磨损 2：刀尖半径 3：刀尖半径磨损 4：刀尖方向）
	返回值：成功返回0, 否则返回错误码
	*/
  GSKAPI int GSKRM_SetToolOffsetDoubleValue(HINSGSKRM hInst, int index, int axisspd, int type, double value);

  /*
	功  能：设置刀补值（双精度） - 区分通道
	参  数：hInst:  GSK数据通信实例句柄
	index: 刀补号
	axisspd: 轴号
	type: 值类型（0：长度偏置 1：长度磨损 2：刀尖半径 3：刀尖半径磨损 4：刀尖方向）
	返回值：成功返回0, 否则返回错误码
	*/
  GSKAPI int GSKRM_SetToolOffsetDoubleValue_path(HINSGSKRM hInst, int path, int index, int axisspd, int type, double value);

  /********** 宏变量读写 ************/

  /*
功  能：读取宏变量值
参  数：hInst:  GSK数据通信实例句柄
		varID:  宏变量号
		pValue: 用于存放获得的宏变量值
		pEmpty: 该变量得到的值，如果等于1，表示宏变量是空值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetMacroValue(HINSGSKRM hInst, int varID, double *pValue, int *pEmpty);

  /*
功  能：读取宏变量值 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
		varID:  宏变量号
		pValue: 用于存放获得的宏变量值
		pEmpty: 该变量得到的值，如果等于1，表示宏变量是空值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetMacroValue_path(HINSGSKRM hInst, BYTE path, int varID, double *pValue, int *pEmpty);

  /*
功  能：设置宏变量值
参  数：hInst:  GSK数据通信实例句柄
		varID:  宏变量号
		value: 宏变量值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_SetMacroValue(HINSGSKRM hInst, int varID, double value);

  /*
功  能：设置宏变量值 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
		varID:  宏变量号
		value: 宏变量值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_SetMacroValue_path(HINSGSKRM hInst, BYTE path, int varID, double value);

  /*
功  能：设置宏变量为空值
参  数：hInst:  GSK数据通信实例句柄
		varID:  宏变量号
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_SetMacroEmpty(HINSGSKRM hInst, int varID);

  /*
功  能：设置宏变量值 - 区分通道
参  数：hInst:  GSK数据通信实例句柄
		varID:  宏变量号
		value: 宏变量值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_SetMacroEmpty_path(HINSGSKRM hInst, BYTE path, int varID);

  /********** 螺距补偿读写 ************/

  /*
功  能：读取螺距补偿值数据项个数
参  数：hInst:  GSK数据通信实例句柄
		pCount: 用于存放获得的数据项个数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetWormOffsetCount(HINSGSKRM hInst, int *pCount);

  /*
功  能：读取螺距补偿值
参  数：hInst:  GSK数据通信实例句柄
		index:  螺补号
		pValue: 用于存放获得的螺距补偿值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetWormOffset(HINSGSKRM hInst, int index, int *pValue);

  /*
功  能：设置螺距补偿值
参  数：hInst: GSK数据通信实例句柄
		index: 螺补号
		value: 螺距补偿值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_SetWormOffset(HINSGSKRM hInst, int index, int value);

  /********** 刀具寿命读写 ************/

  /*
功  能：获取当前正使用的刀组号
参  数：hInst:  GSK数据通信实例句柄
		pGroupNum:  用于存放获得的刀组号
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetCurToolGroup(HINSGSKRM hInst, int *pGroupNum);

  /*
功  能：获取刀组内当前使用的刀具在组内的序号
参  数：hInst:  GSK数据通信实例句柄
		groupNum: 刀组号
		pToolIndex: 用于存放获得的刀具序号
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetCurToolInGroup(HINSGSKRM hInst, int groupNum, int *pToolIndex);

  /*
功  能：获取刀组属性(计数单位和预设寿命)
参  数：hInst: GSK数据通信实例句柄
		groupNum: 刀组号
		pUnit: 用于存放获得的计数单位(0 时间秒，1 次数)
		pToolLife: 用于存放获得的刀具预设寿命
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetToolGroupProp(HINSGSKRM hInst, int groupNum, int *pUnit, unsigned int *pToolLife);

  /*
功  能：设置刀组属性(计数单位和预设寿命)，注意设置刀组属性之前，必须先调用
		GSKRM_ClearToolGroup() 清除刀组原有的数据，否则无法设置。

参  数：hInst:  GSK数据通信实例句柄
		groupNum: 刀组号
		unit:  计数单位(0 时间秒，1 次数)
		toolLife:刀具预设寿命
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_SetToolGroupProp(HINSGSKRM hInst, int groupNum, int unit, unsigned int toolLife);

  /*
功  能：获取刀具属性(计数单位和预设寿命)
参  数：hInst: GSK数据通信实例句柄
		groupNum:刀组号
		toolIndex 刀具在组内的序号
		pUnit: 用于存放获得的计数单位(0 时间秒，1 次数)
		pToolLife: 用于存放获得的刀具预设寿命
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetToolGroupPropEx(HINSGSKRM hInst, int groupNum, int toolIndex, int *pUnit, unsigned int *pToolLife);

  /*
功  能：设置刀组属性(计数单位和预设寿命)
参  数：hInst:  GSK数据通信实例句柄
		groupNum:刀组号
		toolIndex 刀具在组内的序号
		unit:  计数单位(0 时间秒，1 次数)
		toolLife:刀具预设寿命
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_SetToolGroupPropEx(HINSGSKRM hInst, int groupNum, int toolIndex, int unit, unsigned int toolLife);

  /*
功  能：获取刀组内指定刀具的刀具刀补号
参  数：hInst:  GSK数据通信实例句柄
		groupNum刀组号
		toolIndex 刀具在组内的序号
		pToolOffNum: 用于存放获得的刀具刀补号,最低字节为刀补号，第二个字节为刀具号, 高位的两个字节暂时保留
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetToolOffNumInGroup(HINSGSKRM hInst, int groupNum, int toolIndex, unsigned int *pToolOffNum);

  /*
功  能：设置刀组内指定刀具的刀具刀补号
参  数：hInst:  GSK数据通信实例句柄
		groupNum刀组号
		toolIndex 刀具在组内的序号
		toolOffNum: 刀具刀补号,最低字节为刀补号，第二个字节为刀具号, 高位的两个字节暂时保留，设置为0
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_SetToolOffNumInGroup(HINSGSKRM hInst, int groupNum, int toolIndex, unsigned int toolOffNum);

  /*
功  能：获取刀组内刀具已用寿命
参  数：hInst:  GSK数据通信实例句柄
		groupNum刀组号
		toolIndex 刀具在组内的序号
		pUsedLife: 用于存放获得的刀具已用寿命
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetToolUnsedLife(HINSGSKRM hInst, int groupNum, int toolIndex, unsigned int *pUsedLife);

  /*
功  能：获取刀组内刀具状态
参  数： hInst:  GSK数据通信实例句柄
         groupNum刀组号
		 toolIndex 刀具在组内的序号
		pToolState: 用于存放获得的刀具状态
(-1: 寿命已到; 0:未设置, 1:已设置未启用; 2:跳过，3:正在使用)
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetToolStateInGroup(HINSGSKRM hInst, int groupNum, int toolIndex, int *pToolState);

  /*
功  能：设置刀组内刀具跳过状态（如果刀具被设置为跳过，那么换刀时该刀具被跳过）
参  数：hInst:  GSK数据通信实例句柄
		groupNum刀组号
		toolIndex 刀具在组内的序号
		skipState: 跳过状态(0:不跳过; 1:跳过)
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_SetToolSkipState(HINSGSKRM hInst, int groupNum, int toolIndex, int skipState);

  /* 
功  能：获取刀组数
参  数： hInst:  GSK数据通信实例句柄
		pGroupCount: 用于存放获得的获取刀组数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetToolGroupCount(HINSGSKRM hInst, int *pGroupCount);

  /* 
功  能：获取刀组内的刀具数
参  数： hInst:  GSK数据通信实例句柄
pToolCount: 用于存放获得的获取刀具数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetToolCountInGroup(HINSGSKRM hInst, int *pToolCount);

  /* 
功  能：清除刀组数据
参  数： hInst:  GSK数据通信实例句柄
groupNum:刀组号
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_ClearToolGroup(HINSGSKRM hInst, int groupNum);

  /********** 诊断数据与报警信息 ****************/

  /*
功  能：获取某个诊断号的诊断值
参  数：hInst:  GSK数据通信实例句柄
		index: 诊断号
		axisspd: 轴号或主轴号，如是轴型诊断值为轴号，如是主轴型诊断值为主轴号，其他类型诊断值该形参不起作用,设置为0即可
		pDgnValueLow: 用于存放获得的诊断值低32的值
		pDgnValueHigh: 用于存放获得的诊断值高32的值
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetDiagnoseValue(HINSGSKRM hInst, int index, int axisspd, long *pDgnValueLow, long *pDgnValueHigh);

  /*
功  能：获取CNC报警数
参  数：hInst:  GSK数据通信实例句柄
		pErrCount: 用于存放获得的错误级别的报警数
		pWarnCount: 用于存放获得的警告级别的报警数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetAlarmCount(HINSGSKRM hInst, unsigned long *pErrCount, unsigned long *pWarnCount);

  /*
功  能：获取当前某条CNC报警的信息(报警号和报警内容)
参  数：hInst:  GSK数据通信实例句柄
		index: 报警在报警列表中的序号
		pAlmNum: 用于存放获得的报警号
		pAlmType: 用于存放获得的报警类型(0:错误; 1:警告或提示)
		almTextBuf: 用于存放获得的报警内容的缓冲
		bufLen: 报警内容缓冲的大小
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetAlarmInfo(HINSGSKRM hInst, int index, int *pAlmNum, int *pAlmType, char almTextBuf[], unsigned bufLen);

  /*
功  能：获取CNC报警历史记录数
参  数：hInst:  GSK数据通信实例句柄
		pCount: 用于存放获得的记录数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetAlarmLogCount(HINSGSKRM hInst, unsigned long *pCount);

  /*
功  能：获取一条报警历史记录信息
参  数：hInst:  GSK数据通信实例句柄
		index: 报警在报警列表中的序号
		pAlmNum: 用于存放获得的报警号
		pAlmType: 用于存放获得的报警类型(0:错误; 1:警告或提示)
		pAlmTime: 用于存放获得的报警发生时间
		almTextBuf: 用于存放获得的报警内容的缓冲
		bufLen: 报警内容缓冲的大小
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetAlarmLogInfo(HINSGSKRM hInst, int index, int *pAlmNum, int *pAlmType, time_t *pAlmTime, char almTextBuf[], unsigned bufLen);

  /********** CNC文件传输 ****************/

  /*
文件传输进度的回调函数定义
参数：completeBytes 完成传输的字节数
	  percent 完成百分比(0 ~100)
*/

#ifdef CSHARP_USE
  typedef void(__stdcall *FTPROGRESS)(unsigned long completeBytes, int percent); //C#调用
#else
typedef void (*FTPROGRESS)(unsigned long completeBytes, int percent);
#endif

  /*
功  能： 获取系统内部存储的CNC程序文件数
参  数：hInst:  GSK数据通信实例句柄
		pAlmCount: 用于存放获得的报警数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetCNCFileCount(HINSGSKRM hInst, unsigned long *pFileCount);

  /*
功  能： 获取系统内部存储的CNC程序文件数
参  数： hInst:  GSK数据通信实例句柄
		pNameBuf: 用于存放文件名列表的缓冲，文件名之间以'|' 号隔开，
				  比如："O0001.CNC|O0002.CNC|O0003.CNC"。
		bufLen: 文件名列表缓冲的大小
		pNameCount: 存放实际得到的文件名的个数
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetCNCFileList(HINSGSKRM hInst, char *pNameBuf, unsigned int bufLen, unsigned long *pNameCount);

  /*
功  能： 获取CNC程序文件信息
参  数： hInst:  GSK数据通信实例句柄
         pFileName: CNC 文件名(带后缀但不带路径，如 O0001.CNC)
         pFileSize: 用于存放得到的文件大小
		 pModifiedTime: 用于存放得到的文件修改时间
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_GetCNCFileInfo(HINSGSKRM hInst, char *pFileName, unsigned long *pFileSize, time_t *pModifiedTime);

  /*
功  能： 从CNC系统接收一个CNC程序文件
参  数： hInst:  GSK数据通信实例句柄
		 pCNCFileName: CNC 文件名(带后缀但不带路径，如 O0001.CNC)
		 pSavePathName: 保存到本地的文件路径名
	     funcProgress: 传输进度回调函数，如果不需要获得进度设置为NULL
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_ReceiveCNCFile(HINSGSKRM hInst, char *pCNCFileName, char *pSavePathName, FTPROGRESS funcProgress);

  /*
功  能：发送一个CNC程序文件到CNC系统
参  数：hInst:  GSK数据通信实例句柄
		pLocalFilePath: 本地文件名，完整路径名
		pDestFileName: 目标文件名，不带路径，但必须是标准的CNC文件名，如O1234.CNC
		funcProgress: 传输进度回调函数，如果不需要获得进度设置为NULL
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_SendCNCFile(HINSGSKRM hInst, char *pLocalFilePath, char *pDestFileName, FTPROGRESS funcProgress);

  /*
功  能： 删除一个CNC系统内部的CNC程序文件
参  数： hInst:  GSK数据通信实例句柄
         pFileName: CNC 文件名(带后缀但不带路径，如 O0001.CNC)
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_DeleteCNCFile(HINSGSKRM hInst, char *pFileName);

  /********** 伺服数据传输 ****************/

  typedef struct
  {
    long axisPos[3];  //各轴位置脉冲数
    long speed[3];    //各轴转速，放大100倍，即单位为0.01r/min
    short current[3]; //各轴力矩电流，放大100倍，即单位为0.01A
  } SERVO_SAMPDATA;

//伺服后台采样每个采样数据的长度
#define SERVO_SAMPLE_LEN 30
#define SERVO_SAMPLEPOS_LEN 100

  /*
功  能： 启动伺服数据采样，最大三个采样轴。需指定三个采样轴名，轴名为空字符串表示该信道不采样，
		 轴名为：X,Y,Z,A,B,C，主轴名为: S1,S2,S3，…, 以此类推.
参  数： hInst:  GSK数据通信实例句柄
		 axisName1:第一信道采样轴轴轴名
         axisName2:第二信道采样轴轴轴名
		 axisName3:第三信道采样轴轴轴名
返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_StartServoSample(HINSGSKRM hInst, const char *axisName1, const char *axisName2, const char *axisName3);

  /*
功  能： 结束伺服数据采样
参  数： hInst:  GSK数据通信实例句柄
返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_EndServoSample(HINSGSKRM hInst);

  /*
功  能： 获取一段伺服采样数据，受通讯数据包大小的限制，每次不超过50个。
参  数： hInst:  GSK数据通信实例句柄
		buffer: 用于存放采样数据的缓冲
		bufLen: 缓冲大小，即最大可以存放多少个SERVO_SAMPDATA类型的数据
		pDataCount: 实际获取的数据个数
返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_GetServoSampleData(HINSGSKRM hInst, SERVO_SAMPDATA buffer[], unsigned int bufLen, unsigned int *pDataCount);

  /*
功  能： 获取一段伺服采样数据，受通讯数据包大小的限制，每次不超过100个。
参  数： hInst:  GSK数据通信实例句柄
         buffer: 用于存放采样数据的缓冲
         bufLen: 缓冲大小，即最大可以存放多少个伺服位置的数据
		 pDataCount: 实际获取的数据个数
返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_GetServoSamplePos(HINSGSKRM hInst, unsigned int buffer[], unsigned int bufLen, unsigned int *pDataCount);

  /*
功  能： 申请接管机床面板
参  数： hInst:  GSK数据通信实例句柄
返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_StartRemoteMau(HINSGSKRM hInst);

  /*
功  能： 结束接管机床面板
参  数： hInst:  GSK数据通信实例句柄
返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_EndRemoteMau(HINSGSKRM hInst);

  typedef struct
  {
    unsigned char type; //远程机床面板按钮对应的类型（X，F，R等）
    unsigned char bit;  //远程机床面板按钮对应的位（0~7）
    short add;          //远程机床面板按钮对应的地址（范围根据类型来确定）
  } ADDRESS_SET_DATA;

  /*
功  能： 发送远程机床面板数据
参  数： hInst:  GSK数据通信实例句柄
		 count:	 地址个数
		 plcData: 地址信息
返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_SendRm_Mau_Data(HINSGSKRM hInst, int count, ADDRESS_SET_DATA *plcData);

  /*
功  能： 查询PLC寄存器，单一类型地址
参  数： hInst:  GSK数据通信实例句柄
		 type:	 地址类型
		 start:	 起始地址号
		 count:	 地址个数
		 pValue: 返回地址当前数据
返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_GetPlcData(HINSGSKRM hInst, short type, short start, short count, BYTE *pValue);

  typedef struct
  {
    short type; //远程机床面板按钮对应的类型（X，F，R等）
    short add;  //远程机床面板按钮对应的地址（范围根据类型来确定）
  } ADDRESS_GET_DATA;

  /*
功  能： 查询PLC寄存器，，多种类型混合
参  数： hInst:  GSK数据通信实例句柄
		 type:	 地址类型
		 count:	 地址个数
		 pValue: 返回地址当前数据
返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_GetPlcData_batch(HINSGSKRM hInst, short count, ADDRESS_GET_DATA info[], BYTE *pValue, short *pValSize);

  /*
功  能： 卸载当前执行程序
参  数： hInst:  GSK数据通信实例句柄
		 pCNCFileName: CNC 文件名(带后缀但不带路径，如 O0001.CNC)
返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_Prog_Uninstall(HINSGSKRM hInst, char *pCNCFileName);

  /*
功  能： 装载当前执行程序
参  数： hInst:  GSK数据通信实例句柄
		 pCNCFileName: CNC 文件名(带后缀但不带路径，如 O0001.CNC)
返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_Prog_Install(HINSGSKRM hInst, char *pCNCFileName);

  /*
功  能： 获取状态信息指令
参  数： hInst:  GSK数据通信实例句柄
		 MainProg:	 主程序名
		 CurProg:		 当前程序名
		 CurSeq:	 程序段号
		 status:		 模态
		 mode:		状态
		 Alarm:		报警状态
		 EMG:		急停状态

返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_GetStatus(HINSGSKRM hInst, char MainProg[], char CurProg[], int *CurSeq, int *Mode, int *Status, int Alarm[], int *EMG);

  /*
功  能： 获取状态信息指令- 区分通道
参  数： hInst:  GSK数据通信实例句柄
		 MainProg:	 主程序名
		 CurProg:		 当前程序名
		 CurSeq:	 程序段号
		 status:		 模态
		 mode:		状态
		 Alarm:		报警状态
		 EMG:		急停状态
		 path:		通道

返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_GetStatus_path(HINSGSKRM hInst, BYTE path, char MainProg[], char CurProg[], int *CurSeq, int *Mode, int *Status, int Alarm[], int *EMG);

  /*
功  能： 获取位置信息指令
参  数： hInst:  GSK数据通信实例句柄
		 axisName:	 轴名
		 unit:		 单位
		 decPoint:	 小数点位数
		 mach:		 机床坐标
		 abs:		绝对坐标
		 real:		剩余坐标
		 dist:		目标坐标

返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_GetPosition(HINSGSKRM hInst, char axisName[], int unit[], int decPoint[], float mach[], float abs[], float real[], float dist[]);

  /*
功  能： 获取位置信息指令- 区分通道
参  数： hInst:  GSK数据通信实例句柄
		 axisName:	 轴名
		 unit:		 单位
		 decPoint:	 小数点位数
		 mach:		 机床坐标
		 abs:		绝对坐标
		 real:		剩余坐标
		 dist:		目标坐标
		 path:		通道

返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_GetPosition_path(HINSGSKRM hInst, BYTE path, char axisName[], int unit[], int decPoint[], float mach[], float abs[], float real[], float dist[]);

  /*
功  能： 获取系统信息指令
参  数： hInst:  GSK数据通信实例句柄
		 axisCount:	 有效轴数
		 cncType:		 系统类型
		 maxAxis:	 最大轴数
		 axisName:		 轴名


返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_GetCncInfo(HINSGSKRM hInst, int *axisCount, char cncType[], char axisName[]);

  /*
功  能： 获取系统信息指令- 区分通道
参  数： hInst:  GSK数据通信实例句柄
		 axisCount:	 有效轴数
		 cncType:		 系统类型
		 maxAxis:	 最大轴数
		 axisName:		 轴名
		 path:			通道

返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_GetCncInfo_path(HINSGSKRM hInst, BYTE path, int *axisCount, char cncType[], char axisName[]);

  /*
功  能： 获取倍率转速信息指令
参  数： hInst:  GSK数据通信实例句柄
		 OvFeed:		进给倍率
		 OvSpindle:		 主轴倍率
		 actFeed:		进给速度
		 actSpindle:	主轴速度轴名


返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_GetRateInfo(HINSGSKRM hInst, double *OvFeed, double *OvSpindle, double *actFeed, double *actSpindle);

  /*
功  能： 获取倍率转速信息指令- 区分通道
参  数： hInst:  GSK数据通信实例句柄
		 OvFeed:		进给倍率
		 OvSpindle:		 主轴倍率
		 actFeed:		进给速度
		 actSpindle:	主轴速度轴名
		 path:			通道

返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_GetRateInfo_path(HINSGSKRM hInst, BYTE path, double *OvFeed, double *OvSpindle, double *actFeed, double *actSpindle);

  /*
功  能： 获取所有倍率转速信息指令
参  数： hInst:  GSK数据通信实例句柄
		 pFeedRate：	进给倍率
		 pSpdRate:		主轴倍率
		 pFastRate:		快速倍率
		 pJogRate:		手轮倍率
		 pHWRate:		手动倍率
		 pFeedSpeed:	编程进给速度
		 pActFeedSpeed:	进给速度
		 nSpdCount:		主轴数，nSpdCount < 4
		 spdnum[nSpdCount];		主轴号数组, 从1开始, spdnum[i]=1表示主轴1,
		 pSpdSpeed:		主轴编程速度数组
		 pActSpdSpeed:	主轴速度数组

返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_GetAllRateInfo(HINSGSKRM hInst,
                                  double *pFeedRate, double *pSpdRate, double *pFastRate,
                                  double *pJogRate, double *pHWRate,
                                  double *pFeedSpeed, double *pActFeedSpeed, int nSpdCount,
                                  int spdnum[], double *pSpdSpeed, double *pActSpdSpeed);

  /*
功  能： 获取所有倍率转速信息指令- 区分通道
参  数： hInst:  GSK数据通信实例句柄
		 path:			通道
		 pFeedRate：	进给倍率
		 pSpdRate:		主轴倍率
		 pFastRate:		快速倍率
		 pJogRate:		手轮倍率
		 pHWRate:		手动倍率
		 pFeedSpeed:	编程进给速度
		 pActFeedSpeed:	进给速度
		 nSpdCount:		主轴数，nSpdCount < 4
		 spdnum[nSpdCount];		主轴号数组, 从1开始, spdnum[i]=1表示主轴1,
		 pSpdSpeed:		主轴编程速度数组
		 pActSpdSpeed:	主轴速度数组

返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_GetAllRateInfo_path(HINSGSKRM hInst, BYTE path,
                                       double *pFeedRate, double *pSpdRate, double *pFastRate,
                                       double *pJogRate, double *pHWRate,
                                       double *pFeedSpeed, double *pActFeedSpeed, int nSpdCount,
                                       int spdnum[], double *pSpdSpeed, double *pActSpdSpeed);

  /*
功  能： 获取时间信息指令
参  数： hInst:  GSK数据通信实例句柄
		 RunTime:		运行时间
		 CutTime:		 切屑时间
		 

返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_GetTimeInfo(HINSGSKRM hInst, int *RunTime, int *CutTime);

  /*
功  能： 获取时间信息指令- 区分通道
参  数： hInst:  GSK数据通信实例句柄
		 RunTime:		运行时间
		 CutTime:		 切屑时间
		 path:			 通道

返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_GetTimeInfo_path(HINSGSKRM hInst, BYTE path, int *RunTime, int *CutTime);
  /*
功  能： 测试打包指令
参  数： hInst:  GSK数据通信实例句柄
		 coord1:	 绝对坐标
		 coord2:	 相对坐标
		 coord3:	 机床坐标
		 pPartCount: 加工件数
返回值：成功返回0, 否则返回错误码*/
  GSKAPI int GSKRM_GetSpCoord(HINSGSKRM hInst, float coord1[], float coord2[], float coord3[], unsigned long *pPartCount);

  /*
功  能： 设置PLC寄存器，单一类型地址，从地址起点开始的连续多个数据的写入
参  数： hInst:  GSK数据通信实例句柄
		   type:	地址类型
		   count:	地址个数 起点
		   num:    读取寄存器的数量 (从起点开始的连续多个数据)
		   pValue: 当前数据缓冲区指针
返回值：成功返回0, 否则返回错误码
*/
  GSKAPI int GSKRM_SetPlcData(HINSGSKRM hInst, int type, int count, int num, unsigned char dValue[]);

  /*
功  能： 设置PLC寄存器，单一类型地址，从地址起点开始的连续多个数据的写入
参  数： hInst:  GSK数据通信实例句柄
		   type:	地址类型
		   count:	地址个数 起点
		   num:    读取寄存器的数量 (从起点开始的连续多个数据)
		   pValue: 当前数据缓冲区指针
返回值：成功返回0, 否则返回错误码
*/
  //GSKAPI int GSKRM_SetPlcData(HINSGSKRM hInst, int type, int count, int num, unsigned char dValue[]);

  /*
	功  能：设置温度补偿值
	参  数：hInst: GSK数据通信实例句柄
	axis:  轴序号(从0开始)
	value: 补偿值，排序按照K0，ExpFactor，RefPos
	返回值：成功返回0, 否则返回错误码
	*/
  GSKAPI int GSKRM_SetTempComp(HINSGSKRM hInst, int axis, int mode, double *pValue);

  /*
	功  能：设置温度补偿值
	参  数：hInst: GSK数据通信实例句柄
	path:  通道号
	axis:  轴序号(从0开始)
	value: 补偿值，排序按照K0，ExpFactor，RefPos
	返回值：成功返回0, 否则返回错误码
	*/
  GSKAPI int GSKRM_SetTempComp_path(HINSGSKRM hInst, int path, int axis, int mode, double *pValue);

  /*
	功  能：设置温度
	参  数：hInst: GSK数据通信实例句柄
	axis:  轴序号(从0开始)
	value: 温度
	返回值：成功返回0, 否则返回错误码
	*/
  GSKAPI int GSKRM_SetTemperature(HINSGSKRM hInst, int nsize, float *pValue);

  /*
	功  能：设置温度
	参  数：hInst: GSK数据通信实例句柄
	path:  通道号
	nsize: 温度个数
	value: 温度
	返回值：成功返回0, 否则返回错误码
	*/
  GSKAPI int GSKRM_SetTemperature_path(HINSGSKRM hInst, int path, int nsize, float *pValue);

  /*
	功  能：获取温度
	参  数：hInst: GSK数据通信实例句柄
	nsize: 温度个数
	value: 温度
	返回值：成功返回0, 否则返回错误码
	*/
  GSKAPI int GSKRM_GetTemperature(HINSGSKRM hInst, int nsize, float *pValue);

  /*
	功  能：获取温度
	参  数：hInst: GSK数据通信实例句柄
	path:  通道号
	nsize: 温度个数
	value: 温度
	返回值：成功返回0, 否则返回错误码
	*/
  GSKAPI int GSKRM_GetTemperature_path(HINSGSKRM hInst, int path, int nsize, float *pValue);

  typedef struct
  {
    int id;
    int type;
    double data;
  } NCRM_CUSTOMDATA3;

  /*
	功  能：获取自定义数据（研发三室）
	参  数：hInst: GSK数据通信实例句柄
			data: 接收数据缓冲数组
			size: 数组大小
			dataSize: 实际数据个数
	返回值：成功返回0, 否则返回错误码
	*/
  GSKAPI int GSKRM_GetCustomData3(HINSGSKRM hInst, NCRM_CUSTOMDATA3 *data, int size, int *dataSize);

  /*
	功  能：设置自定义数据（研发三室）
	参  数：hInst: GSK数据通信实例句柄
			data: 发送数据所存数组
			size: 数组大小
	返回值：成功返回0, 否则返回错误码
	*/
  GSKAPI int GSKRM_SetCustomData3(HINSGSKRM hInst, NCRM_CUSTOMDATA3 *data, int size);

#ifdef __cplusplus
}
#endif