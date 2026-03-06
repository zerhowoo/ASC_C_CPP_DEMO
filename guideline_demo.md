# SPiiPlus C Library Demo — 部署指南与功能说明

## 第一部分：Windows 11 x64 系统部署指南

### 1. 前提条件

| 项目 | 要求 |
|------|------|
| 操作系统 | Windows 11 64 位 |
| IDE | Visual Studio 2019 或更高版本（需安装 **"使用 C++ 的桌面开发"** 工作负载，包含 MFC 组件） |
| ACS 软件包 | SPiiPlus ADK Suite（建议 v2.70 及以上），安装后会自动部署所需的 DLL 和驱动 |
| 控制器 | ACS SPiiPlus 系列控制器（实物），或使用 SPiiPlus Simulator 仿真模式 |

### 2. 安装 SPiiPlus ADK Suite

1. 从 ACS Motion Control 官方获取 **SPiiPlus ADK Suite** 安装包。
2. 运行安装程序，默认安装路径为：
   ```
   C:\Program Files (x86)\ACS Motion Control\SPiiPlus ADK Suite v2.70\
   ```
3. 安装完成后，安装程序会自动将以下 DLL 文件放置到系统目录中：
   - `ACSCL_x64.DLL` → `C:\Windows\System32\`（64 位系统的 64 位 DLL）
   - `ACSCL_x86.DLL` → `C:\Windows\SysWOW64\`（64 位系统下的 32 位兼容 DLL）

   > **重要**：如果没有安装 ADK Suite，Demo 程序将无法运行，因为缺少运行时 DLL。

### 3. 获取仓库代码

```bash
git clone <仓库地址>
```

仓库结构如下：
```
ASC_C_CPP_DEMO/
├── ACSC.h                              # SPiiPlus C Library 主头文件 (v7.6.0.0)
├── ACSCL_x64.LIB                       # 64 位静态链接库
├── ACSCL_x86.LIB                       # 32 位静态链接库
└── Samples/
    ├── Programming Examples.txt         # 示例说明文档
    ├── SPiiPlus C Library Demo/         # 本指南的主要对象
    ├── Terminal/                         # 通信终端示例
    ├── Reciprocated/                    # 往复运动示例
    └── Measurements Demo/               # 测量应用示例
