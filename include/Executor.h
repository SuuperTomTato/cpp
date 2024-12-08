#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
using namespace std;

struct Position
{
    int x;
    int y;
    char heading;
    bool fast;
    bool reverse;
    bool operator==(const Position& other) const {
        return ((x==other.x)&&(y==other.y)&&(heading==other.heading)&&(fast==other.fast))&&(reverse==other.reverse);
    }
};

// PoseHandler类负责管理车辆的状态，包括位置、朝向以及加速和倒车状态。
class PoseHandler {
public:
    // 构造函数：初始化位置(x, y)和朝向(heading)
    PoseHandler(Position initpos={0,0,'N',false,false})
        :pos(initpos){}
    
    // Move方法：根据当前朝向和状态逐步移动
    void Move() ;

    // MoveSteps方法：处理多步移动逻辑
    void MoveSteps() ;


    // 左转方法：更新朝向，fast状态下移动一次
    void TurnLeft() ;

    // 右转方法：更新朝向，fast状态下移动一次
    void TurnRight();

    // 切换加速状态
    void ToggleFast() { pos.fast = !pos.fast; }

    // 切换倒车状态
    void ToggleReverse() { pos.reverse = !pos.reverse; }

    // 获取当前状态
    void GetPos(Position& currentpos) const;

private:
        Position pos;

    // 获取当前朝向的索引，用于计算转向后的新朝向
    int GetHeadingIndex() const {
        return string("ESWN").find(pos.heading);
    }
};

// MoveCommand类：处理移动指令
class MoveCommand {
public:
    // 重载()运算符，支持以对象调用的方式执行指令
    void operator()(PoseHandler& handler) const { handler.MoveSteps(); }
};

// TurnLeftCommand类：处理左转指令
class TurnLeftCommand {
public:
    void operator()(PoseHandler& handler) const { handler.TurnLeft(); }
};

// TurnRightCommand类：处理右转指令
class TurnRightCommand {
public:
    void operator()(PoseHandler& handler) const { handler.TurnRight(); }
};

// FastCommand类：处理加速状态切换指令
class FastCommand {
public:
    void operator()(PoseHandler& handler) const { handler.ToggleFast(); }
};

// ReverseCommand类：处理倒车状态切换指令
class ReverseCommand {
public:
    void operator()(PoseHandler& handler) const { handler.ToggleReverse(); }
};
// Executor类：负责解析和执行指令
class Executor {
public:
    // 构造函数：初始化车辆的状态
    Executor(Position initpos)
        : handler(initpos){};

    // 执行一系列指令，使用表驱动方式提高可扩展性
    void ExecuteCommands(const string& commands);

    // 获取当前车辆的状态
    void GetStatus(Position& currentpos) const {
        handler.GetPos(currentpos);
    }

private:
    PoseHandler handler; // 管理车辆状态的PoseHandler实例
};


Position test(int x,int y,char heading,const string& commands);