```

### 4. 用 Visual Studio 打开项目

1. 使用 Visual Studio 2019/2022 打开解决方案文件：
   ```
   Samples\SPiiPlus C Library Demo\SPiiPlusCLibraryDemo VS.2019.sln
   ```
2. 如果 VS 提示升级工具集（Platform Toolset），选择 **"确定"** 升级到当前版本（如 v143）。

### 5. 配置项目（针对 x64 平台）

仓库中的 `.vcxproj` 文件默认的 Release/Debug 配置是 **Win32 (x86)** 平台。对于 Windows 11 x64 系统，建议配置 **x64** 平台：

#### 5.1 添加 x64 平台配置（如不存在）

1. 菜单 → **生成** → **配置管理器**
2. 在 "活动解决方案平台" 下拉框中选择 **"<新建...>"**
3. 新平台选择 **x64**，从 "Win32" 复制设置，点击确定

#### 5.2 配置头文件路径

在 **项目属性** → **C/C++** → **附加包含目录** 中确认包含了 `ACSC.h` 的路径。
该文件位于仓库根目录，项目中通过相对路径 `..\..\ACSC.h` 引用，通常无需额外设置。

#### 5.3 配置链接库

在 **项目属性** → **链接器** → **输入** → **附加依赖项** 中：
- **x64 平台**：设置为 `..\..\ACSCL_x64.LIB`
- **x86 平台**：设置为 `..\..\ACSCL_x86.LIB`（已默认配置）

> 注意：原 Win32 配置中链接的是 `..\..\ACSCL_x86.lib`，如果切换到 x64 平台，**必须** 将其改为 `..\..\ACSCL_x64.LIB`。

#### 5.4 MFC 配置

项目使用 MFC 动态链接库（`UseOfMfc = Dynamic`）。确保 Visual Studio 安装了 MFC 组件：
- **Visual Studio Installer** → **修改** → **单个组件** → 搜索 "MFC" → 勾选对应版本的 **"C++ MFC for latest build tools (x86 & x64)"**

#### 5.5 字符集设置

项目使用 **多字节字符集 (MultiByte)**，请确认项目属性 → **高级** → **字符集** 设置为 "使用多字节字符集"。

### 6. 编译与运行

1. 选择 **Release | x64**（或 Debug | x64）配置
2. 菜单 → **生成** → **生成解决方案**（Ctrl+Shift+B）
3. 编译成功后，在 `Release\` 或 `Debug\` 目录下生成 `SPiiPlusCLibraryDemo.exe`
4. 运行程序前确保：
   - 已安装 SPiiPlus ADK Suite（提供 `ACSCL_x64.DLL`）
   - 或将 `ACSCL_x64.DLL` 手动复制到 exe 同目录下

### 7. 连接控制器

程序启动后，可选择两种连接方式：
- **Simulator 模式**：无需实体控制器，使用 SPiiPlus 软件模拟器
- **Ethernet (TCP/IP) 模式**：输入控制器 IP（默认 `10.0.0.100`）和端口（默认 `701`，即 `ACSC_SOCKET_STREAM_PORT`）

---

## 第二部分：SPiiPlus C Library Demo 功能模块详细说明

本 Demo 是一个基于 MFC 的 Windows 桌面应用程序，演示了 SPiiPlus C Library 的核心 API 用法。以下按功能模块逐一说明。

---

### 模块 1：通信连接管理 (Communication)

**对应函数**：`OnBtnConnect()`, `OnBtnDisconn()`, `OnBtnClose()`, `TerminatePrevConnect()`

**功能描述**：
建立和管理与 ACS 运动控制器的通信连接。支持两种连接方式：

| 连接类型 | C Library API | 说明 |
|----------|---------------|------|
| 模拟器 | `acsc_OpenCommSimulator()` | 无需硬件，使用软件模拟器测试 |
| TCP/IP 以太网 | `acsc_OpenCommEthernetTCP(IP, Port)` | 通过以太网连接实体控制器 |

**连接流程**：
1. 调用 `TerminatePrevConnect()` 清除 User Mode Driver (UMD) 中的已有连接（最多支持 10 个通道）
2. 根据选择调用对应的 `acsc_OpenComm*` 函数，获得通信句柄 `m_hAcsComm`
3. 调用 `acsc_SysInfo(handle, 13, ...)` 获取控制器支持的最大轴数
4. 调用 `acsc_SysInfo(handle, 10, ...)` 获取控制器支持的缓冲区数量
5. 初始化定时器，开始周期性状态更新（间隔 50ms）

**断开连接**：调用 `acsc_CloseComm(handle)` 关闭通信。

**相关 C Library API 参考**：
- `acsc_OpenCommSimulator` — 打开模拟器通信通道
- `acsc_OpenCommEthernetTCP` — 通过 TCP 打开以太网通信
- `acsc_OpenCommEthernetUDP` — 通过 UDP 打开以太网通信（代码中注释为备选方案）
- `acsc_CloseComm` — 关闭通信通道
- `acsc_SysInfo` — 查询控制器系统信息
- `acsc_GetConnectionsList` — 获取当前 UMD 连接列表
- `acsc_TerminateConnection` — 终止指定的 UMD 连接

---

### 模块 2：电机使能/禁用 (Motor Enable/Disable)

**对应函数**：`OnBtnEnable()`, `OnBtnDisable()`, `OnBtnDisableall()`

**功能描述**：
控制电机的伺服使能（Servo On）和禁用（Servo Off）。

| 操作 | C Library API | 说明 |
|------|---------------|------|
| 单轴使能 | `acsc_Enable(handle, axis, NULL)` | 使能指定轴的伺服 |
| 等待使能完成 | `acsc_WaitMotorEnabled(handle, axis, 1, timeout)` | 阻塞等待使能完成，超时 3000ms |
| 单轴禁用 | `acsc_Disable(handle, axis, NULL)` | 禁用指定轴的伺服 |
| 等待禁用完成 | `acsc_WaitMotorEnabled(handle, axis, 0, timeout)` | 阻塞等待禁用完成 |
| 全轴禁用 | `acsc_DisableAll(handle, NULL)` | 一次性禁用所有轴 |

**多轴操作**（代码中注释说明）：
```cpp
int AxisList[] = { 0, 1, 5, 7, -1 };   // 末尾必须为 -1
acsc_EnableM(handle, AxisList, NULL);    // 批量使能
acsc_DisableM(handle, AxisList, NULL);   // 批量禁用
```

**错误处理**：
- 使能失败时通过 `acsc_GetMotorError()` 获取电机错误码
- 通过 `acsc_GetErrorString()` 将错误码转换为可读字符串

---

### 模块 3：运动参数设置 (Motion Parameters)

**对应函数**：`UpdateParameters()`, `OnKillfocusEdtVel()`, 以及其他 `OnKillfocus*` 函数

**功能描述**：
读取和设置轴的运动参数。所有参数都可以在电机运动中实时修改。

| 参数 | 读取 API | 设置 API（立即生效） | 对应 ACSPL+ 变量 |
|------|----------|---------------------|-------------------|
| 速度 (Velocity) | `acsc_GetVelocity()` | `acsc_SetVelocityImm()` | VEL |
| 加速度 (Acceleration) | `acsc_GetAcceleration()` | `acsc_SetAccelerationImm()` | ACC |
| 减速度 (Deceleration) | `acsc_GetDeceleration()` | `acsc_SetDecelerationImm()` | DEC |
| 急停减速度 (Kill Deceleration) | `acsc_GetKillDeceleration()` | `acsc_SetKillDecelerationImm()` | KDEC |
| 加加速度 (Jerk) | `acsc_GetJerk()` | `acsc_SetJerkImm()` | JERK |

**两类设置函数的区别**：
- `acsc_SetVelocity` — 设置后在**下一次运动**生效
- `acsc_SetVelocityImm` — **立即**生效，即使电机正在运动中也会改变（本 Demo 使用此类）

---

### 模块 4：定时器状态监控 (Real-time Monitoring)

**对应函数**：`OnTimer()`

**功能描述**：
以 50ms 为间隔周期性读取控制器状态并更新界面显示。使用 `acsc_ReadReal` / `acsc_ReadInteger` 批量读取多轴数据，效率远高于逐轴调用 `acsc_GetFPosition` 等函数。

**监控的数据项**：

| 数据 | ACSPL+ 变量 | 读取方式 | 说明 |
|------|-------------|----------|------|
| 反馈位置 | FPOS | `acsc_ReadReal(handle, -1, "FPOS", ...)` | 编码器反馈位置 |
| 参考位置 | RPOS | `acsc_ReadReal(handle, -1, "RPOS", ...)` | 指令参考位置 |
| 反馈速度 | FVEL | `acsc_ReadReal(handle, -1, "FVEL", ...)` | 编码器反馈速度 |
| 位置误差 | PE | `acsc_ReadReal(handle, -1, "PE", ...)` | 位置跟踪误差 |
| 电机状态 | MST | `acsc_ReadInteger(handle, -1, "MST", ...)` | 位掩码状态值 |
| 电机错误 | MERR | `acsc_ReadInteger(handle, -1, "MERR", ...)` | 电机错误码 |

**电机状态位掩码**：
- `ACSC_MST_ENABLE` — 伺服已使能
- `ACSC_MST_MOVE` — 电机正在运动
- `ACSC_MST_ACC` — 电机正在加减速
- `ACSC_MST_INPOS` — 电机到位（In Position）

**批量读取 vs 逐轴读取**：
```cpp
// 推荐：一次读取所有轴的位置（单次通信）
acsc_ReadReal(handle, -1, "FPOS", 0, nTotalAxes-1, -1, -1, buffer, NULL);

// 不推荐：逐轴读取（N 次通信，延迟大）
for (int i = 0; i < nTotalAxes; i++)
    acsc_GetFPosition(handle, i, &pos[i], NULL);
```

---

### 模块 5：点对点运动 (PTP Motion)

**对应函数**：`OnBtnMovetopoint()`, `OnBtnMoveinc()`, `OnBtnMovedec()`

**功能描述**：
执行点对点（Point-to-Point）运动指令。

| 运动类型 | C Library API | 说明 |
|----------|---------------|------|
| 绝对位置运动 | `acsc_ToPoint(handle, 0, axis, position, NULL)` | 运动到指定绝对位置 |
| 相对正向运动 | `acsc_ToPoint(handle, ACSC_AMF_RELATIVE, axis, +distance, NULL)` | 从当前位置正向移动 |
| 相对负向运动 | `acsc_ToPoint(handle, ACSC_AMF_RELATIVE, axis, -distance, NULL)` | 从当前位置负向移动 |

**安全措施**：运动前检查 `m_MotorStatus[axis] & ACSC_MST_MOVE`，如果电机正在运动中，则不发送新指令。

---

### 模块 6：JOG 运动 (Jog Motion)

**对应函数**：`OnBtnJogPositive()`, `OnBtnJogNegative()`

**功能描述**：
执行持续运动（Jog），电机将持续移动直到收到停止指令。

| JOG 模式 | C Library API | 说明 |
|-----------|---------------|------|
| 无速度指定（正向） | `acsc_Jog(handle, 0, axis, ACSC_POSITIVE_DIRECTION, NULL)` | 以默认速度正向持续运动 |
| 无速度指定（负向） | `acsc_Jog(handle, 0, axis, ACSC_NEGATIVE_DIRECTION, NULL)` | 以默认速度负向持续运动 |
| 指定速度（正向） | `acsc_Jog(handle, ACSC_AMF_VELOCITY, axis, velocity, NULL)` | 以指定速度正向运动 |
| 指定速度（负向） | `acsc_Jog(handle, ACSC_AMF_VELOCITY, axis, -velocity, NULL)` | 以指定速度负向运动 |

---

### 模块 7：运动停止 (Motion Stop)

**对应函数**：`OnBtnStop()`, `OnBtnStopall()`

**功能描述**：

| 停止类型 | C Library API | 说明 |
|----------|---------------|------|
| 单轴正常停止 | `acsc_Halt(handle, axis, NULL)` | 以 DEC 减速度减速停止 |
| 单轴紧急停止 | `acsc_Kill(handle, axis, NULL)` | 以 KDEC 急停减速度停止（代码中注释备用） |
| 多轴停止 | `acsc_HaltM(handle, axesList, NULL)` | 同时停止多个轴，轴数组以 -1 结尾 |

---

### 模块 8：位置归零 (Set Zero)

**对应函数**：`OnBtnSetZero()`

**功能描述**：
将指定轴的反馈位置设置为零，相当于在当前位置建立原点。

```cpp
acsc_SetFPosition(handle, axis, 0, NULL);  // 将反馈位置重置为 0
```

---

### 模块 9：通用数字 I/O 控制 (General Digital I/O)

**对应函数**：`UpdateGeneralIO()`, `OnBtnOutput()`

**功能描述**：
读取和控制通用数字输入/输出端口（8 位输入 + 8 位输出）。

| 操作 | C Library API | 说明 |
|------|---------------|------|
| 读取输入端口 | `acsc_GetInputPort(handle, port, &value, NULL)` | 读取 8 位数字输入状态 |
| 读取输出端口 | `acsc_GetOutputPort(handle, port, &value, NULL)` | 读取 8 位数字输出状态 |
| 设置输出位 | `acsc_SetOutput(handle, port, bit, value, NULL)` | 设置指定位的输出（1=ON, 0=OFF） |

- 端口号 `GPIO_PORT_NO` 默认为 0，对应 ACSPL+ 变量 `IN(0)` 和 `OUT(0)`
- 使用位掩码 `ACSC_MASK_INPUT_0` ~ `ACSC_MASK_INPUT_7` 判断各位状态
- 界面用 BMP 图片（On.bmp / Off.bmp）直观显示 I/O 状态

---

### 模块 10：安全状态监控 (Safety Monitoring)

**对应函数**：`UpdateRightLimit()`, `UpdateLeftLimit()`, `UpdateEmergency()`

**功能描述**：
实时监控硬件限位开关和急停状态。

| 监控项 | C Library API | ACSPL+ 变量 | 说明 |
|--------|---------------|-------------|------|
| 右限位 | `acsc_GetFault()` + `acsc_GetFaultMask()` | FAULT | 硬件右限位开关状态 |
| 左限位 | `acsc_GetFault()` + `acsc_GetFaultMask()` | FAULT | 硬件左限位开关状态 |
| 急停 | `acsc_GetFault(handle, ACSC_NONE, ...)` | S_FAULT | 系统急停开关状态 |

**状态标志**：
- `ACSC_SAFETY_RL` — 右限位标志
- `ACSC_SAFETY_LL` — 左限位标志
- `ACSC_SAFETY_ES` — 急停标志

**显示逻辑**（三态）：
- 绿色 (On.bmp) — 安全功能已启用且正常
- 红色 (Error.bmp) — 触发了限位/急停
- 灰色 (Off.bmp) — 安全功能未在 FaultMask 中启用

---

### 模块 11：缓冲区程序管理 (Buffer Program Management)

**对应函数**：`OnBtnBufferStart()`, `OnBtnBufferStop()`

**功能描述**：
运行和停止控制器中的 ACSPL+ 缓冲区程序。

| 操作 | C Library API | 说明 |
|------|---------------|------|
| 从指定标签运行 | `acsc_RunBuffer(handle, bufNo, labelName, NULL)` | 从程序中指定标签位置开始执行 |
| 从首行运行 | `acsc_RunBuffer(handle, bufNo, NULL, NULL)` | 从第一行开始执行缓冲区程序 |
| 停止程序 | `acsc_StopBuffer(handle, bufNo, NULL)` | 停止指定缓冲区的程序 |

---

### 模块 12：回调函数 (Callbacks)

**对应函数**：`OnBtnCallbackMotionend()`, `OnBtnCallbackProgend()`, `OnBtnCallbackInput()`

**功能描述**：
安装异步回调函数，当特定事件发生时由 C Library 自动调用。

| 回调类型 | 中断类型常量 | 说明 |
|----------|-------------|------|
| 运动结束 | `ACSC_INTR_PHYSICAL_MOTION_END` | 电机物理运动结束时触发（基于 SETTLE/TARGRAD） |
| 程序结束 | `ACSC_INTR_PROGRAM_END` | 缓冲区程序正常结束时触发 |
| 输入变化 | `ACSC_INTR_INPUT` | 数字输入状态变化时触发（不支持仿真模式） |

**安装回调**：
```cpp
acsc_InstallCallback(handle, callbackFunc, &userParam, interruptType);
```

回调函数签名：
```cpp
static int WINAPI CallbackMotionEnd(UINT64 Param, void *UserParameter);
```
- `Param` 是位掩码，每一位对应一个轴/缓冲区/输入位
- `UserParameter` 是安装时传入的用户参数指针

> 注意：运动结束有两种类型：
> - `ACSC_INTR_PHYSICAL_MOTION_END`：基于反馈位置判定（更精确）
> - `ACSC_INTR_LOGICAL_MOTION_END`：基于 AST（指令完成）判定

---

### 模块 13：轴同步 (Axis Synchronization / CONNECT)

**对应函数**：`OnBtnSyncSet()`, `OnBtnSyncRelease()`

**功能描述**：
使用 ACSPL+ 的 CONNECT/DEPENDS 指令将两个轴进行同步（主从跟随）。

**建立同步**（通过 `acsc_Command` 直接发送 ACSPL+ 命令）：
```acspl
MFLAGS(slave).17 = 0              ! 关闭默认跟随行为
CONNECT RPOS(slave) = APOS(master) ! 从轴参考位置 = 主轴实际位置
DEPENDS slave, master              ! 建立依赖关系
```

**释放同步**：
```acspl
MFLAGS(slave).17 = 1              ! 恢复默认行为
```

**C Library API**：此处使用 `acsc_Command(handle, cmd, length, NULL)` 直接发送 ACSPL+ 命令字符串，适用于 C Library 没有封装的 ACSPL+ 原生命令。

---

### 模块 14：多段速度运动 (Multi-Speed Motion)

**对应函数**：`OnBtnMoveMulspd()`

**功能描述**：
使用 PTP/VF（Final Velocity）指令实现分段变速运动。在一次运动中设定多个位置点，每个点可指定不同的运行速度。

**运动曲线示意**：
```
       ------------- (Velocity = Vel1st)
      /             |\
     /              | \
    /               |  \----- (Velocity = Vel2nd)
 --/                |        \--- (Velocity = 0, 停止)
   |                |        |
   0              Pos1st   Pos2nd
```

**ACSPL+ 命令**：
```acspl
PTP/VF axis, Pos1st, Vel1st, Vel2nd    ! 运动到 Pos1st，以 Vel2nd 为终速
PTP/VF axis, Pos2nd, Vel2nd, 0          ! 运动到 Pos2nd，减速至 0 停止
```

**C Library 等效 API**（代码中注释）：
```cpp
acsc_ExtToPoint(handle, ACSC_AMF_VELOCITY | ACSC_AMF_ENDVELOCITY, axis, pos, vel, endVel, NULL);
```

---

### 模块 15：通信终端 (Communication Terminal)

**对应函数**：`OnBnClickedBtnSendCmd()`, `AddString()`

**功能描述**：
内嵌的 ACSPL+ 命令终端，可直接向控制器发送 ACSPL+ 命令并显示返回结果。

**C Library API**：
```cpp
acsc_Transaction(handle, command, cmdLen, response, respSize, &recvCount, NULL);
```

- 发送命令字符串（末尾追加 `\r`）
- 接收控制器返回的响应
- 错误时通过 `acsc_GetLastError()` 获取错误码

**用途**：可用于调试任何 ACSPL+ 命令，如读取变量值、执行即时运动命令等。

---

### 模块 16：错误处理 (Error Handling)

**对应函数**：`ShowErrorMsg()`

**功能描述**：
统一的错误提示机制，调用 C Library 获取错误信息并弹窗显示。

```cpp
int errCode = acsc_GetLastError();                              // 获取最后一个错误码
acsc_GetErrorString(handle, errCode, errStr, 100, &recvCnt);   // 将错误码转为可读字符串
```

---

## 第三部分：常用 C Library API 速查表

| 分类 | API 函数 | 用途 |
|------|----------|------|
| **通信** | `acsc_OpenCommSimulator` | 打开模拟器连接 |
| | `acsc_OpenCommEthernetTCP` | TCP 以太网连接 |
| | `acsc_CloseComm` | 关闭连接 |
| **电机控制** | `acsc_Enable` / `acsc_Disable` | 使能/禁用单轴 |
| | `acsc_EnableM` / `acsc_DisableM` | 使能/禁用多轴 |
| | `acsc_DisableAll` | 禁用全部轴 |
| **运动指令** | `acsc_ToPoint` | 点对点运动 |
| | `acsc_ExtToPoint` | 扩展点对点运动（含终速） |
| | `acsc_Jog` | 持续运动 |
| | `acsc_Halt` / `acsc_HaltM` | 正常停止 |
| | `acsc_Kill` | 紧急停止 |
| **参数读写** | `acsc_GetVelocity` / `acsc_SetVelocityImm` | 速度 |
| | `acsc_GetAcceleration` / `acsc_SetAccelerationImm` | 加速度 |
| | `acsc_GetDeceleration` / `acsc_SetDecelerationImm` | 减速度 |
| | `acsc_GetJerk` / `acsc_SetJerkImm` | 加加速度 |
| | `acsc_GetKillDeceleration` / `acsc_SetKillDecelerationImm` | 急停减速度 |
| **数据读写** | `acsc_ReadReal` / `acsc_ReadInteger` | 批量读取 ACSPL+ 变量 |
| | `acsc_WriteReal` / `acsc_WriteInteger` | 批量写入 ACSPL+ 变量 |
| **I/O** | `acsc_GetInputPort` / `acsc_GetOutputPort` | 读取 I/O 端口 |
| | `acsc_SetOutput` | 设置输出位 |
| **状态查询** | `acsc_GetMotorState` | 电机状态 |
| | `acsc_GetFault` / `acsc_GetFaultMask` | 故障状态 |
| | `acsc_GetMotorError` | 电机错误码 |
| | `acsc_GetFPosition` / `acsc_SetFPosition` | 反馈位置 |
| **程序控制** | `acsc_RunBuffer` | 运行缓冲区程序 |
| | `acsc_StopBuffer` | 停止缓冲区程序 |
| **回调** | `acsc_InstallCallback` | 安装事件回调 |
| **命令** | `acsc_Command` | 发送 ACSPL+ 命令（无返回） |
| | `acsc_Transaction` | 发送命令并接收返回 |
| **错误** | `acsc_GetLastError` | 获取最后错误码 |
| | `acsc_GetErrorString` | 错误码转字符串 |
| **系统** | `acsc_SysInfo` | 查询系统信息 |

---

## 第四部分：快速上手步骤总结

1. **安装** SPiiPlus ADK Suite → 获得 DLL 和 Simulator
2. **克隆** 本仓库代码
3. **打开** `SPiiPlusCLibraryDemo VS.2019.sln`（用 VS 2019+）
4. **配置** x64 平台，链接 `ACSCL_x64.LIB`
5. **编译** Release|x64 配置
6. **运行** EXE，选择 Simulator 或 TCP/IP 连接
7. **使能** 电机 → 设置运动参数 → 执行 PTP/Jog 运动
8. **监控** 实时位置、速度、I/O 和安全状态
